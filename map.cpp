#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> phoneBook;

    phoneBook["Alice"] = "123-456-7890";
    phoneBook["Bob"] = "987-654-3210";
    phoneBook["Carol"] = "555-555-5555";

    std::cout << "Phone Book Entries:" << std::endl;
    for (const auto& entry : phoneBook) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    std::string nameToSearch = "Bob";
    if (phoneBook.find(nameToSearch) != phoneBook.end()) {
        std::cout << nameToSearch << "'s Phone Number: " << phoneBook[nameToSearch] << std::endl;
    } else {
        std::cout << nameToSearch << " not found in the phone book." << std::endl;
    }

    return 0;
}
