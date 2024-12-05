#include <fstream>
#include <print>
#include <string>
#include <vector>


int main() {
    std::string s;
    std::vector<std::string> v;
    int soma = 0;
    std::ifstream f("input");

    if (!f.is_open()) {
        std::println("Error f");
        return 1;
    }

    while (std::getline(f, s)) {
        v.push_back(s);
    }

    std::string word{"XMAS"};
    for (std::vector<std::string>::iterator iter = v.begin(); iter != v.end(); ++iter) {
        for (std::size_t pos = 0; pos < (*iter).length(); pos += word.length()) {
            pos = (*iter).find(word, pos);
            if (pos != std::string::npos)
                ++soma;
            else
                break;
        }
    }

    std::string word2{"SAMX"};
    for (std::vector<std::string>::iterator iter = v.begin(); iter != v.end(); ++iter) {
        for (std::size_t pos = 0; pos < (*iter).length(); pos += word2.length()) {
            pos = (*iter).find(word2, pos);
            if (pos != std::string::npos)
                ++soma;
            else
                break;
        }
    }

    for (std::size_t col = 0; col < 140; ++col) {
        std::string vertical_string;

        for (const auto& row: v) {
            if (col < row.length())
                vertical_string.push_back(row[col]);
        }

        std::size_t pos = 0;
        while ((pos = vertical_string.find(word2, pos)) != std::string::npos) {
            ++soma;
            pos += word2.length();
        }
    }

    for (std::size_t col = 0; col < 140; ++col) {
        std::string vertical_string;

        for (const auto& row: v) {
            if (col < row.length())
                vertical_string.push_back(row[col]);
        }

        std::size_t pos = 0;
        while ((pos = vertical_string.find(word, pos)) != std::string::npos) {
            ++soma;
            pos += word.length();
        }
    }

    std::println("{}", soma);
}
