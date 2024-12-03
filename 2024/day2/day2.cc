#include <fstream>
#include <print>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream token_stream(s);
    std::string token;

    while (std::getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    std::vector<int> v;
    std::vector<int> d;
    std::string s;

    std::ifstream f("input");

    if (!f.is_open()) {
        std::println("Error f");
        return 1;
    }

    int safe{0};
    while (std::getline(f, s)) {
        for (auto s: split(s, ' ')) {
            v.push_back(std::stoi(s));
        }

        for (auto i = 0; i < v.size() - 1; ++i) {
            d.push_back(v[i] - v[i + 1]);
        }

        bool is_safe{true};

        for (auto i: d) {
            if (i <= 0 || i >= 4) {
                is_safe = false;
                break;
            }
        }

        bool is_safe2{true};

        for (auto i: d) {
            if (i >= 0 || i <= -4) {
                is_safe2 = false;
                break;
            }
        }

		if (is_safe || is_safe2)
			safe++;

        d.clear();
        v.clear();
    }

    std::println("{}", safe);
    f.close();

    return 0;
}
