#include "Student.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Student>& students);
void changeObject(Marray<Student>& students);
void deleteObject(Marray<Student>& students);
void print(Marray<Student>& students);
void searchObjects(Marray<Student>& students);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Student> students;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			addObject(students);
			break;
		case 2:
			changeObject(students);
			break;
		case 3:
			deleteObject(students);
			break;
		case 4:
			print(students);
			break;
		case 5:
			searchObjects(students);
			break;
		case 6:
			students.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. Добавить студента" << endl;
	cout << "2. Изменить студента" << endl;
	cout << "3. Удалить студента" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "5. Вывести фамилии стдентов и номера групп, имеющих хотябы одну 2" << endl;
	cout << "6. Отсортировать студентов по возрастанию среднего балла" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Marray<Student>& students) {
	Student student;
	student.inputFromConsole();
	students += student;
}

void changeObject(Marray<Student>& students) {
	if (students.getSize() > 0) {
		print(students);
		cout << "Введите номер студента для изменения: ";
		students[safeInput(1, students.getSize()) - 1].change();
	}
	else
		cout << "Список студентов пуст. Нечего изменять\n";
}

void deleteObject(Marray<Student>& students) {
	if (students.getSize() > 0) {
		print(students);
		cout << "Введите номер студента для удаления: ";
		students -= safeInput(1, students.getSize()) - 1;
	}
	else
		cout << "Список студентов пуст. Нечего удалять\n";
}

void print(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "Список студентов пуст.\n";
	else {
		cout << "Список студентов\n";
		for (int i = 0; i < students.getSize(); i++) {
			cout << i + 1 << ". Студент\n";
			students[i].printToConsole();
		}
	}
}

void searchObjects(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "Список студентов пуст\n";
	else {
		bool isPrint = false;
		for (int i = 0; i < students.getSize(); i++) {
			Marray<pair<string, int>> objects = students[i].gettObjects();
			for (int j = 0; j < objects.getSize(); j++)
				if (objects[j].second == 2) {
					isPrint = true;
					cout << students[i].getNumberGroup() << " " << students[i].getSecondName() << endl;
				}
		}

		if (!isPrint)
			cout << "Студентов хотя бы с одной 2 нет\n";
	}
}