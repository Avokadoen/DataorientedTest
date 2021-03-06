#include "pch.h"
#include <iostream>
#include <vector>
#include <chrono>


// used to test data oriented structure
// returns times used
std::chrono::nanoseconds DataOrientedTest() {
	AnimalDataController dataCenter;

	Gender prevGender = male;

	for (int i = 0; i < CAT_COUNT; i++) {
		switch (prevGender) {
		case male:
			prevGender = female;
			break;

		case female:
			prevGender = male;
			break;
		}
		dataCenter.createNewCat("abc" + i, prevGender, i, "cba" + i);
	}


	for (int i = 0; i < DOG_COUNT; i++) {
		switch (prevGender) {
		case male:
			prevGender = female;
			break;

		case female:
			prevGender = male;
			break;
		}
		dataCenter.createNewDog("abc" + i, prevGender, i, "cba" + i);
	}

	auto start = std::chrono::steady_clock::now();
	dataCenter.updateAge();
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	return diff;
}

// used to test object oriented structure
// returns times used
std::chrono::nanoseconds ObjectOrientedTest() {

	std::vector<CatClass> catObjects;
	catObjects.reserve(CAT_COUNT);

	std::vector<CatClass> dogObjects;
	dogObjects.reserve(DOG_COUNT);

	Gender prevGender = male;
	for (int i = 0; i < CAT_COUNT; i++) {
		switch (prevGender) {
		case male:
			prevGender = female;
			break;

		case female:
			prevGender = male;
			break;
		}
		catObjects.push_back(CatClass("abc" + i, "cba" + i, prevGender, i));
	}
	for (int i = 0; i < DOG_COUNT; i++) {
		switch (prevGender) {
		case male:
			prevGender = female;
			break;

		case female:
			prevGender = male;
			break;
		}
		dogObjects.push_back(CatClass("abc" + i, "cba" + i, prevGender, i));
	}

	auto start = std::chrono::steady_clock::now();
	for (auto&& animal : catObjects) {
		animal.age += 1;
	}
	for (auto&& animal : dogObjects) {
		animal.age += 1;
	}
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	return diff;
}

int main()
{
	for (int i = 0; i < 10; i++) {
		std::cout << std::endl << "----- new test -----" << std::endl;
		auto dataResult = DataOrientedTest();
		std::cout << "time to update data took " << dataResult.count() << " nanoseconds" << std::endl;
		
		auto objectResult = ObjectOrientedTest();
		std::cout << "time to update objects took " << objectResult.count() << " nanoseconds" << std::endl;
		
		std::cout << "data oriented was " << (objectResult - dataResult).count() << " nanoseconds faster" << std::endl;
		auto totalTime = dataResult + objectResult;
		auto procentResult = 100 - ((float)dataResult.count() / (float)objectResult.count()) * 100;
		
		if(procentResult > 0)
			std::cout << "that is " << procentResult << "\% faster than object oriented" << std::endl;
		if (procentResult <= 0)
			std::cout << "that is " << procentResult << "\% less than object oriented" << std::endl;
	}
	
}

