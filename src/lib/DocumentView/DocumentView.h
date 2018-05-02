virtual class DocumentView {
public:
	DocumentView();
	
	virtual char charAt(int pos);
	virtual std::string substring(int startPos, int endPos);
	virtual std::vector<int> search(const std::string &pattern);
	virtual std::vector<int> search(const std::string &pattern, int startPos, int endPos);
};