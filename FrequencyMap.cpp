#include <algorithm>
#include <ranges>
#include <cctype>

#include "FrequencyMap.h"

void FrequencyMap::initialize(std::string const& data) const {
	/* Initialize frequency map */
	std::ranges::for_each(data,
		[this](const auto& c) {
			frequenceis.try_emplace(c, 0);
			frequenceis[c] += 1;
		});

	/* Initialize alphabet */
	alphabet.resize(frequenceis.size());
	std::ranges::copy(frequenceis | std::views::keys | std::views::reverse,
		alphabet.begin());
	std::ranges::sort(alphabet);
}