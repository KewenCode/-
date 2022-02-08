#pragma once
#pragma warning(disable : 6031)//忽略vs中scanf报错的nc行为
#pragma warning(disable : 5105)//生成“已定义”的宏扩展具有未定义的行为

#define FileVersion "V0.0.6.2-dev"
#define ProductVersion "V0.0.1.0"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define YEAR_4 5
#define MONTH_2 3
#define DAY_2 3
#define TEXT_10 11
#define TEXT_100 101
#define TEXT_200 201
#define TEXT_500 501
#define TEXT_1000 1001

#define DEFAULT_SZ 3//默认大小
#define MAX 3

//类型定义
typedef struct Base_Main
{
	char id[9];
	unsigned short year;
	unsigned short month;
	unsigned short day;
	unsigned short headlinecount;
	unsigned short line;//记录行数
	unsigned short contextcount;//字数
}Base_Main;
//主结构
	typedef struct Base_Struct
	{
		Base_Main* BM;//存放的信息空间
		unsigned int sz;//记录已读取有效信息总量
		unsigned int capacity;//目前malloc容量
	}Base_Struct;

//名称 存储结构
	typedef struct Base_Name
	{
		char id[9];
		char headline[0];//标题内容
	}Base_Name;
	typedef unsigned long* DN_TypeDefine;
	typedef struct DN_SingleList
	{
		unsigned int sz; //已存储有效信息量
		unsigned int capacity;//目前malloc容量
		DN_TypeDefine DN[0]; //DN指针
	}DN_SingleList;

//文本内容 存储结构
	typedef struct Base_Context
	{
		char id[11];
		char context_paragraph[0];//每段内容
	}Base_Context;
	//行结构
	typedef unsigned long* BC_TypeDefine;
	typedef struct BC_LineList
	{
		unsigned short line; //行数
		BC_TypeDefine BCL[0]; //BC指针
	}BC_LineList;
	//单结构
	typedef unsigned long* BCL_TypeDefine;
	typedef struct BC_SingleList
	{
		unsigned short alline; //总行数
		unsigned int sz; //已存储有效信息量
		unsigned int capacity;//目前malloc容量
		BCL_TypeDefine DC[0]; //BCL指针
	}BC_SingleList;

//结构初始化
void InitResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

//录入数据
void AddResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);
//录入数据 - 标题
void AddResource_Headline(Base_Struct* ptrq, DN_SingleList** DN_sl, char* id);
//录入数据 - 文本
void AddResource_Context(Base_Struct* ptrq, BC_SingleList** BC_sl, char* id);

//查询
void SeacrhResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

//检测增容
void CheckResource(Base_Struct* ptrq);

//修改文件
void ModifyResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

//删除内容
void DelateResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

//销毁内存
void Destorycontact(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

