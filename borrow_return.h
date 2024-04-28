#ifndef LIBRARYMANAGEMENT_BORROW_RETURN_H
#define LIBRARYMANAGEMENT_BORROW_RETURN_H
#include <string.h>
#include <stdio.h>
#include "reader.h"
#include "book.h"

#define MAX_BORROWED_BOOKS 5

// Global arrays to store borrowed book information
extern int borrowedBooks[MAX_READERS][MAX_BORROWED_BOOKS];
extern int numBorrowedBooks[MAX_READERS];

void borrowBook();
void returnBook();

#endif //LIBRARYMANAGEMENT_BORROW_RETURN_H
