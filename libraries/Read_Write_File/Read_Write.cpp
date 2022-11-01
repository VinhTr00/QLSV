#define _CRT_SECURE_NO_WARNINGS 
#include "Read_Write.h"

int readFile(SinhVien sv[], char path[]) {
	SinhVien sinhvien;
	int i = 0;
	FILE *fp = fopen(path, "r");

	while (fread(&sinhvien, sizeof(SinhVien), 1, fp)) {
		sv[i].age = sinhvien.age;
		sv[i].id = sinhvien.id;
		sv[i].entryPoint = sinhvien.entryPoint;
		sv[i].gpa = sinhvien.gpa;
		strcpy_s(sv[i].name, sinhvien.name);
		strcpy_s(sv[i].lastname, sinhvien.lastname);
		strcpy_s(sv[i].country, sinhvien.country);
		strcpy_s(sv[i].faculty, sinhvien.faculty);
		strcpy_s(sv[i].major, sinhvien.major);
		strcpy_s(sv[i].sex, sinhvien.sex);
		i++;
	}
	printf("\nTim thay %d sinh vien trong file\n", i);
	return i;	
}

int writeFile(SinhVien sv[], char path[], int numberStudent) {
	FILE* fp = fopen(path, "w");
	if (fp != NULL) {
		for (int i = 0; i < numberStudent; i++) {
			fwrite(&sv[i], sizeof(SinhVien), 1, fp);
		}
		fclose(fp);
		return 1;
	}
	return 0;
}