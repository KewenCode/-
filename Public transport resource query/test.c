#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"

// ������Ŀ¼
void menu_1_1()
{
	printf("--------------------------------------------------\n");
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
	printf("--------------------------------------------------\n");
}

// ����Ŀ¼
void menu_1()
{
	printf("--------------------------------------------------\n");
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
	printf("--------------------------------------------------\n");
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
	//��ʼ������ֵ
	int input_1 = 0;
	int input_1_1 = 0;
	int templeinput = 1;//����input

	//������Դ�ռ�
	Base_Struct ptrq;//��Դ����
	Date_Name_arr dna;//����ָ��ռ�
	Date_Context_arr dca;//����ָ��ռ�
	//��ʼ��������ռ�
	InitResource(&ptrq, &dna, &dca);

	do
	{
		menu_1();//����Ŀ¼
		printf("��ѡ��:->");
		scanf("%d", &input_1);
		switch (input_1)
		{
		case Search:
			//��ѯ
			//function_underbuild();
			SeacrhResource(&ptrq, &dna, &dca);
			system("cls");
			break;
		case Exit_Witnout_Saving:
			//(������)�˳�
			//Destorycontact(&Base_1);//�����ڴ�
			break;
		case Save:
			//����
			//function_underbuild();
			//SaveResource(&Base_1);
			//Destorycontact(&Base_1);//�����ڴ�
			input_1 = 0;//ת���˳�
			break;
		case Manage_Function:
			//���� ������ Ŀ¼
			system("cls");
			do
			{
				menu_1_1();
				printf(" [������] ��ѡ��:->");
				scanf("%d", &input_1_1);
				switch (input_1_1)
				{
				case Add:
					//�������
					/*function_underbuild();*/
					AddResource(&ptrq, &dna, &dca);
					system("cls");
					break;
				case Out:
					//��������
					function_underbuild();
					system("cls");
					break;
				case Change:
					//�޸�����
					function_underbuild();
					//ModityResource(&Base_1);
					system("cls");
					break;
				case Delete:
					//ɾ������
					function_underbuild();
					//DelateResource(&Base_1);
					system("cls");
					break;
				case Back_menu_1:
					//�����ϼ�Ŀ¼
					system("cls");
					break;
				default:
					input_error();
					break;
				}
			} while (input_1_1);
			break;
		case About:
			//����
			function_About();
			system("cls");
			break;
		default:
			input_error();
			break;
		}
	}while (input_1);
	return 0;
}