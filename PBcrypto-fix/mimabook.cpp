#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ctr1.h"
#include<Windows.h>



#define ��������	1
#define �޸�����	2
#define ɾ������	3
#define �鿴����	4
#define �鿴����	5
#define �������	6
#define	�˳� 		7


char g_arrweb[300][20];
char g_arrname[300][20];
char g_arrpasswd[300][20];
int	g_num = 0;
int	nSelect = 0;
int	nOver = 1;


void AddData(char web[300][20], char username[300][20], char pass[300][20],int *number)
{
	printf("����վ��:");
	scanf_s("%s", web[*number], 20);
	printf("�����˺�:");
	scanf_s("%s", username[*number], 20);
	printf("��������:");
	scanf_s("%s", pass[*number], 20);
	*number += 1;
}

void AlterDate(char web[300][20], char username[300][20], char pass[300][20], int number)
{
	char	szTemp[20] = { 0 };
	printf("����Ҫ�޸ĵ�վ��\n");
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
		printf("�����˺�:\n");
		scanf_s("%s", username[index], 20);
		printf("��������:\n");
		scanf_s("%s", pass[index], 20);
		printf("�޸ĳɹ� :) \n");
	}
	else
	{
		printf("ɾ��ʧ��,��Ϣ���� :( \n");
	}
}

void DeleteDate(char web[300][20], char username[300][20], char pass[300][20], int* number)
{
	char sztemp[20] = { 0 };
	printf("��������Ҫɾ����վ��:\n");
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
	printf("��ɾ��");
	system("pause");

}

void ShowData(char web[300][20], char username[300][20], char pass[300][20], int number)
{
	char sztemp[20] = { 0 };
	printf("��������Ҫ�鿴��վ��:\n");
	scanf_s("%s", sztemp, 20);

	int nFind = 0;
	int nIndex = 0;
	for (; nIndex < number; nIndex++)
	{

		if (strcmp(sztemp, web[nIndex]) == 0)
		{
			printf("վ��%s\n", web[nIndex]);
			printf("�û���%s\n", username[nIndex]);
			printf("����%s\n", pass[nIndex]);
			nFind = 1;
			break;
		}
	}
	if (nFind == 0)
	{
		printf("û���ҵ�\n");
	}


}

void SaveData(char web[300][20], char username[300][20], char pass[300][20], int number)
{
	
	FILE* MMbook = NULL;
	errno_t err = fopen_s(&MMbook, "demo.bin", "wb+");
	//д�����뱾����
	fwrite(&number, sizeof(int), 1, MMbook);

	// д����������
	for (int i = 0; i < number; i++) {
			fwrite(web[i], sizeof(web[i]), 1, MMbook);
			fwrite(username[i], sizeof(username[i]), 1, MMbook);
			fwrite(pass[i], sizeof(pass[i]), 1, MMbook);
		}
	printf("д��ɹ�\n");
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
	//д�����뱾����
	fread(number, sizeof(int), 1, MMbook);

	// д����������
	for (int i = 0; i < *number; i++) {
		fread(web[i], sizeof(web[i]), 1, MMbook);
		fread(username[i], sizeof(username[i]), 1, MMbook);
		fread(pass[i], sizeof(pass[i]), 1, MMbook);
	}
	printf("��ȡ�ɹ�\n");
	fclose(MMbook);

}

void ShowMenu()
{
	printf("-------------------------\n");
	printf("---------welcome---------\n");
	printf("-------------------------\n");
	printf("1.��������\n");
	printf("2.�޸�����\n");
	printf("3.ɾ������\n");
	printf("4.�鿴����\n");
	printf("5.��������\n");
	printf("6.�����������\n");
	printf("7.�Ҳ����ˣ��˳���\n");
	printf("��ѡ��: ");
}

int	main()
{
	// ��ȡ���뱾
	ReadData(g_arrweb, g_arrname, g_arrpasswd, &g_num);
	int	nSelect = 0;
	int	nOver = 1;
	while (nOver) {
		ShowMenu();
		scanf_s("%d", &nSelect);
		switch (nSelect) {
			case ��������:
			{
				AddData(g_arrweb, g_arrname, g_arrpasswd, &g_num);
				break;
			}
			case �޸�����: {
				AlterDate(g_arrweb, g_arrname, g_arrpasswd, g_num);
				break;
			}
			case ɾ������: {
				DeleteDate(g_arrweb, g_arrname, g_arrpasswd, &g_num);
				break;
			}
			case �鿴����:
			{
				ShowData(g_arrweb, g_arrname, g_arrpasswd, g_num);
				break;
			}
			case �������:
			{
				SaveData(g_arrweb, g_arrname, g_arrpasswd, g_num);
				break;
			}
			case �˳�:
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
	