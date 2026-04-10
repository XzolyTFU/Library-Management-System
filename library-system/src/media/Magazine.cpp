#include "media/Magazine.h"
#include <iostream>
#include <utility>

Magazine::Magazine() : Media(), issueNumber(0), year(0) {}

Magazine::Magazine(std::string t, int issue, int y, std::string loc)
    : Media(std::move(t), std::move(loc)), issueNumber(issue), year(y) {}

std::string Magazine::getType() const {
    return "Magazine";
}

void Magazine::display() const {
    std::cout << "[Magazine] " << title
              << " | Issue: " << issueNumber
              << " | Year: " << year
              << " | Location: " << location
              << "\n";
}

bool Magazine::matches(std::string query) const {
    return title.find(query) != std::string::npos;
}
