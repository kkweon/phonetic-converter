#include "phonetic_reader.hpp"

namespace pr {
dict read_file(std::string filename) {
    dict result;
    std::ifstream phoentic_file(filename);

    if (phoentic_file.is_open()) {
        std::string line;

        while (std::getline(phoentic_file, line)) {
            std::istringstream iss(line);

            std::string key;
            std::string value;

            iss >> key >> value;

            result.insert({to_lower(key)[0], to_upper(value)});
            result.insert({key[0], to_upper(value)});
        }

        phoentic_file.close();
    }

    return result;
}

inline std::string to_upper(std::string word) {
    std::string temp;

    for (auto& ch : word) {
        temp += std::toupper(ch);
    }

    return temp;
}

inline std::string to_lower(std::string word) {
    std::string temp;

    for (auto& ch : word) {
        temp += std::tolower(ch);
    }

    return temp;
}

void process_input(dict phonetic_dict, std::string sentence) {
    std::cout << "\n";
    
    for (auto& ch : sentence) {
        auto it = phonetic_dict.find(ch);

        if (it != phonetic_dict.end()) {
            std::cout << ch << " as in " << it->second << std::endl;
        } else {
            std::cout << ch << std::endl;
        }
    }

    std::cout << "\n";

}
}
