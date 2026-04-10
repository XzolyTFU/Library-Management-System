#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include <memory>
#include "../media/DVD.h"

class Playlist {
    std::vector<std::shared_ptr<DVD>> dvds;

public:
    void addDVD(std::shared_ptr<DVD> dvd) {
        dvds.push_back(dvd);
    }

    void display() const {
        for (const auto& d : dvds) {
            d->display();
        }
    }
};

#endif
