#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"



//�ṹ��ʼ�� - ��̬�汾
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

	//�����ļ�
	//Load_Resource(pc);  
	printf("�䳤������ԣ���ͣ�����ļ�\n");
}

//�����ļ�
//void Load_Resource(Date_Base* pc)
//{
//	FILE* pf = fopen("Resource.dat", "r");
//	if (pf == NULL)
//	{
//		perror("LoadResource");
//		return;
//	}
//	//���ļ�
//	Date_Name tmp1 = { 0 };//ȷ���ļ��Ƿ����
//	Date_Context tmp2 = { 0 };
//	while (fread(&tmp1.year, sizeof(Date_Name), 1, pf))
//	{
//		if(fread(&tmp2.context_paragraph, sizeof(Date_Context), 1, pf)!=0)
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

//�������
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
//			printf("���ݳɹ���\n");
//			return;
//		}
//		else
//		{
//			perror("CheckResource");
//			printf("����ʧ�ܣ�\n3������\n");
//			Sleep(3000);
//			return;
//		}
//	}
//}

//¼������ - ��̬�汾
void AddResource(Base_Name* name, Base_Context* context)
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
	int contextcount = 0;
	char context_paragraph[TEXT_1000] = { 0 };
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
				headlinecount = strlen(headline);
				char* headlinepoint = headline;//�ַ���תΪ�ַ�ָ��
				Base_Name* BN = malloc(sizeof(Base_Name) + (headlinecount + 1) * sizeof(char));
				//�ṹ�帳ֵ
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
	printf("���������ݣ�\n");
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
	printf("          |  �ɹ�¼�룬3����Զ�����  |           \n");
	printf("          -----------------------------           \n");
	Sleep(3000);
}

//¼������ - ����β�巨
		//void AddResource_LinkedList(Date_Base** resource)//resource��ͷָ��
		//{
		//	Date_Base* pc = NULL;
		//	Date_Base* temp = NULL;
		//	static Date_Base* tail = NULL;//���ÿ�ָ��
		//	pc = (Date_Base*)malloc(sizeof(struct Date_Base));
		//	if (pc = NULL)
		//	{
		//		perror("addinfo");
		//		exit(1);
		//	}
		//	AddResource(pc);
		//	if (*resource != NULL)
		//	{
		//		tail->next = pc;//��ָ̬�����һλ����
		//		pc->next = NULL;
		//	}
		//	else
		//	{
		//		*resource = pc;
		//		pc->next = NULL;
		//	}
		//}

//��ѯ
//void SeacrhResource(Date_Name* name, Date_Context* context)
//{
//	int i = 0;
//	if (pc->sz == 0)
//	{
//		printf("��δ¼������,3����Զ����ء�\n");
//		Sleep(3000);
//		return;
//	}
//	for (i = 0;i < pc->sz;i++)
//	{
//		printf("��ѯ�������£�\n");
//		printf("[ ʱ �� ]��%d��%d��%d��\t\t[ �� �� ]��%s\n",
//			pc->name_1[i].year,
//			pc->name_1[i].month,
//			pc->name_1[i].day,
//			pc->name_1[i].headline);
//		printf("[ �� �� ]��%s\n",pc->context_1[i].context_paragraph);
//	}
//	system("pause");
//}

//�����ļ�
//void SaveResource(Date_Base* pc)
//{
//	//���ļ�
//	FILE*pf= fopen("Resource.dat", "w");
//	if (pf == NULL)
//	{
//		perror("SaveResource");
//		return;
//	}
//	//д�ļ�
//	int i = 0;
//	for (i = 0;i < pc->sz;i++)
//	{
//		fwrite(pc->name_1 + i, sizeof(Date_Name), 1, pf);
//		fwrite(pc->context_1 + i, sizeof(Date_Context), 1, pf);
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	//void function_over();//���Թ���
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
//	return -1;//�Ҳ���
//}
//ɾ������
//void DelateResource(Date_Base* pc)
//{
//	char Headline[TEXT_200];
//	if (pc->sz == 0)
//	{
//		printf("δ��¼����,3����Զ����ء�\n");
//		Sleep(3000);
//		return;
//	}
//	printf("������Ҫɾ�������ݱ��⣺");
//	scanf("%s", Headline);
//	//���Ҷ�Ӧ����
//	int pos = FindHeadlineResource(pc, Headline);
//	if (pos == -1)
//	{
//		printf("δ�ҵ��������,3����Զ����ء�\n");
//		Sleep(3000);
//		return;
//	}
//	//ɾ��
//	int i = 0;
//	for (i = pos;i < pc->sz;i++)
//	{
//		pc->name_1[i] = pc->name_1[i + 1];
//		pc->context_1[i] = pc->context_1[i + 1];
//		pc->sz--;
//	}
//	printf("ɾ���ɹ�,3����Զ����ء�\n");
//	Sleep(3000);
//}

//�޸��ļ�
//void ModityResource(Date_Base* pc)
//{
//	char Headline[TEXT_200];
//	printf("������Ҫ�޸ĵı�������:");
//	scanf("%s", Headline);
//	int pos = FindHeadlineResource(pc, Headline);
//	if (pos == -1)
//	{
//		printf("δ�ҵ��������,3����Զ����ء�\n");
//		Sleep(3000);
//		return;
//	}
//	else
//	{
//		printf("������ �� �� �� [����20220101]��\n");
//		scanf("%4d%2d%2d", &(pc->name_1[pos].year), &(pc->name_1[pos].month), &(pc->name_1[pos].day));
//		while (1)
//		{
//			if ((pc->name_1[pos].month) < 13 && (pc->name_1[pos].month) > 0)
//			{
//				if (pc->name_1[pos].day > 0 && pc->name_1[pos].day < 32)
//				{
//					printf("��������⣺\n");
//					scanf("%s", pc->name_1[pos].headline);
//					printf("���������ݣ�\n");
//					scanf("%s", pc->context_1[pos].context_paragraph);//ע�⣬�˴�sz����Ҫ++
//					printf("          -----------------------------           \n");
//					printf("          |  �ɹ�¼�룬3����Զ�����  |           \n");
//					printf("          -----------------------------           \n");
//					Sleep(3000);
//					break;
//				}
//				else
//				{
//					printf("���ڷ��������ݣ���ȷ�����룡\n3��󷵻ع������\n");
//					Sleep(3000);
//					break;
//				}
//			}
//			else
//			{
//				printf("�·ݷ��������ݣ���ȷ�����룡\n3��󷵻ع������\n");
//				Sleep(3000);
//				break;
//			}
//		}
//	}
//}

//�����ڴ�
//void Destorycontact(Date_Base* pc)
//{
//	free(pc->name_1);
//	pc->name_1 = NULL;
//	free(pc->context_1);
//	pc->context_1 = NULL;
//	pc->sz = 0;
//	pc->capacity = 0;
//}