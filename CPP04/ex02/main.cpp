#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	std::cout << "=== exo tests ===" << std::endl << std::endl;
	Animal *tab[100];
	for(int i = 0;i < 100;i++)
	{
		if(i < 50)
			tab[i] = new Dog;
		else
			tab[i] = new Cat;
	}
	for(int i = 0;i<100;i++)
		delete tab[i];
	

	std::cout << std::endl << std::endl << "=== copy brain test ===" << std::endl;
	Dog dog;
	dog.setIdea(1, "First idea");
	std::cout << "First dog idea : " << dog.getIdea(1) << std::endl;
	Dog dog2;
	dog2 = dog;
	std::cout << "Before change : " << dog2.getIdea(1) << std::endl;
	dog2.setIdea(1, "Second idea");
	std::cout << "After change : " << dog2.getIdea(1) << std::endl;
	std::cout << "First dog idea : " << dog.getIdea(1) << std::endl;

	std::cout << std::endl << std::endl << std::endl << "=== canonical tests ===" << std::endl;
	//does not compile
	//Animal aa;
	//Animal ab(aa);
	//Animal ac;
	//ac = aa;
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
	//(void) aa;
	//(void) ab;
	//(void) ac;
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