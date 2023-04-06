#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

static int createInputFile(std::ifstream& inFile, char *inFileName);
static int createOutputFile(std::ofstream& outFile, char *inFileName);
static void writeToOutput(std::ifstream& inFile, std::ofstream& outFile,
						  char **argv);
static void printModifedLine(std::string& input, char **argv, size_t argv2Len,
							 std::ofstream& outFile);

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Expected 3 arguments\n\t./sedIsForLosers FILE_NAME STR STR2"
				  << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream inFile;
	if (createInputFile(inFile, argv[1]) == EXIT_FAILURE)
		return EXIT_FAILURE;
	std::ofstream outFile;
	if (createOutputFile(outFile, argv[1]) == EXIT_FAILURE)
		return EXIT_FAILURE;

	writeToOutput(inFile, outFile, argv);
}

static int createInputFile(std::ifstream& inFile, char *inFileName) {
	inFile.open(inFileName);
	if (!inFile) {
		std::cerr << "Failed to open " << inFileName << ": " << strerror(errno)
				  << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

static int createOutputFile(std::ofstream& outFile, char *inFileName) {
	std::string outFileName = std::string(inFileName).append(".replace");
	outFile.open(outFileName.c_str());
	if (!outFile) {
		std::cerr << "Failed to open " << outFileName << ": " << strerror(errno)
				  << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

static void writeToOutput(std::ifstream& inFile, std::ofstream& outFile,
						  char **argv) {
	std::size_t argv2Len = std::strlen(argv[2]);
	std::string input;
	while (std::getline(inFile, input)) {
		printModifedLine(input, argv, argv2Len, outFile);
		if (!inFile.eof())
			outFile << std::endl;
	}
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
