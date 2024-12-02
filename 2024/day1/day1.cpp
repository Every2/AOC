#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
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

int main() {
    std::vector<std::string> v;
    std::string s;

    std::ifstream f("input");

    if (!f.is_open()) {
        std::cerr << "Error f";
        return 1;
    }

    while (std::getline(f, s)) {
        s[5] = 't';
        v.push_back(s);
    }

    f.close();

    std::vector<std::string> nv;

    for (auto i: v)
        for (auto j: split(i, 't'))
			nv.push_back(j);

    std::vector<int> integers;
    for (std::string i: nv)
		integers.push_back(std::stoi(i));

    std::vector<int> left;
    std::vector<int> right;

    for (auto i{0}; i < integers.size(); ++i) {
        if (i % 2 == 0)
            right.push_back(integers[i]);
        else
            left.push_back(integers[i]);
    }

    std::stable_sort(left.begin(), left.end());
    std::stable_sort(right.begin(), right.end());

    std::vector<int> r;
    for (auto i {0}; i < left.size(); ++i)
		r.push_back(std::abs(left[i] - right[i]));
     
    int sum {std::accumulate(r.begin(), r.end(), 0)};

    std::cout << sum << '\n';

    return 0;
}
