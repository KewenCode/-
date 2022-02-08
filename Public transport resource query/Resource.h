#pragma once
#pragma warning(disable : 6031)//����vs��scanf�����nc��Ϊ
#pragma warning(disable : 5105)//���ɡ��Ѷ��塱�ĺ���չ����δ�������Ϊ

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

//���� �洢�ṹ
	typedef struct Base_Name
	{
		char id[9];
		char headline[0];//��������
	}Base_Name;
	typedef unsigned long* DN_TypeDefine;
	typedef struct DN_SingleList
	{
		unsigned int sz; //�Ѵ洢��Ч��Ϣ��
		unsigned int capacity;//Ŀǰmalloc����
		DN_TypeDefine DN[0]; //DNָ��
	}DN_SingleList;

//�ı����� �洢�ṹ
	typedef struct Base_Context
	{
		char id[11];
		char context_paragraph[0];//ÿ������
	}Base_Context;
	//�нṹ
	typedef unsigned long* BC_TypeDefine;
	typedef struct BC_LineList
	{
		unsigned short line; //����
		BC_TypeDefine BCL[0]; //BCָ��
	}BC_LineList;
	//���ṹ
	typedef unsigned long* BCL_TypeDefine;
	typedef struct BC_SingleList
	{
		unsigned short alline; //������
		unsigned int sz; //�Ѵ洢��Ч��Ϣ��
		unsigned int capacity;//Ŀǰmalloc����
		BCL_TypeDefine DC[0]; //BCLָ��
	}BC_SingleList;

//�ṹ��ʼ��
void InitResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

//¼������
void AddResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);
//¼������ - ����
void AddResource_Headline(Base_Struct* ptrq, DN_SingleList** DN_sl, char* id);
//¼������ - �ı�
void AddResource_Context(Base_Struct* ptrq, BC_SingleList** BC_sl, char* id);

//��ѯ
void SeacrhResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

//�������
void CheckResource(Base_Struct* ptrq);

//�޸��ļ�
void ModifyResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

//ɾ������
void DelateResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

//�����ڴ�
void Destorycontact(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl);

