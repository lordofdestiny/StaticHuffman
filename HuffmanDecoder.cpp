#include <sstream>
#include "HuffmanDecoder.h"
#include "Huffman.h"

std::string HuffmanDecoder::operator()(std::string const& str) const {
	std::size_t begin = 0, length = 1;
	std::stringstream ss;
	auto& code = _huffamn.get()._inverse_code;
	while (length < str.length()) {
		std::string curr = str.substr(begin, length);
		if (!code.contains(curr)) {
			length += 1;
		}
		else {
			ss << code[curr];
			begin += std::exchange(length, 0);
		}
	}
	return ss.str();
}