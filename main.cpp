
#include <iostream>
#include "main.h"
#include "add_Student.h"
#include "sort_find_Student.h"
#include "Read_Write.h"

using namespace std;

void clean_stdin(void)
{
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

void pressAnyKey() {
	system("pause");
	system("cls");
}

int main() {
	SinhVien sinhvien[MaxStudent];
	int key;
	char path[] = "D:\\Visual Studio 2022/QLSV/QLSV.txt";
	int numberSV = readFile(sinhvien, path);
	int idSV = maxID(sinhvien, numberSV);
	while (1)
	{
		cout << "********************************************" << endl;
		cout << "**** 1. Them Sinh Vien                  ****" << endl;
		cout << "**** 2. Thong tin Sinh Vien             ****" << endl;
		cout << "**** 3. Xoa Sinh Vien                   ****" << endl;
		cout << "**** 4. Chinh sua thong tin Sinh Vien   ****" << endl;
		cout << "**** 5. Sap xep danh sach Sinh Vien     ****" << endl;
		cout << "**** 6. Tim kiem Sinh Vien              ****" << endl;
		cout << "**** 7. Viet du lieu sinh vien vao file ****" << endl;
		cout << "**** 8. Doc du lieu sinh vien tu file   ****" << endl;
		cout << "********************************************" << endl;
		cout << "Enter number: ";
		cin >> key;
		switch (key)
		{
		case 1:
			cout << "\n1. Them Sinh Vien" << endl;
			idSV++;
			addNewStudent(sinhvien, idSV, numberSV);
			numberSV++;
			pressAnyKey();
			break;
		case 2:
			cout << "\n2. Thong tin Sinh Vien" << endl;
			showStudent(sinhvien, numberSV);
			pressAnyKey();
			break;
		case 3:
			cout << "\n3. Xoa Sinh Vien" << endl;
			if (removeStudent(sinhvien, numberSV)) {
				numberSV--;
			}
			pressAnyKey();
			break;
		case 4:
			cout << "\n4. Chinh sua thong tin Sinh Vien" << endl;
			modifyStudent(sinhvien, numberSV);
			pressAnyKey();
			break;
		case 5:
			cout << "\n5. Sap xep danh sach Sinh Vien" << endl;
			sortStudent(sinhvien, numberSV);
			pressAnyKey();
			break;
		case 6:
			cout << "\n6. Tim kiem Sinh Vien" << endl;
			findStudent(sinhvien, numberSV);
			pressAnyKey();
			break;
		case 7:
			cout << "\n7. Viet du lieu sinh vien vao file" << endl;
			if (writeFile(sinhvien, path, numberSV)) cout << "OK !!!" << endl;
			else cout << "Error !!!" << endl;
			pressAnyKey();
			break;
		case 8:
			cout << "\n8. Doc du lieu sinh vien tu file" << endl;
			readFile(sinhvien, path);
			pressAnyKey();
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	}
	return 0;
}
