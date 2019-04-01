#include "pch.h"

// |-------------------------------------------------------------------|
Animal::Animal(std::string name, Gender gender, int age, int selfIndex) {
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->selfIndex = selfIndex;
}

// |-------------------------------------------------------------------|
Domesticated::Domesticated(std::string owner, int selfIndex, int animalIndex) {
	this->owner = owner;
	this->selfIndex = selfIndex;
	this->animalIndex = animalIndex;
}

// |-------------------------------------------------------------------|
Cat::Cat(int selfIndex, int domesticIndex) {
	this->selfIndex = selfIndex;
	this->domesticatedIndex = domesticatedIndex;
}

// |-------------------------------------------------------------------|
Dog::Dog(int selfIndex, int domesticIndex) {
	this->selfIndex = selfIndex;
	this->domesticatedIndex = domesticatedIndex;
}


// |-------------------------------------------------------------------|
AnimalDataController::AnimalDataController() {
	animalData.reserve(CAT_COUNT + DOG_COUNT);
	domesticatedData.reserve(CAT_COUNT + DOG_COUNT);
	catData.reserve(CAT_COUNT);
	dogData.reserve(DOG_COUNT);
}

void AnimalDataController::createNewAnimal(std::string name, Gender gender, int age) {
	animalData.push_back(Animal(name, gender, age, animalCount++));
}

void AnimalDataController::createNewDomesticated(int animalIndex, std::string owner) {

	if (animalCount < animalIndex) {
		std::cout << "invalid index used for animal";
		return;
	}

	domesticatedData.push_back(Domesticated(owner, domesticatedCount++, animalIndex));
}

void AnimalDataController::createNewCat(std::string name, Gender gender, int age, std::string owner) {
	createNewAnimal(name, gender, age);
	createNewDomesticated(animalCount - 1, owner);

	catData.push_back(Cat(catCount++, domesticatedCount - 1));
}

void AnimalDataController::createNewDog(std::string name, Gender gender, int age, std::string owner) {
	createNewAnimal(name, gender, age);
	createNewDomesticated(animalCount - 1, owner);

	dogData.push_back(Dog(dogCount++, domesticatedCount - 1));
}

void AnimalDataController::updateAge() {
	for (auto&& animal : animalData) {
		animal.age += 1;
	}
}