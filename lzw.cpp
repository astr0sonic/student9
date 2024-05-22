#include "lzw.h"
#include <string>
#include <map>
#include <vector>
#include<algorithm>

std::vector<int> compress(const std::string& text) {
    std::vector<int> compressed;
    std::map<std::string, int> dictionary = {};
    for (int i = 0; i < 256; ++i) 
        dictionary[std::string(1, i)] = i;

    std::string current = "";
    for (char c : text) {
        std::string next = current + c;
        if (dictionary.find(next) != dictionary.end()) {
            current = next;
        }
        else {
            compressed.push_back(dictionary[current]);
            dictionary[next] = dictionary.size();
            current = std::string(1, c);
        }
    }
    if (!current.empty()) {
        compressed.push_back(dictionary[current]);
    }
    return compressed;
}

std::string decompress(const std::vector<int>& compressed) {
    std::string decompressed = "";
    std::map<int, std::string> dictionary = {};
    for (int i = 0; i < 256; ++i)
        dictionary[i] = std::string(1, i);
    std::string prev;
    for (int code : compressed) {
        std::string current;
        if (dictionary.find(code) != dictionary.end()) {
            current = dictionary[code];
        }
        else if (code == dictionary.size()) {
            current = prev + prev[0];
        }
        decompressed += current;
        if (!prev.empty()) {
            dictionary[dictionary.size()] = prev + current[0];
        }
        prev = current;
    }
    return decompressed;
}
