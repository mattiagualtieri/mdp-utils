#include <fstream>

template<typename T>
std::istream& raw_read(std::istream& is, T& value, size_t size = sizeof(T)) {
	return is.read(reinterpret_cast<char*>(&value), size);
}

class bitreader {
	uint8_t buffer_;
	int n_ = 0;
	std::istream& is_;

	uint32_t read_bit() {
		if (n_ == 0) {
			raw_read(is_, buffer_);
			n_ = 8;
		}
		n_--;
		return (buffer_ >> n_) & 1;
	}

public:
	bitreader(std::istream& is) : is_(is) {}

	uint32_t read(size_t n) {
		uint32_t u = 0;
		for (int i = n - 1; i >= 0; i--) {
			u = (u << 1) | read_bit();
		}
		return u;
	}

    int32_t read(size_t n, bool is_signed) {
		uint32_t u;
		u = read(n);
		int32_t i = static_cast<int32_t>(u);
		return i;
	}

	bool fail() const {
		return is.fail();
	}

};
