#include <fstream>
#include <print>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream token_stream(s);
    std::string token;

    while (std::getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

bool check_if_safe(std::vector<int>& v) {
	std::vector<int> d;
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


    return is_safe || is_safe2;
}

int main() {
    std::vector<int> v;

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

	    
        for (auto i = 0; i < v.size(); ++i) {
            auto v2 = v;
            v2.erase(v2.begin() + i);
            if (check_if_safe(v2)) {
                safe++;
                break;
            }
        }

        v.clear();
    }

    std::println("{}", safe);
    f.close();

    return 0;
}
