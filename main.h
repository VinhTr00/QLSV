#pragma once

#include <stdio.h>
#include <string.h>

#define MaxStudent 100

typedef struct SVien{
	char name[30];
	char lastname[30];
	char sex[10];
	char country[10];
	int age;
	char faculty[30];
	char major[30];
	float entryPoint;
	float gpa;
	int id;
} SinhVien;

void clean_stdin(void);



