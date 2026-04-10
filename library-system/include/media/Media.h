#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>
#include "../interfaces/ISearchable.h"

class Media : public ISearchable {
protected:
    std::string title;
    std::string ID;
    std::string year;
    std::string place;

public:
    Media(std::string title, std::string ID, std::string year, std::string place)
        : title(title), ID(ID), year(year), place(place) {}

    std::string getTitle() const { return title; }
    std::string getID() const { return ID; }
    std::string getYear() const { return year; }
    std::string getPlace() const { return place; }

    virtual void display() = 0;
    virtual std::string getType() const = 0;
    virtual ~Media() {}
};

#endif
