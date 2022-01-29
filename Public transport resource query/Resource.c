#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"

//随机id
char* Randomid(char* dst)
{
	unsigned long seconds;
	seconds = (unsigned long)time(NULL);
	char id[9];
	sprintf(id, "%8X", seconds);
	memcpy(dst, id, 9);
	return dst;
}


//结构初始化 - 动态版本
void InitResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca)
{
	ptrq->BM = (Base_Main*)malloc(DEFAULT_SZ * sizeof(Base_Main));
	if (ptrq->BM == NULL)
	{
		perror("Initresource/Base_Main*");
		return;
	}
	ptrq->capacity = DEFAULT_SZ;
	ptrq->sz = 0;

	dna->DN = (Date_Name*)malloc(DEFAULT_SZ * sizeof(Date_Name));	
	if (dna->DN == NULL)
	{
		perror("Initresource/Date_Name*");
		return;
	}
	dna->capacity = 0;
	dna->sz = 0;
	dca->DC = (Date_Context*)malloc(DEFAULT_SZ * sizeof(Date_Context));
	if (dca->DC == NULL)
	{
		perror("Initresource/Date_Context*");
		return;
	}
	dca->capacity = 0;
	dca->sz = 0;
	int i = 0;
	for (i = 0; i < DEFAULT_SZ; i++)
	{
		dna->DN[i] = (unsigned long*)malloc(sizeof(unsigned long));
		dna->capacity++;
	}
	for (i = 0; i < DEFAULT_SZ; i++)
	{
		dca->DC[i] = (unsigned long*)malloc(sizeof(unsigned long));
		dca->capacity++;
	}


	//加载文件
	//Load_Resource(pc);  
	printf("变长数组调试，暂停加载文件\n");
}

//加载文件
//void Load_Resource(Date_Base* pc)
//{
//	FILE* pf = fopen("Resource.dat", "r");
//	if (pf == NULL)
//	{
//		perror("LoadResource");
//		return;
//	}
//	//读文件
//	Date_Name tmp1 = { 0 };//确定文件是否存在
//	Date_Context tmp2 = { 0 };
//	while (fread(&tmp1.year, sizeof(Date_Name), 1, pf))
//	{
//		if(fread(&tmp2.context_paragraph, sizeof(Date_Context), 1, pf)!=0)
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

//增容检测
//void CheckResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca)
//{
//	if (ptrq->sz == ptrq->capacity)
//	{
//		Base_Main* ptr = (Base_Main*)realloc(ptrq->BM, (ptrq->capacity + DEFAULT_SZ) * sizeof(Base_Main));
//		if (ptr != NULL)
//		{
//			ptrq->BM = ptr;
//			ptrq->capacity += DEFAULT_SZ;
//			printf("增容成功！\n");
//		}
//		else
//		{
//			perror("CheckResource/Base_Struct*");
//			printf("增容失败！\n3秒后继续\n");
//			Sleep(3000);
//			return;
//		}
//	}
//	while (1)
//	{
//		int i = 1;
//		if (*dn[DEFAULT_SZ * i - 1] != NULL)
//		{
//
//			int t = 0;
//
//		}
//		i++;
//	}
//}

//录入数据 - 动态版本
void AddResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca)
{
	//确认容量
	//CheckResource(ptrq, dna, dca);
	printf("变长数组调试，暂停加载确认容量\n");
	//结构体临时内容
	int clear = 0;
	char id[9] = { 0 };
	unsigned short year = 0;
	unsigned short month = 0;
	unsigned short day = 0;
	unsigned short headlinecount = 0;
	char headline[TEXT_200] = { 0 };
	unsigned short contextcount = 0;
	char context_paragraph[TEXT_1000] = { 0 };
	//赋值
	while (1)
	{
		printf("请输入 年 月 日 [例：20220101]：\n");
		scanf("%4hu%2hu%2hu", &(year), &(month), &(day));
		while ((clear = getchar()) != '\n' && clear != EOF);//清空输入缓冲区
		//if (clear != 0)
		//{
		//	printf("          -----------------------------           \n");
		//	printf("          输入超出规定大小，请确认输入！          \n");
		//	printf("                2秒后返回输入界面                 \n");
		//	printf("          -----------------------------           \n");
		//	Sleep(2000);
		//}
		if (month < 13 && month > 0)
		{
			if (day > 0 && day < 32)
			{
				//创建id标识
				Randomid(id);
				memcpy(ptrq->BM[ptrq->sz].id, id, 9);
				//年月日
				int BN_sz = 0;//确定数组位置
				ptrq->BM[ptrq->sz].year = year;
				ptrq->BM[ptrq->sz].month = month;
				ptrq->BM[ptrq->sz].day = day;
				//标题
				printf("请输入标题：\n");
				scanf("%s", headline);
				headlinecount = (unsigned short)strlen(headline);
				char* headlinepoint = headline;//字符串转为字符指针
				Base_Name* BN = malloc(sizeof(Base_Name) + (headlinecount + 1) * sizeof(char));
				if (BN == NULL)
				{
					perror("malloc/Base_Name* BN ");
					return;
				}
				ptrq->BM[ptrq->sz].headlinecount = headlinecount;
				memcpy(BN[BN_sz].id, id, 9);
				memcpy(BN[BN_sz].headline, headlinepoint, headlinecount + 1);
				dna->DN[dna->sz] = (unsigned long*)BN;//指针复制
				dna->sz++;
				BN = NULL;
				//内容
				printf("请输入内容：\n");
				scanf("%s", context_paragraph);
				contextcount = (unsigned short)strlen(context_paragraph);
				char* contextpoint = context_paragraph;
				Base_Context* BC = malloc(sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
				if (BC == NULL)
				{
					perror("malloc/Base_Context* BC ");
					return;
				}
				int BC_sz = 0;//确定数组位置
				ptrq->BM[ptrq->sz].contextcount = contextcount;
				ptrq->sz++;
				memcpy(BC[BC_sz].id, id, 9);
				memcpy(BC[BC_sz].context_paragraph, contextpoint, contextcount + 1);
				{
					dca->DC[dca->sz] = (unsigned long*)BC;//指针复制
					dca->sz++;
				}
				BC = NULL;
				printf("          -----------------------------           \n");
				printf("          |  成功录入，3秒后自动返回  |           \n");
				printf("          -----------------------------           \n");
				Sleep(3000);
				break;
			}
			else
			{
				printf("          -----------------------------           \n");
				printf("           日期非正常数据，请确认输入！           \n");
				printf("                2秒后返回输入界面                 \n");
				printf("          -----------------------------           \n");
				Sleep(2000);
			}
		}
		else
		{
			printf("          -----------------------------           \n");
			printf("           月份非正常数据，请确认输入！           \n");
			printf("                2秒后返回输入界面                 \n");
			printf("          -----------------------------           \n");
			Sleep(2000);
		}
	}
}

//录入数据 - 链表尾插法
		//void AddResource_LinkedList(Date_Base** resource)//resource是头指针
		//{
		//	Date_Base* pc = NULL;
		//	Date_Base* temp = NULL;
		//	static Date_Base* tail = NULL;//设置空指针
		//	pc = (Date_Base*)malloc(sizeof(struct Date_Base));
		//	if (pc = NULL)
		//	{
		//		perror("addinfo");
		//		exit(1);
		//	}
		//	AddResource(pc);
		//	if (*resource != NULL)
		//	{
		//		tail->next = pc;//静态指向最后一位函数
		//		pc->next = NULL;
		//	}
		//	else
		//	{
		//		*resource = pc;
		//		pc->next = NULL;
		//	}
		//}

//查询
void SeacrhResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca)
{
	unsigned int i = 0;
	while (1)
	{
		if (ptrq->sz == 0)
		{
			printf("          -----------------------------           \n");
			printf("          |         无输入数据        |           \n");
			printf("          -----------------------------           \n");
			system("pause");
			break;
		}
		for (i = 0; i < ptrq->sz; i++)
		{
			Base_Name* BN = NULL;
			BN = (Base_Name*)dna->DN[i];//指针复制
			printf("查询内容如下：\n");
			printf("[ 时 间 ]：%d年%d月%d日\t\t[ 标 题 ]：%s\n",
				ptrq->BM[i].year,
				ptrq->BM[i].month,
				ptrq->BM[i].day,
				BN->headline);
			Base_Context* BC = NULL;
			BC = (Base_Context*)dca->DC[i];//指针复制
			printf("[ 正 文 ]：%s\n", BC->context_paragraph);
		}
		printf("          -----------------------------           \n");
		printf("          |          输出完成         |           \n");
		printf("          -----------------------------           \n");
		system("pause");
		break;
	}
}

//保存文件
//void SaveResource(Date_Base* pc)
//{
//	//打开文件
//	FILE*pf= fopen("Resource.dat", "w");
//	if (pf == NULL)
//	{
//		perror("SaveResource");
//		return;
//	}
//	//写文件
//	int i = 0;
//	for (i = 0;i < pc->sz;i++)
//	{
//		fwrite(pc->name_1 + i, sizeof(Date_Name), 1, pf);
//		fwrite(pc->context_1 + i, sizeof(Date_Context), 1, pf);
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	//void function_over();//测试功能
//}

//static int FindHeadlineResource(Date_Base* pc, char Headline[])
//{
//	int i = 0;
//	for (i = 0;i < pc->sz;i++)
//	{
//		if (strcmp(pc->name_1[i].headline, Headline) == 0)
//		{
//			return i;
//		}
//	}
//	return -1;//找不到
//}
//删除内容
//void DelateResource(Date_Base* pc)
//{
//	char Headline[TEXT_200];
//	if (pc->sz == 0)
//	{
//		printf("未记录内容,3秒后自动返回。\n");
//		Sleep(3000);
//		return;
//	}
//	printf("请输入要删除的内容标题：");
//	scanf("%s", Headline);
//	//查找对应内容
//	int pos = FindHeadlineResource(pc, Headline);
//	if (pos == -1)
//	{
//		printf("未找到相关内容,3秒后自动返回。\n");
//		Sleep(3000);
//		return;
//	}
//	//删除
//	int i = 0;
//	for (i = pos;i < pc->sz;i++)
//	{
//		pc->name_1[i] = pc->name_1[i + 1];
//		pc->context_1[i] = pc->context_1[i + 1];
//		pc->sz--;
//	}
//	printf("删除成功,3秒后自动返回。\n");
//	Sleep(3000);
//}

//修改文件
//void ModityResource(Date_Base* pc)
//{
//	char Headline[TEXT_200];
//	printf("请输入要修改的标题名称:");
//	scanf("%s", Headline);
//	int pos = FindHeadlineResource(pc, Headline);
//	if (pos == -1)
//	{
//		printf("未找到相关内容,3秒后自动返回。\n");
//		Sleep(3000);
//		return;
//	}
//	else
//	{
//		printf("请输入 年 月 日 [例：20220101]：\n");
//		scanf("%4d%2d%2d", &(pc->name_1[pos].year), &(pc->name_1[pos].month), &(pc->name_1[pos].day));
//		while (1)
//		{
//			if ((pc->name_1[pos].month) < 13 && (pc->name_1[pos].month) > 0)
//			{
//				if (pc->name_1[pos].day > 0 && pc->name_1[pos].day < 32)
//				{
//					printf("请输入标题：\n");
//					scanf("%s", pc->name_1[pos].headline);
//					printf("请输入内容：\n");
//					scanf("%s", pc->context_1[pos].context_paragraph);//注意，此处sz不需要++
//					printf("          -----------------------------           \n");
//					printf("          |  成功录入，3秒后自动返回  |           \n");
//					printf("          -----------------------------           \n");
//					Sleep(3000);
//					break;
//				}
//				else
//				{
//					printf("日期非正常数据，请确认输入！\n3秒后返回管理界面\n");
//					Sleep(3000);
//					break;
//				}
//			}
//			else
//			{
//				printf("月份非正常数据，请确认输入！\n3秒后返回管理界面\n");
//				Sleep(3000);
//				break;
//			}
//		}
//	}
//}

//销毁内存
void Destorycontact(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca)
{
	free(ptrq->BM);
	ptrq->BM = NULL;
	ptrq->capacity = 0;
	ptrq->sz = 0;

	unsigned int i = 0;
	for (i = 0; i < dna->capacity; i++)
	{
		if (dna->DN[i] != NULL)
		{
			Base_Name* BN = NULL;
			BN = (Base_Name*)dna->DN[i];//指针复制
			free(BN);
			dna->DN[i] = NULL;
		}
	}
	for(i = 0; i < dca->capacity; i++)
	{
		if (dca->DC[i] != NULL)
		{
			Base_Context* BC = NULL;
			BC = (Base_Context*)dca->DC[i];
			free(BC);
			dca->DC[i] = NULL;
		}
	}

	dna->capacity = 0;
	dna->sz = 0;
	dca->capacity = 0;
	dca->sz = 0;

	free(dna->DN);
	dna->DN = NULL;
	free(dca->DC);
	dca->DC = NULL;
}