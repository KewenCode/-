#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"
#include "File.h"

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
void InitResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//主结构
	ptrq->BM = (Base_Main*)malloc(DEFAULT_SZ * sizeof(Base_Main));//默认三个
	if (ptrq->BM == NULL)
	{
		perror("Initresource/主结构");
		return;
	}
	ptrq->capacity = DEFAULT_SZ;
	ptrq->sz = 0;

	//日期名称 存储结构
	*DN_sl = malloc(sizeof(DN_SingleList) + sizeof(DN_TypeDefine));//默认一个
	if (*DN_sl == NULL)
	{
		perror("Initresource/日期名称 存储结构");
		return;
	}
	DN_sl[0]->capacity = 1;
	DN_sl[0]->sz = 0;

	//文本内容 存储结构
	*BC_sl = malloc(sizeof(BC_SingleList) + sizeof(BCL_TypeDefine));//默认一个
	if (*BC_sl == NULL)
	{
		perror("Initresource/文本内容 存储结构");
		return;
	}
	BC_sl[0]->capacity = 1;
	BC_sl[0]->sz = 0;
	BC_sl[0]->alline = 0;

	//加载文件
	//Load_Resource(pc);  
	printf("变长数组调试，暂停加载文件\n");
}

//增容检测
void CheckResource(Base_Struct* ptrq)
{
	if (ptrq->sz == ptrq->capacity)
	{
		Base_Main* ptr = (Base_Main*)realloc(ptrq->BM, ((int)ptrq->capacity + DEFAULT_SZ) * sizeof(Base_Main));
		if (ptr != NULL)
		{
			ptrq->BM = ptr;
			ptrq->capacity += DEFAULT_SZ;
			//printf("          -----------------------------           \n");
			//printf("          |         增容成功！        |           \n");
			//printf("          -----------------------------           \n");
		}
		else
		{
			perror("CheckResource/Base_Main* ptr");
			printf("          -----------------------------           \n");
			printf("           开辟增容空间失败！存在空指针           \n");
			printf("                2秒后返回输入界面                 \n");
			printf("          -----------------------------           \n");
			Sleep(2000);
			return;
		}
	}
}

//录入数据 - 动态版本
void AddResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//确认容量
	CheckResource(ptrq);
	printf("        -------------------------------           \n");
	printf("          主结构 已使用：%d 容量：%d\n", ptrq->sz, ptrq->capacity);
	printf("          标题 已使用：%d 容量：%d\n", DN_sl[0]->sz, DN_sl[0]->capacity);
	printf("          文本 已使用：%d 容量：%d\n", BC_sl[0]->sz, BC_sl[0]->capacity);
	printf("        -------------------------------           \n");
	//结构体临时变量
	int clear = 0;
	char id[9] = { 0 };
	unsigned short year = 0;
	unsigned short month = 0;
	unsigned short day = 0;
	unsigned short headlinecount = 0;
	char headline[TEXT_200] = { 0 };
	//赋值
	while (1)
	{
		printf("\033[1;46;37m请输入 年 月 日 [例：20220101]：\033[1;47;30m\n");
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
				memcpy(ptrq->BM[ptrq->sz].id, id, 9);//复制id
				//年月日
				ptrq->BM[ptrq->sz].year = year;
				ptrq->BM[ptrq->sz].month = month;
				ptrq->BM[ptrq->sz].day = day;
				//标题
				AddResource_Headline(ptrq, DN_sl, id);
				//内容
				AddResource_Context(ptrq, BC_sl, id);
				//反馈
				printf("          -----------------------------           \n");
				printf("          |         成功录入！        |           \n");
				printf("          -----------------------------           \n");
				system("pause");
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
//录入数据 - 标题
void AddResource_Headline(Base_Struct* ptrq, DN_SingleList** DN_sl, char* id)
{
	//结构体临时变量
	int clear = 0;
	unsigned short headlinecount = 0;
	char headline[TEXT_200] = { 0 };
	//输入
	printf("\033[1;46;37m请输入标题：\033[1;47;30m\n");
	scanf("%[^\n]", headline);
	while ((clear = getchar()) != '\n' && clear != EOF);//清空输入缓冲区
	headlinecount = (unsigned short)strlen(headline); //标题字数
	char* headlinepoint = headline; //字符串转为字符指针
//开辟存储空间&赋值
	Base_Name* BN = malloc(sizeof(Base_Name) + ((int)headlinecount + 1) * sizeof(char));
	if (BN == NULL)
	{
		perror("AddResource_Headline/Base_Name* BN ");
		return;
	}
	memcpy(BN[0].id, id, 9);
	memcpy(BN[0].headline, headlinepoint, (int)headlinecount + 1);
	//数据&指针转移
	ptrq->BM[ptrq->sz].headlinecount = headlinecount;
	DN_sl[0]->DN[DN_sl[0]->sz] = (unsigned long*)BN;//指针复制
	DN_sl[0]->sz++;
	BN = NULL;
	//DN_sl新开辟空间
	if (DN_sl[0]->sz == DN_sl[0]->capacity)
	{
		DN_SingleList* str1 = NULL;
		DN_sl[0]->capacity++;
		str1 = realloc(*DN_sl, sizeof(DN_SingleList) + sizeof(DN_TypeDefine) * ((int)DN_sl[0]->sz + 1));
		if (str1 == NULL)
		{
			perror("AddResource_Headline/DN_SingleList* str1");
			return;
		}
		*DN_sl = str1;
		str1 = NULL;
	}
}
//录入数据 - 文本
void AddResource_Context(Base_Struct* ptrq, BC_SingleList** BC_sl, char* id)
{
	//BC_sl临时存储501行
	BC_LineList BC_T;
	BC_LineList* BC_Temple = &BC_T;
	BC_Temple = (BC_LineList*)malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * TEXT_500);//默认501行
	if (BC_Temple == NULL)
	{
		perror("AddResource_Context/BC_LineList*");
		return;
	}
	//结构体临时变量
	int clear = 0;
	unsigned short contextcount = 0;
	char context_paragraph[TEXT_1000] = { 0 };
	char id_line[11] = { 0 };
	char linecount_line[301] = { 0 };
	int lines = 0;//确定行数
	int count = 0;//数字数
	printf("\033[1;46;37m请输入内容：\033[1;47;30m\n");
	do
	{
		//输入
		printf("\033[1;46;37m第%d行:\033[1;47;30m", lines);
		scanf("%[^\n]", context_paragraph);
		while ((clear = getchar()) != '\n' && clear != EOF);//清空输入缓冲区
		if (strcmp(context_paragraph, "quit") == 0) //为quit时退出
		{
			break;
		}
		contextcount = (unsigned short)strlen(context_paragraph);
		count = contextcount + count;//字数统计
		char* contextpoint = context_paragraph;
		//开辟行存储空间&赋值
		Base_Context* BC = malloc(sizeof(Base_Context) + ((int)contextcount + 1) * sizeof(char));
		if (BC == NULL)
		{
			perror("AddResource_Context/Base_Context* BC ");
			break;
		}
		sprintf(id_line, "%s%d", id, lines);
		if (lines < 1)
		{
			sprintf(linecount_line, "%d", contextcount);
		}
		else
		{

			sprintf(linecount_line, "%s%s%d", linecount_line, "|", contextcount);
		}
		memcpy(BC[0].id, id_line, 11);
		memcpy(BC[0].context_paragraph, contextpoint, (int)contextcount + 1);
		//数据&指针转移
		BC_Temple->BCL[lines] = (unsigned long*)BC;//单行指针复制
		BC = NULL;
		lines++;
	} while (1);

	//BC_sl正式存储lines行
	BC_LineList* BC_Formal = malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * lines);
	if (BC_Formal == NULL)
	{
		return;
	}
	BC_Formal->line = lines;
	//BC_sl临时存储转正式
	for (int i = 0; i < lines; i++)
	{
		BC_Formal->BCL[i] = BC_Temple->BCL[i];//单行指针复制
	}
	free(BC_Temple);
	//数据&指针转移
	ptrq->BM[ptrq->sz].line = lines;
	ptrq->BM[ptrq->sz].contextcount = count;
	strcpy(ptrq->BM[ptrq->sz].linecount, linecount_line);
	ptrq->sz++;
	BC_sl[0]->DC[BC_sl[0]->sz] = (BCL_TypeDefine)BC_Formal;//指针复制
	BC_Formal = NULL;
	BC_sl[0]->sz++;
	//BC_sl新开辟空间
	if (BC_sl[0]->sz == BC_sl[0]->capacity)
	{
		BC_SingleList* str1 = NULL;
		BC_sl[0]->capacity++;
		str1 = realloc(*BC_sl, sizeof(BC_SingleList) + sizeof(BCL_TypeDefine) * ((int)BC_sl[0]->sz + 1));
		if (str1 == NULL)
		{
			perror("AddResource_Context/BC_SingleList* str1");
			return;
		}
		*BC_sl = str1;
		str1 = NULL;
	}
}

//查询
void SeacrhResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//临时变量
	unsigned int i = 0;
	unsigned short j = 0;
	unsigned short linecount = 0;
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
			BN = (Base_Name*)DN_sl[0]->DN[i];//指针复制
			printf("查询内容如下：\n");
			printf("[ 时 间 ]：%d年%d月%d日\t\t[ 标 题 ]：%s\n",
				ptrq->BM[i].year,
				ptrq->BM[i].month,
				ptrq->BM[i].day,
				BN->headline);
			printf("[ 正 文 ]：\n");
			Base_Context* BC = NULL;
			BC_LineList* BCA = NULL;
			BCA = (BC_LineList*)BC_sl[0]->DC[i];
			for (j = 0; j < ptrq->BM[i].line; j++)
			{
				BC = (Base_Context*)BCA->BCL[j];
				printf("    %s\n", BC->context_paragraph);
			}
		}
		printf("          -----------------------------           \n");
		printf("                     输出完成                     \n");
		printf("               总计输出 %d 个数据\n", i);
		printf("          -----------------------------           \n");
		system("pause");
		break;
	}
}

static int FindHeadlineResource(DN_SingleList** DN_sl, char Headline[])
{
	unsigned int i = 0;
	for (i = 0; i < DN_sl[0]->sz; i++)
	{
		Base_Name* BN = NULL;
		BN = (Base_Name*)DN_sl[0]->DN[i];//指针复制
		if (strcmp(BN->headline, Headline) == 0)
		{
			return i;
		}
	}
	return -1;//找不到
}
//删除内容
void DelateResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//临时变量
	char Headline[TEXT_200];
	unsigned int i = 0;
	//确认容量
	if (ptrq->sz == 0)
	{
		printf("未记录内容,3秒后自动返回。\n");
		Sleep(3000);
		return;
	}
	//输入
	printf("请输入要删除的内容标题：");
	scanf("%s", Headline);
	//查找对应内容
	int pos = FindHeadlineResource(DN_sl, Headline);
	if (pos == -1)
	{
		printf("未找到相关内容,3秒后自动返回。\n");
		Sleep(3000);
		return;
	}
	//释放无用空间
	Base_Name* BN = NULL;
	BN = (Base_Name*)DN_sl[0]->DN[pos];//指针复制
	free(BN);
	BN = NULL;

	Base_Context* BC = NULL;
	BC_LineList* BCA = NULL;
	BCA = (BC_LineList*)BC_sl[0]->DC[pos];
	for (i = 0; i < ptrq->BM[pos].line; i++)
	{
		BC = (Base_Context*)BCA->BCL[i];
		free(BC);
		BC = NULL;
	}
	free(BCA);
	BCA = NULL;
	//删除
	for (i = pos; i < ptrq->sz; i++)
	{
		ptrq->BM[i] = ptrq->BM[i + 1];
		BC_sl[0]->DC[i] = BC_sl[0]->DC[i + 1];
		DN_sl[0]->DN[i] = DN_sl[0]->DN[i + 1];
	}
	ptrq->sz--;
	BC_sl[0]->sz--;
	DN_sl[0]->sz--;
	printf("删除成功,3秒后自动返回。\n");
	Sleep(3000);
}

//修改文件
void ModifyResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//临时变量
	char Headline[TEXT_200];
	//输入
	printf("请输入要修改的标题名称:");
	scanf("%s", Headline);
	//查找对应内容
	int pos = FindHeadlineResource(DN_sl, Headline);
	if (pos == -1)
	{
		printf("未找到相关内容,3秒后自动返回。\n");
		Sleep(3000);
		return;
	}
	else
	{
		printf("\033[1;46;37m请输入 年 月 日 [例：20220101]：\033[1;47;30m\n");
		scanf("%4hu%2hu%2hu", &(ptrq->BM[pos].year), &(ptrq->BM[pos].month), &(ptrq->BM[pos].day));
		while (1)
		{
			if ((ptrq->BM[pos].month) < 13 && (ptrq->BM[pos].month) > 0)
			{
				if (ptrq->BM[pos].day > 0 && ptrq->BM[pos].day < 32)
				{
					int clear = 0;
					unsigned int i = 0;
					//释放内存
					Base_Name* BN = NULL;
					BN = (Base_Name*)DN_sl[0]->DN[pos];//指针复制					
					free(BN);
					BN = NULL;

					Base_Context* BC = NULL;
					BC_LineList* BCA = NULL;
					BCA = (BC_LineList*)BC_sl[0]->DC[pos];
					for (i = 0; i < ptrq->BM[pos].line; i++)
					{
						BC = (Base_Context*)BCA->BCL[i];
						free(BC);
						BC = NULL;
					}
					free(BCA);
					BCA = NULL;
					//标题
						//结构体临时变量
					unsigned short headlinecount = 0;
					char headline[TEXT_200] = { 0 };
					char id[9] = { 0 };
					//创建id标识
					Randomid(id);
					memcpy(ptrq->BM[ptrq->sz].id, id, 9);//复制id
					//输入
					printf("\033[1;46;37m请输入标题：\033[1;47;30m\n");
					scanf("%[^\n]", headline);
					while ((clear = getchar()) != '\n' && clear != EOF);//清空输入缓冲区
					headlinecount = (unsigned short)strlen(headline); //标题字数
					char* headlinepoint = headline; //字符串转为字符指针
					//开辟存储空间&赋值
					Base_Name* BN_temp = malloc(sizeof(Base_Name) + (headlinecount + 1) * sizeof(char));
					if (BN_temp == NULL)
					{
						perror("ModifyResource/Base_Name* BN ");
						return;
					}
					memcpy(BN_temp[0].id, id, 9);
					memcpy(BN_temp[0].headline, headlinepoint, headlinecount + 1);
					//数据&指针转移
					ptrq->BM[pos].headlinecount = headlinecount;
					DN_sl[0]->DN[pos] = (unsigned long*)BN_temp;//指针复制
					BN_temp = NULL;
					//内容
						//BC_sl临时存储501行
					BC_LineList BC_T;
					BC_LineList* BC_Temple = &BC_T;
					BC_Temple = (BC_LineList*)malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * TEXT_500);//默认501行
					if (BC_Temple == NULL)
					{
						perror("ModifyResource/BC_LineList*");
						return;
					}
					//结构体临时变量
					unsigned short contextcount = 0;
					char context_paragraph[TEXT_1000] = { 0 };
					char id_line[11] = { 0 };
					int lines = 0;//确定行数
					int count = 0;//数字数
					printf("\033[1;46;37m请输入内容：\033[1;47;30m\n");
					do
					{
						//输入
						printf("\033[1;46;37m第%d行:\033[1;47;30m", lines);
						scanf("%[^\n]", context_paragraph);
						while ((clear = getchar()) != '\n' && clear != EOF);//清空输入缓冲区
						if (strcmp(context_paragraph, "quit") == 0) //为quit时退出
						{
							break;
						}
						contextcount = (unsigned short)strlen(context_paragraph);
						count = contextcount + count;//字数统计
						char* contextpoint = context_paragraph;
						//开辟行存储空间&赋值
						Base_Context* BC = malloc(sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
						if (BC == NULL)
						{
							perror("ModifyResource/Base_Context* BC ");
							break;
						}
						sprintf(id_line, "%s%d", id, lines);
						memcpy(BC[0].id, id_line, 11);
						memcpy(BC[0].context_paragraph, contextpoint, contextcount + 1);
						//数据&指针转移
						BC_Temple->BCL[lines] = (unsigned long*)BC;//单行指针复制
						BC = NULL;
						lines++;
					} while (1);
					//BC_sl正式存储lines行
					BC_LineList* BC_Formal = malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * lines);
					if (BC_Formal == NULL)
					{
						return;
					}
					BC_Formal->line = lines;
					//BC_sl临时存储转正式
					for (int i = 0; i < lines; i++)
					{
						BC_Formal->BCL[i] = BC_Temple->BCL[i];//单行指针复制
					}
					free(BC_Temple);
					//数据&指针转移
					ptrq->BM[pos].line = lines;
					ptrq->BM[pos].contextcount = count;
					BC_sl[0]->DC[pos] = (BCL_TypeDefine)BC_Formal;//指针复制
					BC_Formal = NULL;

					printf("          -----------------------------           \n");
					printf("          |         成功录入！        |           \n");
					printf("          -----------------------------           \n");
					system("pause");
					break;
				}
				else
				{
					printf("          -----------------------------           \n");
					printf("           日期非正常数据，请确认输入！           \n");
					printf("                2秒后返回输入界面                 \n");
					printf("          -----------------------------           \n");
					Sleep(2000);
					break;
				}
			}
			else
			{
				printf("          -----------------------------           \n");
				printf("           月份非正常数据，请确认输入！           \n");
				printf("                2秒后返回输入界面                 \n");
				printf("          -----------------------------           \n");
				Sleep(2000);
				break;
			}
		}
	}
}

//销毁内存
void Destorycontact(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//临时变量
	unsigned int i = 0;
	unsigned int j = 0;
	//销毁名称
	for (i = 0; i < DN_sl[0]->sz; i++)
	{
		if (DN_sl[0]->DN[i] != NULL)
		{
			Base_Name* BN = NULL;
			BN = (Base_Name*)DN_sl[0]->DN[i];//指针复制
			free(BN);
			BN = NULL;
		}
	}
	//销毁行
	Base_Context* BC = NULL;
	BC_LineList* BCA = NULL;
	for (i = 0; i < BC_sl[0]->sz; i++)
	{
		BCA = (BC_LineList*)BC_sl[0]->DC[i];
		for (j = 0; j < ptrq->BM[i].line; j++)
		{
			BC = (Base_Context*)BCA->BCL[j];
			free(BC);
			BC = NULL;
		}
		free(BCA);
		BCA = NULL;
	}
	//销毁主结构
	free(ptrq->BM);
	ptrq->BM = NULL;
	ptrq->capacity = 0;
	ptrq->sz = 0;
	ptrq = NULL;
	//销毁DN_sl
	*DN_sl[0]->DN = NULL;
	DN_sl[0]->capacity = 0;
	DN_sl[0]->sz = 0;
	free(*DN_sl);
	*DN_sl = NULL;
	//销毁BC_sl
	*BC_sl[0]->DC = NULL;
	BC_sl[0]->capacity = 0;
	BC_sl[0]->sz = 0;
	BC_sl[0]->alline = 0;
	free(*BC_sl);
	*BC_sl = NULL;
}