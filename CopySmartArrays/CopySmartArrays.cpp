// CopySmartArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//необходимо глубокое копирование. оно включает в себя наличие Конструкторa копирования and Операторa присваивания

#include <iostream>
#include <exception>

class smart_array {
public:
      //Конструктор, принмающий количество элементов, которое будет хранить массив.
		//здесь должно происходить выделение памяти
	smart_array(int size) {
		Size = size;
		very_smart_arr = new int[size];
		std::cout << "Вызвался конструктор " << this << std::endl;
	}
	
	~smart_array() {
		std::cout << "Вызвался деструктор " << this << std::endl;
		//освобождаем память
		delete[] very_smart_arr;
	}
	// Конструктор копирования (глубокое копирование)
	smart_array(const smart_array& other) {
		// Копирование полей класса
		// Глубокое копирование динамических ресурсов
		this->Size = other.Size;
		this->very_smart_arr = new int[other.Size];

		for (int i = 0; i < other.Size; i++) {
		
			this->very_smart_arr[i] = other.very_smart_arr[i];
		}
		std::cout << "Вызвался конструктор копирования " << this << std::endl;

	}
	int add_element(int new_element);
	int get_element(int index);

	// Оператор присваивания (глубокое копирование)
	smart_array& operator=(const smart_array& other) {
		std::cout << "Вызвался operator = " << this << std::endl;
		if (this != &other) {
			this->Size = other.Size;

			this->very_smart_arr = new int[other.Size];
			for (int i = 0; i < other.Size; i++) {
				this->very_smart_arr[i] = other.very_smart_arr[i];
			}
		}
		std::cout << "Вызвался конструктор копирования " << this << std::endl;
		return *this;
	}
private:
	int Size;
	int* very_smart_arr;

};


int smart_array::add_element(int new_element) {
	//Функция добавления нового элемента в массив. Не забудьте обработать случай, когда количество элементов больше количества элементов, на которую выделена память.
	//если выходим за рамки arr
	//можно попробовать выбросить исключение или увеличить массив
	int newSize = Size + 1;
	//Созд новый массив newArr с увеличенным размером.
	int* newArr = new int[newSize];

	// Копирование элементов из исходного массива в новый массив
	for (int i = 0; i < Size; i++) {
		newArr[i] = very_smart_arr[i];
	}

	// Добавление нового элемента в конец нового массива
	newArr[newSize - 1] = new_element;

	// Освобождение памяти, занимаемой исходным массивом
	delete[] very_smart_arr;

	// Указатель very_smart_arr назначается на новый массив newArr
	very_smart_arr = newArr;
	//Размер size обновляется на newSize
	Size = newSize;

	return *newArr;

}
int smart_array::get_element(int index) {
	//Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
	if (index >= 0 && index < Size) {
		// Индекс корректен, обращаемся к элементу массива
		int element = very_smart_arr[index];
		// Дальнейшие действия с элементом массива
		return very_smart_arr[index];
		std::cout << "Ответ: " << very_smart_arr[index] << std::endl;
	}
	else {
		// Индекс некорректен, выбрасываем исключение
		throw std::out_of_range("Некорректный индекс!");
	}

}

int main()
{
	setlocale(LC_ALL, "RU");
	//создаём объект класса смарт эррей, передаём параметр

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
/*this - это указатель на текущий объект класса, он используется для доступа к членам объекта.

this->Size = size; присваивает переменной Size текущего объекта значение аргумента size, переданного в конструктор.

this->very_smart_arr = nullptr; присваивает указателю very_smart_arr значение nullptr, то есть нулевой указатель, для обозначения того, 
что пока массив ещё не выделен и не инициализирован.*/
/*Деструктор класса ~smart_array() освобождает память, выделенную под массив, при удалении объекта класса. Это позволяет избежать утечек памяти*/
/*В операторе присваивания вам нужно предусмотреть ситуацию, когда пользователь класса пытается присвоить класс самому себе: arr = arr;. 
Обычно делают проверку сравнением указателя. И если указатели равны, то просто код оператора присваивания ничего не делает и возвращает ссылку на себя:

smart_array& smart_array::operator=(const smart_array& other) {
	if (this != &other) {
		//Здесь весь остальной код:
		// ...
		
	}
	return *this;
}*/

//В программе возникает исключение, потому что компилятор самостоятельно сгенерировал оператор присваивания, 
//который просто копирует все поля одного объекта другому. В частности, проблема возникает из-за копирования 
//указателя: оба объекта класса имеют одинаковый указатель на область памяти и в своих деструкторах пытаются 
//освободить его. Происходит двойное освобождение памяти.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
