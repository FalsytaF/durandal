char NaiveDocumentView::charAt(int pos) {
	assert(checkRange(pos, 0, size));
	return content[pos];
}

