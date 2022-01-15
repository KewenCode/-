#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"

//结构初始化 - 动态版本
//void InitResource(Date_Base* pc)
//{
//	pc->name_1 = (Date_Name*)malloc(Default_sz * sizeof(Date_Name));
//	if (pc->name_1 == NULL)
//	{
//		perror("Initresource/Date_Name");
//		return;
//	}
//	pc->context_1 = (Date_Context*)malloc(Default_sz * sizeof(Date_Context));
//	if (pc->context_1 == NULL)
//	{
//		perror("Initresource/Date_Context");
//		return;
//	}
//	pc->sz = 0;
//	pc->capacity = Default_sz;
//
//	//加载文件
//	LoadResource(pc);
//}

//结构初始化 - 静态版本
void InitResource(Date_Base* pc)
{
	memset(pc->name_1, 0, sizeof(pc->name_1));
	memset(pc->context_1, 0, sizeof(pc->context_1));
	pc->sz = 0;
	pc->capacity = Default_sz;
}

//添加数据
void AddResource(Date_Base* pc)
{

}



//加载文件
void LoadResource(Date_Base* pc)
{

}