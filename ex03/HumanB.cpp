#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) {
	this->_name = name;
	this->_weapon = NULL;
}

void HumanB::attack() {
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << *this->_weapon << std::endl;
	else
		std::cout << this->_name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
