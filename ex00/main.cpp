#include "Zombie.hpp"

int main(void) {
	Zombie* zombieOnHeap = newZombie("zombieOnHeap");
	delete zombieOnHeap;
	randomChump("randomChump");
}