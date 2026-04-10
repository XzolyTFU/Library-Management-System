#include "media/Media.h"
#include <utility>

Media::Media() : title(""), location("") {}

Media::Media(std::string t, std::string loc) : title(std::move(t)), location(std::move(loc)) {}

std::string Media::getTitle() const {
    return title;
}

std::string Media::getLocation() const {
    return location;
}
