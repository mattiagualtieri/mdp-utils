#include <map>

class frequency_counter {
	std::map<uint8_t, int> freqs;

public:
	std::map<uint8_t, int> load(istream& is) {
		while (true) {
			uint8_t byte = is.get();
			if (!is) {
				return freqs;
			}
			if (freqs.count(byte) == 0) {
				freqs.insert({ byte, 1 });
			}
			else {
				freqs.at(byte) = freqs.at(byte) + 1;
			}
		}
		return freqs;
	}
};
