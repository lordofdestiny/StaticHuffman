#include <iostream>
#include <string>
#include <iterator>
#include "Helpers.h"
#include "Huffman.h"

int main(int argc, const char* argv[])
{
	std::string str;
	std::getline(std::cin, str);
	std::string toencode = toLowerCase(str);
	Huffman huffman(toencode);
	auto encoded = huffman.encode(toencode);
	auto decoded = huffman.decode(encoded);

	//std::string encoded = getEncoder(codes, toencode);
	std::cout << "Encoded: " << encoded << '\n';
	//std::string decoded = getDecoder(codes, encoded);
	std::cout << "Decoded: " << decoded << '\n';
}