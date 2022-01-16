#define _CRT_SECURE_NO_WARNINGS 1

#include "Prompttext.h"

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
	printf("请输入：\n");
}

//情况反馈
void function_over()
{
	printf("正常 正常 正常\n");
	Sleep(3000);
}
