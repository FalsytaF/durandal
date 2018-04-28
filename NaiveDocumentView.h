class NaiveDocumentView : public DocumentView {
private:
	std::string content;
	int size;

public:
	NaiveDocumentView();

	char charAt(int pos);
	std::string substring(int startPos, int endPos);
	std::vector<int> search(std::string pattern);
	std::vector<int> search(std::string, int startPos, int endPos);	
};