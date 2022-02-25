#pragma once

#include "Resource.h"

//SQLite�汾
void SQliteVersion();
//CMD-UTF8ģʽ
void windows_cmd_support_utf8(void);
//CMD-GBKģʽ
void windows_cmd_support_GBK(void);

//GBKתUTF-8
// / * input Ϊ char text[] * \
// / * output Ϊ utf8bufferָ�� * \
// !! ע��: ʹ�ú�����ͷſռ� !!
// !! Attention: Must Free Space after Used !!
char* GBK_UTF8_Trans(char text[]);

//��ӡSQLite��׼ģ��
//���sqlite3_get_table()�Ⱥ���ʹ��
//inputΪ
// / *�򿪵����ݿ�* \ sqlite3 * db
// / *Ҫ��ֵ��SQL* \ const char * zSql
// / *���ݿ�ָ��* \ int ret
void StandPrintSQValue(sqlite3* db, const char* zSql, int* ret, int Model);

void SQliteSearch();
