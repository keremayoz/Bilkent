//
//  Book.cpp
//  Homework
//
//  Created by Kerem Ayöz on 10.04.2017.
//  Copyright © 2017 Kerem Ayöz. All rights reserved.
//

#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

Book::Book(string title, string publisher, int year, int authorCount) {
    this->bookTitle = title;
    this->publisher = publisher;
    this->year = year;
    this->authorCount = authorCount;
    this->authors = NULL;
}

Book::Book(const Book & obj) {
    bookTitle = obj.bookTitle;
    publisher = obj.publisher;
    year = obj.year;
    authorCount = obj.authorCount;
    if (obj.authors != NULL) {
        authors = new string[obj.authorCount];
        for (int i = 0; i < obj.authorCount; i++)
            *authors = obj.authors[i];
    }
    else
        authors = NULL;
}

Book::Book() {
    bookTitle = "";
    publisher = "";
    year = 0;
    authorCount = 0;
    authors = NULL;
}

Book::~Book() {
    if (authors != NULL)
        delete[] authors;
}

void Book::operator=(const Book & b) {
    if (&b != this) {
        bookTitle = b.bookTitle;
        publisher = b.publisher;
        year = b.year;
        if (authorCount != b.authorCount) {
            if (authorCount > 0)
                delete[]authors;
            authorCount = b.authorCount;
            if (authorCount > 0)
                authors = new string[authorCount];
            else
                authors = NULL;
        }
        for (int i = 0; i < authorCount; i++)
            authors[i] = b.authors[i];
    }
}

string Book::getBookTitle() {
    return bookTitle;
}

string Book::getPublisher() {
    return publisher;
}

int Book::getYear() {
    return year;
}

string * Book::getAuthors() {
    return authors;
}

int Book::getAuthorCount() {
    return authorCount;
}

void Book::setBookTitle(string newTitle) {
    bookTitle = newTitle;
}

void Book::setPublisher(string newPublisher) {
    publisher = newPublisher;
}

void Book::setYear(int newYear) {
    year = newYear;
}

void Book::setAuthors(string * newAuthors) {
    delete[] authors;
    authors = NULL;
    authors = newAuthors;
}

void Book::setAuthorCount(int newAuthorCount) {
    authorCount = newAuthorCount;
}

void Book::deleteAuthors() {
    delete[] (this -> authors);
}
