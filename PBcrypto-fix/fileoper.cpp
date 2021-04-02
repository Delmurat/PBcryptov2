#include<stdio.h>
#include"fileoper.h"

void ReadMimaInfo(char website[20][50], char mima[20][50], int* pCount) {
	FILE* pFile = NULL;
	int nError = fopen_s(
		&pFile,
		"mima_file.a",
		"rb+"
	);

	/*
	int i,j;
	i = 0;
	j = 0;

	for (int j = 0; j < sizeof(char mima[20][50]); j++)
	{
		char mima[20][50] += 10;
	}
	for (int j = 0; j < sizeof(char mima[20][50]); j++)
	{
		char mima[20][50] += 10;
	}

	for (int j = 0; j < sizeof(char mima[i]); j++)
	{
		char mima[20][50] += 10;
	}

	*/

	


	if (nError != 0) {
		return;
	}
	int nNum = 0;
	fread(
		&nNum,
		4,
		1,
		pFile)
		;
	*pCount = nNum;
	fread(
		website,
		50 * 20,
		1,
		pFile
	);

	fread(
		mima,
		50 * 20,
		1,
		pFile
	);
	fclose(pFile);
}


/*

void SaveFile(char website[20][50], char mima[20][50], int	nCount);{
	FILE* pFILE, =NULL;
	int nError = fopen_s(
		&pFile,
		"mima_file.a",
		"wb+"
	);
	if (nError != 0) {
		return;
	}
	fwrite(
		&pCount,
		4,
		1,
		pFile
		);
	fwrite(
		mima,
		50,
		20,
		pFile
	);

	fclose(pFile);
	*/

