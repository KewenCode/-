#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"
#include "File.h"

//SQLite版本
void SQliteVersion()
{
    printf("%s\n", sqlite3_libversion());
}

//CMD-UTF8模式
void windows_cmd_support_utf8(void)
{
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

//CMD-GBK模式
void windows_cmd_support_GBK(void)
{
#ifdef WIN32
    system("chcp 936 & cls"); //cls 用来清除 chcp 的输出
#endif
}

//GBK转UTF-8
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
        
    windows_cmd_support_utf8();//cmd转码
    strcpy(sql, "SELECT * FROM test WHERE context LIKE '%901%';");
    /*ret = sqlite3_exec(ppdb, sql, printf, NULL, NULL); 
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
        exit(1);
    }*/
    char** result;
    int row, col;
    ret = sqlite3_get_table(ppdb, sql, &result, &row, &col, NULL);
        if (ret != SQLITE_OK)
        {
            printf("sqlite3_get_table:%s\n", sqlite3_errmsg(ppdb));
            exit(1);
        }
    int i;
    int Index = col;
    //for (i = 0; i < row; i++)
    //{
    //    Index += 1;
    //    for (j = 1; j < 6; j++)
    //    {
    //        printf("%s=%s", result[j], result[Index]);
    //        Index++;
    //    }
    //    Index += 4;
    //    printf("\n");
    //}

    char* line[9] = { "查询内容如下：\n","\033[42;37;1m[ 时 间 ]\033[1;47;30m：","年","月","日",
                      "\033[42;37;1m[ 标 题 ]\033[1;47;30m：",
                      "\033[42;37;1m[ 正 文 ]\033[1;47;30m：" ,
                      "         -----------------------------           \n"
                      "                     输出完成                     \n"
                      "               总计输出\033[1;46;37m ",
                      " \033[1;47;30m个数据\n"
                      "          -----------------------------           \n" };
    char* line_trans[9];//存储转换后字符串指针
    for (i = 0; i < 9; i++)
    {
        line_trans[i] = GBK_UTF8_Trans(line[i]);
    }
    printf("%s\n", line_trans[0]);
    for (i = 0; i < row; i++)
    {
        Index += 1;
        printf("%s%s%s%s%s%s%s\t\t%s%s\n", line_trans[1], result[Index], line_trans[2], result[Index + 1], line_trans[3], result[Index + 2], line_trans[4], line_trans[5], result[Index + 3]);
        printf("%s\n%s", line_trans[6], result[Index + 4]);
        Index += 9;
        printf("\n");
    }

    printf("\n");
    printf("%s%d%s", line_trans[7], row, line_trans[8]);
    for (i = 0; i < 9; i++)
    {
        free(line_trans[i]);
    }
    system("pause");
    windows_cmd_support_GBK();
}