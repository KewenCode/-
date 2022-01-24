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


//日期名称 存储结构
typedef struct Base_Name
{
	unsigned int id;
	unsigned int sz;//记录当前有效信息数量
	unsigned int capacity;//记录当前最大容量
	unsigned short year;
	unsigned short month;
	unsigned short day;
	unsigned short headlinecount;
	char headline[0];
}Base_Name;
unsigned long* Date_Name_arr[DEFAULT_SZ];//指针数组
unsigned long** Date_Name;//指针地址

//文本内容 存储结构
typedef struct Base_Context
{
	unsigned int sz;//记录当前有效信息数量
	unsigned int capacity;//记录当前最大容量
	unsigned int id;
	unsigned short line;//记录行数
	unsigned short contextcount;
	char context_paragraph[0];//每段内容
}Base_Context;
unsigned long* Date_Context_arr[DEFAULT_SZ];//指针数组
unsigned long** Date_Context;//指针地址

//线路 存储结构
//typedef struct Date_BusLine
//{
//	int Busline;//线路编号
//	char id_1[TEXT_10];//每个数据赋予单一编号
//}Date_BusLine;

//结构初始化
//void InitResource(Base_Name* name, Base_Context* context);

////加载文件
//void Load_Resource(Date_Base* pc);

//录入数据
void AddResource(unsigned long** dn, unsigned long** dc);

//查询
void SeacrhResource(unsigned long** dn, unsigned long** dc);

////检测增容
//void CheckResource(Date_Base* pc);
//
////保存文件
//void SaveResource(Date_Base* pc);
//
////修改文件
//void ModityResource(Date_Base* pc);
//
////删除内容
//void DelateResource(Date_Base* pc);
//
////销毁内存
//void Destorycontact(Date_Base* pc);