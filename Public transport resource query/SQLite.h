#pragma once

#include "Resource.h"

//SQLite版本
void SQliteVersion();
//CMD-UTF8模式
void windows_cmd_support_utf8(void);
//CMD-GBK模式
void windows_cmd_support_GBK(void);

int Login(const char* Username, char* Password);

//GBK转UTF-8
// / * input 为 char text[] * \
// / * output 为 utf8buffer指针 * \
// !! 注意: 使用后必须释放空间 !!
// !! Attention: Must Free Space after Used !!
char* GBK_UTF8_Trans(char text[]);

//公交线路去重查询模块
//配合StandPrintSQValue()等函数使用
// {* 打开的数据库 *}  sqlite3 * db
// {* 要求值的SQL或线路名 *}  const char * zSql
// {* 数据库指针 *}  int ret
// {* 查重返回字符串 格式【0|1|0|】*}  char** ExpelLineReturn
void BuslineExpelModel(sqlite3* db, const char* zSql, int* ret, char** ExpelLineReturn);

//打印SQLite标准模板
//配合sqlite3_get_table()等函数使用
// / *打开的数据库* \ sqlite3 * db
// / *要求值的SQL* \ const char * zSql
// / *数据库指针* \ int ret
// / *使用模式* \ int Model 
// / * 1.公交线路去重查询模块 
void StandPrintSQValue(sqlite3* db, const char* zSql, int* ret, int Model);

void SQliteSearch();
