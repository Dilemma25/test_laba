#include<iostream>
#include "windows.h"
class Conteiner {
public:
	int value = 0;

	Conteiner(int inputValue) : value(inputValue) {};

	//Констуктор копирования
	Conteiner(const Conteiner& node) {
		this->value = node.value;
		std::cout << "Переменная с value " << node.value << " скопирована" << '\n';
	}
};

void incrementCopy(Conteiner node) {
	node.value++;
}

void incrementLink(Conteiner& node) {
	node.value++;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Conteiner node(5);
	std::cout << "Value контейнера до функций = " << node.value << '\n' << '\n';

	std::cout << "Вход в функцию, где переменная передается не по ссылке" << '\n' ;
	incrementCopy(node);
	std::cout << "Контейнер после функции с копированием: " << node.value << '\n' << '\n';
	
	std::cout << "Вход в функцию, где переменная передается по ссылке" << '\n';
	incrementLink(node);
	std::cout << "Контейнер после функции с передачей по ссылке: " << node.value << '\n';
	return 0;
}