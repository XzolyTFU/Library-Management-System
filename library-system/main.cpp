#include <memory>
#include "include/management/Library.h"
#include "include/media/Book.h"
#include "include/media/DVD.h"
#include "include/media/Magazine.h"
#include "include/media/ReferenceBook.h"
#include "include/management/Playlist.h"
#include "include/management/MediaCollection.h"
#include "include/util/ScopedLogger.h"

int main() {
    Library lib("My Library", 10);

    auto b = std::make_unique<Book>("Atomic Habits", "B1", "2018", "USA",
                                    "James Clear", "111", 320);

    auto d = std::make_shared<DVD>("Tounes Rahi Behya", "D102", "2021", "TUNISIA",
                                   "EL Ghrab", 90, 18);

    lib.addMedia(std::move(b));
    lib.displayAll();

    Playlist p1;
    Playlist p2;
    p1.addDVD(d);
    p2.addDVD(d);

    {
        ScopedLogger log("MoveTest");
        MediaCollection c1("Test");
        c1.addMedia(std::make_unique<Book>("C++", "B2", "2020",
                                           "DE", "Bjarne", "222", 500));
        MediaCollection c2 = std::move(c1);
    }

    return 0;
}
