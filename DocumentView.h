virtual class DocumentView {
public:
	DocumentView();
	
	virtual char charAt(int pos);
	virtual std::string substring(int startPos, int endPos);
	virtual std::vector<int> search(std::string pattern);
	virtual std::vector<int> search(std::string, int startPos, int endPos);
};