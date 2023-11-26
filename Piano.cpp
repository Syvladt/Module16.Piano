#include<iostream>
#include<string>

int main()
{
	enum note { DO = 1, RE = 2, MI = 4, FA = 8, SOL = 16, LA = 32, SI = 64 };
	setlocale(LC_ALL, "ru");
	std::string in_str = "", buffer;
	int melody[12], notes;
	bool success = true;
	std::cout << "������������ �������.\n";
	
	while (in_str.size() < 12)
	{
		std::cout << "������� ���������� ���: ";
		std::cin >> buffer;
		success = true;
		for (int j = 0; j < buffer.size(); ++j)
		{
			if (buffer[j] < '1' or buffer[j] > '7')
			{
				std::cout << "����� �������������� ����: " << buffer[j] << '.';
				success = false;
				std::cout << " ��������� ����\n";
			}
		}
		if (success)
			in_str += buffer;
	}
	if (in_str.size() > 12)
	{
		std::cout << "�������� ������ ������ 12, �������� ������ 12 ��������.\n";
		in_str = (in_str.substr(0, 12));
	}
	// �������� ������� �������
	for (int i = 0; i < 12; ++i)
	{
		melody[i] = in_str[i] - '0' - 1;
		notes = 1 << melody[i];
		if (notes & note::DO)
			std::cout << "DO";
		else if (notes & note::RE)
			std::cout << "RE";
		else if (notes & note::MI)
			std::cout << "MI";
		else if (notes & note::FA)
			std::cout << "FA";
		else if (notes & note::SOL)
			std::cout << "SOL";
		else if (notes & note::LA)
			std::cout << "LA";
		else 
			std::cout << "SI";
		std::cout << ' ';
	}
}
