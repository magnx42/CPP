#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	std::cout << "=== exo tests ===" << std::endl << std::endl;
	const Animal *a = new Dog;
	const Animal *b = new Cat;
	const WrongAnimal *c = new WrongCat;
	const Animal *d = new Animal;
	a->makeSound();
	b->makeSound();
	c->makeSound();
	d->makeSound();
	std::cout << "Animal a is : " << a->getType() << std::endl;
	std::cout << "Animal b is : " << b->getType() << std::endl;
	std::cout << "Animal c is : " << c->getType() << std::endl;
	std::cout << "Animal d is : " << d->getType() << std::endl;
	delete a;
	delete b;
	delete c;
	delete d;


	std::cout << std::endl << std::endl << std::endl << "=== canonical tests ===" << std::endl;
	Animal aa;
	Animal ab(aa);
	Animal ac;
	ac = aa;
	Cat ba;
	Cat bb(ba);
	Cat bc;
	bc = ba;
	Dog ca;
	Dog cb(ca);
	Dog cc;
	cc = ca;
	WrongAnimal da;
	WrongAnimal db(da);
	WrongAnimal dc;
	dc = da;
	WrongCat ea;
	WrongCat eb(ea);
	WrongCat ec;
	ec = ea;
	(void) aa;
	(void) ab;
	(void) ac;
	(void) ba;
	(void) bb;
	(void) bc;
	(void) ca;
	(void) cb;
	(void) cc;
	(void) da;
	(void) db;
	(void) dc;
	(void) ea;
	(void) eb;
	(void) ec;
}