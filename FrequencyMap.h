#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class HuffmanTree;

class FrequencyMap
{
public:
	friend HuffmanTree;
	using AlphabetType = std::vector<char>;
	using ContainerType = std::unordered_map<char, uint32_t>;
private:
	mutable ContainerType frequenceis{};
	mutable AlphabetType alphabet{};
public:
	FrequencyMap(std::string const& data) {
		initialize(data);
	}
	AlphabetType const& getAlphabet() const {
		return alphabet;
	}
	ContainerType const& getFrequencyMap() const {
		return frequenceis;
	}
private:
	void initialize(std::string const& data) const;
};
