#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	virtual ~Cure();
	virtual void use(ICharacter& target);
	virtual AMateria* clone() const;
};

#endif