#pragma once
#include "globals.h"
#include <iostream>
#include <vector>

// base data type
struct Animal
{
public:
	std::string name;
	Gender gender;
	int age;

	// in data oriented other object cannot inherent, but they can however
	// point to some other data through indexing
	int selfIndex;

	Animal(std::string name, Gender gender, int age, int selfIndex);
};

struct Domesticated
{
	std::string owner;

	int selfIndex;
	int animalIndex;

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

// we use mediator pattern to make it easier to create and reference objects 
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

	AnimalDataController();
	void createNewAnimal(std::string name, Gender gender, int age);
	void createNewDomesticated(int animalIndex, std::string owner);
	void createNewCat(std::string name, Gender gender, int age, std::string owner);
	void createNewDog(std::string name, Gender gender, int age, std::string owner);
	void updateAge();
};