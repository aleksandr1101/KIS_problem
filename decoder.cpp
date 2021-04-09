#include "decoder.hpp"
#include <fstream>
#include <vector>
#include <algorithm>

namespace decoding {

    void Decoder::CorrectWord(std::string &word) {
        std::string corrected_word;
        for (char c : word) {
            if (isalpha(c)) {
                corrected_word.push_back(tolower(c));
            }
        }
        word = corrected_word;
    }

    bool Decoder::IsWord(std::string &word) {
        CorrectWord(word);
        return !word.empty();
    }

    int Decoder::Decode(const std::string &file_name, std::string key_word) {
        CorrectWord(key_word);
        std::ifstream in;
        in.open("./texts/" + file_name);
        std::string current_word;
        std::vector<size_t> dp(key_word.length(), 0);
        size_t words_cnt = 0;
        while (in >> current_word) {
            if (!IsWord(current_word)) {
                continue;
            }
            words_cnt++;
            for (size_t i = 0; i < key_word.length(); ++i) {
                if (i < current_word.length() && current_word[i] == key_word[i]) {
                    dp[i]++;
                }
            }
            std::rotate(dp.rbegin(), dp.rbegin() + 1, dp.rend());
            if (dp.front() == key_word.length()) {
                in.close();
                return static_cast<int>(words_cnt - key_word.length());
            }
            dp[0] = 0;
        }
        in.close();
        return -1;
    }

}