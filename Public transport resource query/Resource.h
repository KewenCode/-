#pragma once
#pragma warning(disable : 6031)//忽略vs中scanf报错的nc行为
#pragma warning(disable : 5105)//生成“已定义”的宏扩展具有未定义的行为

#define FileVersion "V0.0.4.1-dev"
#define ProductVersion "V0.0.1.0"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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

//--------------------[ 静 态 ]可修改范围--------------------

//完整结构 - 静态版本
//typedef struct Date_Base
//{
//	Date_Name name_1[MAX];//日期名称
//	Date_Context context_1[MAX];//内容
//	//Date_BusLine* Busline_1;//线路
//
//	//char id[TEXT_10];//每个数据赋予单一编号
//	int sz;//记录当前有效信息数量
//	int capacity;//记录当前最大容量
//}Date_Base;


//日期名称 存储结构
typedef struct Date_Name
{
	int year;
	int month;
	int day;
	int headlinecount;
	char headline[0];
	//char id_1[TEXT_10];//每个数据赋予单一编号
}Date_Name;

//内容 存储结构
typedef struct Date_Context
{
	char context_paragraph[TEXT_1000];//每段内容
	//int line;//记录行数
	//char id_2[TEXT_10];//每个数据赋予单一编号
}Date_Context;

//完整结构 - 动态版本
typedef struct Date_Base
{
	Date_Name* name_1;//日期名称
	Date_Context* context_1;//内容
	//Date_BusLine* Busline_1;//线路

	//char id[TEXT_10];//每个数据赋予单一编号
	int sz;//记录当前有效信息数量
	int capacity;//记录当前最大容量
	Date_Base* next;
}Date_Base;

//线路 存储结构
//typedef struct Date_BusLine
//{
//	int Busline;//线路编号
//	char id_1[TEXT_10];//每个数据赋予单一编号
//}Date_BusLine;

//结构初始化
void InitResource(Date_Base* pc);

//加载文件
void Load_Resource(Date_Base* pc);

//录入数据
void AddResource(Date_Base* pc);

//查询
void SeacrhResource(Date_Base* pc);

//检测增容
void CheckResource(Date_Base* pc);

//保存文件
void SaveResource(Date_Base* pc);

//修改文件
void ModityResource(Date_Base* pc);

//删除内容
void DelateResource(Date_Base* pc);

//销毁内存
void Destorycontact(Date_Base* pc);