using vec3b = std::array<uint8_t, 3>;

template <typename T>
class mat {
	int rows_, cols_;
	std::vector<T> data_;

public:
	mat(int rows = 0, int cols = 0) : rows_(rows), cols_(cols), data_(rows* cols) {}

	void resize(int rows, int cols) {
		rows_ = rows;
		cols_ = cols;
		data_.resize(rows * cols);
	}

	const T& operator()(int r, int c) const {
		return data_[r * cols_ + c];
	}

	T& operator()(int r, int c) {
		return data_[r * cols_ + c];
	}

	int rows() const {
		return rows_;
	}

	int cols() const {
		return cols_;
	}

	int size() const {
		return rows_ * cols_;
	}

};