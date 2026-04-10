#include "util/MediaFactory.h"
#include <memory>
#include <utility>

std::unique_ptr<Book> createBook(std::string title,
                                std::string author,
                                std::string isbn,
                                int year,
                                std::string location,
                                int pages) {
    return std::make_unique<Book>(std::move(title),
                                 std::move(author),
                                 std::move(isbn),
                                 year,
                                 std::move(location),
                                 pages);
}

std::unique_ptr<DVD> createDVD(std::string title,
                              std::string director,
                              int durationMinutes,
                              int year,
                              std::string location,
                              int ageRating) {
    return std::make_unique<DVD>(std::move(title),
                                std::move(director),
                                durationMinutes,
                                year,
                                std::move(location),
                                ageRating);
}

std::unique_ptr<Magazine> createMagazine(std::string title,
                                        int issueNumber,
                                        int year,
                                        std::string location) {
    return std::make_unique<Magazine>(std::move(title),
                                     issueNumber,
                                     year,
                                     std::move(location));
}

std::unique_ptr<ReferenceBook> createReferenceBook(std::string title,
                                                  std::string author,
                                                  std::string isbn,
                                                  int year,
                                                  std::string location,
                                                  int pages,
                                                  std::string topic) {
    return std::make_unique<ReferenceBook>(std::move(title),
                                          std::move(author),
                                          std::move(isbn),
                                          year,
                                          std::move(location),
                                          pages,
                                          std::move(topic));
}
