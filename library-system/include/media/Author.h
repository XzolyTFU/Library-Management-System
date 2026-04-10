#ifndef AUTHOR_H
#define AUTHOR_H

#include <memory>
#include <vector>
#include <string>
#include <iostream>

class Book;

class Author : public std::enable_shared_from_this<Author> {
    std::string name;
    std::vector<std::shared_ptr<Book>> books;

public:
    Author(std::string name) : name(name) {}

    void addBook(std::shared_ptr<Book> book) {
        books.push_back(book);
    }

    std::string getName() const { return name; }
};

#endif
