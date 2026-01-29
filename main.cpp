#include <iostream>
#include <string>
#include <set>
#include "DataStructure/Matcher.cpp"

int main() {
    // Testiamo il Matcher Linguistico
    std::string nomeA = "OrderDate";
    std::string nomeB = "Date";
    std::string nomeC = "Customer_ID";
    std::string nomeD = "customerID";

    std::cout << "--- TEST MATCHING LINGUISTICO ---\n";
    
    double sim1 = calculateLinguisticSimilarity(nomeA, nomeB);
    std::cout << "Confronto '" << nomeA << "' vs '" << nomeB << "': " << sim1 << "\n";
    // Dovrebbe dare 0.5 (hanno in comune "date", totale parole uniche "order", "date" -> 1 su 2)

    double sim2 = calculateLinguisticSimilarity(nomeC, nomeD);
    std::cout << "Confronto '" << nomeC << "' vs '" << nomeD << "': " << sim2 << "\n";
    // Dovrebbe dare 1.0 (token identici: "customer", "id")

    double sim3 = calculateLinguisticSimilarity("Prezzo", "Quantita");
    std::cout << "Confronto 'Prezzo' vs 'Quantita': " << sim3 << "\n";
    // Dovrebbe dare 0.0

    return 0;
}