#ifndef BOOK_H
#define BOOK_H

#include "Media.h"
#include "../interfaces/IBorrowable.h"

class Book : public Media, public IBorrowable {
protected:
    std::string author;
    std::string ISBN;
    int pages;

public:
    Book(std::string title, std::string ID, std::string year, std::string place,
         std::string author, std::string ISBN, int pages)
        : Media(title, ID, year, place),
          author(author), ISBN(ISBN), pages(pages) {}

    bool keyWord(std::string word) override {
        return word == title || word == author;
    }

    void search() override {
        std::cout << title << " by " << author << std::endl;
    }

    void borrow(std::string user) override {
        if (!isBorrowed) {
            borrower = user;
            isBorrowed = true;
        }
    }

    void giveBack() override {
        isBorrowed = false;
    }

    void availablity() override {
        std::cout << (isBorrowed ? "not available" : "available") << std::endl;
    }

    void display() override {
        std::cout << "Book: " << title << " " << author << std::endl;
    }

    std::string getType() const override { return "Book"; }
};

#endif
