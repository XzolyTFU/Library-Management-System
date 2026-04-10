#include "management/MediaCollection.h"
#include <utility>

MediaCollection::MediaCollection() : name("") {}

MediaCollection::MediaCollection(std::string n) : name(std::move(n)) {}

MediaCollection::MediaCollection(MediaCollection&& other) noexcept
    : name(std::move(other.name)),
      items(std::move(other.items)) {
    // moved-from other is left valid by std::move of vector/string
}

MediaCollection& MediaCollection::operator=(MediaCollection&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    name = std::move(other.name);
    items = std::move(other.items);
    return *this;
}

void MediaCollection::addMedia(std::unique_ptr<Media> item) {
    items.push_back(std::move(item));
}

std::size_t MediaCollection::size() const {
    return items.size();
}

std::string MediaCollection::getName() const {
    return name;
}
