// Bug: Incorrectly counting number of countries against which the batter has never scored a century
// Changes Made: Used a map to keep track of centuries scored against each country and then checked for non-century scoring countries

#include <iostream>
#include <string>
#include <map>

int main() {
    std::string country;
    int runs;
    std::map<std::string, bool> hasCentury;

    while (std::cin >> country >> runs) {
        if (runs >= 100) {
            hasCentury[country] = true;
        } else {
            // If runs are not a century, set the value to false or keep it as false if not present in the map
            if (hasCentury.find(country) == hasCentury.end()) {
                hasCentury[country] = false;
            }
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
