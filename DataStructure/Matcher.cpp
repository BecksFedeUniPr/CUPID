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

bool shouldSplit(char c, const std::string& current) {
    // Spezza quando trova maiuscola (se current non è vuoto) o underscore
    return (std::isupper(c) && !current.empty()) || c == '_';
}

std::set<std::string> tokenize(const std::string& str) {
    std::set<std::string> tokens;
    std::istringstream stream(str);
    std::string token;
    while (stream >> token) { //legge parola per parola
        std::string current = "";
        for (size_t i = 0; i < token.size(); ++i) {
            if (shouldSplit(token[i], current)) {
                // per evitare token vuoti
                if (!current.empty()) {
                    tokens.insert(toLower(current));
                }
                // Inizia nuovo token
                current = (token[i] == '_') ? "" : std::string(1, token[i]);
            } else {
                // aggiunge carattere al token corrente
                current += token[i];
            }
        }
        if (!current.empty()) {
            tokens.insert(toLower(current));
        }
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
    return (double)intersectionCount / unionCount;
}