#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define YEAR_4 4
#define MONTH_2 2
#define DAY_2 2
#define TEXT_10 10
#define TEXT_100 100
#define TEXT_200 200
#define TEXT_500 500
#define TEXT_1000 1000

#define Default_sz 3//默认大小

//日期名称 存储结构
typedef struct Date_Name
{
	char year[YEAR_4];
	char month[MONTH_2];
	char day[DAY_2];
	char headline[TEXT_200];
	char id_1[TEXT_10];//每个数据赋予单一编号
}Date_Name;

//内容 存储结构
typedef struct Date_Context
{
	char context_paragraph[TEXT_1000];//每段内容
	int line;//记录行数
	char id_2[TEXT_10];//每个数据赋予单一编号
}Date_Context;

//线路 存储结构
//typedef struct Date_BusLine
//{
//	int Busline;//线路编号
//	char id_1[TEXT_10];//每个数据赋予单一编号
//}Date_BusLine;

//完整结构
typedef struct Date_Base
{
	Date_Name* name_1;//日期名称
	Date_Context* context_1;//内容
	//Date_BusLine* Busline_1;//线路

	char id[TEXT_10];//每个数据赋予单一编号
	int sz;//记录当前有效信息数量
	int capacity;//记录当前最大容量
}Date_Base;

//--------------------静态可修改范围--------------------

//结构初始化
void InitResource(Date_Base* pc);

//添加数据
void AddResource(Date_Base* pc);

//加载文件
void LoadResource(Date_Base* pc);