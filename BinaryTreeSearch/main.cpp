#include<iostream>
#include "BinaryTree.h"
#include<string>

//C:\Users\ACER\source\repos\BinaryTreeSearch\Debug\number.txt
//C:\Users\ACER\source\repos\BinaryTreeSearch\BinaryTreeSearch.sln
int main(int agrc, char** argv) {
	try {
		BinaryTree b;
		std::string t;
		if (agrc == 1) {
			std::cout << "Enter the path to the file" << std::endl;
			std::getline(std::cin, t);
		}
		if (agrc == 2) {
			t = std::string(argv[1]);
		}
		b.CreateTree(t);
		float element = 0;
		int check = 0;
		while(true){
		std::cout << "Enter your element" << std::endl;
		std::cin >> element;
		if (b.find_el(element)) {
			std::cout << "Element found" << std::endl;
			std::cout << "Do you want to repeat? 1-yes 2-no" << std::endl;
			std::cin >> check;
			if (check != 1) {
				break;
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "Element not found" << std::endl;
			std::cout << "Do you want to repeat? 1-yes 2-no" << std::endl;
			std::cin >> check;
			if (check != 1) {
				break;
			}
			std::cout << std::endl;
		}
		}
		return 0;
	}
	catch (const std::ios_base::failure &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (const std::logic_error &ex) {
		std::cout << ex.what() << std::endl;
	}
}