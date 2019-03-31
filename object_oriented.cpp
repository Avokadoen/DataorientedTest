#include "pch.h"

// |-------------------------------------------------------------------|
AnimalClass::AnimalClass(std::string name, Gender gender, int age) {
	this->name = name;
	this->gender = gender;
	this->age = age;
}

// |-------------------------------------------------------------------|
DomesticatedClass::DomesticatedClass(std::string owner, std::string name, Gender gender, int age) 
	: AnimalClass(name, gender, age) {
		this->owner = owner;
	}

// |-------------------------------------------------------------------|
CatClass::CatClass(std::string owner, std::string name, Gender gender, int age)
	: DomesticatedClass(owner, name, gender, age) {
}

// |-------------------------------------------------------------------|
DogClass::DogClass(std::string owner, std::string name, Gender gender, int age)
		: DomesticatedClass(owner, name, gender, age) {
}

