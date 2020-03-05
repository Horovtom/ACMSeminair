

#include <iostream>



double roll(std::string line, int index, int increment) {
	// It fell off the edge
	if (index < 0 || index >= line.size()) return 100;

	// It fell through the hole
	if (line[index] == '.') return 100;

	if (line[index] == '/' && increment > 0) return 0;
	if (line[index] == '\\' && increment < 0) return 0;
	if (line[index] == '|') return 0;
	if (line[index] == '_') return roll(line, index + increment, increment);
	// std::cerr << "I do not know what to do when roll(" << line << ", " << index << ", " << increment << std::endl;
	return 0;
}

int main() {
	while(true) {

		std::string in;
		std::cin >> in;
		if (in == "#") break;

		bool isStart = true;
		double totalPercentage = 0;
		for (int i = 0; i < in.size(); ++i) {
			if (in.at(i) == '.') totalPercentage += 100;
			else if (in.at(i) == '/') totalPercentage += roll(in, i-1, -1);
			else if (in.at(i) == '\\') totalPercentage += roll(in, i+1, 1);
			else if (in.at(i) == '|') {
				totalPercentage += 0.5 * roll(in, i-1, -1);
				totalPercentage += 0.5 * roll(in, i+1, 1);
			}
		}
		std::cout << static_cast<int>(totalPercentage / in.size()) << std::endl;
	}


}
