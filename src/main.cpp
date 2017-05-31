#include <string>
#include "phonetic_reader.hpp"

using string = std::string;

string ask_input() {
    string line;
    std::cout << "Enter your input [Any single character to exit]: ";
    std::getline(std::cin, line);

    return line;
}

int main(int argc, char* argv[]) {
    pr::dict phonetic_dict;

    if (argc == 2) {
        string filename = argv[1];
        phonetic_dict   = pr::read_file(filename);

        while (true) {
            string input = ask_input();

            if (input.length() < 2) {
                break;
            }

            pr::process_input(phonetic_dict, input);
        }
    } else if (argc == 3) {
        string filename = argv[1];
        phonetic_dict   = pr::read_file(filename);

        string input = argv[2];
        pr::process_input(phonetic_dict, input);

    } else {
        std::cout << "Usage: ./phonetic NATO.txt\n";
    }
}