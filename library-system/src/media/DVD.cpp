#include "media/DVD.h"
#include <iostream>
#include <utility>

DVD::DVD()
    : Media(), director(""), durationMinutes(0), year(0), ageRating(0),
      borrowed(false), borrower("") {}

DVD::DVD(std::string t,
         std::string d,
         int dur,
         int y,
         std::string loc,
         int ar)
    : Media(std::move(t), std::move(loc)),
      director(std::move(d)), durationMinutes(dur), year(y), ageRating(ar),
      borrowed(false), borrower("") {}

std::string DVD::getType() const {
    return "DVD";
}

void DVD::display() const {
    std::cout << "[DVD] " << title
              << " | Director: " << director
              << " | Duration: " << durationMinutes << " min"
              << " | Year: " << year
              << " | Age: " << ageRating
              << " | Location: " << location;

    if (borrowed) {
        std::cout << " | Borrowed by: " << borrower;
    } else {
        std::cout << " | Available";
    }
    std::cout << "\n";
}

bool DVD::matches(std::string query) const {
    return title.find(query) != std::string::npos
        || director.find(query) != std::string::npos;
}

bool DVD::isBorrowed() const {
    return borrowed;
}

void DVD::borrowItem(std::string borrowerName) {
    borrowed = true;
    borrower = std::move(borrowerName);
}

void DVD::returnItem() {
    borrowed = false;
    borrower = "";
}

std::string DVD::getBorrowerName() const {
    return borrower;
}
