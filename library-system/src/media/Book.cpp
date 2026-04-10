#include "media/Book.h"
#include "media/Author.h"
#include <iostream>
#include <utility>

Book::Book()
    : Media(), authorName(""), isbn(""), year(0), pages(0),
      borrowed(false), borrower("") {}

Book::Book(std::string t,
           std::string a,
           std::string i,
           int y,
           std::string loc,
           int p)
    : Media(std::move(t), std::move(loc)),
      authorName(std::move(a)), isbn(std::move(i)),
      year(y), pages(p),
      borrowed(false), borrower("") {}

std::string Book::getType() const {
    return "Book";
}

void Book::display() const {
    std::cout << "[Book] " << title << " | Author: " << authorName
              << " | ISBN: " << isbn << " | Year: " << year
              << " | Pages: " << pages << " | Location: " << location;

    if (borrowed) {
        std::cout << " | Borrowed by: " << borrower;
    } else {
        std::cout << " | Available";
    }

    // Show linked author (weak_ptr) if available
    if (auto a = authorPtr.lock()) {
        std::cout << " | AuthorObj: " << a->getName();
    } else {
        std::cout << " | AuthorObj: (none)";
    }

    std::cout << "\n";
}

bool Book::matches(std::string query) const {
    return title.find(query) != std::string::npos
        || authorName.find(query) != std::string::npos
        || isbn.find(query) != std::string::npos;
}

bool Book::isBorrowed() const {
    return borrowed;
}

void Book::borrowItem(std::string borrowerName) {
    borrowed = true;
    borrower = std::move(borrowerName);
}

void Book::returnItem() {
    borrowed = false;
    borrower = "";
}

std::string Book::getBorrowerName() const {
    return borrower;
}

void Book::setAuthor(std::shared_ptr<Author> author) {
    authorPtr = author;
}

std::shared_ptr<Author> Book::getAuthor() const {
    return authorPtr.lock();
}

bool Book::authorExpired() const {
    return authorPtr.expired();
}
