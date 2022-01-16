#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"

//�ṹ��ʼ�� - ��̬�汾
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

	//�����ļ�
	Load_Resource(pc);
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

//¼������ - ��̬����̬���汾
void AddResource(Date_Base* pc)
{
	//ȷ������
	CheckResource(pc);

	if (pc->sz == MAX)
	{
		printf("�ռ�����,3����Զ����ء�\n");
		Sleep(3000);
		return;
	}
	//��������
	printf("������ �� �� �� [����20220101]��\n");
	scanf("%4d%2d%2d", &(pc->name_1[pc->sz].year), &(pc->name_1[pc->sz].month), &(pc->name_1[pc->sz].day));
	while (1)
	{
		if ((pc->name_1[pc->sz].month) < 13 && (pc->name_1[pc->sz].month) > 0)
		{
			if (pc->name_1[pc->sz].day > 0 && pc->name_1[pc->sz].day < 32)
			{
				printf("��������⣺\n");
				scanf("%s", pc->name_1[pc->sz].headline);
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

//�������
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
			printf("���ݳɹ���\n3������\n");
			Sleep(3000);
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
//	pc->capacity = Default_sz;
//}