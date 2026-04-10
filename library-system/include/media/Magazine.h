#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Media.h"
#include "../interfaces/IBorrowable.h"

class Magazine : public Media, public IBorrowable {
    std::string publisher;
    int nummer;

public:
    Magazine(std::string title, std::string ID, std::string year, std::string place,
             std::string publisher, int nummer)
        : Media(title, ID, year, place),
          publisher(publisher), nummer(nummer) {}

    bool keyWord(std::string word) override {
        return word == title || word == publisher;
    }

    void search() override {
        std::cout << title << " " << publisher << std::endl;
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
        std::cout << "Magazine: " << title << std::endl;
    }

    std::string getType() const override { return "Magazine"; }
};

#endif
