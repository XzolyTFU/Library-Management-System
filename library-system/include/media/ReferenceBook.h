#ifndef REFERENCEBOOK_H
#define REFERENCEBOOK_H

#include "Book.h"

class ReferenceBook : public Book {
    std::string edition;

public:
    ReferenceBook(std::string title, std::string ID, std::string year,
                  std::string place, std::string author,
                  std::string ISBN, int pages, std::string edition)
        : Book(title, ID, year, place, author, ISBN, pages),
          edition(edition) {}

    void display() override {
        std::cout << "ReferenceBook: " << title << std::endl;
    }

    std::string getType() const override { return "ReferenceBook"; }
};

#endif
