#pragma once
#pragma warning(disable : 6031)//����vs��scanf�����nc��Ϊ
#pragma warning(disable : 5105)//���ɡ��Ѷ��塱�ĺ���չ����δ�������Ϊ

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

#define DEFAULT_SZ 3//Ĭ�ϴ�С
#define MAX 3

//--------------------[ �� ̬ ]���޸ķ�Χ--------------------

//�����ṹ - ��̬�汾
//typedef struct Date_Base
//{
//	Date_Name name_1[MAX];//��������
//	Date_Context context_1[MAX];//����
//	//Date_BusLine* Busline_1;//��·
//
//	//char id[TEXT_10];//ÿ�����ݸ��赥һ���
//	int sz;//��¼��ǰ��Ч��Ϣ����
//	int capacity;//��¼��ǰ�������
//}Date_Base;


//�������� �洢�ṹ
typedef struct Date_Name
{
	int year;
	int month;
	int day;
	int headlinecount;
	char headline[0];
	//char id_1[TEXT_10];//ÿ�����ݸ��赥һ���
}Date_Name;

//���� �洢�ṹ
typedef struct Date_Context
{
	char context_paragraph[TEXT_1000];//ÿ������
	//int line;//��¼����
	//char id_2[TEXT_10];//ÿ�����ݸ��赥һ���
}Date_Context;

//�����ṹ - ��̬�汾
typedef struct Date_Base
{
	Date_Name* name_1;//��������
	Date_Context* context_1;//����
	//Date_BusLine* Busline_1;//��·

	//char id[TEXT_10];//ÿ�����ݸ��赥һ���
	int sz;//��¼��ǰ��Ч��Ϣ����
	int capacity;//��¼��ǰ�������
	Date_Base* next;
}Date_Base;

//��· �洢�ṹ
//typedef struct Date_BusLine
//{
//	int Busline;//��·���
//	char id_1[TEXT_10];//ÿ�����ݸ��赥һ���
//}Date_BusLine;

//�ṹ��ʼ��
void InitResource(Date_Base* pc);

//�����ļ�
void Load_Resource(Date_Base* pc);

//¼������
void AddResource(Date_Base* pc);

//��ѯ
void SeacrhResource(Date_Base* pc);

//�������
void CheckResource(Date_Base* pc);

//�����ļ�
void SaveResource(Date_Base* pc);

//�޸��ļ�
void ModityResource(Date_Base* pc);

//ɾ������
void DelateResource(Date_Base* pc);

//�����ڴ�
void Destorycontact(Date_Base* pc);