#include "Intern.hpp"
#include <iostream>

Intern::Intern(){
}

Intern::Intern(const Intern& other){
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	return *this;
}

Intern::~Intern() {
}

Form* makeForm(std::string formName, std::string target){
	
}