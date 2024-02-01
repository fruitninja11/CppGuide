// Bug: Incorrectly counting number of countries against which the batter has never scored a century
// Changes Made: Used a map to keep track of centuries scored against each country and then checked for non-century scoring countries

#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, bool> hasCentury;

    std::cout << "Enter country and runs (Country:Runs) or 'exit' to finish: " << std::endl;

    std::string input;
    while (true) {
        std::cin >> input;
        if (input == "exit") {
            break;
        }

        size_t found = input.find(':');
        if (found != std::string::npos) {
            std::string country = input.substr(0, found);
            int runs = std::stoi(input.substr(found + 1));

            if (runs >= 100) {
                hasCentury[country] = true;
            } else {
                if (hasCentury.find(country) == hasCentury.end()) {
                    hasCentury[country] = false;
                }
            }
        } else {
            std::cout << "Invalid input format. Please enter in 'Country:Runs' format." << std::endl;
        }
    }

    int nonCenturyCountries = 0;
    for (const auto &entry : hasCentury) {
        if (!entry.second) {
            nonCenturyCountries++;
        }
    }

    std::cout << "Number of countries against which the batter has never scored a century: " << nonCenturyCountries << std::endl;

    return 0;
}
