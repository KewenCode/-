#define _CRT_SECURE_NO_WARNINGS 1
#include "File.h"

//�����ļ�
//void Load_Resource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
//{
//	FILE* pf = fopen("Resource.dat", "r");
//	if (pf == NULL)
//	{
//		perror("LoadResource");
//		return;
//	}
//	//���ļ�
//	DN_TypeDefine tmp1 = { 0 };//ȷ���ļ��Ƿ����
//	BCL_TypeDefine tmp2 = { 0 };
//	while (fread(&tmp1.year, sizeof(DN_TypeDefine), 1, pf))
//	{
//		if(fread(&tmp2.context_paragraph, sizeof(BCL_TypeDefine), 1, pf)!=0)
//		{
//			//����Ƿ���Ҫ����
//			CheckResource(pc);
//			pc->name_1[pc->sz] = tmp1;
//			pc->context_1[pc->sz] = tmp2;
//			pc->sz++;
//			system("cls");//��ʱ�Դ�ʩ
//		}
//		else
//		{
//			break;
//		}
//		
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//}

//�����ļ�
void SaveResource(Base_Struct* ptrq, DN_SingleList** DN_sl)
{
	//�ṹ����ʱ����
	unsigned int i = 0;

	//���ṹ�ļ�
	FILE* pf = fopen(".\\Date\\Resource.dat", "w");
	if (pf == NULL)
	{
		perror("SaveResource");
		return;
	}
	//д�ļ�
	for (i = 0; i < ptrq->sz; i++)
	{
		fwrite(ptrq->BM + i, sizeof(Base_Main), 1, pf);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	//����
	FILE* pf1 = fopen(".\\Date\\Head.dat", "w");
	if (pf1 == NULL)
	{
		perror("SaveResource");
		return;
	}
	//д�ļ�
	for (i = 0; i < ptrq->sz; i++)
	{
		Base_Name* BN = NULL;
		BN = (Base_Name*)DN_sl[0]->DN[i];
		fwrite(BN, sizeof(Base_Main) + (ptrq->BM[i].headlinecount * sizeof(char)), 1, pf1);
	}
	//�ر��ļ�
	fclose(pf1);
	pf1 = NULL;


	//void function_over();//���Թ���
}