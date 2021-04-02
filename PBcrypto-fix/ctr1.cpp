#include<stdio.h>
#include<string.h>
#include"ctr1.h"


void PrintAllInfo(char website[20][50], char mima[20][50], int nCount) {
	for (int i = 0; i < nCount; i++) {
		printf("站点:%s 密码:%s\n",website[i],mima[i]);
	}
}


void AddInfo(char website[20][50], char mima[20][50], int* pCount) {
	printf("输入站点:");
	scanf_s("%s",website[*pCount],50);
	printf("输入密码:");
	scanf_s("%s",mima[*pCount], 50);
	(*pCount)++;
}

void AlterInfo(char website[20][50], char mima[20][50], int nCount) {
	nCount++;
	printf("输入你要修改的站点：");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	int nFind = 0;
	for (int i = 0; i < nCount; i++) {
		if (strcmp(buf, website[i]) == 0) {
			printf("输入密码:");
			scanf_s("%s", mima[i], 50);
			nFind = 1;
		}
	}
}

void PrintOneInfo(char website[20][50], char mima[20][50], int nCount) {
	nCount++;
	int nFind = 0;
	printf("输入查找的站点:");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	nFind = 0;
	for (int i = 0; i < nCount; i++) {
		if (strcmp(buf, website[i]) == 0) {
			printf("%s %s",website[i],mima[i]);
			nFind = 1;
		}
	}
	if (nFind == 0) {
		printf("没有站点");
	}
}

void DeleteInfo(char website[20][50], char mima[20][50], int* pCount) {
	printf("输入删除站点:");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	for (int i = 0; i < *pCount; i++)
	{
		if (strcmp(buf, website[i]) == 0) {
			for (int j = i; j < *pCount; j++) {
				strcpy_s(website[j], 50, website[j + 1]);
				strcpy_s(mima[j], 50, mima[j + 1]);
			}
		}
	}
	*pCount = *pCount - 1;

}