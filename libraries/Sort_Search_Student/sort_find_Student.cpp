/* Includes ------------------------------------------------------------------*/
#include "add_Student.h"
#include "sort_find_Student.h"
#include <iostream>

using namespace std;

extern void clean_stdin(void);

/* PRIVATE FUNCTION */

// Sort from low to high bye Age
void sort_L_to_H(SinhVien sv[], int numberStudent)
{
	SinhVien temp;
	for (int i = 0; i < numberStudent - 1; i++)
	{
		for (int j = i + 1; j < numberStudent; j++)
		{
			if (sv[i].age > sv[j].age)
			{
				temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}
}

// Sort from high to low bye Age
void sort_H_to_L(SinhVien sv[], int numberStudent)
{
	SinhVien temp;
	for (int i = 0; i < numberStudent - 1; i++)
	{
		for (int j = i + 1; j < numberStudent; j++)
		{
			if (sv[i].age < sv[j].age)
			{
				temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}
}

// Convert to uppercase
// If the first letter is lowercase, convert it to uppercase
void upper(char chr[], int count)
{

	for (int i = 0; i < count; i++)
	{
		if ('a' <= chr[i] && chr[i] <= 'z')
		{
			chr[i] = chr[i] + ((int)('A') - (int)('a'));
		}
	}
}

/* ---- SORT STUDENT FUNCTION ---- */
void sortStudentbyAge(SinhVien sv[], int numberStudent)
{
	// Print selection mode
	cout << "**********************************" << endl;
	cout << "**** Hay chon che do sap xep  ****" << endl;
	cout << "**** Mode 1: Low to High      ****" << endl;
	cout << "**** Mode 2: High to Low      ****" << endl;
	cout << "**********************************" << endl;
	cout << "Enter your mode: ";
	int mode;
	cin >> mode;
	
	// Check mode
	switch (mode)
	{
	case 1:
		sort_L_to_H(sv, numberStudent);
		break;
	case 2:
		sort_H_to_L(sv, numberStudent);
		break;
	default:
		cout << "Wrong choice" << endl;
		break;
	}
}

// Sort student by name
void sortStudentbyName(SinhVien sv[], int numberStudent)
{
	cout << " Sap xep ten theo bang chu cai " << endl;
	SinhVien tempSV;
	char nameSV[30];
	char nameSV2[30];

	// Sort by name
	for (int i = 0; i < numberStudent - 1; i++)
	{
		strcpy_s(nameSV, sv[i].name); // Copy name of student i to nameSV
		for (int j = i + 1; j < numberStudent; j++)
		{
			strcpy_s(nameSV2, sv[j].name); // Copy name of student j to nameSV2
			upper(nameSV2, sizeof(nameSV2)); 
			upper(nameSV, sizeof(nameSV));
			// Compare nameSV and nameSV2
			if (strcmp(nameSV, nameSV2) > 0)
			{
				tempSV = sv[i];
				sv[i] = sv[j];
				sv[j] = tempSV;
			}
		}
	}
}

// Sort student by Age	
void sortStudent(SinhVien sv[], int numberStudent)
{
	// Print selection mode
	cout << "***************************************" << endl;
	cout << "**** Hay chon che do sap xep      	****" << endl;
	cout << "**** Mode 1: Sap xep theo tuoi     ****" << endl;
	cout << "**** Mode 2: Sap xep theo ten      ****" << endl;
	cout << "***************************************" << endl;
	cout << "Enter your mode: ";
	int mode;
	cin >> mode;

	// Check mode
	switch (mode)
	{
	case 1:
		sortStudentbyAge(sv, numberStudent);
		break;
	case 2:
		sortStudentbyName(sv, numberStudent);
		break;
	default:
		break;
	}
	showStudent(sv, numberStudent);
}

/* ---- FIND STUDENT FUNCTION ---- */
// Find student by Name
void findStudentbyName(SinhVien sv[], int numberStudent)
{
	cout << "**** Hay nhap ten sinh vien muon tim kiem ****" << endl;
	SinhVien arrayTemp[MaxStudent]; // Array temp to save student
	char nameSV[30];
	char nameSV2[30];
	int count = 0;
	cout << "Enter name: ";
	clean_stdin();
	gets_s(nameSV); // Get name student
	upper(nameSV, sizeof(nameSV));
	// Find student
	for (int i = 0; i < numberStudent; i++)
	{
		strcpy_s(nameSV2, sv[i].name);
		upper(nameSV2, sizeof(nameSV2));
		if (strstr(nameSV2, nameSV))
		{
			arrayTemp[count] = sv[i];
			count++;
		}
	}
	cout << "**** Tim thay " << count << " sinh vien ****" << endl;
	showStudent(arrayTemp, count); // Show student
}

// Find student by Age
void findStudentbyAge(SinhVien sv[], int numberStudent)
{
	cout << "**** Hay nhap tuoi sinh vien muon tim kiem ****" << endl;
	int age;
	SinhVien arrayTemp[MaxStudent];
	int count = 0;
	cin >> age;
	for (int i = 0; i < numberStudent; i++)
	{
		if (sv[i].age == age)
		{
			arrayTemp[count] = sv[i];
			count++;
		}
	}
	cout << "**** Tim thay " << count << " sinh vien ****" << endl;
	showStudent(arrayTemp, count);
}

// Find student
void findStudent(SinhVien sv[], int numberStudent)
{
	cout << "**********************************" << endl;
	cout << "**** Hay chon che do tim kiem ****" << endl;
	cout << "**** 1. Tim kiem theo ten     ****" << endl;
	cout << "**** 2. Tim kiem theo tuoi    ****" << endl;
	cout << "**********************************" << endl;
	cout << "Enter your mode: ";
	int mode;
	cin >> mode;
	switch (mode)
	{
	case 1:
		findStudentbyName(sv, numberStudent);
		break;
	case 2:
		findStudentbyAge(sv, numberStudent);
		break;
	default:
		break;
	}
}
/* END OF FILE ------------------------------------------------------------------*/
