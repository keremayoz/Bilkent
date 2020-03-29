//
//  Library.h
//  Homework
//
//  Created by Kerem Ayöz on 10.04.2017.
//  Copyright © 2017 Kerem Ayöz. All rights reserved.
//
#include <string>
#include "Book.h"
using namespace std;
class Library {
public:
    Library();
    ~Library();
    void addBook(string bookTitle, string publishingHouse, int publishingYear);
    void removeBook(string bookTitle);
    
    void addCoauthor(string bookTitle, string coauthorName);
    void removeCoauthor(string bookTitle, string coauthorName);
    
    void displayAllBooks();
    void displayBook(string bookTitle);
    void displayAuthor(string authorName);
    
    int findBook(string title);
    int caseControl(string s1, string s2);
    
    Book **books;
    int numberOfBooks;
    
};

