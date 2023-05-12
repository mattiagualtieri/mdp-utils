#include <fstream>

template<typename T>
std::istream& raw_read(std::istream& is, T& val, size_t size = sizeof(T)) {
	return is.read(reinterpret_cast<char*>(&val), sizeof(val));
}

class bitreader {
	uint8_t buffer;
	int n = 0;
	std::istream& is;

	uint32_t read_bit() {
		if (n == 0) {
			raw_read(is, buffer);
			n = 8;
		}
		n--;
		return (buffer >> n) & 1;
	}

public:
	bitreader(std::istream& is) : is(is) {}

	uint32_t read(uint8_t n) {
		uint32_t u = 0;
		for (int i = n - 1; i >= 0; i--) {
			u = (u << 1) | read_bit();
		}
		return u;
	}

	bool fail() const {
		return is.fail();
	}

};