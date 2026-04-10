#include "management/Library.h"
#include <iostream>
#include <utility>

Library::Library() : name("") {}

Library::Library(std::string n) : name(std::move(n)) {}

std::string Library::getName() const {
    return name;
}

void Library::addMedia(std::unique_ptr<Media> item) {
    media.push_back(std::move(item)); // transfer ownership (move)
}

void Library::displayAll() const {
    std::cout << "Library: " << name << "\n";
    if (media.empty()) {
        std::cout << "  (no media)\n";
        return;
    }
    for (std::size_t i = 0; i < media.size(); i++) {
        if (media[i]) {
            std::cout << "  ";
            media[i]->display();
        }
    }
}

std::size_t Library::getMediaCount() const {
    return media.size();
}
