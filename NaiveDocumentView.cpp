#include "NaiveDocumentView.h"
#include "algorithm/KnuthMorrisPratt.hpp"

char NaiveDocumentView::charAt(int pos) {
	assert(checkRange(pos, 0, size));
	return content[pos];
}

std::vector<int> search(std::string pattern) {
	return findAllMatches(content, pattern);
}