#pragma once
#include "enums.h"
#include <iostream>
#include <vector>

struct Animal
{
public:
	std::string name;
	Gender gender;
	int age;
	int selfIndex;

	Animal(std::string name, Gender gender, int age, int selfIndex);
};

struct Domesticated
{
	int selfIndex;
	int animalIndex;

	std::string owner;

	Domesticated(std::string owner, int selfIndex, int animalIndex);
};

struct Cat
{
	int selfIndex;
	int domesticatedIndex;

	Cat(int selfIndex, int domesticIndex);
};

struct Dog
{
	int selfIndex;
	int domesticatedIndex;

	Dog(int selfIndex, int domesticIndex);
};



struct AnimalDataController
{
	std::vector<Animal>	animalData;
	int animalCount = 0;

	std::vector<Domesticated> domesticatedData;
	int domesticatedCount = 0;

	std::vector<Cat> catData;
	int catCount = 0;

	std::vector<Dog> dogData;
	int dogCount = 0;

	void createNewAnimal(std::string name, Gender gender, int age);
	void createNewDomesticated(int animalIndex, std::string owner);
	void createNewCat(std::string name, Gender gender, int age, std::string owner);
	void createNewDog(std::string name, Gender gender, int age, std::string owner);
	void updateAge();
};