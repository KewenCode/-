#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"

//�ṹ��ʼ�� - ��̬�汾
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
//	//�����ļ�
//	LoadResource(pc);
//}

//�ṹ��ʼ�� - ��̬�汾
void InitResource(Date_Base* pc)
{
	memset(pc->name_1, 0, sizeof(pc->name_1));
	memset(pc->context_1, 0, sizeof(pc->context_1));
	pc->sz = 0;
	pc->capacity = Default_sz;
}

//�������
void AddResource(Date_Base* pc)
{

}



//�����ļ�
void LoadResource(Date_Base* pc)
{

}