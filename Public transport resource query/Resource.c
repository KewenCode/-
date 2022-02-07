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
	ptrq->BM = (Base_Main*)malloc(DEFAULT_SZ * sizeof(Base_Main));//Ĭ������
	if (ptrq->BM == NULL)
	{
		perror("Initresource/���ṹ");
		return;
	}
	ptrq->capacity = DEFAULT_SZ;
	ptrq->sz = 0;

	//�������� �洢�ṹ
	*DN_sl = malloc(sizeof(DN_SingleList)+ sizeof(DN_TypeDefine));//Ĭ��һ��
	if (*DN_sl == NULL)
	{
		perror("Initresource/�������� �洢�ṹ");
		return;
	}
	DN_sl[0]->capacity = 1;
	DN_sl[0]->sz = 0;

	//�ı����� �洢�ṹ
	*BC_sl = malloc(sizeof(BC_SingleList) + sizeof(BCL_TypeDefine));//Ĭ��һ��
	if (*BC_sl == NULL)
	{
		perror("Initresource/�ı����� �洢�ṹ");
		return;
	}
	BC_sl[0]->capacity = 1;
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
void CheckResource(Base_Struct* ptrq)
{
	if (ptrq->sz == ptrq->capacity)
	{
		Base_Main* ptr = (Base_Main*)realloc(ptrq->BM, (ptrq->capacity + DEFAULT_SZ) * sizeof(Base_Main));
		if (ptr != NULL)
		{
			ptrq->BM = ptr;
			ptrq->capacity += DEFAULT_SZ;
			//printf("          -----------------------------           \n");
			//printf("          |         ���ݳɹ���        |           \n");
			//printf("          -----------------------------           \n");
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
}

//¼������ - ��̬�汾
void AddResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//ȷ������
		CheckResource(ptrq);
		printf("        -------------------------------           \n");
		printf("          ���ṹ ��ʹ�ã�%d ������%d\n", ptrq->sz, ptrq->capacity); 
		printf("          ���� ��ʹ�ã�%d ������%d\n", DN_sl[0]->sz, DN_sl[0]->capacity); 
		printf("          �ı� ��ʹ�ã�%d ������%d\n", BC_sl[0]->sz, BC_sl[0]->capacity); 
		printf("        -------------------------------           \n");
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
				memcpy(ptrq->BM[ptrq->sz].id, id, 9);//����id
				//������
				ptrq->BM[ptrq->sz].year = year;
				ptrq->BM[ptrq->sz].month = month;
				ptrq->BM[ptrq->sz].day = day;
				//����
				AddResource_Headline(ptrq, DN_sl, id);
				//����
				AddResource_Context(ptrq, BC_sl, id);
				//����
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
//¼������ - ����
void AddResource_Headline(Base_Struct* ptrq, DN_SingleList** DN_sl, char* id)
{
	//�ṹ����ʱ����
		unsigned short headlinecount = 0;
		char headline[TEXT_200] = { 0 };
	//����
		printf("��������⣺\n");
		scanf("%s", headline);
		headlinecount = (unsigned short)strlen(headline); //��������
		char* headlinepoint = headline; //�ַ���תΪ�ַ�ָ��
	//���ٴ洢�ռ�&��ֵ
		Base_Name* BN = malloc(sizeof(Base_Name) + (headlinecount + 1) * sizeof(char));
		if (BN == NULL)
		{
			perror("malloc/Base_Name* BN ");
			return;
		}
		memcpy(BN[0].id, id, 9);
		memcpy(BN[0].headline, headlinepoint, headlinecount + 1);
	//����&ָ��ת��
		ptrq->BM[ptrq->sz].headlinecount = headlinecount;
		DN_sl[0]->DN[DN_sl[0]->sz] = (unsigned long*)BN;//ָ�븴��
		DN_sl[0]->sz++;
		BN = NULL;
	//DN_sl�¿��ٿռ�
		if (DN_sl[0]->sz == DN_sl[0]->capacity)
		{
			DN_SingleList* str1 = NULL;
			DN_sl[0]->capacity++;
			str1 = realloc(*DN_sl, sizeof(DN_SingleList) + sizeof(DN_TypeDefine) * (DN_sl[0]->sz + 1));
			if (str1 == NULL)
			{
				perror("Initresource/BC_sl");
				return;
			}
			*DN_sl = str1;
			str1 = NULL;
		}
}
//¼������ - �ı�
void AddResource_Context(Base_Struct* ptrq, BC_SingleList** BC_sl, char* id)
{
	//BC_sl��ʱ�洢501��
		BC_LineList BC_T;
		BC_LineList* BC_Temple = &BC_T;
		BC_Temple = (BC_LineList*)malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * TEXT_500);//Ĭ��501��
		if (BC_Temple == NULL)
		{
			perror("Initresource/BC_LineList*");
			return;
		}
	//�ṹ����ʱ����
		unsigned short contextcount = 0;
		char context_paragraph[TEXT_1000] = { 0 };
		char id_line[11] = { 0 };
		int lines = 0;//ȷ������
		int count = 0;//������
	printf("���������ݣ�\n");
	do
	{
		//����
			printf("��%d��:", lines);
			scanf("%s", context_paragraph);
			if (strcmp(context_paragraph, "quit") == 0) //Ϊquitʱ�˳�
			{
				break;
			}
			contextcount = (unsigned short)strlen(context_paragraph);
			count = contextcount + count;//����ͳ��
			char* contextpoint = context_paragraph;
		//�����д洢�ռ�&��ֵ
			Base_Context* BC = malloc(sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
			if (BC == NULL)
			{
				perror("malloc/Base_Context* BC ");
				break;
			}
			sprintf(id_line, "%s%d", id, lines);
			memcpy(BC[0].id, id_line, 11);
			memcpy(BC[0].context_paragraph, contextpoint, contextcount + 1);
		//����&ָ��ת��
			BC_Temple->BCL[lines] = (unsigned long*)BC;//����ָ�븴��
			BC = NULL;
			lines++;
	} while (1);

	//BC_sl��ʽ�洢lines��
		BC_LineList* BC_Formal = malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * lines);
		if (BC_Formal == NULL)
		{
			return;
		}
		BC_Formal->line = lines;
	//BC_sl��ʱ�洢ת��ʽ
		for (int i = 0; i < lines; i++)
		{
			BC_Formal->BCL[i] = BC_Temple->BCL[i];//����ָ�븴��
		}
		free(BC_Temple);
	//����&ָ��ת��
		ptrq->BM[ptrq->sz].line = lines;
		ptrq->BM[ptrq->sz].contextcount = count;
		ptrq->sz++;
		BC_sl[0]->DC[BC_sl[0]->sz] = (BCL_TypeDefine)BC_Formal;//ָ�븴��
		BC_Formal = NULL;
		BC_sl[0]->sz++;
	//BC_sl�¿��ٿռ�
		if (BC_sl[0]->sz == BC_sl[0]->capacity)
		{
			BC_SingleList* str1 = NULL;
			BC_sl[0]->capacity++;
			str1 = realloc(*BC_sl, sizeof(BC_SingleList) + sizeof(BCL_TypeDefine) * (BC_sl[0]->sz + 1));
			if (str1 == NULL)
			{
				perror("Initresource/BC_sl");
				return;
			}
			*BC_sl = str1;
			str1 = NULL;
		}
}

//��ѯ
void SeacrhResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//��ʱ����
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

static int FindHeadlineResource(DN_SingleList** DN_sl, char Headline[])
{
	unsigned int i = 0;
	for (i = 0; i < DN_sl[0]->sz; i++)
	{
		Base_Name* BN = NULL;
		BN = (Base_Name*)DN_sl[0]->DN[i];//ָ�븴��
		if (strcmp(BN->headline, Headline) == 0)
		{
			return i;
		}
	}
	return -1;//�Ҳ���
}
//ɾ������
void DelateResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//��ʱ����
		char Headline[TEXT_200];
		unsigned int i = 0;
	//ȷ������
		if (ptrq->sz == 0)
		{
			printf("δ��¼����,3����Զ����ء�\n");
			Sleep(3000);
			return;
		}
	//����
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
	//�ͷ����ÿռ�
		Base_Name* BN = NULL;
		BN = (Base_Name*)DN_sl[0]->DN[pos];//ָ�븴��
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
	//ɾ��
		for (i = pos; i < ptrq->sz; i++)
		{
			ptrq->BM[i] = ptrq->BM[i + 1];
			BC_sl[0]->DC[i] = BC_sl[0]->DC[i + 1];
			DN_sl[0]->DN[i] = DN_sl[0]->DN[i + 1];
		}
		ptrq->sz--;
		BC_sl[0]->sz--;
		DN_sl[0]->sz--;
	printf("ɾ���ɹ�,3����Զ����ء�\n");
	Sleep(3000);
}

//�޸��ļ�
void ModifyResource(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//��ʱ����
		char Headline[TEXT_200];
	//����
		printf("������Ҫ�޸ĵı�������:");
		scanf("%s", Headline);
	//���Ҷ�Ӧ����
	int pos = FindHeadlineResource(DN_sl, Headline);
	if (pos == -1)
	{
		printf("δ�ҵ��������,3����Զ����ء�\n");
		Sleep(3000);
		return;
	}
	else
	{
		printf("������ �� �� �� [����20220101]��\n");
		scanf("%4hu%2hu%2hu", &(ptrq->BM[pos].year), &(ptrq->BM[pos].month), &(ptrq->BM[pos].day));
		while (1)
		{
			if ((ptrq->BM[pos].month) < 13 && (ptrq->BM[pos].month) > 0)
			{
				if (ptrq->BM[pos].day > 0 && ptrq->BM[pos].day < 32)
				{
						unsigned int i = 0;
						//�ͷ��ڴ�
						Base_Name* BN = NULL;
						BN = (Base_Name*)DN_sl[0]->DN[pos];//ָ�븴��					
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
					//����
						//�ṹ����ʱ����
						unsigned short headlinecount = 0;
						char headline[TEXT_200] = { 0 };
						char id[9] = { 0 };
						//����id��ʶ
						Randomid(id);
						memcpy(ptrq->BM[ptrq->sz].id, id, 9);//����id
						//����
						printf("��������⣺\n");
						scanf("%s", headline);
						headlinecount = (unsigned short)strlen(headline); //��������
						char* headlinepoint = headline; //�ַ���תΪ�ַ�ָ��
						//���ٴ洢�ռ�&��ֵ
						Base_Name* BN_temp = malloc(sizeof(Base_Name) + (headlinecount + 1) * sizeof(char));
						if (BN_temp == NULL)
						{
							perror("malloc/Base_Name* BN ");
							return;
						}
						memcpy(BN_temp[0].id, id, 9);
						memcpy(BN_temp[0].headline, headlinepoint, headlinecount + 1);
						//����&ָ��ת��
						ptrq->BM[pos].headlinecount = headlinecount;
						DN_sl[0]->DN[pos] = (unsigned long*)BN_temp;//ָ�븴��
						BN_temp = NULL;
					//����
						//BC_sl��ʱ�洢501��
						BC_LineList BC_T;
						BC_LineList* BC_Temple = &BC_T;
						BC_Temple = (BC_LineList*)malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * TEXT_500);//Ĭ��501��
						if (BC_Temple == NULL)
						{
							perror("Initresource/BC_LineList*");
							return;
						}
						//�ṹ����ʱ����
						unsigned short contextcount = 0;
						char context_paragraph[TEXT_1000] = { 0 };
						char id_line[11] = { 0 };
						int lines = 0;//ȷ������
						int count = 0;//������
						printf("���������ݣ�\n");
						do
						{
							//����
							printf("��%d��:", lines);
							scanf("%s", context_paragraph);
							if (strcmp(context_paragraph, "quit") == 0) //Ϊquitʱ�˳�
							{
								break;
							}
							contextcount = (unsigned short)strlen(context_paragraph);
							count = contextcount + count;//����ͳ��
							char* contextpoint = context_paragraph;
							//�����д洢�ռ�&��ֵ
							Base_Context* BC = malloc(sizeof(Base_Context) + (contextcount + 1) * sizeof(char));
							if (BC == NULL)
							{
								perror("malloc/Base_Context* BC ");
								break;
							}
							sprintf(id_line, "%s%d", id, lines);
							memcpy(BC[0].id, id_line, 11);
							memcpy(BC[0].context_paragraph, contextpoint, contextcount + 1);
							//����&ָ��ת��
							BC_Temple->BCL[lines] = (unsigned long*)BC;//����ָ�븴��
							BC = NULL;
							lines++;
						} while (1);
						//BC_sl��ʽ�洢lines��
						BC_LineList* BC_Formal = malloc(sizeof(BC_LineList) + sizeof(BC_TypeDefine) * lines);
						if (BC_Formal == NULL)
						{
							return;
						}
						BC_Formal->line = lines;
						//BC_sl��ʱ�洢ת��ʽ
						for (int i = 0; i < lines; i++)
						{
							BC_Formal->BCL[i] = BC_Temple->BCL[i];//����ָ�븴��
						}
						free(BC_Temple);
						//����&ָ��ת��
						ptrq->BM[pos].line = lines;
						ptrq->BM[pos].contextcount = count;
						BC_sl[0]->DC[pos] = (BCL_TypeDefine)BC_Formal;//ָ�븴��
						BC_Formal = NULL;

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
void Destorycontact(Base_Struct* ptrq, DN_SingleList** DN_sl, BC_SingleList** BC_sl)
{
	//��ʱ����
	unsigned int i = 0;
	unsigned int j = 0;
	//��������
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
	//������
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
		free(BCA);
		BCA = NULL;
	}
	//�������ṹ
		free(ptrq->BM);
		ptrq->BM = NULL;
		ptrq->capacity = 0;
		ptrq->sz = 0;
		ptrq = NULL;
	//����DN_sl
		*DN_sl[0]->DN = NULL;
		DN_sl[0]->capacity = 0;
		DN_sl[0]->sz = 0;
		free(*DN_sl);
		*DN_sl = NULL;
	//����BC_sl
		*BC_sl[0]->DC = NULL;
		BC_sl[0]->capacity = 0;
		BC_sl[0]->sz = 0;
		BC_sl[0]->alline = 0;
		free(*BC_sl);
		*BC_sl = NULL;
}