#include "Library.h"
#include <iostream>
#include <string>
using namespace std;

Library::Library() {
    books = NULL;
    numberOfBooks = 0;
}

Library::~Library() {
    if (books != NULL)
        delete[] books;
}

void Library::addBook(string bookTitle, string publishingHouse, int publishingYear) {
    //Checking the existence
    if (findBook(bookTitle) != -1) {
        cout << "The book " << bookTitle << " is already in the library" << endl;
        return;
    }
    else {
        //Creating the book
   //     Book *newBook = new Book(bookTitle,publishingHouse,publishingYear,0);
        if (books == NULL) {
            books = new Book*[++numberOfBooks];
            books[0] = new Book(bookTitle,publishingHouse,publishingYear,0);//newBook;
        }
        else {
            Book** temp = new Book*[++numberOfBooks];
            for (int i = 0; i < numberOfBooks - 1; i++) {
                temp[i] = books[i];
            }
            temp[numberOfBooks - 1] = new Book(bookTitle,publishingHouse,publishingYear,0);//newBook;
            delete[]books;
            books = NULL;
            books = temp;
        }
    }
    
}

void Library::removeBook(string bookTitle) {
    if (findBook(bookTitle) == -1) {
        cout << "The book " << bookTitle << " is not in the library" << endl;
        return;
    }
    else {
        int index = findBook(bookTitle);
        delete books[index];
        for (int i = index; i < numberOfBooks-1; i++)
            books[i] = books[i+1];
        numberOfBooks--;
    }
}

void Library::addCoauthor(string bookTitle, string coauthorName) {
    if (findBook(bookTitle) == -1) {
        cout << "The book " << bookTitle << " is not in the library" << endl;
        return;
    }
    else {
        int index = findBook(bookTitle);
        //Checking the existence of the author
        bool found = false;
        for (int i = 0; i < books[index]->getAuthorCount() && !found; i++) {
            if (caseControl((books[index]->getAuthors())[i], coauthorName) == 0)
                found = true;
        }
        if (found) {
            cout <<"The author " << coauthorName << " is in already in the author list" << endl;
            return;
        }
        else {
            //Incrementing the authorCount
            books[index]->setAuthorCount(books[index]->getAuthorCount() + 1);
            //Creating temp to change the array
            string* temp = new string[books[index]->getAuthorCount()];
            for (int i = 0; i < books[index]->getAuthorCount() - 1; i++)
                temp[i] = books[index]->getAuthors()[i];
            //Assigning the new one
            temp[books[index]->getAuthorCount()-1] = coauthorName;
            books[index]->setAuthors(temp);
        }
    }
}

void Library::removeCoauthor(string bookTitle, string coauthorName) {
    if (findBook(bookTitle) == -1) {
        cout << "The book " << bookTitle << " is not in the library" << endl;
        return;
    }
    else {
        int index = findBook(bookTitle);
        //Checking the existence of the author
        bool found = false;
        int autIn = 0;
        for (int i = 0; !found && i < books[index]->getAuthorCount() ; i++) {
            if (caseControl((books[index]->getAuthors())[i], coauthorName) == 0) {
                found = true;
                autIn = i;
            }
        }
        if (!found) {
            cout << "The author " << coauthorName << " is not in the author list" << endl;
            return;
        }
        else {
            string* temp = new string[books[index]->getAuthorCount()-1];
            //Deep Copying
            for (int i = 0; i < autIn; i++)
                temp[i] = books[index]->getAuthors()[i];
            
            for (int i = autIn + 1; i < books[index]->getAuthorCount(); i++)
                temp[i - 1] = books[index]->getAuthors()[i];
            //Assigning the new array
            books[index]->setAuthors(temp);
            books[index]->setAuthorCount(books[index]->getAuthorCount() - 1);
        }
    }
}

void Library::displayAllBooks() {
    if (numberOfBooks == 0) {
        cout << "--EMPTY--" << endl;
        return;
    }
    for (int i = 0; i < numberOfBooks; i++) {
        cout << books[i]->getBookTitle() << ", " << books[i]->getYear() << endl;
    }
}

void Library::displayBook(string bookTitle) {
    if (findBook(bookTitle) == -1) {
        cout << "This book is not in the library" << endl;
        return;
    }
    int in = findBook(bookTitle);
    cout << books[in]->getBookTitle() << ", " << books[in]->getYear() << endl;
    for (int i = 0; i < books[in]->getAuthorCount(); i++) {
        cout << books[in]->getAuthors()[i] << endl;
    }
}

void Library::displayAuthor(string authorName) {
    cout << authorName << endl;
    for (int i = 0; i < numberOfBooks; i++) {
        for (int j = 0; j < books[i]->getAuthorCount(); j++) {
            if (caseControl(books[i]->getAuthors()[j], authorName) == 0)
                cout << books[i]->getBookTitle() << ", " << books[i]->getYear() << endl;
        }
    }
}

int Library::findBook(string title) {
    if (books == NULL)
        return -1;
    for (int i = 0; i < numberOfBooks; i++)
        if (caseControl((books[i])->getBookTitle(), title) == 0)
            return i;
    return -1;
}

int Library::caseControl(string s1, string s2) {
    int counter = 0;
    char c;
    while (counter < s1.size()) {
        c = s1[counter];
        s1[counter] = tolower(c);
        counter++;
    }
    counter = 0;
    while (counter < s2.size()) {
        c = s2[counter];
        s2[counter] = tolower(c);
        counter++;
    }
    return (s1 == s2 ? 0 : -1);
    
}




