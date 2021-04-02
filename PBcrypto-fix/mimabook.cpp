#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ctr1.h"
#include<Windows.h>



#define 增加数据	1
#define 修改数据	2
#define 删除数据	3
#define 查看数据	4
#define 查看所有	5
#define 输出所有	6
#define	退出 		7


char g_arrweb[300][20];
char g_arrname[300][20];
char g_arrpasswd[300][20];
int	g_num = 0;
int	nSelect = 0;
int	nOver = 1;


void AddData(char web[300][20], char username[300][20], char pass[300][20],int *number)
{
	printf("输入站点:");
	scanf_s("%s", web[*number], 20);
	printf("输入账号:");
	scanf_s("%s", username[*number], 20);
	printf("输入密码:");
	scanf_s("%s", pass[*number], 20);
	*number += 1;
}

void AlterDate(char web[300][20], char username[300][20], char pass[300][20], int number)
{
	char	szTemp[20] = { 0 };
	printf("输入要修改的站点\n");
	scanf_s("%s", szTemp, 20);
	int	nFind = 0;
	int	index = 0;
	for (; index < number; index++)
	{
		if (strcmp(szTemp, web[index]) == 0)
		{
			nFind = 1;
			break;
		}
	}

	if (1 == nFind)

	{
		printf("输入账号:\n");
		scanf_s("%s", username[index], 20);
		printf("输入密码:\n");
		scanf_s("%s", pass[index], 20);
		printf("修改成功 :) \n");
	}
	else
	{
		printf("删除失败,信息有误 :( \n");
	}
}

void DeleteDate(char web[300][20], char username[300][20], char pass[300][20], int* number)
{
	char sztemp[20] = { 0 };
	printf("请输入你要删除的站点:\n");
	scanf_s("%s", sztemp, 20);

	int nFind = 0;
	int nIndex = 0;
	for (; nIndex < *number; nIndex++)
	{

		if (strcmp(sztemp, web[nIndex]) == 0)
		{
			nFind = 1;
			break;
		}
	}
	if (1 == nFind)
	{
		int Loc = 0;
		for (int Loc = nIndex; Loc < *number - 1; Loc++)
		{
			strcpy_s(web[Loc], 20, web[Loc + 1]);
			strcpy_s(username[Loc], 20, username[Loc + 1]);
			strcpy_s(pass[Loc], 20, pass[Loc + 1]);
		}
	}
	*number-=1;
	printf("已删除");
	system("pause");

}

void ShowData(char web[300][20], char username[300][20], char pass[300][20], int number)
{
	char sztemp[20] = { 0 };
	printf("请输入你要查看的站点:\n");
	scanf_s("%s", sztemp, 20);

	int nFind = 0;
	int nIndex = 0;
	for (; nIndex < number; nIndex++)
	{

		if (strcmp(sztemp, web[nIndex]) == 0)
		{
			printf("站点%s\n", web[nIndex]);
			printf("用户名%s\n", username[nIndex]);
			printf("密码%s\n", pass[nIndex]);
			nFind = 1;
			break;
		}
	}
	if (nFind == 0)
	{
		printf("没有找到\n");
	}


}

void SaveData(char web[300][20], char username[300][20], char pass[300][20], int number)
{
	
	FILE* MMbook = NULL;
	errno_t err = fopen_s(&MMbook, "demo.bin", "wb+");
	//写入密码本个数
	fwrite(&number, sizeof(int), 1, MMbook);

	// 写入所有数据
	for (int i = 0; i < number; i++) {
			fwrite(web[i], sizeof(web[i]), 1, MMbook);
			fwrite(username[i], sizeof(username[i]), 1, MMbook);
			fwrite(pass[i], sizeof(pass[i]), 1, MMbook);
		}
	printf("写入成功\n");
	fclose(MMbook);
}

void ReadData(char web[300][20], char username[300][20], char pass[300][20], int* number) {

	FILE* MMbook = NULL;
	errno_t err = fopen_s(&MMbook, "demo.bin", "rb+");
	if (MMbook == NULL || err != 0)
	{
		*number = 0;
		return ;
	}
	//写入密码本个数
	fread(number, sizeof(int), 1, MMbook);

	// 写入所有数据
	for (int i = 0; i < *number; i++) {
		fread(web[i], sizeof(web[i]), 1, MMbook);
		fread(username[i], sizeof(username[i]), 1, MMbook);
		fread(pass[i], sizeof(pass[i]), 1, MMbook);
	}
	printf("读取成功\n");
	fclose(MMbook);

}

void ShowMenu()
{
	printf("-------------------------\n");
	printf("---------welcome---------\n");
	printf("-------------------------\n");
	printf("1.增加数据\n");
	printf("2.修改数据\n");
	printf("3.删除数据\n");
	printf("4.查看数据\n");
	printf("5.所有数据\n");
	printf("6.输出所有数据\n");
	printf("7.我不玩了（退出）\n");
	printf("请选择: ");
}

int	main()
{
	// 读取密码本
	ReadData(g_arrweb, g_arrname, g_arrpasswd, &g_num);
	int	nSelect = 0;
	int	nOver = 1;
	while (nOver) {
		ShowMenu();
		scanf_s("%d", &nSelect);
		switch (nSelect) {
			case 增加数据:
			{
				AddData(g_arrweb, g_arrname, g_arrpasswd, &g_num);
				break;
			}
			case 修改数据: {
				AlterDate(g_arrweb, g_arrname, g_arrpasswd, g_num);
				break;
			}
			case 删除数据: {
				DeleteDate(g_arrweb, g_arrname, g_arrpasswd, &g_num);
				break;
			}
			case 查看数据:
			{
				ShowData(g_arrweb, g_arrname, g_arrpasswd, g_num);
				break;
			}
			case 输出所有:
			{
				SaveData(g_arrweb, g_arrname, g_arrpasswd, g_num);
				break;
			}
			case 退出:
			{
				nOver = 0;
				break;
			}
		}
			system("pause");
			system("cls");
			if (0 == nSelect)
				return	0;

		}
}
	