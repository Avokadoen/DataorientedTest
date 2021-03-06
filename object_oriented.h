#pragma once
#include <iostream>
#include "globals.h"
/*
	NOTE:
	The compelxity differnce in the two paradigms can be due to my inexperience 
	with data oriented
*/


class AnimalClass
{
public:
	std::string name;
	Gender gender;
	int age;
	int selfIndex;

	AnimalClass(std::string name, Gender gender, int age);
};

class DomesticatedClass : public AnimalClass
{
public:
	std::string owner;

	DomesticatedClass(std::string owner, std::string name, Gender gender, int age);
};

class CatClass : public DomesticatedClass
{
public:
	CatClass(std::string owner, std::string name, Gender gender, int age);
};

class DogClass : public DomesticatedClass
{
public:
	DogClass(std::string owner, std::string name, Gender gender, int age);
};
