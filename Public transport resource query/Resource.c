#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"

//结构初始化 - 动态版本
void InitResource(Date_Base* pc)
{
	pc->name_1 = (Date_Name*)malloc(Default_sz * sizeof(Date_Name));
	if (pc->name_1 == NULL)
	{
		perror("Initresource/Date_Name");
		return;
	}
	pc->context_1 = (Date_Context*)malloc(Default_sz * sizeof(Date_Context));
	if (pc->context_1 == NULL)
	{
		perror("Initresource/Date_Context");
		return;
	}
	pc->sz = 0;
	pc->capacity = Default_sz;

	//加载文件
	Load_Resource(pc);
}

//加载文件
void Load_Resource(Date_Base* pc)
{
	FILE* pf = fopen("Resource.dat", "r");
	if (pf == NULL)
	{
		perror("LoadResource");
		return;
	}
	//读文件
	Date_Name tmp1 = { 0 };//确定文件是否存在
	Date_Context tmp2 = { 0 };
	while (fread(&tmp1.year, sizeof(Date_Name), 1, pf))
	{
		if(fread(&tmp2.context_paragraph, sizeof(Date_Context), 1, pf)!=0)
		{
			//检测是否需要增容
			CheckResource(pc);
			pc->name_1[pc->sz] = tmp1;
			pc->context_1[pc->sz] = tmp2;
			pc->sz++;
		}
		else
		{
			break;
		}
		
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}

//录入数据 - 动态（静态）版本
void AddResource(Date_Base* pc)
{
	//确认容量
	CheckResource(pc);

	if (pc->sz == MAX)
	{
		printf("空间已满,3秒后自动返回。\n");
		Sleep(3000);
		return;
	}
	//增加内容
	printf("请输入 年 月 日 [例：20220101]：\n");
	scanf("%4d%2d%2d", &(pc->name_1[pc->sz].year), &(pc->name_1[pc->sz].month), &(pc->name_1[pc->sz].day));
	while (1)
	{
		if ((pc->name_1[pc->sz].month) < 13 && (pc->name_1[pc->sz].month) > 0)
		{
			if (pc->name_1[pc->sz].day > 0 && pc->name_1[pc->sz].day < 32)
			{
				printf("请输入标题：\n");
				scanf("%s", pc->name_1[pc->sz].headline);
				printf("请输入内容：\n");
				scanf("%s", pc->context_1[pc->sz].context_paragraph);
				pc->sz++;
				printf("          -----------------------------           \n");
				printf("          |  成功录入，3秒后自动返回  |           \n");
				printf("          -----------------------------           \n");
				Sleep(3000);
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
}

//查询
void SeacrhResource(Date_Base* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("尚未录入数据,3秒后自动返回。\n");
		Sleep(3000);
		return;
	}
	for (i = 0;i < pc->sz;i++)
	{
		printf("查询内容如下：\n");
		printf("[ 时 间 ]：%d年%d月%d日\t\t[ 标 题 ]：%s\n",
			pc->name_1[i].year,
			pc->name_1[i].month,
			pc->name_1[i].day,
			pc->name_1[i].headline);
		printf("[ 正 文 ]：%s\n",pc->context_1[i].context_paragraph);
	}
	system("pause");
}

//检测增容
void CheckResource(Date_Base* pc)
{
	if (pc->sz == pc->capacity)
	{
		Date_Name* ptr1 = (Date_Name*)realloc(pc->name_1, (pc->capacity + Default_sz) * sizeof(Date_Name));
		Date_Context* ptr2 = (Date_Context*)realloc(pc->context_1, (pc->capacity + Default_sz) * sizeof(Date_Context));
		if (ptr1 != NULL && ptr2 != NULL)
		{
			pc->name_1 = ptr1;
			pc->context_1 = ptr2;
			pc->capacity += Default_sz;
			printf("增容成功！\n3秒后继续\n");
			Sleep(3000);
			return;
		}
		else
		{
			perror("CheckResource");
			printf("增容失败！\n3秒后继续\n");
			Sleep(3000);
			return;
		}
	}
}

//保存文件
void SaveResource(Date_Base* pc)
{
	//打开文件
	FILE*pf= fopen("Resource.dat", "w");
	if (pf == NULL)
	{
		perror("SaveResource");
		return;
	}
	//写文件
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		fwrite(pc->name_1 + i, sizeof(Date_Name), 1, pf);
		fwrite(pc->context_1 + i, sizeof(Date_Context), 1, pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
	//void function_over();//测试功能
}


static int FindHeadlineResource(Date_Base* pc, char Headline[])
{
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		if (strcmp(pc->name_1[i].headline, Headline) == 0)
		{
			return i;
		}
	}
	return -1;//找不到
}
//删除内容
void DelateResource(Date_Base* pc)
{
	char Headline[TEXT_200];
	if (pc->sz == 0)
	{
		printf("未记录内容,3秒后自动返回。\n");
		Sleep(3000);
		return;
	}
	printf("请输入要删除的内容标题：");
	scanf("%s", Headline);
	//查找对应内容
	int pos = FindHeadlineResource(pc, Headline);
	if (pos == -1)
	{
		printf("未找到相关内容,3秒后自动返回。\n");
		Sleep(3000);
		return;
	}
	//删除
	int i = 0;
	for (i = pos;i < pc->sz;i++)
	{
		pc->name_1[i] = pc->name_1[i + 1];
		pc->context_1[i] = pc->context_1[i + 1];
		pc->sz--;
	}
	printf("删除成功,3秒后自动返回。\n");
	Sleep(3000);
}

//销毁内存
void Destorycontact(Date_Base* pc)
{
	free(pc->name_1);
	pc->name_1 = NULL;
	free(pc->context_1);
	pc->context_1 = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//--------------------[ 静 态 ]修改范围--------------------

//结构初始化 - 静态版本
//void InitResource(Date_Base* pc)
//{
//	memset(pc->name_1, 0, sizeof(pc->name_1));
//	memset(pc->context_1, 0, sizeof(pc->context_1));
//	pc->sz = 0;
//	pc->capacity = Default_sz;
//}