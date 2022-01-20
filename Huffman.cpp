#include <sstream>
#include <ranges>
#include <algorithm>
#include "Huffman.h"
#include "HuffmanEncoder.h"
#include "HuffmanDecoder.h"
#include <iostream>

Huffman::Huffman(std::string const& text) :
	_fmap(text), _tree(_fmap) {
	generateCodes();
}

Huffman::Huffman(FrequencyMap const& fmap) :
	_fmap(fmap), _tree(_fmap) {
	generateCodes();
}

Huffman::Huffman(FrequencyMap&& fmap) :
	_fmap(std::move(fmap)), _tree(_fmap) {
	generateCodes();
}

std::string Huffman::encode(std::string const& str) const {
	return _encoder(str);
};

std::string Huffman::decode(std::string const& str) const {
	return _decoder(str);
};

void Huffman::generateCodes() const{
	_code = HuffmanTree::extractCode(_tree);
	for (auto const& [key, value] : _code) {
		_inverse_code.emplace(value, key);
	}
}

HuffmanEncoder const& Huffman::getEncoder() const {
	return _encoder;
}

HuffmanDecoder const& Huffman::getDecoder() const {
	return _decoder;
}