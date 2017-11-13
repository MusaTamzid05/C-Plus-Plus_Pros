#include "regular_exp.h"
#include <iostream>

namespace Util {

    Regex::Regex(const std::string& pattern):regex_pattern(pattern) {

    }

    Regex::~Regex() {

    }

    void Regex::set_pattern(const std::string& pattern) {

        regex_pattern = std::regex(pattern);
    }

    void Regex::get_matches(const std::string& text , std::vector<std::string>& matches) {

        if(!is_match(text)) {

            std::cerr << "No match found.\n";
            return;
        }

        for(auto match : this->matches)
            matches.push_back(match);


    }

    bool Regex::is_match(const std::string& text) {

        return std::regex_match(text.c_str(), matches ,  regex_pattern);

    }
};
