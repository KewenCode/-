#pragma once

//SQLite版本
void SQliteVersion();
//CMD-UTF8模式
void windows_cmd_support_utf8(void);
//CMD-GBK模式
void windows_cmd_support_GBK(void);
//GBK转UTF-8
char* GBK_UTF8_Trans(char text[]);

void SQliteSearch();
