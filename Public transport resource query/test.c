#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)//忽略vs中scanf报错的nc行为

#include "Prompttext.h"
#include "Resource.h"

// 管理功能目录
void menu_1_1()
{
	printf("--------------------------------------------------\n");
	printf("|                  公交信息查询                  |\n");
	printf("|------------------------------------------------|\n");
	printf("|                    管理功能                    |\n");
	printf("|                                                |\n");
	printf("|              1.  [ 导入 数据 ]                 |\n");
	printf("|              2.  [ 导出 数据 ]                 |\n");
	printf("|              3.  [ 删除 数据 ]                 |\n");
	printf("|              4.  [ 修改 数据 ]                 |\n");
	printf("|                                                |\n");
	printf("|              0. < 返回上层目录 >               |\n");
	printf("--------------------------------------------------\n");
}

// 基本目录
void menu_1()
{
	printf("--------------------------------------------------\n");
	printf("|                  公交信息查询                  |\n");
	printf("|------------------------------------------------|\n");
	printf("|                    基础功能                    |\n");
	printf("|                                                |\n");
	printf("|               1.   [ 查 询 ]                   |\n");
	printf("|               2.  [ 管理功能 ]                 |\n");
	printf("|                                                |\n");
	printf("|               3.  < 保存退出 >                 |\n");
	printf("|               0. < 不保存退出 >                |\n");
	printf("--------------------------------------------------\n");
}

//枚举选择
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
	Save
};

int main()
{
	//初始化输入值
	int input_1 = 0;
	int input_1_1 = 0;

	//创建资源空间
	Date_Base Base_1;//资源名称
	//初始化，申请空间
	InitResource(&Base_1);
	
	do
	{
		menu_1();//基本目录
		printf("请选择:->");
		scanf("%d", &input_1);
		switch (input_1)
		{
		case Search:
			//查询
			function_underbuild();
			system("cls");
			break;
		case Exit_Witnout_Saving:
			//(不保存)退出
			//                 ！！！需要销毁内存！！！
			break;
		case Save:
			//保存退出
			function_underbuild();
			//                 ！！！需要销毁内存！！！
			input_1 = 0;
			break;
		case Manage_Function:
			//进入 管理功能 目录
			system("cls");
			do
			{
				menu_1_1();
				printf(" [管理功能] 请选择:->");
				scanf("%d", &input_1_1);
				switch (input_1_1)
				{
				case Add:
					//添加数据
					function_underbuild();
					/*AddResource(&Base_1);*/
					system("cls");
					break;
				case Out:
					//导出数据
					function_underbuild();
					system("cls");
					break;
				case Change:
					//修改数据
					function_underbuild();
					system("cls");
					break;
				case Delete:
					//删除数据
					function_underbuild();
					system("cls");
					break;
				case Back_menu_1:
					//返回上级目录
					system("cls");
					break;
				default:
					input_error();
					break;
				}
			} while (input_1_1);
			break;
		default:
			input_error();
			break;
		}
	}while (input_1);
	return 0;
}