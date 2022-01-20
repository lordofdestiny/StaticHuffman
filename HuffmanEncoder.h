#pragma once
#include <utility>
#include <string>

class Huffman;

class HuffmanEncoder {
private:
	std::reference_wrapper<const Huffman> _huffamn;
	HuffmanEncoder(Huffman const& huffman) :
		_huffamn(huffman) {};
public:
	friend class Huffman;
	std::string operator()(std::string const&) const;
};