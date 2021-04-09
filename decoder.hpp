#pragma once

#include <string>

namespace decoding {

    class Decoder {
    public:
        static int Decode(const std::string & /*file_name*/, std::string /*key_word*/);

    private:
        static void CorrectWord(std::string &/*word*/);

        static bool IsWord(std::string &/*word*/);
    };

}