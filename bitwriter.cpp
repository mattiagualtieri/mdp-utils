#include <fstream>

template<typename T>
std::ostream& raw_write(std::ostream& os, const T& val, size_t size = sizeof(T)) {
	return os.write(reinterpret_cast<const char*>(&val), size);
}

class bitwriter {
	uint8_t buffer;
	int n = 0;
	std::ostream& os;

	std::ostream& write_bit(uint8_t bit) {
		buffer = (buffer << 1) | (bit & 1);
		n++;
		if (n == 8) {
			raw_write(os, buffer);
			n = 0;
		}
		return os;
	}

public: 
	bitwriter(std::ostream& os) : os(os) {}

	std::ostream& write(uint32_t u, size_t n) {
		for (size_t i = n - 1; i >= 0; i--) {
			write_bit(u >> i);
		}
		return os;
	}

	std::ostream& flush(uint32_t bit = 0) {
		while (n > 0) {
			write_bit(bit);
		}
		return os;
	}

	~bitwriter() {
		flush();
	}

};
