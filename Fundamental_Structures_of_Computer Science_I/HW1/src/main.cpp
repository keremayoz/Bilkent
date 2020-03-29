//
//  main.cpp
//  Homework
//
//  Created by Kerem Ayöz on 10.04.2017.
//  Copyright © 2017 Kerem Ayöz. All rights reserved.
//
/*
#include "Library.h"
#include <iostream>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;
int main() {
    
    Library *y = new Library();
    
    y->addBook("Republic", "Love Studios", 2010);
    
    y->addCoauthor("Republic", "Plato");
    
    y->addBook("1984", "Loves Pres", 1998);
    y->addBook("The Short History of Life", "Boston Books", 2009);
    cout << "----" << endl;
    y->addCoauthor("Republic", "Kerem");
    cout << "----" << endl;
    y->addCoauthor("The Short History of Life", "Kerem");
    cout << "----" << endl;
    y->addCoauthor("1984", "Kerem");
    cout << "----" << endl;
    
    y->removeCoauthor("Republic", "Plato");
    cout << "----" << endl;
    y->displayAuthor("Kerem");
    cout << endl << endl;
    y->removeBook("repuBLic");
    y->displayAllBooks();
    
    delete y;
    _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
};*/

#include "Library.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    
    Library *y = new Library();
    
    y->addBook("Republic", "Love Studios", 2010);
    y->addCoauthor("Republic", "Plato");
    cout << "THE END" <<endl;
    
    y->addBook("1984", "Loves Pres", 1998);
    y->addBook("The Short History of Life", "Boston Books", 2009);
    
    y->addCoauthor("Republic", "Kerem");
    y->addCoauthor("The Short History of Life", "Kerem");
    y->addCoauthor("1984", "Kerem");
    
    
    y->removeCoauthor("Republic", "Plato");
    y->displayAuthor("Kerem");
    cout << endl << endl;
    y->removeBook("repuBLic");
    y->removeBook("1984");
    y->removeBook("The ShORt History of Life");
    y->displayAllBooks();
    
   
    return 0;
};

