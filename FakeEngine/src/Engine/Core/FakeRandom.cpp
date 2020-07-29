#include "FakePch.h"
#include "FakeRandom.h"

std::mt19937 FakeRandom::RandomEngine;
std::uniform_int_distribution<std::mt19937::result_type> FakeRandom::Distribution;
