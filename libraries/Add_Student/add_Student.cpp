/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include "add_Student.h"
using namespace std;

extern void clean_stdin(void);

/* Private functions ---------------------------------------------------------*/
void addNewInformation(SinhVien& sv, int id) {
	cout << "\n Nhap ho va ten dem sinh vien: "; clean_stdin(); gets_s(sv.lastname);
	cout << "\n Nhap ten sinh vien: "; gets_s(sv.name);
	cout << "\n Nhap gioi tinh sinh vien (Male/Female/LGBT): "; gets_s(sv.sex); 
	cout << "\n Khoa dao tao cua sinh vien: "; gets_s(sv.faculty);
	cout << "\n Nganh dao tao cua sinh vien: "; gets_s(sv.major);
	cout << "\n Que quan cua sinh vien: "; gets_s(sv.country);
	cout << "\n Diem dau vao cua sinh vien: "; cin >> sv.entryPoint;	
	cout << "\n Diem trung binh cua sinh vien: "; cin >> sv.gpa;
	cout << "\n Nhap tuoi sinh vien: "; cin >> sv.age;
	sv.id = id;
	cout << "\n *** Them sinh vien thanh cong ***" << endl;
}

void addNewStudent(SinhVien sv[], int id, int numberStudent) {
	cout << "\n **** Nhap du lieu sinh vien thu " << numberStudent + 1 << " ****" << endl;
	addNewInformation(sv[numberStudent], id);
}

void showStudent(SinhVien sv[], int numberStudent) {
	printf("\n\STT\tID\tFirst Name\tLast Name\tAge\tSex\tCountry\t\tFaculty\t\tMajor\tEntryPoint\tGPA");
	for (int i = 0; i < numberStudent; i++) {
		printf("\n\ %d", i + 1);
		printf("\t%d", sv[i].id);
		printf("\t%s", sv[i].name);
		printf("\t%s", sv[i].lastname);
		printf("\t%d", sv[i].age);
		printf("\t%s", sv[i].sex);
		printf("\t%s", sv[i].country);
		printf("\t\t%s", sv[i].faculty);
		printf("\t\t%s", sv[i].major);
		printf("\t%.2f", sv[i].entryPoint);
		printf("\t\t%.2f", sv[i].gpa);
	}
}

int removeStudent(SinhVien sv[], int numberStudent) {
	cout << "Nhap MSSV muon xoa khoi danh sach" << endl;
	int MSSV;
	cin >> MSSV;
	bool flag = false;
	for (int i = 0; i < numberStudent; i++) {
		if (sv[i].id == MSSV) {
			flag = true;
			for (int j = i; j < numberStudent; j++) {
				sv[j] = sv[j + 1];
			}
			cout << "Da xoa sinh vien co ID: " << MSSV << endl;
			break;
		}
	}
	if (flag == false) {
		cout << "Khong tim thay sinh vien co ID: " << MSSV << endl;
		return 0;
	}
	else return 1;
}

void modifyStudent(SinhVien sv[], int numberStudent) {
	cout << "Nhap ID cua sinh vien muon thay doi thong tin" << endl;
	int ID;
	cin >> ID;
	for (int i = 0; i < numberStudent; i++) {
		if (sv[i].id == ID) {
			addNewInformation(sv[i], sv[i].id);
		}
		break;
	}
}

int maxID(SinhVien sv[], int numberStudent) {
	int max;
	if (numberStudent > 0) {
		max = sv[0].id;
		for (int i = 1; i < numberStudent; i++) {
			if (max < sv[i].id) max = sv[i].id;
		}
		return max;
	}
	return 0;
}
/************************ END OF FILE ************************/
