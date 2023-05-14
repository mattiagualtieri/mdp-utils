#include <vector>

// Simple bubblesort implementation
template <typename T>
void sort(vector<T>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j] < v[j + 1]) {
				std::swap(v[j], v[j + 1]);
			}
		}
	}
}

// Useful method to parse a 32 bit integer into 4 uint8_t (little endian)
uint8_t* from_32_to_8_bits(uint32_t value) {
	uint8_t ret[4];
	ret[0] = (value & 0x000000ff);
	ret[1] = (value & 0x0000ff00) >> 8;
	ret[2] = (value & 0x00ff0000) >> 16;
	ret[3] = (value & 0xff000000) >> 24;
	return ret;
}
