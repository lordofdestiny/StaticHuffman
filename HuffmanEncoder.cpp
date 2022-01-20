#include <iterator>
#include <sstream>
#include "HuffmanEncoder.h"
#include "Huffman.h"

std::string HuffmanEncoder::operator()(std::string const& str) const {
	std::stringstream buffer;
	auto const& code = _huffamn.get()._code;
	std::ranges::copy(str | std::views::transform(
		[&code](auto& c) {
			return code.at(c);
		}),
		std::ostream_iterator<std::string>(buffer));
	return buffer.str();
}