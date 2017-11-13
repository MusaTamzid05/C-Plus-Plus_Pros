#ifndef REGULAR_EXP_H
#define REGULAR_EXP_H


#include <string>
#include <regex>

namespace Util {

    class Regex {

        public:

            Regex(const std::string& pattern);
            virtual ~Regex();


            void set_pattern(const std::string& pattern);
            bool is_match(const std::string& text);

            void get_matches(const std::string& text , std::vector<std::string>& matches);


        private:

            std::regex regex_pattern;
            std::cmatch matches;

    };
};

#endif
