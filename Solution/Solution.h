#pragma once

#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <utility>

#include "../DataBase/DataBase.h"

template<typename DataBase = DataBaseUnMap>
class Solution {
 public:
    Solution(std::ifstream&, PosType size_of_window = 5);
    std::optional<PosType> request(const std::string&);

 private:
    const PosType size_of_window_;
    char get_letter(std::string&, unsigned int);
    std::string get_key_word(std::deque<std::string>&);
    void preprocessing_(std::ifstream&);
    DataBase data_base_;
};

template<typename DataBase>
Solution<DataBase>::Solution(std::ifstream& file, PosType size_of_window):
    size_of_window_(size_of_window) {
    preprocessing_(file);
}

template<typename DataBase>
std::optional<PosType> Solution<DataBase>::request(const std::string& key) {
    return data_base_.get_pos(key);
}

template<typename DataBase>
char Solution<DataBase>::get_letter(std::string& word, unsigned int pos) {
    return word.size() > pos ? word[pos] : '\0';
}

template<typename DataBase>
std::string Solution<DataBase>::get_key_word(std::deque<std::string>& window) {
    std::string return_value;
    for (PosType i = 0; i < size_of_window_; ++i) {
        char letter = get_letter(window[i], i);
        return_value += letter;
    }
    return return_value;
}

template<typename DataBase>
void Solution<DataBase>::preprocessing_(std::ifstream& file) {
    std::deque<std::string> window_of_words = {""};

    for (PosType i = 0; i < size_of_window_ - 1 && !file.eof(); ++i) {
        std::string word;
        file >> word;
        window_of_words.push_back(std::move(word));
    }

    PosType position = 0;

    auto handler = [this, &position, &window_of_words, &file](bool eof) {
        ++position;
        window_of_words.pop_front();
        if (eof) {
            window_of_words.push_back("");
        } else {
            std::string word;
             file >> word;
            window_of_words.push_back(std::move(word));
        }
        std::string key_word = get_key_word(window_of_words);
        for (PosType size = 0; size < size_of_window_ && get_letter(key_word, size) != '\0'; ++size) {
            data_base_.add_key(key_word.substr(0, size + 1), position);
        }
    };

    while (!file.eof()) {
        handler(false);
    }

    for (PosType i = 0; i < size_of_window_ - 1; ++i) {
        handler(true);
    }
}
