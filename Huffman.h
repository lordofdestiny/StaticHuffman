#pragma once
#include <string>
#include <utility>
#include "FrequencyMap.h"
#include "HuffmanTree.h"
#include "HuffmanEncoder.h"
#include "HuffmanDecoder.h"

class Huffman final {
public:
	using CodeT = HuffmanTree::HuffmanCodeT;
	using ReverseCodeT = std::unordered_map<std::string, char>;
private:
	FrequencyMap _fmap;
	HuffmanTree _tree;
	mutable HuffmanTree::HuffmanCodeT _code{};
	mutable ReverseCodeT _inverse_code{};
	mutable HuffmanEncoder _encoder{ *this };
	mutable HuffmanDecoder _decoder{ *this };
public:
	Huffman(std::string const& text);
	Huffman(FrequencyMap const& fmap);
	Huffman(FrequencyMap&& fmap);
	friend class HuffmanEncoder;
	friend class HuffmanDecoder;
public:
	std::string encode(std::string const&) const;
	std::string decode(std::string const&) const;
	HuffmanEncoder const& getEncoder() const;
	HuffmanDecoder const& getDecoder() const;
private:
	void generateCodes() const;
};