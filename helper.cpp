#include "helper.h"

bool checkChar(const char& ch) {
	return isalpha(ch) && !islower(ch);
}

bool checkStringToIniciales(std::string s) {
	return s.size() == 4 && checkChar(s[0]) && s[1] == '.' && checkChar(s[2]) && s[3] == '.';
}

std::string inputIniciales() {
	std::string years;
	while (true) {
		std::cin >> years;
		if (!checkStringToIniciales(years))
			std::cout << "�������� ����.\n��������� �����: " << std::endl;
		else
			return years;
	}
}

void inputData(std::string help, std::string& data) {
	std::cout << help;
	getline(std::cin, data);
	while (data.size() < 1) {
		std::cout << "������ �� ������ ���� ������. ������� ��������: ";
		getline(std::cin, data);
	}
}