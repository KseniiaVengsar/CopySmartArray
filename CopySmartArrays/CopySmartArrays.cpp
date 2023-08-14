// CopySmartArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//���������� �������� �����������. ��� �������� � ���� ������� �����������a ����������� and ��������a ������������

#include <iostream>
#include <exception>

class smart_array {
public:
      //�����������, ���������� ���������� ���������, ������� ����� ������� ������.
		//����� ������ ����������� ��������� ������
	smart_array(int size) {
		Size = size;
		very_smart_arr = new int[size];
		std::cout << "�������� ����������� " << this << std::endl;
	}
	
	~smart_array() {
		std::cout << "�������� ���������� " << this << std::endl;
		//����������� ������
		delete[] very_smart_arr;
	}
	// ����������� ����������� (�������� �����������)
	smart_array(const smart_array& other) {
		// ����������� ����� ������
		// �������� ����������� ������������ ��������
		this->Size = other.Size;
		this->very_smart_arr = new int[other.Size];

		for (int i = 0; i < other.Size; i++) {
		
			this->very_smart_arr[i] = other.very_smart_arr[i];
		}
		std::cout << "�������� ����������� ����������� " << this << std::endl;

	}
	int add_element(int new_element);
	int get_element(int index);

	// �������� ������������ (�������� �����������)
	smart_array& operator=(const smart_array& other) {
		std::cout << "�������� operator = " << this << std::endl;
		if (this != &other) {
			this->Size = other.Size;

			this->very_smart_arr = new int[other.Size];
			for (int i = 0; i < other.Size; i++) {
				this->very_smart_arr[i] = other.very_smart_arr[i];
			}
		}
		std::cout << "�������� ����������� ����������� " << this << std::endl;
		return *this;
	}
private:
	int Size;
	int* very_smart_arr;

};


int smart_array::add_element(int new_element) {
	//������� ���������� ������ �������� � ������. �� �������� ���������� ������, ����� ���������� ��������� ������ ���������� ���������, �� ������� �������� ������.
	//���� ������� �� ����� arr
	//����� ����������� ��������� ���������� ��� ��������� ������
	int newSize = Size + 1;
	//���� ����� ������ newArr � ����������� ��������.
	int* newArr = new int[newSize];

	// ����������� ��������� �� ��������� ������� � ����� ������
	for (int i = 0; i < Size; i++) {
		newArr[i] = very_smart_arr[i];
	}

	// ���������� ������ �������� � ����� ������ �������
	newArr[newSize - 1] = new_element;

	// ������������ ������, ���������� �������� ��������
	delete[] very_smart_arr;

	// ��������� very_smart_arr ����������� �� ����� ������ newArr
	very_smart_arr = newArr;
	//������ size ����������� �� newSize
	Size = newSize;

	return *newArr;

}
int smart_array::get_element(int index) {
	//������� ��������� �������� �� �������. �� �������� �������� �� ������������ �������.
	if (index >= 0 && index < Size) {
		// ������ ���������, ���������� � �������� �������
		int element = very_smart_arr[index];
		// ���������� �������� � ��������� �������
		return very_smart_arr[index];
		std::cout << "�����: " << very_smart_arr[index] << std::endl;
	}
	else {
		// ������ �����������, ����������� ����������
		throw std::out_of_range("������������ ������!");
	}

}

int main()
{
	setlocale(LC_ALL, "RU");
	//������ ������ ������ ����� �����, ������� ��������

	try {
		
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}
/*this - ��� ��������� �� ������� ������ ������, �� ������������ ��� ������� � ������ �������.

this->Size = size; ����������� ���������� Size �������� ������� �������� ��������� size, ����������� � �����������.

this->very_smart_arr = nullptr; ����������� ��������� very_smart_arr �������� nullptr, �� ���� ������� ���������, ��� ����������� ����, 
��� ���� ������ ��� �� ������� � �� ���������������.*/
/*���������� ������ ~smart_array() ����������� ������, ���������� ��� ������, ��� �������� ������� ������. ��� ��������� �������� ������ ������*/
/*� ��������� ������������ ��� ����� ������������� ��������, ����� ������������ ������ �������� ��������� ����� ������ ����: arr = arr;. 
������ ������ �������� ���������� ���������. � ���� ��������� �����, �� ������ ��� ��������� ������������ ������ �� ������ � ���������� ������ �� ����:

smart_array& smart_array::operator=(const smart_array& other) {
	if (this != &other) {
		//����� ���� ��������� ���:
		// ...
		
	}
	return *this;
}*/

//� ��������� ��������� ����������, ������ ��� ���������� �������������� ������������ �������� ������������, 
//������� ������ �������� ��� ���� ������ ������� �������. � ���������, �������� ��������� ��-�� ����������� 
//���������: ��� ������� ������ ����� ���������� ��������� �� ������� ������ � � ����� ������������ �������� 
//���������� ���. ���������� ������� ������������ ������.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
