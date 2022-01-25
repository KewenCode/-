#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"

//���id
char* Randomid(char* dst)
{
	unsigned long seconds;
	seconds = (unsigned long)time(NULL);
	char id[9];
	sprintf(id, "%8X", seconds);
	memcpy(dst, id, 9);
	return dst;
}


//�ṹ��ʼ�� - ��̬�汾
void InitResource(Base_Struct* ptrq)
{
	ptrq->BM = (Base_Main*)malloc(DEFAULT_SZ * sizeof(Base_Main));
	if (ptrq->BM == NULL)
	{
		perror("Initresource/Base_Main*");
		return;
	}
	ptrq->capacity = DEFAULT_SZ;
	ptrq->sz = 0;	

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
void AddResource(Base_Struct* ptrq, unsigned long** dn, unsigned long** dc)
{
	//ȷ������
	//CheckResource(pc);
	printf("�䳤������ԣ���ͣ����ȷ������\n");
	//�ṹ����ʱ����
	char id[9] = { 0 };
	unsigned short year = 0;
	unsigned short month = 0;
	unsigned short day = 0;
	unsigned short headlinecount = 0;
	char headline[TEXT_200] = { 0 };
	unsigned short contextcount = 0;
	char context_paragraph[TEXT_1000] = { 0 };
	//��ֵ
	printf("������ �� �� �� [����20220101]��\n");
	scanf("%4hu%2hu%2hu", &(year), &(month), &(day));
	while (1)
	{
		if (month < 13 && month > 0)
		{
			if (day > 0 && day < 32)
			{
				//����id��ʶ
				Randomid(id);
				memcpy(ptrq->BM[ptrq->sz].id, id, 9);
				//������
				int BN_sz = 0;//ȷ������λ��
				ptrq->BM[ptrq->sz].year = year;
				ptrq->BM[ptrq->sz].month = month;
				ptrq->BM[ptrq->sz].day = day;
				ptrq->sz++;
				//����
				printf("��������⣺\n");
				scanf("%s", headline);
				headlinecount = (unsigned short)strlen(headline);
				char* headlinepoint = headline;//�ַ���תΪ�ַ�ָ��
				Base_Name* BN = malloc(sizeof(Base_Name) + (headlinecount + 1) * sizeof(char));
				if (BN == NULL)
				{
					perror("malloc/Base_Name* BN ");
					return;
				}
				ptrq->BM[ptrq->sz].headlinecount = headlinecount;
				memcpy(BN[BN_sz].id, id, 9);
				memcpy(BN[BN_sz].headline, headlinepoint, headlinecount + 1);
				*(Date_Name_arr) = (unsigned long*)BN;//ָ�븴��
				BN = NULL;
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
	contextcount = (unsigned short)strlen(context_paragraph);
	char* contextpoint = context_paragraph;
	Base_Context* BC = malloc(sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
	if (BC == NULL)
	{
		perror("malloc/Base_Context* BC ");
		return;
	}
	int BC_sz = 0;//ȷ������λ��
	ptrq->BM[ptrq->sz].contextcount = contextcount;
	memcpy(BC[BC_sz].id, id, 9);
	memcpy(BC[BC_sz].context_paragraph, contextpoint, contextcount + 1);
	*(Date_Context_arr) = (unsigned long*)BC;//ָ�븴��
	BC = NULL;
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
void SeacrhResource(Base_Struct* ptrq, unsigned long** dn, unsigned long** dc)
{
	int i = 0;
	while (1)
	{
		for (i = 0; i < 3; i++)
		{
			Base_Name* BN = NULL;
			BN = (Base_Name*)Date_Name_arr[i];//ָ�븴��
			printf("��ѯ�������£�\n");
			printf("[ ʱ �� ]��%d��%d��%d��\t\t[ �� �� ]��%s\n",
				ptrq->BM[i].year,
				ptrq->BM[i].month,
				ptrq->BM[i].day,
				BN->headline);
			Base_Context* BC = NULL;
			BC = (Base_Context*)Date_Context_arr[i];//ָ�븴��
			printf("[ �� �� ]��%s\n", BC->context_paragraph);
			system("pause");
		}
		break;
	}
	/*if (pc->sz == 0)
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
	system("pause");*/
}

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