#define _CRT_SECURE_NO_WARNINGS 1

#include "Prompttext.h"

//#define function_printf(X,FORMAT) printf("当前参数："#X" 值："FORMAT"\n"，X);

//倒计时组件
//void Countdown()
//{
//	int time = 3;
//	while (time)
//	{
//		system("cls");
//		printf("倒计时：%d", time);
//		Sleep(1000);
//		time--;
//	}
//}

// 输入错误反馈
void input_error()
{
	system("cls");
	printf(" \n");
	printf(" \n");
	printf(" \n");
	printf("          -----------------------------           \n");
	printf("          |   输入错误，请重新输入！  |           \n");
	printf("          |       2秒后自动返回       |           \n");
	printf("          -----------------------------           \n");
	Sleep(2000);
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

// 成功反馈 - 待修复
void function_success()
{
	printf("          -----------------------------           \n");
	printf("          |         成功完成！        |           \n");
	printf("          -----------------------------           \n");
	Sleep(3000);
}

// 继续反馈 - 待修复
void function_countion()
{
	printf(" \n");
	printf("          -----------------------------           \n");
	printf("          |      再次使用本功能？     |           \n");
	printf("          |                           |           \n");
	printf("          |        1. [ 确定 ]        |           \n");
	printf("          |    0. < 返回上层目录 >    |           \n");
	printf("          |                           |           \n");
	printf("          -----------------------------           \n");
}

//情况反馈
void function_over()
{
	printf("正常 正常 正常\n");
	Sleep(3000);
}

//关于
void function_About()
{
	printf("        -----------------------------------       \n");
	printf("        文件版本(FileVersion):"); 
	printf("%s", FileVersion);
	printf("\n");
	printf("        发布版本(ProductVersion):");
	printf("%s", ProductVersion);
	printf("\n");
	printf("        -----------------------------------       \n");
	system("pause");
}