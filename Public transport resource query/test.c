#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"
#include "File.h"

// ������Ŀ¼
void menu_1_1()
{
	printf("\033[1;46;37m--------------------------------------------------\n");
	printf("|                  ������Ϣ��ѯ                  |\n");
	printf("|------------------------------------------------|\n");
	printf("|                    ������                    |\n");
	printf("|                                                |\n");
	printf("|               1.  [ ¼������ ]                 |\n");
	printf("|               2.  [ �������� ]                 |\n");
	printf("|               3.  [ ɾ������ ]                 |\n");
	printf("|               4.  [ �޸����� ]                 |\n");
	printf("|                                                |\n");
	printf("|               0. <�����ϲ�Ŀ¼>                |\n");
	printf("--------------------------------------------------\033[1;47;30m\n");
}

// ����Ŀ¼
void menu_1()
{
	//printf("\033[0mĬ������\033[0m\n");
	//printf("\033[1m��������\033[0m\n");
	printf("\033[1;46;37m--------------------------------------------------\n");
	printf("|                  ������Ϣ��ѯ                  |\n");
	printf("|------------------------------------------------|\n");
	printf("|                    ��������                    |\n");
	printf("|                                                |\n");
	printf("|               1.  [ ��    ѯ ]                 |\n");
	printf("|               2.  [ ������ ]                 |\n");
	printf("|               3.  [ ��    �� ]                 |\n");
	printf("|                                                |\n");
	printf("|               4. <  ���� �˳� >                |\n");
	printf("|               0. < �������˳� >                |\n");
	printf("--------------------------------------------------\033[1;47;30m\n");
}

//ö��ѡ��
enum Option_menu_1_1
{
	Back_menu_1,
	Add,
	Out,
	Delete,
	Change
};
enum Option_menu_1
{
	Exit_Witnout_Saving,
	Search,
	Manage_Function,
	About,
	Save
};

int main()
{
	system("@color 78");
	//��ʼ������ֵ
	int input_1 = 99;
	int input_1_1 = 99;
	//int templeinput = 1;//����input

	//������Դ�ռ�
	DN_SingleList* DN_sl = NULL;//����ָ��ռ�
	BC_SingleList* BC_sl = NULL;//����ָ��ռ�
	Base_Struct ptrq;//��Դ����
	//��ʼ��������ռ�
	InitResource(&ptrq, &DN_sl, &BC_sl);

	do
	{
		menu_1();//����Ŀ¼
		printf("��ѡ��:->");
		scanf("%d", &input_1);
		switch (input_1)
		{
		case Search: //��ѯ
			//function_underbuild();
			SeacrhResource(&ptrq, &DN_sl, &BC_sl);
			system("cls");
			break;
		case Exit_Witnout_Saving: //(������)�˳�
			Destorycontact(&ptrq, &DN_sl, &BC_sl);//�����ڴ�
			break;
		case Save: //����
			//function_underbuild();
			SaveResource(&ptrq, &DN_sl);
			Destorycontact(&ptrq, &DN_sl, &BC_sl);
			input_1 = 0;//ת���˳�
			break;
		case Manage_Function: //���� ������ Ŀ¼
			system("cls");
			do
			{
				menu_1_1();
				printf(" [������] ��ѡ��:->");
				scanf("%d", &input_1_1);
				switch (input_1_1)
				{
				case Add: //�������
					AddResource(&ptrq, &DN_sl, &BC_sl);
					system("cls");
					break;
				case Out: //��������
					function_underbuild();
					system("cls");
					break;
				case Change: //�޸�����
					ModifyResource(&ptrq, &DN_sl, &BC_sl);
					system("cls");
					break;
				case Delete: //ɾ������
					DelateResource(&ptrq, &DN_sl, &BC_sl);
					system("cls");
					break;
				case Back_menu_1: //�����ϼ�Ŀ¼
					system("cls");
					break;
				default:
					setbuf(stdin, NULL);//������뻺����
					input_error();
					break;
				}
			} while (input_1_1);
			break;
		case About: //����
			function_About();
			system("cls");
			break;
		default:
			setbuf(stdin, NULL);//������뻺����
			input_error();
			break;
		}
	}while (input_1);
	return 0;
}