#include <iostream>
#include <string>
#include <fstream>



int main() {
    // Declaring necessary variables
    std::string file;
    std::string searchWord;
    std::string currentWord;
    std::string replacedWord;
    int count = 0;

    // Gets the file name from the user
    std::cout << "Enter the input file name: ";
    std::cin >> file;

    // Gets the word the user is looking for
    std::cout << "Enter the word to search for: ";
    std::cin >> searchWord;

    // Gets the replacement word from the user
    std::cout << "Enter the replacement word: ";
    std::cin >> replacedWord;

    // This will open the input file
    std::ifstream inputFile(file);

    // This validates if the file was opened.
    if (!inputFile) {
        std::cout << "The file could not be opened." << std::endl;
        return 1;
    }

    // This creates the output file
    std::ofstream outputFile("output.txt");

    // Reads each word from the file
    while (inputFile >> currentWord) {
        // Looks for the word and replaces it
        if (currentWord == searchWord) {
            outputFile << replacedWord << " ";
            count++;
        } else {
            outputFile << currentWord << " ";
        }
    }

    // Closes both the files
    inputFile.close();
    outputFile.close();

    // Displays the final results to the terminal
    std::cout << "The word " << searchWord << " was replaced " << count << " times." << std::endl;

    return 0;
}