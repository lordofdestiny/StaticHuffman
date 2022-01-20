#include <ostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>

template<typename T>
inline std::ostream& operator<<(std::ostream& os, std::vector<T> const& vec) {
	std::ranges::copy(vec, std::ostream_iterator<T>(os, " "));
	return os;
}

inline std::string toLowerCase(std::string s) {
	std::ranges::transform(s, s.begin(), [](char c) {return tolower(c); });
	return s;
}