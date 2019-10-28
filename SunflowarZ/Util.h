#pragma once
#include <vector>
#include <random>

class Util
{
private:
	Util() = default;

public:
	
	template<typename T>
	static T randomElement(const std::vector<T>& vec);
};

template <typename T>
T Util::randomElement(const std::vector<T>& vec)
{
	std::random_device seed;
	std::mt19937 engine(seed());
	const std::uniform_int_distribution<int> choose(0, vec.size() - 1);
	return vec[choose(engine)];
}

