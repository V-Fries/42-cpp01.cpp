#include <string>
#include <iostream>

int main(void) {
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "The memory address of the string variable: " << &string << std::endl
			  << "The memory address held by stringPTR: " << stringPTR << std::endl
			  << "The memory address held by stringREF: " << &stringREF << std::endl

			  << "The value of the string variable: " << string << std::endl
			  << "The value pointed to by stringPTR: " << *stringPTR << std::endl
			  << "The value pointed to by stringREF: " << stringREF << std::endl;
}
