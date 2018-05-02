template<typename T> class StaticArray {
private:
	int arraySize;
	T* array;
	bool useMalloc;

public:
	StaticArray(int sz, bool useMalloc = false) {
		this->arraySize = sz;
		this->useMalloc = useMalloc;
		if (useMalloc) {
			this->array = (T*) malloc(sz * sizeof(T));
		} else {
			this->array = new T[sz];
		}
	}

	~StaticArray() {
		if (useMalloc) {
			free(array);
		} else {
			delete[] array;
		}
	}

	int size() const {
		return arraySize;
	}

	int content() const {
		return array;
	}

	void fill(const T &e) const {
		std::fill(array, array + arraySize, e);
	}

	T& operator[](int index) {
#ifdef DEBUG
		assert(0 <= index && index < arraySize);
#endif
		return array[index];
	}

};