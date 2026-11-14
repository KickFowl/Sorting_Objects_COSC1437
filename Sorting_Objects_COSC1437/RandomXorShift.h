#pragma once

#include <stdint.h>
#include <chrono>

class RandomXorShift
{
	uint32_t state;
	uint32_t xorshift32();

	uint32_t get_time_seed();
public:
	RandomXorShift();
	RandomXorShift(uint32_t seed);

	int getRandomRange(int min, int max);
};

