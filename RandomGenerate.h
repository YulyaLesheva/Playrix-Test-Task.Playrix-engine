#pragma once
#include <ctime>
#include "stdafx.h"
int RandomInteger() {
	
	int x;
	srand(time(0));

	x = 1 + rand() % 500;


	return x;
}