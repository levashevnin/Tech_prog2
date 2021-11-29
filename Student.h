#pragma once
#include "helper.h"
#include "Marray.h"
using namespace std;

class Student
{
private:
	string secondName, iniciales;
	int numberGroup;
	Marray<std::pair<string, int>> objects;

	void inputObjects();
public:
	Student();
	Student(string secondName, string iniciales, int numberGroup, Marray<std::pair<string, int>> objects);
	Student(const Student& student);
	~Student();

	void inputFromConsole();
	void printToConsole();
	void change();

	string getSecondName() { return secondName; }
	void setSecondName(string secondName) { this->secondName = secondName; }

	string getIniciales() { return iniciales; }
	void setIniciales(string iniciales) { this->iniciales = iniciales; }

	int getNumberGroup() { return numberGroup; }
	void setNumberGroup(int numberGroup) { this->numberGroup = numberGroup; }

	Marray<std::pair<string, int>> gettObjects() { return objects; }
	void setObjects(Marray<std::pair<string, int>>& objects) { this->objects = objects; }

	double getAverageMark();

	Student& operator=(const Student& student);
	bool operator>(Student& student);
};
