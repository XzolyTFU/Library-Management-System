#ifndef DVD_H
#define DVD_H

#include "Media.h"
#include "../interfaces/IBorrowable.h"

class DVD : public Media, public IBorrowable {
    std::string regisseur;
    int runtime;
    int age_restriction;

public:
    DVD(std::string title, std::string ID, std::string year, std::string place,
        std::string regisseur, int runtime, int age_restriction)
        : Media(title, ID, year, place),
          regisseur(regisseur), runtime(runtime),
          age_restriction(age_restriction) {}

    bool keyWord(std::string word) override {
        return word == title || word == regisseur;
    }

    void search() override {
        std::cout << title << " by " << regisseur << std::endl;
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
        std::cout << "DVD: " << title << std::endl;
    }

    std::string getType() const override { return "DVD"; }
};

#endif
