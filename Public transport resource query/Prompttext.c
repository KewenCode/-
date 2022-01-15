#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"

// 输入错误反馈
void input_error()
{
	system("cls");
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf("          -----------------------------           \n");
	printf("          |   输入错误，请重新输入！  |           \n");
	printf("          |       3秒后自动返回       |           \n");
	printf("          -----------------------------           \n");
	Sleep(3000);
	system("cls");
}

// 功能暂未开放反馈
void function_underbuild()
{
	system("cls");
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf("          -----------------------------           \n");
	printf("          |  功能暂未开放，敬请期待！ |           \n");
	printf("          |       3秒后自动返回       |           \n");
	printf("          -----------------------------           \n");
	Sleep(3000);
	system("cls");
}