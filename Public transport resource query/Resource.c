#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"

//���� - β�巨
void addinfo(Date_Base** resource)//resource��ͷָ��
{
	Date_Base* pc = NULL;
	Date_Base* temp = NULL;
	static Date_Base* tail = NULL;//���ÿ�ָ��
	pc = (Date_Base*)malloc(sizeof(struct Date_Base));
	if (pc = NULL)
	{
		perror("addinfo");
		exit(1);
	}
	AddResource(pc);
	if (*resource != NULL)
	{
		tail->next = pc;//��ָ̬�����һλ����
		pc->next = NULL;
	}
	else
	{
		*resource = pc;
		pc->next = NULL;
	}
}

//�ṹ��ʼ�� - ��̬�汾
void InitResource(Date_Base* pc)
{
	pc->name_1 = (Date_Name*)malloc(sizeof(Date_Name));
	if (pc->name_1 == NULL)
	{
		perror("Initresource/Date_Name");
		return;
	}
	pc->context_1 = (Date_Context*)malloc(sizeof(Date_Context));
	if (pc->context_1 == NULL)
	{
		perror("Initresource/Date_Context");
		return;
	}
	pc->sz = 0;
	pc->capacity = 1;

	//�����ļ�
	//Load_Resource(pc);  
	printf("�䳤������ԣ���ͣ����\n");
}

//�����ļ�
void Load_Resource(Date_Base* pc)
{
	FILE* pf = fopen("Resource.dat", "r");
	if (pf == NULL)
	{
		perror("LoadResource");
		return;
	}
	//���ļ�
	Date_Name tmp1 = { 0 };//ȷ���ļ��Ƿ����
	Date_Context tmp2 = { 0 };
	while (fread(&tmp1.year, sizeof(Date_Name), 1, pf))
	{
		if(fread(&tmp2.context_paragraph, sizeof(Date_Context), 1, pf)!=0)
		{
			//����Ƿ���Ҫ����
			CheckResource(pc);
			pc->name_1[pc->sz] = tmp1;
			pc->context_1[pc->sz] = tmp2;
			pc->sz++;
			system("cls");//��ʱ�Դ�ʩ
		}
		else
		{
			break;
		}
		
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//�������
void CheckResource(Date_Base* pc)
{
	if (pc->sz == pc->capacity)
	{
		Date_Name* ptr1 = (Date_Name*)realloc(pc->name_1, (pc->capacity + DEFAULT_SZ) * sizeof(Date_Name));
		Date_Context* ptr2 = (Date_Context*)realloc(pc->context_1, (pc->capacity + DEFAULT_SZ) * sizeof(Date_Context));
		if (ptr1 != NULL && ptr2 != NULL)
		{
			pc->name_1 = ptr1;
			pc->context_1 = ptr2;
			pc->capacity += DEFAULT_SZ;
			printf("���ݳɹ���\n");
			return;
		}
		else
		{
			perror("CheckResource");
			printf("����ʧ�ܣ�\n3������\n");
			Sleep(3000);
			return;
		}
	}
}

//¼������ - ��̬����̬���汾
void AddResource(Date_Base* pc)
{
	//ȷ������
	//CheckResource(pc);
	printf("�䳤������ԣ���ͣ����ȷ������\n");
	//�ṹ����ʱ����
	int year = 0;
	int month = 0;
	int day = 0;
	int headlinecount = 0;
	char headline[TEXT_200] = { 0 };
	//��ֵ
	printf("������ �� �� �� [����20220101]��\n");
	scanf("%4d%2d%2d", &(year), &(month), &(day));
	while (1)
	{
		if (month < 13 && month > 0)
		{
			if (day > 0 && day < 32)
			{
				printf("��������⣺\n");
				scanf("%s", headline);
				headlinecount = sizeof(headline);
				realloc(pc->name_1, sizeof(Date_Name) + (headlinecount + 1) * sizeof(char));//���ݿռ�
				//�ṹ�帳ֵ
				pc->name_1[pc->sz].year = year;
				pc->name_1[pc->sz].month = month;
				pc->name_1[pc->sz].day = day;
				pc->name_1[pc->sz].headlinecount = headlinecount;
				char* headlinepoint = headline;//�ַ���תΪ�ַ�ָ��
				memcpy(pc->name_1[pc->sz].headline, headlinepoint, headlinecount);
				printf("���������ݣ�\n");
				scanf("%s", pc->context_1[pc->sz].context_paragraph);
				pc->sz++;
				printf("          -----------------------------           \n");
				printf("          |  �ɹ�¼�룬3����Զ�����  |           \n");
				printf("          -----------------------------           \n");
				Sleep(3000);
				break;
			}
			else
			{
				printf("���ڷ��������ݣ���ȷ�����룡\n3��󷵻ع������\n");
				Sleep(3000);
				break;
			}
		}
		else
		{
			printf("�·ݷ��������ݣ���ȷ�����룡\n3��󷵻ع������\n");
			Sleep(3000);
			break;
		}
	}
}

//��ѯ
void SeacrhResource(Date_Base* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("��δ¼������,3����Զ����ء�\n");
		Sleep(3000);
		return;
	}
	for (i = 0;i < pc->sz;i++)
	{
		printf("��ѯ�������£�\n");
		printf("[ ʱ �� ]��%d��%d��%d��\t\t[ �� �� ]��%s\n",
			pc->name_1[i].year,
			pc->name_1[i].month,
			pc->name_1[i].day,
			pc->name_1[i].headline);
		printf("[ �� �� ]��%s\n",pc->context_1[i].context_paragraph);
	}
	system("pause");
}

//�����ļ�
void SaveResource(Date_Base* pc)
{
	//���ļ�
	FILE*pf= fopen("Resource.dat", "w");
	if (pf == NULL)
	{
		perror("SaveResource");
		return;
	}
	//д�ļ�
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		fwrite(pc->name_1 + i, sizeof(Date_Name), 1, pf);
		fwrite(pc->context_1 + i, sizeof(Date_Context), 1, pf);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	//void function_over();//���Թ���
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
	return -1;//�Ҳ���
}
//ɾ������
void DelateResource(Date_Base* pc)
{
	char Headline[TEXT_200];
	if (pc->sz == 0)
	{
		printf("δ��¼����,3����Զ����ء�\n");
		Sleep(3000);
		return;
	}
	printf("������Ҫɾ�������ݱ��⣺");
	scanf("%s", Headline);
	//���Ҷ�Ӧ����
	int pos = FindHeadlineResource(pc, Headline);
	if (pos == -1)
	{
		printf("δ�ҵ��������,3����Զ����ء�\n");
		Sleep(3000);
		return;
	}
	//ɾ��
	int i = 0;
	for (i = pos;i < pc->sz;i++)
	{
		pc->name_1[i] = pc->name_1[i + 1];
		pc->context_1[i] = pc->context_1[i + 1];
		pc->sz--;
	}
	printf("ɾ���ɹ�,3����Զ����ء�\n");
	Sleep(3000);
}

//�޸��ļ�
void ModityResource(Date_Base* pc)
{
	char Headline[TEXT_200];
	printf("������Ҫ�޸ĵı�������:");
	scanf("%s", Headline);
	int pos = FindHeadlineResource(pc, Headline);
	if (pos == -1)
	{
		printf("δ�ҵ��������,3����Զ����ء�\n");
		Sleep(3000);
		return;
	}
	else
	{
		printf("������ �� �� �� [����20220101]��\n");
		scanf("%4d%2d%2d", &(pc->name_1[pos].year), &(pc->name_1[pos].month), &(pc->name_1[pos].day));
		while (1)
		{
			if ((pc->name_1[pos].month) < 13 && (pc->name_1[pos].month) > 0)
			{
				if (pc->name_1[pos].day > 0 && pc->name_1[pos].day < 32)
				{
					printf("��������⣺\n");
					scanf("%s", pc->name_1[pos].headline);
					printf("���������ݣ�\n");
					scanf("%s", pc->context_1[pos].context_paragraph);//ע�⣬�˴�sz����Ҫ++
					printf("          -----------------------------           \n");
					printf("          |  �ɹ�¼�룬3����Զ�����  |           \n");
					printf("          -----------------------------           \n");
					Sleep(3000);
					break;
				}
				else
				{
					printf("���ڷ��������ݣ���ȷ�����룡\n3��󷵻ع������\n");
					Sleep(3000);
					break;
				}
			}
			else
			{
				printf("�·ݷ��������ݣ���ȷ�����룡\n3��󷵻ع������\n");
				Sleep(3000);
				break;
			}
		}
	}
}

//�����ڴ�
void Destorycontact(Date_Base* pc)
{
	free(pc->name_1);
	pc->name_1 = NULL;
	free(pc->context_1);
	pc->context_1 = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//--------------------[ �� ̬ ]�޸ķ�Χ--------------------

//�ṹ��ʼ�� - ��̬�汾
//void InitResource(Date_Base* pc)
//{
//	memset(pc->name_1, 0, sizeof(pc->name_1));
//	memset(pc->context_1, 0, sizeof(pc->context_1));
//	pc->sz = 0;
//	pc->capacity = DEFAULT_SZ;
//}