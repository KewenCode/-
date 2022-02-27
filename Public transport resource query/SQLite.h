#pragma once

#include "Resource.h"

//SQLite�汾
void SQliteVersion();
//CMD-UTF8ģʽ
void windows_cmd_support_utf8(void);
//CMD-GBKģʽ
void windows_cmd_support_GBK(void);

int Login(const char* Username, char* Password);

//GBKתUTF-8
// / * input Ϊ char text[] * \
// / * output Ϊ utf8bufferָ�� * \
// !! ע��: ʹ�ú�����ͷſռ� !!
// !! Attention: Must Free Space after Used !!
char* GBK_UTF8_Trans(char text[]);

//������·ȥ�ز�ѯģ��
//���StandPrintSQValue()�Ⱥ���ʹ��
// {* �򿪵����ݿ� *}  sqlite3 * db
// {* Ҫ��ֵ��SQL����·�� *}  const char * zSql
// {* ���ݿ�ָ�� *}  int ret
// {* ���ط����ַ��� ��ʽ��0|1|0|��*}  char** ExpelLineReturn
void BuslineExpelModel(sqlite3* db, const char* zSql, int* ret, char** ExpelLineReturn);

//��ӡSQLite��׼ģ��
//���sqlite3_get_table()�Ⱥ���ʹ��
// / *�򿪵����ݿ�* \ sqlite3 * db
// / *Ҫ��ֵ��SQL* \ const char * zSql
// / *���ݿ�ָ��* \ int ret
// / *ʹ��ģʽ* \ int Model 
// / * 1.������·ȥ�ز�ѯģ�� 
void StandPrintSQValue(sqlite3* db, const char* zSql, int* ret, int Model);

void SQliteSearch();
