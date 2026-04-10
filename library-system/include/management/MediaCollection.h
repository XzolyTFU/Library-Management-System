#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H

#include <vector>
#include <memory>
#include <string>
#include "../media/Media.h"

class MediaCollection {
    std::string name;
    std::vector<std::unique_ptr<Media>> items;

public:
    MediaCollection(std::string name) : name(name) {}

    MediaCollection(const MediaCollection&) = delete;
    MediaCollection& operator=(const MediaCollection&) = delete;

    MediaCollection(MediaCollection&& other) noexcept
        : name(std::move(other.name)),
          items(std::move(other.items)) {}

    MediaCollection& operator=(MediaCollection&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            items = std::move(other.items);
        }
        return *this;
    }

    void addMedia(std::unique_ptr<Media> m) {
        items.push_back(std::move(m));
    }

    size_t size() const { return items.size(); }
};

#endif
