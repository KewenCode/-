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

#define Default_sz 3//Ĭ�ϴ�С

//�������� �洢�ṹ
typedef struct Date_Name
{
	char year[YEAR_4];
	char month[MONTH_2];
	char day[DAY_2];
	char headline[TEXT_200];
	char id_1[TEXT_10];//ÿ�����ݸ��赥һ���
}Date_Name;

//���� �洢�ṹ
typedef struct Date_Context
{
	char context_paragraph[TEXT_1000];//ÿ������
	int line;//��¼����
	char id_2[TEXT_10];//ÿ�����ݸ��赥һ���
}Date_Context;

//��· �洢�ṹ
//typedef struct Date_BusLine
//{
//	int Busline;//��·���
//	char id_1[TEXT_10];//ÿ�����ݸ��赥һ���
//}Date_BusLine;

//�����ṹ
typedef struct Date_Base
{
	Date_Name* name_1;//��������
	Date_Context* context_1;//����
	//Date_BusLine* Busline_1;//��·

	char id[TEXT_10];//ÿ�����ݸ��赥һ���
	int sz;//��¼��ǰ��Ч��Ϣ����
	int capacity;//��¼��ǰ�������
}Date_Base;

//--------------------��̬���޸ķ�Χ--------------------

//�ṹ��ʼ��
void InitResource(Date_Base* pc);

//�������
void AddResource(Date_Base* pc);

//�����ļ�
void LoadResource(Date_Base* pc);