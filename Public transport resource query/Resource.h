#pragma once
#pragma warning(disable : 6031)//忽略vs中scanf报错的nc行为
#pragma warning(disable : 5105)//生成“已定义”的宏扩展具有未定义的行为

#define FileVersion "V0.0.6.0-dev"
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

//日期名称 存储结构
typedef struct Base_Name
{
	char id[9];
	char headline[0];
}Base_Name;
typedef unsigned long* Date_Name;
typedef struct Date_Name_arr
{
	unsigned int sz;//记录已读取有效信息总量
	unsigned int capacity;//目前malloc容量
	Date_Name* DN;
}Date_Name_arr;

//文本内容 存储结构
typedef struct Base_Context
{
	char id[11];
	char context_paragraph[0];//每段内容
}Base_Context;
//
typedef unsigned long* Base_Context_List;
typedef struct Base_Context_arr
{
	unsigned short line;//临时记录行数
	Base_Context_List BCL[0];
}Base_Context_arr;
//储存Base_Context指针
typedef unsigned long* Date_Context;
typedef struct Date_Context_arr
{
	unsigned short alline;//记录行数
	unsigned int sz;//记录已读取有效信息总量
	unsigned int capacity;//目前malloc容量
	Date_Context* DC;
}Date_Context_arr;

//线路 存储结构
//typedef struct Date_BusLine
//{
//	int Busline;//线路编号
//	char id_1[TEXT_10];//每个数据赋予单一编号
//}Date_BusLine;

//结构初始化
void InitResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr** bca);

////加载文件
//void Load_Resource(Date_Base* pc);

//录入数据
void AddResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr** bca);

//录入数据 - 文本
void AddResource_Context(Base_Struct* ptrq, Date_Context_arr* dca, Base_Context_arr** bca, char* id);

//查询
void SeacrhResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr** bca);

//检测增容
void CheckResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca);

//保存文件
//void SaveResource(Date_Base* pc);

//修改文件
//void ModifyResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca);

//删除内容
void DelateResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca);

//销毁内存
void Destorycontact(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca);

