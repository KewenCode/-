#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 6385)//忽略vs中scanf报错的nc行为

#include "Resource.h"
#include "Prompttext.h"
#include "File.h"

void SQliteVersion()
{
    printf("%s\n", sqlite3_libversion());
}

void windows_cmd_support_utf8(void)
{
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

void windows_cmd_support_GBK(void)
{
#ifdef WIN32
    system("chcp 936 & cls"); //cls 用来清除 chcp 的输出
#endif
}

char* GBK_UTF8_Trans(char text[])
{
    str_normalize_init();
    const char* utf8 = text;
    uint32_t utf8_len = strlen(utf8);
    uint32_t utf8buffer_len = utf8_len * 3 + 1;
    char* utf8buffer = (char*)malloc(utf8buffer_len);
    if (utf8buffer == NULL)
    {
        perror("utf8buffer:");
        return 0;
    }
    memset(utf8buffer, 0, utf8buffer_len);
    gbk_to_utf8(utf8, utf8_len, &utf8buffer, &utf8buffer_len);
    return utf8buffer;
}

int Login(const char* Username, char* Password)
{
    sqlite3* ppdb;
    char** SQLiteResult = NULL;
    int Row = 0, Col = 0;
    int ret = sqlite3_open(".\\Date\\test.db", &ppdb);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n", sqlite3_errmsg(ppdb));
        exit(1);
    }
    char SQL_Username[128] = { 0 };
    memset(SQL_Username, 0, sizeof(SQL_Username));
    //char SQL_Password[128] = { 0 };
    //memset(SQL_Password, 0, sizeof(SQL_Password));
    //sprintf(SQL_Password, "SELECT * FROM User WHERE context GLOB '*%s*';", Password);
    sprintf(SQL_Username, "SELECT * FROM User WHERE Name GLOB '*%s*';", Username);
    ret = sqlite3_get_table(ppdb, GBK_UTF8_Trans(SQL_Username), &SQLiteResult, &Row, &Col, NULL);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_get_table:%s\n", sqlite3_errmsg(ppdb));
        exit(1);
    }
    if (Row == 0)
    {
        printf("用户名输入错误！\n");
        system("pause");
        return 1;
    }
    else if (strcmp(SQLiteResult[Col + 1], GBK_UTF8_Trans(Password)) == 0)
    {
        return 2;
    }
    else if (strcmp(SQLiteResult[Col + 1], GBK_UTF8_Trans(Password)) != 0)
    {
        printf("密码输入错误！\n");
        system("pause");
        return 3;
    }
    else
    {
        printf("return 4\n");
        system("pause");
        return 4;
    }
}

void BuslineExpelModel(sqlite3* db, const char* zSql, int* ret, char** ExpelLineReturn)
{
    //存储ID结构体
    typedef struct ID
    {
        char id[9];
    }ID;
    ID* IDStock = malloc(sizeof(ID));
    ID* IDStock_NullPointer = NULL;
    //变量&定义
    char** SQLiteResult;
    int ExiseSQLiteResult_Num = 0, Strcmp_Compare = 0, Row, Col, i, j;
    //前缀字符
    char ExpelLineLetter[] = "1|2|3|4|5|6|7|8|9|0|Y";//定义前缀
    char* Separator = "|";
    char* Letter;
    Letter = strtok(ExpelLineLetter, Separator);
    //循环添加前缀
    while (Letter != NULL)
    {
        //存储前缀查询线路名
        char BusLine_Extra[10] = { 0 };
        char SQL_BusLine_Extra[128] = { 0 };
        sprintf(BusLine_Extra, "%s", Letter);//添加前缀
        Letter = strtok(NULL, Separator);//读取下一个前缀
        strcat(BusLine_Extra, zSql);
        strcat(BusLine_Extra, "路");
        sprintf(SQL_BusLine_Extra, "SELECT * FROM Date_2016 WHERE context GLOB '*%s*';", BusLine_Extra);
        *ret = sqlite3_get_table(db, GBK_UTF8_Trans(SQL_BusLine_Extra), &SQLiteResult, &Row, &Col, NULL);//使用SQL语句
        if (*ret != SQLITE_OK)
        {
            printf("sqlite3_get_table:%s\n", sqlite3_errmsg(db));
            exit(1);
        }
        //结果行数自加
        //ExiseSQLiteResult_Num定义为0，不能加入循环内，否则realloc为free
        ExiseSQLiteResult_Num += Row;
        if (Row != 0)
        {
            IDStock_NullPointer = realloc(IDStock, ExiseSQLiteResult_Num * sizeof(ID));
            //开辟空间判断，不成功跳过
            if (IDStock_NullPointer != NULL)
            {
                IDStock = IDStock_NullPointer;
                IDStock_NullPointer = NULL;
            }
            //ID存储
            for (j = ExiseSQLiteResult_Num - Row; j < ExiseSQLiteResult_Num; j++)
            {
                memcpy(IDStock[j].id, SQLiteResult[Col], 9);
                Col += 10;
            }
        }
    }
    //存储查询线路名
    char BusLine_Base[10] = { 0 };
    char SQL_BusLine_Base[128] = { 0 };
    strcat(BusLine_Base, zSql);
    strcat(BusLine_Base, "路");
    sprintf(SQL_BusLine_Base, "SELECT * FROM Date_2016 WHERE context GLOB '*%s*';", BusLine_Base);
    *ret = sqlite3_get_table(db, GBK_UTF8_Trans(SQL_BusLine_Base), &SQLiteResult, &Row, &Col, NULL);//使用SQL语句
    if (*ret != SQLITE_OK)
    {
        printf("sqlite3_get_table:%s\n", sqlite3_errmsg(db));
        exit(1);
    }
    //与前缀线路名ID对比，获得*ExpelLineReturn字符串
    //相同返回 “0|”，不同返回 “1|”
    for (i = 0; i < Row; i++)
    {
        if (ExiseSQLiteResult_Num == 0)
        {
            //ExiseSQLiteResult_Num为0，每次添加“1|”
            strcat(*ExpelLineReturn, "1|");
        }
        else
        {
            //遍历结构体中所有ID
            for (j = 0; j < ExiseSQLiteResult_Num; j++)
            {
                Strcmp_Compare = strcmp(SQLiteResult[Col], IDStock[j].id);
                if (Strcmp_Compare == 0)
                {
                    //前缀线路名与查询线路名ID相同
                    strcat(*ExpelLineReturn, "0|");//丢弃
                    break;
                }
            }
            if (Strcmp_Compare != 0)
            {
                //所有结果不同
                strcat(*ExpelLineReturn, "1|");//保留
            }
        }
        Col += 10;//跳过一行十列
    }
    free(IDStock);//释放结构体内存空间
}

void StandPrintSQValue(sqlite3* db, const char* zSql, int* ret, int Model)
{
    //变量&定义
    char** SQLiteResult = NULL;
    char ExpelLine[128] = { 0 };
    char* pExpelLine = ExpelLine;
    char SQL_BusLine[128] = { 0 };
    char BusLine[10] = { 0 };
    int Row, Col, i, j = 0;
    //模式选择
    switch (Model)
    {
    case 1: //公交线路去重查询模块
        BuslineExpelModel(db, zSql, ret, &pExpelLine);
        strcat(BusLine, zSql);//转码避免查询错误
        strcat(BusLine, "路");//转码避免查询错误
        //strcpy(SQL_BusLine, "SELECT * FROM test WHERE context GLOB '*444*';");
        sprintf(SQL_BusLine, "SELECT * FROM Date_2016 WHERE context GLOB '*%s*';", BusLine);
        *ret = sqlite3_get_table(db, GBK_UTF8_Trans(SQL_BusLine), &SQLiteResult, &Row, &Col, NULL);
        if (*ret != SQLITE_OK)
        {
            printf("sqlite3_get_table:%s\n", sqlite3_errmsg(db));
            exit(1);
        }
        break;
    default: //默认常规SQL查询
        *ret = sqlite3_get_table(db, zSql, &SQLiteResult, &Row, &Col, NULL);
        if (*ret != SQLITE_OK)
        {
            printf("sqlite3_get_table:%s\n", sqlite3_errmsg(db));
            exit(1);
        }
        break;
    }
    int Index = Col;
    char* ContextLine[9] = { "查询内容如下：\n","\033[42;37;1m[ 时 间 ]\033[0;47;30m ","年","月","日",   //待转换字符
                      "\033[42;37;1m[ 标 题 ]\033[0;47;30m ",                      //ContextLine_Trans[5]
                      "\033[42;37;1m[ 正 文 ]\033[0;47;30m " ,                     //ContextLine_Trans[6]
                      "\033[1;47;30m         -----------------------------           \n"
                      "                     输出完成                     \n"
                      "               总计输出\033[1;46;37m ",                      //ContextLine_Trans[7]
                      " \033[1;47;30m个数据\n"
                      "          -----------------------------           \n" };     //ContextLine_Trans[8]
    char* ContextLine_Trans[9];//存储转换后字符串指针
    for (i = 0; i < 9; i++)
    {
        //GBK转UTF8
        ContextLine_Trans[i] = GBK_UTF8_Trans(ContextLine[i]);
    }
    if (SQLiteResult == NULL)
    {
        printf("%s%d%s", ContextLine_Trans[7], Row, ContextLine_Trans[8]);//打印输出统计
    }
    else
    {
        printf("%s\n", ContextLine_Trans[0]);
        char* Separator = "|";
        char* Strtok_ExpeLine;
        if (Model == 1)
        {
            Strtok_ExpeLine = strtok(ExpelLine, Separator);
        }
        else
        {
            Strtok_ExpeLine = "0";
        }
        while (Strtok_ExpeLine != NULL)
        {
            //打印输出部分
            Index += 1;
            if (strcmp(Strtok_ExpeLine, "0") != 0)
            {
                printf("%s%s%s%s%s%s%s\t\t%s%s\n", ContextLine_Trans[1], SQLiteResult[Index], ContextLine_Trans[2], SQLiteResult[Index + 1], ContextLine_Trans[3], SQLiteResult[Index + 2], ContextLine_Trans[4], ContextLine_Trans[5], SQLiteResult[Index + 3]);
                printf("%s\n%s", ContextLine_Trans[6], SQLiteResult[Index + 4]);
                printf("\n");
                printf("\n");
                j++;
            }
            Index += 9;
            if (Model == 1)
            {
                Strtok_ExpeLine = strtok(NULL, Separator);
            }
            else
            {
                Strtok_ExpeLine = "0";
            }
        }
        printf("\n");
        printf("%s%d%s", ContextLine_Trans[7], j, ContextLine_Trans[8]);//打印输出统计
        for (i = 0; i < 9; i++)
        {
            //释放存储指针
            free(ContextLine_Trans[i]);
        }
    }
}

//打印所有数值
//void print(void* arg, int colunm, char** value, char** name)
//{
//    int i;
//    for (i = 0; i < colunm; i++)
//    {
//        printf("%s=%s", name[i], value[i]);
//    }
//    printf("\n");
//}

//关键词搜索
void SQliteSearch()
{
    sqlite3* ppdb;
    int ret = sqlite3_open(".\\Date\\test.db", &ppdb);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n", sqlite3_errmsg(ppdb));
        exit(1);
    }
    char sql[128] = { 0 };
    memset(sql, 0, sizeof(sql));
    char busline[10] = { 0 };
    printf("请输入查询线路号：\n");
    scanf("%s", &busline);
    //strcat(busline, "路");//转码避免查询错误
    windows_cmd_support_utf8();//cmd转码
    //strcpy(sql, "SELECT * FROM test WHERE context GLOB '*444*';");
    //sprintf(sql, "SELECT * FROM Date_2016 WHERE context GLOB '*%s*';",busline);
    StandPrintSQValue(ppdb, busline, &ret, 1);
    system("pause");
    ret = sqlite3_close(ppdb);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_close:%s\n", sqlite3_errmsg(ppdb));
        exit(1);
    }
    windows_cmd_support_GBK();
}