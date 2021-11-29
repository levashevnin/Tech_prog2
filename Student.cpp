#include "Student.h"

Student::Student() : secondName("�� ������"), iniciales("�� ������"), numberGroup(0), isFellow(false), isDeduction(false)
{
	cout << "������ ����������� Student" << endl;
}

Student::Student(string secondName, string iniciales, int numberGroup, Marray<std::pair<string, int>> objects) :
	secondName(secondName), iniciales(iniciales), numberGroup(numberGroup), objects(objects)
{
	setStatus();
	cout << "������ ����������� Student" << endl;
}

Student::Student(const Student& student) : secondName(student.secondName), iniciales(student.iniciales),
numberGroup(student.numberGroup), objects(student.objects), isFellow(student.isFellow), isDeduction(student.isDeduction)
{
	cout << "������ ����������� ����������� Student" << endl;
}

Student::~Student()
{
	cout << "������ ���������� Student" << endl;
}

void Student::inputFromConsole()
{
	inputData("������� �������: ", secondName);
	inputData("������� ��������: ", iniciales);
	inputData("������� ����� ������: ", numberGroup, 0, INT32_MAX);
	inputObjects();
	setStatus();
}

void Student::printToConsole()
{
	cout << "���: " << secondName << " " << iniciales << endl;
	cout << "����� ������: " << numberGroup << endl;
	cout << "��������: ";
	for (int i = 0; i < objects.getSize(); i++)
		cout << i + 1 << ". " << objects[i].first << " " << objects[i].second << endl;
	if (isFellow)
		cout << "�� ���������" << endl;
	if (isDeduction)
		cout << "�� ����������" << endl;
}

void Student::change()
{
	std::string tmpString;
	int tmpInt = 0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. �������� �������" << std::endl;
		std::cout << "2. �������� ��������" << std::endl;
		std::cout << "3. �������� ����� ������" << std::endl;
		std::cout << "4. �������� �������" << std::endl;
		std::cout << "5. ������� ������ �� �����" << std::endl;
		std::cout << "0. ��������� ���������" << std::endl;
		std::cout << "�������� ����� ����: ";

		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			inputData("������� �������: ", secondName);
			break;
		case 2:
			inputData("������� ��������: ", iniciales);
			break;
		case 3:
			inputData("������� ����� ������: ", numberGroup, 0, INT32_MAX);
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
	inputData("������� ���������� ���������: ", countObjects, 1, INT32_MAX);
	for (int i = 0; i < countObjects; i++) {
		cout << "������� " << i + 1 << " �������: ";
		string tmp;
		getline(cin, tmp);
		cout << "������� ������ �� ����� ��������: ";
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