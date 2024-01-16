#include <iostream>
#include <vector>
#include <stdexcept>

class Book
{
public:
    std::string title, author;
    int year;
    Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {}
};

class Library
{
    std::vector<Book> books;

public:
    void addBook(const Book &b) { books.push_back(b); }
    void displayBooks()
    {
        for (auto &b : books)
            std::cout << "Title: " << b.title << ", Author: " << b.author << ", Year: " << b.year << std::endl;
    }
    Book *searchBook(const std::string &title)
    {
        for (auto &b : books)
            if (b.title == title)
                return &b;
        return nullptr;
    }
};

int main()
{
    Library lib;
    lib.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    lib.addBook(Book("1984", "George Orwell", 1949));
    lib.displayBooks();

    Book *found = lib.searchBook("1984");
    if (found)
        std::cout << "Found: " << found->title << std::endl;
    else
        std::cout << "Book not found" << std::endl;
}
