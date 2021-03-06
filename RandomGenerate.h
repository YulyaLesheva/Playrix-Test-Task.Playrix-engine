#pragma once
#include <random>
#include "stdafx.h"

namespace RandomGenerate {
	int RandomInteger(int max) {

		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(100, max-100); // guaranteed unbiased

		auto random_integer = uni(rng);

		return random_integer;
	}

	int RandomVector() {

		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(-10, 10); // guaranteed unbiased
		
		auto random_integer = uni(rng);
		return random_integer;
	}

	int RandomBomb() {

		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(1, 4); // guaranteed unbiased

		auto random_bomb = uni(rng);
		return random_bomb;
	}

}