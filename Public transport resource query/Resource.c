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
void InitResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr* bca)
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

	bca->BCL = (Base_Context_List*)malloc(sizeof(Base_Context_List));//Ĭ��һ��
	if (bca->BCL == NULL)
	{
		perror("Initresource/Base_Context_arr*");
		return;
	}
	bca->line = 0;
	bca->Next = NULL;
	bca->BCL[bca->line] = (unsigned long*)malloc(sizeof(unsigned long));

	int i = 0;
	for (i = 0; i < DEFAULT_SZ; i++)
	{
		dna->DN[i] = (unsigned long*)malloc(sizeof(unsigned long));
		dna->capacity++;
		dca->DC[i] = (unsigned long*)malloc(sizeof(unsigned long));
		dca->capacity++;
	}


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

//���ݼ��
void CheckResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca)
{
	if (ptrq->sz == ptrq->capacity && dna->sz == dna->capacity && dca->sz == dca->capacity)
	{
		Base_Main* ptr = (Base_Main*)realloc(ptrq->BM, (ptrq->capacity + DEFAULT_SZ) * sizeof(Base_Main));
		Date_Name* ptr1 = (Date_Name*)realloc(dna->DN, (dna->capacity + DEFAULT_SZ) * sizeof(Date_Name));
		Date_Context* ptr2 = (Date_Context*)realloc(dca->DC, (dca->capacity + DEFAULT_SZ) * sizeof(Date_Context));

		if (ptr != NULL && ptr1 != NULL && ptr2 != NULL)
		{
			ptrq->BM = ptr;
			ptrq->capacity += DEFAULT_SZ;
			dna->DN = ptr1;
			dca->DC = ptr2;

			unsigned int i = 0;
			for (i = ptrq->sz; i < ptrq->capacity; i++)
			{
				dna->DN[i] = (unsigned long*)malloc(sizeof(unsigned long));
				dna->capacity++;
				dca->DC[i] = (unsigned long*)malloc(sizeof(unsigned long));
				dca->capacity++;
			}

			printf("          -----------------------------           \n");
			printf("          |         ���ݳɹ���        |           \n");
			printf("          -----------------------------           \n");
		}
		else
		{
			perror("CheckResource/ptr");
			printf("          -----------------------------           \n");
			printf("           �������ݿռ�ʧ�ܣ����ڿ�ָ��           \n");
			printf("                2��󷵻��������                 \n");
			printf("          -----------------------------           \n");
			Sleep(2000);
			return;
		}
	}
	else if (ptrq->sz != dna->sz && ptrq->sz != dca->sz)
	{
		perror("CheckResource/NotSame");
		printf("          -----------------------------           \n");
		printf("              ����ʧ�ܣ�������һ�£�              \n");
		printf("                2��󷵻��������                 \n");
		printf("          -----------------------------           \n");
		Sleep(2000);
		return;
	}
}

//¼������ - ��̬�汾
void AddResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr* bca)
{
	//ȷ������
	CheckResource(ptrq, dna, dca);
	//�ṹ����ʱ����
	int clear = 0;
	char id[9] = { 0 };
	unsigned short year = 0;
	unsigned short month = 0;
	unsigned short day = 0;
	unsigned short headlinecount = 0;
	char headline[TEXT_200] = { 0 };
	//��ֵ
	while (1)
	{
		printf("������ �� �� �� [����20220101]��\n");
		scanf("%4hu%2hu%2hu", &(year), &(month), &(day));
		while ((clear = getchar()) != '\n' && clear != EOF);//������뻺����
		//if (clear != 0)
		//{
		//	printf("          -----------------------------           \n");
		//	printf("          ���볬���涨��С����ȷ�����룡          \n");
		//	printf("                2��󷵻��������                 \n");
		//	printf("          -----------------------------           \n");
		//	Sleep(2000);
		//}
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
				dna->DN[dna->sz] = (unsigned long*)BN;//ָ�븴��
				dna->sz++;
				BN = NULL;
				//����
				AddResource_Context(ptrq, dca, bca, id);
				//�Ͻṹ
				//printf("���������ݣ�\n");
				//scanf("%s", context_paragraph);
				//contextcount = (unsigned short)strlen(context_paragraph);
				//char* contextpoint = context_paragraph;
				//Base_Context* BC = malloc(sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
				//if (BC == NULL)
				//{
				//	perror("malloc/Base_Context* BC ");
				//	return;
				//}
				//int BC_sz = 0;//ȷ������λ��
				//ptrq->BM[ptrq->sz].contextcount = contextcount;
				//ptrq->sz++;
				//memcpy(BC[BC_sz].id, id, 9);
				//memcpy(BC[BC_sz].context_paragraph, contextpoint, contextcount + 1);
				//{
				//	dca->DC[dca->sz] = (unsigned long*)BC;//ָ�븴��
				//	dca->sz++;
				//}
				//BC = NULL;


				printf("          -----------------------------           \n");
				printf("          |         �ɹ�¼�룡        |           \n");
				printf("          -----------------------------           \n");
				system("pause");
				break;
			}
			else
			{
				printf("          -----------------------------           \n");
				printf("           ���ڷ��������ݣ���ȷ�����룡           \n");
				printf("                2��󷵻��������                 \n");
				printf("          -----------------------------           \n");
				Sleep(2000);
			}
		}
		else
		{
			printf("          -----------------------------           \n");
			printf("           �·ݷ��������ݣ���ȷ�����룡           \n");
			printf("                2��󷵻��������                 \n");
			printf("          -----------------------------           \n");
			Sleep(2000);
		}
	}
}

//¼������ - �ı�
void AddResource_Context(Base_Struct* ptrq, Date_Context_arr* dca, Base_Context_arr* bca, char* id)
{

	unsigned short contextcount = 0;
	char context_paragraph[TEXT_1000] = { 0 };
	char id_line[11] = { 0 };
	int lines = 0;//ȷ������
	int count = 0;//������
	Base_Context_arr* head;

	printf("���������ݣ�\n");
	do
	{
		printf("��%d��:", lines);
		scanf("%s", context_paragraph);
		if (strcmp(context_paragraph, "quit") == 0)
		{
			break;
		}
		if (lines != 0)
		{
			Base_Context_List* str = realloc(bca->BCL, sizeof(Base_Context_List) * (lines + 1));
			if (str == NULL)
			{
				perror("Initresource/Base_Context_arr*_realloc");
				return;
			}
			bca->BCL = str;
			str = NULL;
			bca->BCL[bca->line + 1] = (unsigned long*)malloc(sizeof(unsigned long));
		}
		contextcount = (unsigned short)strlen(context_paragraph);
		count = contextcount + count;//����ͳ��
		char* contextpoint = context_paragraph;
		Base_Context* BC = malloc(sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
		if (BC == NULL)
		{
			perror("malloc/Base_Context* BC ");
			break;
		}
		sprintf(id_line, "%s%d", id, lines);
		memcpy(BC[0].id, id_line, 11);
		memcpy(BC[0].context_paragraph, contextpoint, contextcount + 1);
		bca->line = lines;
		bca->BCL[bca->line] = (unsigned long*)BC;//����ָ�븴��
		
		BC = NULL;
		lines++;
	//} while (1);
	//bca->Next = head;
	//head = bca;

	////��������
	//Base_Context_arr* beg;
	//Base_Context_arr* end;
	//beg = head;
	//end = head->Next;
	//while (end != NULL)
	//{
	//	beg->Next = end->Next;
	//	end->Next = head;
	//	head = end;
	//	end = beg->Next;
	//}

	ptrq->BM[ptrq->sz].contextcount = count;
	ptrq->BM[ptrq->sz].line = lines - 1;
	ptrq->sz++;
	dca->DC[dca->sz] = (unsigned long*)head;//ָ�븴��
	dca->sz++;
}

//��ѯ
void SeacrhResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca, Base_Context_arr* bca)
{
	unsigned int i = 0;
	while (1)
	{
		if (ptrq->sz == 0)
		{
			printf("          -----------------------------           \n");
			printf("          |         ����������        |           \n");
			printf("          -----------------------------           \n");
			system("pause");
			break;
		}
		for (i = 0; i < ptrq->sz; i++)
		{
			int j = 0;
			Base_Name* BN = NULL;
			BN = (Base_Name*)dna->DN[i];//ָ�븴��
			printf("��ѯ�������£�\n");
			printf("[ ʱ �� ]��%d��%d��%d��\t\t[ �� �� ]��%s\n",
				ptrq->BM[i].year,
				ptrq->BM[i].month,
				ptrq->BM[i].day,
				BN->headline);
			printf("[ �� �� ]��\n");
			Base_Context* BC = NULL;
			Base_Context_arr* BCA = NULL;
			BCA = (Base_Context_arr*)dca->DC[i];//ָ�븴��
			for (j = 0; j <= ptrq->BM[i].line; j++)
			{
				BC = (Base_Context*)bca->BCL[j];
				printf("��%d�У�%s\n", j, BC->context_paragraph);
			}
		}
		printf("          -----------------------------           \n");
		printf("                     ������                     \n");
		printf("               �ܼ���� %d ������\n", i);
		printf("          -----------------------------           \n");
		system("pause");
		break;
	}
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

static int FindHeadlineResource(Date_Name_arr* pc, char Headline[])
{
	unsigned int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		Base_Name* BN = NULL;
		BN = (Base_Name*)pc->DN[i];//ָ�븴��
		if (strcmp(BN->headline, Headline) == 0)
		{
			return i;
		}
	}
	return -1;//�Ҳ���
}
//ɾ������
void DelateResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca)
{
	char Headline[TEXT_200];
	if (ptrq->sz == 0)
	{
		printf("δ��¼����,3����Զ����ء�\n");
		Sleep(3000);
		return;
	}
	printf("������Ҫɾ�������ݱ��⣺");
	scanf("%s", Headline);
	//���Ҷ�Ӧ����
	int pos = FindHeadlineResource(dna, Headline);
	if (pos == -1)
	{
		printf("δ�ҵ��������,3����Զ����ء�\n");
		Sleep(3000);
		return;
	}
	//ɾ��
	unsigned int i = 0;
	for (i = pos; i < ptrq->sz; i++)
	{
		ptrq->BM[i] = ptrq->BM[i + 1];
		dca->DC[i] = dca->DC[i + 1];
		dna->DN[i] = dna->DN[i + 1];
	}
	ptrq->sz--;
	dca->sz--;
	dna->sz--;
	printf("ɾ���ɹ�,3����Զ����ء�\n");
	Sleep(3000);
}

//�޸��ļ�
//void ModifyResource(Base_Struct* ptrq, Date_Name_arr* dna, Date_Context_arr* dca)
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
			BN = (Base_Name*)dna->DN[i];//ָ�븴��
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