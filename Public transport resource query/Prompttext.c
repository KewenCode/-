#define _CRT_SECURE_NO_WARNINGS 1

#include "Prompttext.h"

//#define function_printf(X,FORMAT) printf("��ǰ������"#X" ֵ��"FORMAT"\n"��X);

//����ʱ���
//void Countdown()
//{
//	int time = 3;
//	while (time)
//	{
//		system("cls");
//		printf("����ʱ��%d", time);
//		Sleep(1000);
//		time--;
//	}
//}

// ���������
void input_error()
{
	system("cls");
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf("          -----------------------------           \n");
	printf("          |   ����������������룡  |           \n");
	printf("          |       2����Զ�����       |           \n");
	printf("          -----------------------------           \n");
	Sleep(2000);
	system("cls");
}

// ������δ���ŷ���
void function_underbuild()
{
	system("cls");
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf("          -----------------------------           \n");
	printf("          |  ������δ���ţ������ڴ��� |           \n");
	printf("          |       3����Զ�����       |           \n");
	printf("          -----------------------------           \n");
	Sleep(3000);
	system("cls");
}

// �ɹ����� - ���޸�
void function_success()
{
	printf("          -----------------------------           \n");
	printf("          |         �ɹ���ɣ�        |           \n");
	printf("          -----------------------------           \n");
	Sleep(3000);
}

// �������� - ���޸�
void function_countion()
{
	printf(" \n");
	printf("          -----------------------------           \n");
	printf("          |      �ٴ�ʹ�ñ����ܣ�     |           \n");
	printf("          |                           |           \n");
	printf("          |        1. [ ȷ�� ]        |           \n");
	printf("          |    0. < �����ϲ�Ŀ¼ >    |           \n");
	printf("          |                           |           \n");
	printf("          -----------------------------           \n");
}

//�������
void function_over()
{
	printf("���� ���� ����\n");
	Sleep(3000);
}

//����
void function_About()
{
	printf("        -----------------------------------       \n");
	printf("        �ļ��汾(FileVersion):"); 
	printf("%s", FileVersion);
	printf("\n");
	printf("        �����汾(ProductVersion):");
	printf("%s", ProductVersion);
	printf("\n");
	printf("        -----------------------------------       \n");
	system("pause");
}