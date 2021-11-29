#include "Student.h"

Student::Student() : secondName("Не задано"), iniciales("Не задано"), numberGroup(0), isFellow(false), isDeduction(false)
{
	cout << "Вызван конструктор Student" << endl;
}

Student::Student(string secondName, string iniciales, int numberGroup, Marray<std::pair<string, int>> objects) :
	secondName(secondName), iniciales(iniciales), numberGroup(numberGroup), objects(objects)
{
	setStatus();
	cout << "Вызван конструктор Student" << endl;
}

Student::Student(const Student& student) : secondName(student.secondName), iniciales(student.iniciales),
numberGroup(student.numberGroup), objects(student.objects), isFellow(student.isFellow), isDeduction(student.isDeduction)
{
	cout << "Вызван конструктор копирования Student" << endl;
}

Student::~Student()
{
	cout << "Вызван деструктор Student" << endl;
}

void Student::inputFromConsole()
{
	inputData("Введите фамилию: ", secondName);
	inputData("Введите инициалы: ", iniciales);
	inputData("Введите номер группы: ", numberGroup, 0, INT32_MAX);
	inputObjects();
	setStatus();
}

void Student::printToConsole()
{
	cout << "ФИО: " << secondName << " " << iniciales << endl;
	cout << "Номер группы: " << numberGroup << endl;
	cout << "Предметы: ";
	for (int i = 0; i < objects.getSize(); i++)
		cout << i + 1 << ". " << objects[i].first << " " << objects[i].second << endl;
	if (isFellow)
		cout << "На стипендии" << endl;
	if (isDeduction)
		cout << "На отчисление" << endl;
}

void Student::change()
{
	std::string tmpString;
	int tmpInt = 0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. Изменить фамилию" << std::endl;
		std::cout << "2. Изменить инициалы" << std::endl;
		std::cout << "3. Изменить номер группы" << std::endl;
		std::cout << "4. Изменить предеты" << std::endl;
		std::cout << "5. Вывести данные на экран" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			inputData("Введите фамилию: ", secondName);
			break;
		case 2:
			inputData("Введите инициалы: ", iniciales);
			break;
		case 3:
			inputData("Введите номер группы: ", numberGroup, 0, INT32_MAX);
			break;
		case 4:
			inputObjects();
			setStatus();
			break;
		case 6:
			printToConsole();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

double Student::getAverageMark() {
	int sum = 0;
	for (int i = 0; i < objects.getSize(); i++)
		sum += objects[i].second;
	return double(sum) / double(objects.getSize());
}

Student& Student::operator=(const Student& student) {
	if (this == &student)
		return *this;
	secondName = student.secondName;
	iniciales = student.iniciales;
	numberGroup = student.numberGroup;
	objects = student.objects;
	isFellow = student.isFellow;
	isDeduction = student.isDeduction;
	return *this;
}

bool Student::operator>(Student& student) {
	return getAverageMark() > student.getAverageMark();
}

void Student::inputObjects() {
	objects.clear();
	int countObjects;
	inputData("Введите количество предметов: ", countObjects, 1, INT32_MAX);
	for (int i = 0; i < countObjects; i++) {
		cout << "Введите " << i + 1 << " предмет: ";
		string tmp;
		getline(cin, tmp);
		cout << "Введите оценку по этому предмету: ";
		objects += make_pair(tmp, safeInput(2, 5));
	}
	setStatus();
}

void Student::setStatus() {
	isFellow = false;
	isDeduction = false;
	int countMarks[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < objects.getSize(); i++)
		countMarks[objects[i].second - 2]++;
	if (countMarks[0] > 2)
		isDeduction = true;
	if (countMarks[0] == 0 && countMarks[1] == 0)
		isFellow = true;
}