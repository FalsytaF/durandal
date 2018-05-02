StaticArray<int> initKMP(const std::string &pattern) {
	int len = pattern.length();
	StaticArray<int> next(len, false);
	int j = -1;
	next[0] = -1;
	for (int i = 1; i < len; ++i) {
		while (j != -1 && pattern[i] != pattern[j + 1]) j = next[j];
		if (pattern[i] == pattern[j + 1]) ++j;
		next[i] = j;
	}
	return next;
}

void findAllMatchesByNext(const std::string &searchText, const std::string &pattern, const StaticArray<int> &next, std::vector<int> &result) {
	const int lenPattern = pattern.length();
	
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j != -1 && (j == lenPattern || searchText[i] != pattern[j + 1])) j = next[j];
		if (searchText[i] == pattern[j + 1]) ++j;
		if (j == lenPattern) {
			result.push_back(i - lenPattern + 1);
		}
	}
}

std::vector<int> findAllMatches(const std::string &searchText, const std::string &pattern) {
	vector<int> result;
	StaticArray<int> next = initKMP(pattern);
	findAllMatchesByNext(searchText, pattern, next, result);
	return result;
}
