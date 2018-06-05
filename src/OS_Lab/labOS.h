// 
// Aswis
// v0.1
// 05/06/2018
// 
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include <iostream>
#include <fstream>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl

int sizeFile(char* fileName);
void coutFile(char* fileName);
void copyingFile(char* nameCopiedFile, char* nameCopy);


int sizeFile(char* fileName)
{
	FILE * pFile = fopen(fileName, "rb");
	int sizeFile;
	if (pFile == NULL) perror("Error open file");
	else
	{
		fseek ( pFile , 0 , SEEK_END );
		sizeFile = ftell (pFile);
		fseek ( pFile , 0 , SEEK_SET );
		sizeFile -= ftell (pFile);
		return sizeFile;
	}
	return 0;
}

void coutFile(char* fileName)
{
	int fileSize = sizeFile(fileName);
	char mass[fileSize];

	FILE * pFile = fopen(fileName, "rb");

	fread (mass,1,fileSize,pFile);

	for (int i = 0; i < fileSize; ++i)
	{
		cout<<mass[i];
	}
}

void copyingFile(char* nameCopiedFile, char* nameCopy)
{
	int copiedFileSize = sizeFile(nameCopiedFile);
	char dataOfCopiedFile[copiedFileSize];

	FILE * pCopiedFile = fopen(nameCopiedFile, "rb");
	if (pCopiedFile == NULL) perror("Error open file");
	else
	{
		fread (dataOfCopiedFile,1,copiedFileSize,pCopiedFile);
		fclose(pCopiedFile);
	}

	FILE * pNameCopy = fopen(nameCopy, "wb");
	if (pNameCopy == NULL) perror("Error open file");
	else
	{
		fwrite (dataOfCopiedFile , sizeof(char), sizeof(dataOfCopiedFile), pNameCopy);
		fclose(pNameCopy);
	}
}






















