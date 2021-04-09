#include <iostream>
#include "decoder.hpp"

int main(int argc, char *argv[]) {
    std::string file_name(argv[1]);
    std::string key_word(argv[2]);
    std::cout << file_name << ", " << key_word << " => ";
    std::cout << decoding::Decoder::Decode(file_name, key_word) << std::endl;
    return 0;
}