#include "media/ReferenceBook.h"
#include <iostream>
#include <utility>

ReferenceBook::ReferenceBook() : Book(), topic("") {}

ReferenceBook::ReferenceBook(std::string t,
                             std::string a,
                             std::string i,
                             int y,
                             std::string loc,
                             int p,
                             std::string top)
    : Book(std::move(t), std::move(a), std::move(i), y, std::move(loc), p),
      topic(std::move(top)) {}

std::string ReferenceBook::getType() const {
    return "ReferenceBook";
}

void ReferenceBook::display() const {
    std::cout << "[ReferenceBook] ";
    Book::display();
    std::cout << "  Topic: " << topic << "\n";
}

bool ReferenceBook::matches(std::string query) const {
    return Book::matches(query) || topic.find(query) != std::string::npos;
}
