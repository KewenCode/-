#define _CRT_SECURE_NO_WARNINGS 1

#include "Resource.h"
#include "Prompttext.h"
#include "File.h"

// 管理功能目录
void menu_1_1()
{
	printf("\033[1;46;37m--------------------------------------------------\n");
	printf("|                  公交信息查询                  |\n");
	printf("|------------------------------------------------|\n");
	printf("|                    管理功能                    |\n");
	printf("|                                                |\n");
	printf("|               1.  [ 录入数据 ]                 |\n");
	printf("|               2.  [ 导出数据 ]                 |\n");
	printf("|               3.  [ 删除数据 ]                 |\n");
	printf("|               4.  [ 修改数据 ]                 |\n");
	printf("|                                                |\n");
	printf("|               0. <返回上层目录>                |\n");
	printf("--------------------------------------------------\033[1;47;30m\n");
}

// 基本目录
void menu_1()
{
	//printf("\033[0m默认文字\033[0m\n");
	//printf("\033[1m高亮文字\033[0m\n");
	printf("\033[1;46;37m--------------------------------------------------\n");
	printf("|                  公交信息查询                  |\n");
	printf("|------------------------------------------------|\n");
	printf("|                    基础功能                    |\n");
	printf("|                                                |\n");
	printf("|               1.  [ 查    询 ]                 |\n");
	printf("|               2.  [ 管理功能 ]                 |\n");
	printf("|               3.  [ 关    于 ]                 |\n");
	printf("|                                                |\n");
	printf("|               4. <  保存 退出 >                |\n");
	printf("|               0. < 不保存退出 >                |\n");
	printf("--------------------------------------------------\033[1;47;30m\n");
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
	About,
	Save
};

int main()
{
	system("@color 78");
	//初始化输入值
	int input_1 = 99;
	int input_1_1 = 99;
	//int templeinput = 1;//公用input

	//创建资源空间
	DN_SingleList* DN_sl = NULL;//名称指针空间
	BC_SingleList* BC_sl = NULL;//内容指针空间
	Base_Struct ptrq;//资源名称
	//初始化，申请空间
	InitResource(&ptrq, &DN_sl, &BC_sl);

	do
	{
		menu_1();//基本目录
		printf("请选择:->");
		scanf("%d", &input_1);
		switch (input_1)
		{
		case Search: //查询
			//function_underbuild();
			SeacrhResource(&ptrq, &DN_sl, &BC_sl);
			system("cls");
			break;
		case Exit_Witnout_Saving: //(不保存)退出
			Destorycontact(&ptrq, &DN_sl, &BC_sl);//销毁内存
			break;
		case Save: //保存
			//function_underbuild();
			SaveResource(&ptrq, &DN_sl);
			Destorycontact(&ptrq, &DN_sl, &BC_sl);
			input_1 = 0;//转到退出
			break;
		case Manage_Function: //进入 管理功能 目录
			system("cls");
			do
			{
				menu_1_1();
				printf(" [管理功能] 请选择:->");
				scanf("%d", &input_1_1);
				switch (input_1_1)
				{
				case Add: //添加数据
					AddResource(&ptrq, &DN_sl, &BC_sl);
					system("cls");
					break;
				case Out: //导出数据
					function_underbuild();
					system("cls");
					break;
				case Change: //修改数据
					ModifyResource(&ptrq, &DN_sl, &BC_sl);
					system("cls");
					break;
				case Delete: //删除数据
					DelateResource(&ptrq, &DN_sl, &BC_sl);
					system("cls");
					break;
				case Back_menu_1: //返回上级目录
					system("cls");
					break;
				default:
					setbuf(stdin, NULL);//清空输入缓存区
					input_error();
					break;
				}
			} while (input_1_1);
			break;
		case About: //关于
			function_About();
			system("cls");
			break;
		default:
			setbuf(stdin, NULL);//清空输入缓存区
			input_error();
			break;
		}
	}while (input_1);
	return 0;
}