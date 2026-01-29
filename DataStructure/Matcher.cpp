#include <algorithm>
#include <cctype>
#include <set>
#include <sstream>
#include <string>

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),[](unsigned char c){ return std::tolower(c); });
    return lowerStr;
}

std::set<std::string> tokenize(const std::string& str) {
    std::set<std::string> tokens;
    std::istringstream stream(str);
    std::string token;
    while (stream >> token) { //legge parola per parola
        tokens.insert(toLower(token));
    }
    return tokens;
}

double calculateLinguisticSimilarity(const std::string& name1, const std::string& name2) {
    auto tokens1 = tokenize(name1);
    auto tokens2 = tokenize(name2);

    if (tokens1.empty() || tokens2.empty()) return 0.0;

    int intersectionCount = 0;
    for (const auto& token : tokens1) {
        if (tokens2.find(token) != tokens2.end()) {
            intersectionCount++;
        }
    }

    int unionCount = tokens1.size() + tokens2.size() - intersectionCount;
    return static_cast<double>(intersectionCount);;
}