class NaiveDocumentView : public DocumentView {
private:
	std::string content;
	int size;

public:
	NaiveDocumentView();

	char charAt(int pos);
	std::string substring(int beginPos, int endPos);
	std::vector<int> search(const std::string &pattern);
	std::vector<int> search(const std::string &pattern, int startPos, int endPos);
	void insert(int pos, char c);
	void insert(int pos, const std::string &str);
	void erase(int beginPos, int endPos);
};