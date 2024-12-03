#include <fstream>
#include <numeric>
#include <print>
#include <regex>
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

std::string remove_parts(std::string str) {
    size_t start_pos, end_pos;

    start_pos = str.find("don't()");
    while (start_pos != std::string::npos) {
        end_pos = str.find("do()", start_pos);
        if (end_pos != std::string::npos) {
            str.erase(start_pos, end_pos + 4 - start_pos);
        } else {
            str.erase(start_pos);
            break;
        }
        start_pos = str.find("don't()", start_pos);
    }

    return str;
}


int main() {
    std::string s;
    std::vector<std::string> v;
    std::vector<std::string> nv;
	std::vector<std::string> nnv;
    std::vector<int> ints;
    std::vector<int> left;
    std::vector<int> right;
    std::regex p(R"(mul\(\d+,\d+\)|(don't\(\))|do\(\))");
    std::ifstream f("input");

    if (f.is_open()) {
        s.assign((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
        f.close();
    }

    std::sregex_iterator begin(s.begin(), s.end(), p);
    std::sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
        v.push_back(it->str());
    }

    auto ns = remove_parts(std::accumulate(v.begin(), v.end(), std::string()));

    std::size_t pos = 0;
    while ((pos = ns.find("do()", pos)) != std::string::npos) {
        ns.erase(pos, 4);
    }

    for (auto i = 0; i < ns.length(); ++i) {
        if (ns[i] == ')') {
            ns.insert(i + 1, " ");
        }
    }

    nv = split(ns, ' ');

    for (auto &i: nv) {
        i.erase(std::remove_if(i.begin(), i.end(),
                               [](char c) { return c == 'm' || c == 'u' || c == 'l' || c == '(' || c == ')'; }),
                i.end());
    }

    for (auto &i: nv) {
        for (auto j: split(i, ','))
            nnv.push_back(j);
    }

    for (auto i: nnv)
        ints.push_back(std::stoi(i));

    for (auto i = 0; i < ints.size(); ++i) {
        if (i % 2 == 0)
            right.push_back(ints[i]);
        else
            left.push_back(ints[i]);
    }

    ints.clear();
    int result;
    for (auto i = 0; i < left.size(); ++i) {
        ints.push_back(left[i] * right[i]);
    }

    result = std::accumulate(ints.begin(), ints.end(), 0);


	std::println("{}", result);


    return 0;
}

