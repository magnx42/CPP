#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
class Brain {
protected:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain& operator=(const Brain &other);
	~Brain();
	std::string getIdea(int index) const;
	void setIdea(int index, std::string str);
};

#endif