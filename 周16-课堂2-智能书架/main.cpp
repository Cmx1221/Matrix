#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "SmartBookshelf.h"

void printBook(const Book* book, const std::string& prefix = "") {
    if (book) {
        std::cout << prefix << "Title: " << book->title
                  << ", Author: " << book->author
                  << ", ISBN: " << book->isbn
                  << ", Year: " << book->publicationYear << std::endl;
    } else {
        std::cout << prefix << "Book not found." << std::endl;
    }
}

void printBooksVector(const std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books to display." << std::endl;
    } else {
        for (const auto& book : books) {
            printBook(&book);
        }
    }
}


int main() {
    SmartBookshelf shelf;

    // 1. 添加书籍
    std::string name1,name2,name3;
    std::string writer1,writer2,writer3;
    std::string isbn1,isbn2,isbn3;
    int year1,year2,year3;
    std::cin>>name1>>writer1>>isbn1>>year1;
    std::cin>>name2>>writer2>>isbn2>>year2;
    std::cin>>name3>>writer3>>isbn3>>year3;
    Book b1 = {name1, writer1, isbn1, year1};
    Book b2 = {name2, writer2, isbn2, year2};
    Book b3 = {name3, writer3, isbn3, year3};

    shelf.addBook(b1);
    shelf.addBook(b2);
    shelf.addBook(b3);
    std::cout << shelf.getBookCount() << std::endl;

    // 2. 查找书籍
    const Book* found_b1 = shelf.findBookByISBN(isbn1);
    const Book* not_found_book = shelf.findBookByISBN("000-0000000000");

    // 3. 移除书籍
    shelf.removeBook(isbn1);
    std::cout << shelf.getBookCount() << std::endl;
    shelf.removeBook("111-1111111111");
    std::cout << shelf.getBookCount() << std::endl;
    const Book* find_b2_after_removal = shelf.findBookByISBN(isbn1);
    printBook(find_b2_after_removal);

    // 测试空ISBN
    Book b_empty_isbn = {"Empty Test", "Test Author", "", 2024};
    shelf.addBook(b_empty_isbn);
    shelf.findBookByISBN("");
    shelf.removeBook("");

    return 0;
}
