#include "SmartBookshelf.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>


SmartBookshelf::SmartBookshelf() {

}

SmartBookshelf::~SmartBookshelf() {

}

bool SmartBookshelf::addBook(const Book& book) {
    if (book.isbn.empty()) {
        std::cout << "empty ISBN！" << std::endl;
        return false;
    }
    auto result = booksByIsbn_.insert({book.isbn, book});
    if (!result.second) {
         std::cout << "ISBN '" << book.isbn << "' exists" << std::endl;
    }
    else {
        std::cout << "addBook success" << std::endl;
    }
    return result.second;
}

bool SmartBookshelf::removeBook(const std::string& isbn) {
    if (isbn.empty()) {
         std::cout << "empty ISBN！" << std::endl;
        return false;
    }
    size_t erased_count = booksByIsbn_.erase(isbn);
    if (erased_count == 0) {
         std::cout << "ISBN '" << isbn << "' not found" << std::endl;
    }
    else {
        std::cout << "removeBook success" << std::endl;
    }
    return erased_count > 0;
}

const Book* SmartBookshelf::findBookByISBN(const std::string& isbn) const {
    if (isbn.empty()) {
        std::cout << "empty ISBN！" << std::endl;
        return nullptr;
    }
    auto it = booksByIsbn_.find(isbn);
    if (it!= booksByIsbn_.end()) {
        std::cout << "ISBN '" << isbn << "' title:" << it->second.title << std::endl;
        return &(it->second);
    }
    std::cout << "ISBN '" << isbn << "' not found" << std::endl;
    return nullptr;
}

size_t SmartBookshelf::getBookCount() const {
    return booksByIsbn_.size();
}
