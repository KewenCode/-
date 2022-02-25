#pragma once

#include "Resource.h"

//SQLite版本
void SQliteVersion();
//CMD-UTF8模式
void windows_cmd_support_utf8(void);
//CMD-GBK模式
void windows_cmd_support_GBK(void);

//GBK转UTF-8
// / * input 为 char text[] * \
// / * output 为 utf8buffer指针 * \
// !! 注意: 使用后必须释放空间 !!
// !! Attention: Must Free Space after Used !!
char* GBK_UTF8_Trans(char text[]);

//打印SQLite标准模板
//配合sqlite3_get_table()等函数使用
//input为
// / *打开的数据库* \ sqlite3 * db
// / *要求值的SQL* \ const char * zSql
// / *数据库指针* \ int ret
void StandPrintSQValue(sqlite3* db, const char* zSql, int* ret, int Model);

void SQliteSearch();
