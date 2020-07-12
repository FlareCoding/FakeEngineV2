#pragma once

#include <random>

class FakeRandom
	{
	private:
		static std::mt19937 RandomEngine;
		static std::uniform_int_distribution<std::mt19937::result_type> Distribution;

	public:
		static void Init()
			{
			RandomEngine.seed(std::random_device()());
			}

		static float Float()
			{
			return (float)Distribution(RandomEngine) / (float)std::numeric_limits<uint32_t>::max();
			}

		static double Double()
			{
			return (double)Distribution(RandomEngine) / (double)std::numeric_limits<uint32_t>::max();
			}
	};