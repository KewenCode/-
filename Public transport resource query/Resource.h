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


//�������� �洢�ṹ
typedef struct Base_Name
{
	unsigned int id;
	unsigned int sz;//��¼��ǰ��Ч��Ϣ����
	unsigned int capacity;//��¼��ǰ�������
	unsigned short year;
	unsigned short month;
	unsigned short day;
	unsigned short headlinecount;
	char headline[0];
}Base_Name;
unsigned long* Date_Name_arr[DEFAULT_SZ];//ָ������
unsigned long** Date_Name;//ָ���ַ

//�ı����� �洢�ṹ
typedef struct Base_Context
{
	unsigned int sz;//��¼��ǰ��Ч��Ϣ����
	unsigned int capacity;//��¼��ǰ�������
	unsigned int id;
	unsigned short line;//��¼����
	unsigned short contextcount;
	char context_paragraph[0];//ÿ������
}Base_Context;
unsigned long* Date_Context_arr[DEFAULT_SZ];//ָ������
unsigned long** Date_Context;//ָ���ַ

//��· �洢�ṹ
//typedef struct Date_BusLine
//{
//	int Busline;//��·���
//	char id_1[TEXT_10];//ÿ�����ݸ��赥һ���
//}Date_BusLine;

//�ṹ��ʼ��
//void InitResource(Base_Name* name, Base_Context* context);

////�����ļ�
//void Load_Resource(Date_Base* pc);

//¼������
void AddResource(unsigned long** dn, unsigned long** dc);

//��ѯ
void SeacrhResource(unsigned long** dn, unsigned long** dc);

////�������
//void CheckResource(Date_Base* pc);
//
////�����ļ�
//void SaveResource(Date_Base* pc);
//
////�޸��ļ�
//void ModityResource(Date_Base* pc);
//
////ɾ������
//void DelateResource(Date_Base* pc);
//
////�����ڴ�
//void Destorycontact(Date_Base* pc);