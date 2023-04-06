#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

static void printModifedLine(std::string& input, char **argv, size_t argv2Len,
							 std::ofstream& outFile);

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Expected 3 arguments\n\t./sedIsForLosers FILE_NAME STR STR2"
				  << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream inFile(argv[1]);
	if (!inFile) {
		std::cerr << "Failed to open " << argv[1] << ": " << strerror(errno)
				  << std::endl;
		return EXIT_FAILURE;
	}

	std::string outFileName = std::string(argv[1]).append(".replace");
	std::ofstream outFile(outFileName.c_str());
	if (!outFile) {
		std::cerr << "Failed to open " << outFileName << ": " << strerror(errno)
				  << std::endl;
		return EXIT_FAILURE;
	}

	std::size_t argv2Len = std::strlen(argv[2]);
	std::string input;
	while (std::getline(inFile, input)) {
		printModifedLine(input, argv, argv2Len, outFile);
		if (!inFile.eof())
			outFile << std::endl;
	}
	if (inFile.fail())
		std::cerr << "std::getline() failed" << std::endl;
}

static void printModifedLine(std::string& input, char **argv, size_t argv2Len,
							 std::ofstream& outFile) {
	std::size_t found = input.find(argv[2]);
	while (found != std::string::npos) {
		outFile << input.substr(0, found) << argv[3];
		input = input.substr(found + argv2Len, input.length() - found - argv2Len);
		found = input.find(argv[2]);
	}
	outFile << input;
}
