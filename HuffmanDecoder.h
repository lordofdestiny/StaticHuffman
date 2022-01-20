#pragma once
#include <utility>
#include <string>

class Huffman;

class HuffmanDecoder {
private:
	std::reference_wrapper<const Huffman> _huffamn;
	HuffmanDecoder(Huffman const& huffman) :
		_huffamn(huffman) {};
public:
	friend class Huffman;
	std::string operator()(std::string const&) const;
};
