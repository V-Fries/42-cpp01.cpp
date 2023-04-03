#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
	this->name = name;

	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
