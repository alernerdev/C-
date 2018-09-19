#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream outFile;

	std::string outputFileName = "text.txt";
	outFile.open(outputFileName);
	if (outFile.is_open()) {
		outFile << "Hello there";
		outFile.close();
	}
	else
		std::cout << "could not create file: " << outputFileName << std::endl;

	return 0;
}
