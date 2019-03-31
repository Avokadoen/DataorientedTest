#include "pch.h"
#include <iostream>
#include <vector>
#include <chrono>

const int DOG_COUNT = 10000;
const int CAT_COUNT = 10000;


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

std::chrono::nanoseconds ObjectOrientedTest() {
	Gender prevGender = male;
	std::vector<CatClass> catObjects;
	std::vector<CatClass> dogObjects;

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
		auto objectPercent = (float)objectResult.count() / (float)totalTime.count();
		auto dataPercent = (float)dataResult.count() / (float)totalTime.count();
		std::cout << "that is " << (objectPercent - dataPercent)*100 << "% faster than object oriented" << std::endl;
	}
	
}

