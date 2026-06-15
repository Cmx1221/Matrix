#ifndef SMART_BOOKSHELF_HPP
#define SMART_BOOKSHELF_HPP

#include <string>
#include <vector>
#include <map>

struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    int publicationYear;

    bool operator==(const Book& other) const {
        return isbn == other.isbn;
    }
};

class SmartBookshelf {
private:
    std::map<std::string, Book> booksByIsbn_;
public:
    SmartBookshelf();
    ~SmartBookshelf();

    bool addBook(const Book& book);
    bool removeBook(const std::string& isbn);
    const Book* findBookByISBN(const std::string& isbn) const;
    size_t getBookCount() const;
};

#endif
