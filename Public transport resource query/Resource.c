#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"



//结构初始化 - 动态版本
void InitResource(Base_Name* name, Base_Context* context)
{
	Base_Name* BN = malloc(sizeof(Base_Name));
	if (BN == NULL)
	{
		perror("Initresource/Base_Name");
		return;
	}
	name = BN;
	Base_Context* BC = malloc(sizeof(Base_Context));
	if (BC == NULL)
	{
		perror("Initresource/Base_Context");
		return;
	}
	context = BC;

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

//检测增容
//void CheckResource(Date_Base* pc)
//{
//	if (pc->sz == pc->capacity)
//	{
//		Date_Name* ptr1 = (Date_Name*)realloc(pc->name_1, (pc->capacity + DEFAULT_SZ) * sizeof(Date_Name));
//		Date_Context* ptr2 = (Date_Context*)realloc(pc->context_1, (pc->capacity + DEFAULT_SZ) * sizeof(Date_Context));
//		if (ptr1 != NULL && ptr2 != NULL)
//		{
//			pc->name_1 = ptr1;
//			pc->context_1 = ptr2;
//			pc->capacity += DEFAULT_SZ;
//			printf("增容成功！\n");
//			return;
//		}
//		else
//		{
//			perror("CheckResource");
//			printf("增容失败！\n3秒后继续\n");
//			Sleep(3000);
//			return;
//		}
//	}
//}

//录入数据 - 动态版本
void AddResource(Base_Name* name, Base_Context* context)
{
	//确认容量
	//CheckResource(pc);
	printf("变长数组调试，暂停加载确认容量\n");
	//结构体临时内容
	int year = 0;
	int month = 0;
	int day = 0;
	int headlinecount = 0;
	char headline[TEXT_200] = { 0 };
	int contextcount = 0;
	char context_paragraph[TEXT_1000] = { 0 };
	//赋值
	printf("请输入 年 月 日 [例：20220101]：\n");
	scanf("%4d%2d%2d", &(year), &(month), &(day));
	while (1)
	{
		if (month < 13 && month > 0)
		{
			if (day > 0 && day < 32)
			{
				printf("请输入标题：\n");
				scanf("%s", headline);
				headlinecount = strlen(headline);
				char* headlinepoint = headline;//字符串转为字符指针
				Base_Name* BN = malloc(sizeof(Base_Name) + (headlinecount + 1) * sizeof(char));
				//结构体赋值
				BN->sz = 1;
				BN[BN->sz].year = year;
				BN[BN->sz].month = month;
				BN[BN->sz].day = day;
				BN[BN->sz].sz = BN->sz;
				BN[BN->sz].headlinecount = headlinecount;
				strcpy(BN[BN->sz].headline, headlinepoint);
				//realloc(name, sizeof(Base_Name) + (headlinecount + 1) * sizeof(char));
				//if (sizeof(BN) != sizeof(name))
				//{
				//	perror("realloc/BN:name");
				//	return;
				//}
				name = BN;
				//name[name->sz].sz += 1;
				break;
			}
			else
			{
				printf("日期非正常数据，请确认输入！\n3秒后返回管理界面\n");
				Sleep(3000);
				break;
			}
		}
		else
		{
			printf("月份非正常数据，请确认输入！\n3秒后返回管理界面\n");
			Sleep(3000);
			break;
		}
	}
	printf("请输入内容：\n");
	scanf("%s", context_paragraph);
	contextcount = strlen(context_paragraph);
	char* contextpoint = context_paragraph;
	Base_Context* BC = malloc(sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
	BC->sz = 1;
	BC[BC->sz].sz = BC->sz;
	strcpy(BC[BC->sz].context_paragraph, contextpoint);
	//realloc(context, sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
	//if (sizeof(BC) != sizeof(context))
	//{
	//	perror("realloc/BC:context");
	//	return;
	//}
	context = BC;
	//memcpy(context[context->sz].context_paragraph, contextpoint, contextcount);
	printf("          -----------------------------           \n");
	printf("          |  成功录入，3秒后自动返回  |           \n");
	printf("          -----------------------------           \n");
	Sleep(3000);
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
//void SeacrhResource(Date_Name* name, Date_Context* context)
//{
//	int i = 0;
//	if (pc->sz == 0)
//	{
//		printf("尚未录入数据,3秒后自动返回。\n");
//		Sleep(3000);
//		return;
//	}
//	for (i = 0;i < pc->sz;i++)
//	{
//		printf("查询内容如下：\n");
//		printf("[ 时 间 ]：%d年%d月%d日\t\t[ 标 题 ]：%s\n",
//			pc->name_1[i].year,
//			pc->name_1[i].month,
//			pc->name_1[i].day,
//			pc->name_1[i].headline);
//		printf("[ 正 文 ]：%s\n",pc->context_1[i].context_paragraph);
//	}
//	system("pause");
//}

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
//void Destorycontact(Date_Base* pc)
//{
//	free(pc->name_1);
//	pc->name_1 = NULL;
//	free(pc->context_1);
//	pc->context_1 = NULL;
//	pc->sz = 0;
//	pc->capacity = 0;
//}