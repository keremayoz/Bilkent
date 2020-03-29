//
//  Book.h
//  Homework
//
//  Created by Kerem Ayöz on 10.04.2017.
//  Copyright © 2017 Kerem Ayöz. All rights reserved.
//
#include <string>
using namespace std;

class Book {
    
public:
    
    Book(string title, string publisher, int year, int authorCount);
    Book(const Book &obj);
    Book();
    ~Book();
    
    void operator=(const Book &b);
    
    //Getters
    string getBookTitle();
    string getPublisher();
    int getYear();
    string* getAuthors();
    int getAuthorCount();
    
    //Setters
    void setBookTitle(string newTitle);
    void setPublisher(string newPublisher);
    void setYear(int newYear);
    void setAuthors(string* newAuthors);
    void setAuthorCount(int newAuthorCount);
    void deleteAuthors();
    
private:
    string bookTitle;
    string publisher;
    int year;
    string *authors;
    int authorCount;
};


