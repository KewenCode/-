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
void InitResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//���ṹ
	ptrq->BM = (Base_Main*)malloc(DEFAULT_SZ * sizeof(Base_Main));
	if (ptrq->BM == NULL)
	{
		perror("Initresource/���ṹ");
		return;
	}
	ptrq->capacity = DEFAULT_SZ;
	ptrq->sz = 0;

	//�������� �洢�ṹ
	*DN_sl = malloc(sizeof(DN_SingleList)+ sizeof(DN_TypeDefine));
	if (*DN_sl == NULL)
	{
		perror("Initresource/�������� �洢�ṹ");
		return;
	}
	//DN_sl[0]->capacity = 0;
	DN_sl[0]->sz = 0;

	//�ı����� �洢�ṹ
	*BC_sl = malloc(sizeof(BC_SingleList) + sizeof(BCL_TypeDefine));//Ĭ��һ��
	if (*BC_sl == NULL)
	{
		perror("Initresource/�ı����� �洢�ṹ");
		return;
	}
	//BC_sl[0]->capacity = 0;
	BC_sl[0]->sz = 0;
	BC_sl[0]->alline = 0;

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
//	DN_TypeDefine tmp1 = { 0 };//ȷ���ļ��Ƿ����
//	BCL_TypeDefine tmp2 = { 0 };
//	while (fread(&tmp1.year, sizeof(DN_TypeDefine), 1, pf))
//	{
//		if(fread(&tmp2.context_paragraph, sizeof(BCL_TypeDefine), 1, pf)!=0)
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
//void CheckResource(Base_Struct* ptrq, DN_SingleList* DN_sl, BC_SingleList* BC_sl)
//{
//	if (ptrq->sz == ptrq->capacity && DN_sl->sz == DN_sl->capacity && BC_sl->sz == BC_sl->capacity)
//	{
//		Base_Main* ptr = (Base_Main*)realloc(ptrq->BM, (ptrq->capacity + DEFAULT_SZ) * sizeof(Base_Main));
//		DN_TypeDefine* ptr1 = (DN_TypeDefine*)realloc(DN_sl->DN, (DN_sl->capacity + DEFAULT_SZ) * sizeof(DN_TypeDefine));
//		BCL_TypeDefine* ptr2 = (BCL_TypeDefine*)realloc(BC_sl->DC, (BC_sl->capacity + DEFAULT_SZ) * sizeof(BCL_TypeDefine));
//
//		if (ptr != NULL && ptr1 != NULL && ptr2 != NULL)
//		{
//			ptrq->BM = ptr;
//			ptrq->capacity += DEFAULT_SZ;
//			DN_sl->DN = ptr1;
//			BC_sl->DC = ptr2;
//
//			unsigned int i = 0;
//			for (i = ptrq->sz; i < ptrq->capacity; i++)
//			{
//				DN_sl->DN[i] = (unsigned long*)malloc(sizeof(unsigned long));
//				DN_sl->capacity++;
//				BC_sl->DC[i] = (unsigned long*)malloc(sizeof(unsigned long));
//				BC_sl->capacity++;
//			}
//
//			printf("          -----------------------------           \n");
//			printf("          |         ���ݳɹ���        |           \n");
//			printf("          -----------------------------           \n");
//		}
//		else
//		{
//			perror("CheckResource/ptr");
//			printf("          -----------------------------           \n");
//			printf("           �������ݿռ�ʧ�ܣ����ڿ�ָ��           \n");
//			printf("                2��󷵻��������                 \n");
//			printf("          -----------------------------           \n");
//			Sleep(2000);
//			return;
//		}
//	}
//	else if (ptrq->sz != DN_sl->sz && ptrq->sz != BC_sl->sz)
//	{
//		perror("CheckResource/NotSame");
//		printf("          -----------------------------           \n");
//		printf("              ����ʧ�ܣ�������һ�£�              \n");
//		printf("                2��󷵻��������                 \n");
//		printf("          -----------------------------           \n");
//		Sleep(2000);
//		return;
//	}
//}

//¼������ - ��̬�汾
void AddResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//ȷ������
	//CheckResource(ptrq, DN_sl, BC_sl);
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
				memcpy(BN[0].id, id, 9);
				memcpy(BN[0].headline, headlinepoint, headlinecount + 1);
				DN_sl[0]->DN[DN_sl[0]->sz] = (unsigned long*)BN;//ָ�븴��
				DN_sl[0]->sz++;
				BN = NULL;
				//�¿��ٿռ�
				DN_SingleList* str1 = NULL;
				str1 = realloc(*DN_sl, sizeof(DN_SingleList) + sizeof(DN_TypeDefine) * (DN_sl[0]->sz + 1));
				if (str1 == NULL)
				{
					perror("Initresource/BC_sl");
					return;
				}
				*DN_sl = str1;
				str1 = NULL;

				//����
				AddResource_Context(ptrq, BC_sl, id);

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
void AddResource_Context(Base_Struct* ptrq, BC_SingleList** BC_sl, char* id)
{
	BC_LineList p;
	BC_LineList* ptr = &p;
	ptr = (BC_LineList*)malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * TEXT_500);//Ĭ��501��
	if (ptr == NULL)
	{
		perror("Initresource/BC_LineList*");
		return;
	}

	unsigned short contextcount = 0;
	char context_paragraph[TEXT_1000] = { 0 };
	char id_line[11] = { 0 };
	int lines = 0;//ȷ������
	int count = 0;//������

	printf("���������ݣ�\n");
	do
	{
		printf("��%d��:", lines);
		scanf("%s", context_paragraph);
		if (strcmp(context_paragraph, "quit") == 0)
		{
			break;
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
		ptr->BCL[lines] = (unsigned long*)BC;//����ָ�븴��
		BC = NULL;
		lines++;
	} while (1);

	BC_LineList* str = malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * lines);
	if(str==NULL)
	{
		return;
	}
	str->line = lines;
	for (int i = 0; i < lines; i++)
	{
		str->BCL[i] = ptr->BCL[i];//����ָ�븴��
	}
	free(ptr);
	ptrq->BM[ptrq->sz].contextcount = count;
	ptrq->BM[ptrq->sz].line = lines;
	ptrq->sz++;
	BC_sl[0]->DC[BC_sl[0]->sz] = (BCL_TypeDefine)str;//ָ�븴��
	str = NULL;
	BC_sl[0]->sz++;

	BC_SingleList* str1 = NULL;
	str1 = realloc(*BC_sl, sizeof(BC_SingleList) + sizeof(BCL_TypeDefine) * (BC_sl[0]->sz + 1));
	if (str1 == NULL)
	{
		perror("Initresource/BC_sl");
		return;
	}
	*BC_sl = str1;
	str1 = NULL;

	////realloc�ռ�
	//if (lines > 1)
	//{
	//	BC_LineList* str = NULL;
	//	
	//}
	////��ָ��
	//int i = 0;
	//int j = 0;
	//for (i = BC_sl->alline, j = 0; (i < BC_sl->alline + lines) && (j < lines); i++, j++)
	//{
	//	bca[0]->BCL[i] = ptr->BCL[j];//����ָ�븴��
	//	bca[0]->line++;
	//}
	//BC_sl->alline += lines;

	//ptrq->BM[ptrq->sz].contextcount = count;
	//ptrq->BM[ptrq->sz].line = lines;
	//ptrq->sz++;
	//BC_sl->DC[BC_sl->sz] = (unsigned long*)bca;//ָ�븴��
	//BC_sl->sz++;
	//BC_LineList s;
	//BC_LineList* str = &s;
	//str = realloc(*bca, sizeof(BC_LineList) + (BC_sl->alline + 1) * sizeof(BC_TypeDefine));//Ĭ��һ��
	//if (str == NULL)
	//{
	//	perror("Initresource/BC_LineList*");
	//	return;
	//}
	//*bca = str;
	//str = NULL;
}

//��ѯ
void SeacrhResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	unsigned int i = 0;
	unsigned short j = 0;
	unsigned short linecount = 0;
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
			Base_Name* BN = NULL;
			BN = (Base_Name*)DN_sl[0]->DN[i];//ָ�븴��
			printf("��ѯ�������£�\n");
			printf("[ ʱ �� ]��%d��%d��%d��\t\t[ �� �� ]��%s\n",
				ptrq->BM[i].year,
				ptrq->BM[i].month,
				ptrq->BM[i].day,
				BN->headline);
			printf("[ �� �� ]��\n");
			Base_Context* BC = NULL;
			BC_LineList* BCA = NULL;
			BCA = (BC_LineList*)BC_sl[0]->DC[i];

			for (j = 0; j < ptrq->BM[i].line; j++)
			{
				BC = (Base_Context*)BCA->BCL[j];
				printf("��%d�У�%s\n", j, BC->context_paragraph);
			}

			/*Base_Context* BC = NULL;
			for (j = linecount; j < (linecount + ptrq->BM[i].line); j++)
			{
				BC = (Base_Context*)bca[0]->BCL[j];
				printf("��%d�У�%s\n", j, BC->context_paragraph);
			}
			linecount += ptrq->BM[i].line;*/
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
//		fwrite(pc->name_1 + i, sizeof(DN_TypeDefine), 1, pf);
//		fwrite(pc->context_1 + i, sizeof(BCL_TypeDefine), 1, pf);
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	//void function_over();//���Թ���
//}

static int FindHeadlineResource(DN_SingleList* pc, char Headline[])
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
void DelateResource(Base_Struct* ptrq, DN_SingleList* DN_sl, BC_SingleList* BC_sl)
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
	int pos = FindHeadlineResource(DN_sl, Headline);
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
		BC_sl->DC[i] = BC_sl->DC[i + 1];
		DN_sl->DN[i] = DN_sl->DN[i + 1];
	}
	ptrq->sz--;
	BC_sl->sz--;
	DN_sl->sz--;
	printf("ɾ���ɹ�,3����Զ����ء�\n");
	Sleep(3000);
}

//�޸��ļ�
//void ModifyResource(Base_Struct* ptrq, DN_SingleList* DN_sl, BC_SingleList* BC_sl)
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
void Destorycontact(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{

	unsigned int i = 0;
	unsigned int j = 0;
	for (i = 0; i < DN_sl[0]->sz; i++)
	{
		if (DN_sl[0]->DN[i] != NULL)
		{
			Base_Name* BN = NULL;
			BN = (Base_Name*)DN_sl[0]->DN[i];//ָ�븴��
			free(BN);
			BN = NULL;
		}
	}


	Base_Context* BC = NULL;
	BC_LineList* BCA = NULL;
	for(i = 0; i < BC_sl[0]->sz; i++)
	{
		BCA = (BC_LineList*)BC_sl[0]->DC[i];
		for (j = 0; j < ptrq->BM[i].line; j++)
		{
			BC = (Base_Context*)BCA->BCL[j];
			free(BC);
			BC = NULL;
		}
		BCA = NULL;
	}

	free(ptrq->BM);
	ptrq->BM = NULL;
	ptrq->capacity = 0;
	ptrq->sz = 0;
	ptrq = NULL;

	*DN_sl[0]->DN = NULL;
	//DN_sl[0]->capacity = 0;
	DN_sl[0]->sz = 0;
	free(*DN_sl);
	*DN_sl = NULL;

	//BC_sl->capacity = 0;
	*BC_sl[0]->DC = NULL;
	BC_sl[0]->sz = 0;
	BC_sl[0]->alline = 0;
	free(*BC_sl);
	*BC_sl = NULL;

}