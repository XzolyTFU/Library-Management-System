#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include "../media/Media.h"

class Library {
    std::string name;
    int capacity;
    std::vector<std::unique_ptr<Media>> media;

public:
    Library(std::string name, int capacity)
        : name(name), capacity(capacity) {}

    bool addMedia(std::unique_ptr<Media> m) {
        if (media.size() >= static_cast<size_t>(capacity)) return false;
        media.push_back(std::move(m));
        return true;
    }

    void displayAll() const {
        for (const auto& m : media) m->display();
    }
};

#endif
