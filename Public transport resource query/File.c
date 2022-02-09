#define _CRT_SECURE_NO_WARNINGS 1
#include "File.h"

//加载文件
//void Load_Resource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
//{
//	FILE* pf = fopen("Resource.dat", "r");
//	if (pf == NULL)
//	{
//		perror("LoadResource");
//		return;
//	}
//	//读文件
//	DN_TypeDefine tmp1 = { 0 };//确定文件是否存在
//	BCL_TypeDefine tmp2 = { 0 };
//	while (fread(&tmp1.year, sizeof(DN_TypeDefine), 1, pf))
//	{
//		if(fread(&tmp2.context_paragraph, sizeof(BCL_TypeDefine), 1, pf)!=0)
//		{
//			//检测是否需要增容
//			CheckResource(pc);
//			pc->name_1[pc->sz] = tmp1;
//			pc->context_1[pc->sz] = tmp2;
//			pc->sz++;
//			system("cls");//临时性措施
//		}
//		else
//		{
//			break;
//		}
//		
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}

//保存文件
void SaveResource(Base_Struct* ptrq, DN_SingleList** DN_sl)
{
	//结构体临时变量
	unsigned int i = 0;

	//主结构文件
	FILE* pf = fopen(".\\Date\\Resource.dat", "w");
	if (pf == NULL)
	{
		perror("SaveResource");
		return;
	}
	//写文件
	for (i = 0; i < ptrq->sz; i++)
	{
		fwrite(ptrq->BM + i, sizeof(Base_Main), 1, pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;

	//标题
	FILE* pf1 = fopen(".\\Date\\Head.dat", "w");
	if (pf1 == NULL)
	{
		perror("SaveResource");
		return;
	}
	//写文件
	for (i = 0; i < ptrq->sz; i++)
	{
		Base_Name* BN = NULL;
		BN = (Base_Name*)DN_sl[0]->DN[i];
		fwrite(BN, sizeof(Base_Main) + (ptrq->BM[i].headlinecount * sizeof(char)), 1, pf1);
	}
	//关闭文件
	fclose(pf1);
	pf1 = NULL;


	//void function_over();//测试功能
}