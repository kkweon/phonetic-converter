#ifndef PHONETIC_READER_HPP
#define PHONETIC_READER_HPP

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <locale>

namespace pr {
    using dict = std::unordered_map<char, std::string>;
    dict read_file(std::string filename);

    std::string to_upper(std::string word);
    std::string to_lower(std::string word);
    void process_input(dict phonetic_dict, std::string sentence);
}
#endif


