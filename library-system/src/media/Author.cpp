#include "media/Author.h"
#include "media/Book.h"
#include <iostream>
#include <utility>

Author::Author() : name("") {}

Author::Author(std::string n) : name(std::move(n)) {}

std::string Author::getName() const {
    return name;
}

void Author::addBook(std::shared_ptr<Book> book) {
    books.push_back(std::move(book));
}

void Author::displayBooks() const {
    std::cout << "Author: " << name << "\n";
    if (books.empty()) {
        std::cout << "  (no books)\n";
        return;
    }

    for (std::size_t i = 0; i < books.size(); i++) {
        if (books[i]) {
            std::cout << "  - " << books[i]->getTitle() << "\n";
        }
    }
}
