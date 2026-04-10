#ifndef IBORROWABLE_H
#define IBORROWABLE_H

#include <string>

class IBorrowable {
public:
    std::string borrower;
    bool isBorrowed = false;

    virtual void borrow(std::string user) = 0;
    virtual void giveBack() = 0;
    virtual void availablity() = 0;
    virtual ~IBorrowable() {}
};

#endif
