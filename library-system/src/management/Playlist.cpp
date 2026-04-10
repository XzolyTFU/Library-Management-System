#include "management/Playlist.h"
#include <iostream>
#include <utility>

Playlist::Playlist() : name("") {}

Playlist::Playlist(std::string n) : name(std::move(n)) {}

std::string Playlist::getName() const {
    return name;
}

void Playlist::addDVD(std::shared_ptr<DVD> dvd) {
    dvds.push_back(std::move(dvd));
}

void Playlist::removeDVD(std::string title) {
    for (std::size_t i = 0; i < dvds.size(); ) {
        if (dvds[i] && dvds[i]->getTitle() == title) {
            dvds.erase(dvds.begin() + static_cast<long>(i));
        } else {
            i++;
        }
    }
}

void Playlist::display() const {
    std::cout << "Playlist: " << name << "\n";
    if (dvds.empty()) {
        std::cout << "  (empty)\n";
        return;
    }
    for (std::size_t i = 0; i < dvds.size(); i++) {
        if (dvds[i]) {
            std::cout << "  ";
            dvds[i]->display();
            std::cout << "    use_count: " << dvds[i].use_count() << "\n";
        }
    }
}

std::size_t Playlist::size() const {
    return dvds.size();
}
