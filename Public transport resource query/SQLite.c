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

void BuslineExpelModel(sqlite3* db, int* ret, const char* zSql,char** ExpelLineReturn)
{
    char** result;
    int sz = 0, comple = 0, row, col, i, j;

    //循环搜寻前缀0-9
    typedef struct ID
    {
        char id[9];
    }ID;
    ID* tmp = malloc(sizeof(ID));
    ID* tmp_1 = NULL;

    char ExpelLineLetter[] = "1|2|3|4|5|6|7|8|9|0|Y";
    char* delim = "|";
    char* Letter;
    Letter = strtok(ExpelLineLetter, delim);
    while (Letter != NULL)
    {
        char busline[10] = { 0 };
        sprintf(busline, "%s", Letter);
        Letter = strtok(NULL, delim);
        strcat(busline, zSql);
        strcat(busline, "路");
        char sql_temp[128] = { 0 };
        sprintf(sql_temp, "SELECT * FROM Date_2016 WHERE context GLOB '*%s*';", busline);
        *ret = sqlite3_get_table(db, GBK_UTF8_Trans(sql_temp), &result, &row, &col, NULL);
        if (*ret != SQLITE_OK)
        {
            printf("sqlite3_get_table:%s\n", sqlite3_errmsg(db));
            exit(1);
        }
        sz += row;
        if (row != 0)
        {
            tmp_1 = realloc(tmp, sz * sizeof(ID));
            if (tmp_1 != NULL)
            {
                tmp = tmp_1;
                tmp_1 = NULL;
            }
            for (j = sz - row; j < sz; j++)
            {
                memcpy(tmp[j].id, result[col], 9);
                col += 10;
            }
        }

    }
    char BuslineResult[10] = { 0 };
    strcat(BuslineResult, zSql);
    strcat(BuslineResult, "路");
    char sql[128] = { 0 };
    sprintf(sql, "SELECT * FROM Date_2016 WHERE context GLOB '*%s*';", BuslineResult);
    *ret = sqlite3_get_table(db, GBK_UTF8_Trans(sql), &result, &row, &col, NULL);
    if (*ret != SQLITE_OK)
    {
        printf("sqlite3_get_table:%s\n", sqlite3_errmsg(db));
        exit(1);
    }
    for (i = 0; i < row; i++)
    {
        if (sz == 0)
        {
            strcat(*ExpelLineReturn, "1|");
        }
        else
        {
            for (j = 0; j < sz; j++)
            {
                comple = strcmp(result[col], tmp[j].id);
                if (comple == 0)
                {
                    strcat(*ExpelLineReturn, "0|");
                    break;
                }
            }
            if (comple != 0)
            {
                strcat(*ExpelLineReturn, "1|");
            }
        }
        col += 10;
    }
    free(tmp);
}

void StandPrintSQValue(sqlite3* db, const char* zSql,int* ret,int Model)
{
    char** result = NULL;
    char ExpelLine[128] = { 0 };
    char sql[128] = { 0 };
    char busline[10] = { 0 };
    char* pExpelLine = ExpelLine;
    int row, col, i, j = 0;
    switch (Model)
    {
    case 1:
        BuslineExpelModel(db, ret, zSql, &pExpelLine);
        strcat(busline, zSql);//转码避免查询错误
        strcat(busline, "路");//转码避免查询错误
        //strcpy(sql, "SELECT * FROM test WHERE context GLOB '*444*';");
        sprintf(sql, "SELECT * FROM Date_2016 WHERE context GLOB '*%s*';", busline);
        *ret = sqlite3_get_table(db, GBK_UTF8_Trans(sql), &result, &row, &col, NULL);
        if (*ret != SQLITE_OK)
        {
            printf("sqlite3_get_table:%s\n", sqlite3_errmsg(db));
            exit(1);
        }
        break;
    default:
        *ret = sqlite3_get_table(db, zSql, &result, &row, &col, NULL);
        if (*ret != SQLITE_OK)
        {
            printf("sqlite3_get_table:%s\n", sqlite3_errmsg(db));
            exit(1);
        }
        break;
    }
    int Index = col;
    char* line[9] = { "查询内容如下：\n","\033[42;37;1m[ 时 间 ]\033[0;47;30m ","年","月","日",   //待转换字符
                      "\033[42;37;1m[ 标 题 ]\033[0;47;30m ",                      //line_trans[5]
                      "\033[42;37;1m[ 正 文 ]\033[0;47;30m " ,                     //line_trans[6]
                      "\033[1;47;30m         -----------------------------           \n"
                      "                     输出完成                     \n"
                      "               总计输出\033[1;46;37m ",                      //line_trans[7]
                      " \033[1;47;30m个数据\n"
                      "          -----------------------------           \n" };     //line_trans[8]
    char* line_trans[9];//存储转换后字符串指针
    for (i = 0; i < 9; i++)
    {
        //GBK转UTF8
        line_trans[i] = GBK_UTF8_Trans(line[i]);
    }
    if (result == NULL)
    {
        printf("%s%d%s", line_trans[7], row, line_trans[8]);//打印输出统计
    }
    else
    {
        printf("%s\n", line_trans[0]);
        char* delim = "|";
        char* tmp;
        tmp = strtok(ExpelLine, delim);
        while (tmp != NULL)
        {
            //打印输出部分
            Index += 1;
            if (strcmp(tmp, "0") != 0)
            {
                printf("%s%s%s%s%s%s%s\t\t%s%s\n", line_trans[1], result[Index], line_trans[2], result[Index + 1], line_trans[3], result[Index + 2], line_trans[4], line_trans[5], result[Index + 3]);
                printf("%s\n%s", line_trans[6], result[Index + 4]);
                printf("\n");
                printf("\n");
                j++;
            }
            Index += 9;
            tmp = strtok(NULL, delim);
        }
        
        printf("\n");
        printf("%s%d%s", line_trans[7], j, line_trans[8]);//打印输出统计
        for (i = 0; i < 9; i++)
        {
            //释放存储指针
            free(line_trans[i]);
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
    printf("请选择查询线路号：");
    scanf("%s", &busline);
    //strcat(busline, "路");//转码避免查询错误
    windows_cmd_support_utf8();//cmd转码
    //strcpy(sql, "SELECT * FROM test WHERE context GLOB '*444*';");
    sprintf(sql, "SELECT * FROM Date_2016 WHERE context GLOB '*%s*';",busline);
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