#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitString(const string &s, const string &delimiters) {
    vector<string> tokens;
    size_t start = s.find_first_not_of(delimiters);
    while (start != string::npos) {
        size_t end = s.find_first_of(delimiters, start);
        tokens.push_back(s.substr(start, end - start));
        start = s.find_first_not_of(delimiters, end);
    }
    return tokens;
}

int main() {
    string input = "apple,orange;banana,grape;melon";
    // Here, both ',' and ';' are used as delimiters.
    vector<string> words = splitString(input, ",;");
    
    for (const auto &word : words) {
        cout << word << "\n";
    }
    return 0;
}