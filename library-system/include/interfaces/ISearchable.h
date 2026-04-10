#ifndef ISEARCHABLE_H
#define ISEARCHABLE_H

#include <string>

class ISearchable {
public:
    virtual bool keyWord(std::string word) = 0;
    virtual void search() = 0;
    virtual ~ISearchable() {}
};

#endif
