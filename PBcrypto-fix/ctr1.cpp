#include<stdio.h>
#include<string.h>
#include"ctr1.h"


void PrintAllInfo(char website[20][50], char mima[20][50], int nCount) {
	for (int i = 0; i < nCount; i++) {
		printf("վ��:%s ����:%s\n",website[i],mima[i]);
	}
}


void AddInfo(char website[20][50], char mima[20][50], int* pCount) {
	printf("����վ��:");
	scanf_s("%s",website[*pCount],50);
	printf("��������:");
	scanf_s("%s",mima[*pCount], 50);
	(*pCount)++;
}

void AlterInfo(char website[20][50], char mima[20][50], int nCount) {
	nCount++;
	printf("������Ҫ�޸ĵ�վ�㣺");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	int nFind = 0;
	for (int i = 0; i < nCount; i++) {
		if (strcmp(buf, website[i]) == 0) {
			printf("��������:");
			scanf_s("%s", mima[i], 50);
			nFind = 1;
		}
	}
}

void PrintOneInfo(char website[20][50], char mima[20][50], int nCount) {
	nCount++;
	int nFind = 0;
	printf("������ҵ�վ��:");
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
		printf("û��վ��");
	}
}

void DeleteInfo(char website[20][50], char mima[20][50], int* pCount) {
	printf("����ɾ��վ��:");
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