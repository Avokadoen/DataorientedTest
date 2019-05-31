#pragma once

#include "globals.h"
#include <string>

namespace DataorientedTest{
	namespace Entity {
		struct Entity {
			unsigned int id;
		};
	}

	namespace Component { // TODO: create a require behaviour to ensure illegal entity's throw error / report misuse
		struct ComponentData
		{
			unsigned int EntityId;
		};

		struct Animal : ComponentData
		{
			std::string name;
			Gender gender;
			int age;
		};


		struct Domesticated : ComponentData
		{
			std::string owner;
		};

		struct Cat : ComponentData
		{
		};

		struct Dog : ComponentData
		{
		};
	}

	namespace System {
		void UpdateAge();
	}

}




