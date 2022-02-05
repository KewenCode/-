#pragma once
#pragma warning(disable : 6031)//����vs��scanf�����nc��Ϊ
#pragma warning(disable : 5105)//���ɡ��Ѷ��塱�ĺ���չ����δ�������Ϊ

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

#define DEFAULT_SZ 3//Ĭ�ϴ�С
#define MAX 3

//���Ͷ���
typedef struct Base_Main
{
	char id[9];
	unsigned short year;
	unsigned short month;
	unsigned short day;
	unsigned short headlinecount;
	unsigned short line;//��¼����
	unsigned short contextcount;//����
}Base_Main;
//���ṹ
typedef struct Base_Struct
{
	Base_Main* BM;//��ŵ���Ϣ�ռ�
	unsigned int sz;//��¼�Ѷ�ȡ��Ч��Ϣ����
	unsigned int capacity;//Ŀǰmalloc����
}Base_Struct;

//�������� �洢�ṹ
typedef struct Base_Name
{
	char id[9];
	char headline[0];
}Base_Name;
typedef unsigned long* Date_Name;
typedef struct Date_Name_arr
{
	unsigned int sz;//��¼�Ѷ�ȡ��Ч��Ϣ����
	unsigned int capacity;//Ŀǰmalloc����
	Date_Name* DN;
}Date_Name_arr;

//�ı����� �洢�ṹ
typedef struct Base_Context
{
	char id[11];
	char context_paragraph[0];//ÿ������
}Base_Context;
//
typedef unsigned long* Base_Context_List;
typedef struct Base_Context_arr
{
	unsigned short line;//��ʱ��¼����
	Base_Context_List BCL[0];
}Base_Context_arr;
//����Base_Contextָ��
typedef unsigned long* Date_Context;
typedef struct Date_Context_arr
{
	unsigned short alline;//��¼����
	unsigned int sz;//��¼�Ѷ�ȡ��Ч��Ϣ����
	unsigned int capacity;//Ŀǰmalloc����
	Date_Context* DC;
}Date_Context_arr;

//��· �洢�ṹ
//typedef struct Date_BusLine
//{
//	int Busline;//��·���
//	char id_1[TEXT_10];//ÿ�����ݸ��赥һ���
//}Date_BusLine;

//�ṹ��ʼ��
void InitResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr** bca);

////�����ļ�
//void Load_Resource(Date_Base* pc);

//¼������
void AddResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr** bca);

//¼������ - �ı�
void AddResource_Context(Base_Struct* ptrq, Date_Context_arr* dca, Base_Context_arr** bca, char* id);

//��ѯ
void SeacrhResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr** bca);

//�������
void CheckResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca);

//�����ļ�
//void SaveResource(Date_Base* pc);

//�޸��ļ�
//void ModifyResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca);

//ɾ������
void DelateResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca);

//�����ڴ�
void Destorycontact(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca);

