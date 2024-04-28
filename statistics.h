#ifndef LIBRARYMANAGEMENT_STATISTICS_H
#define LIBRARYMANAGEMENT_STATISTICS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "book.h"
#include "reader.h"
#include "borrow_return.h"

void overdueReaders();
int countBorrowedBooks();
void countReadersByGender();
int countReaders();
void countBooksByGenre();
int countBooks();

#endif //LIBRARYMANAGEMENT_STATISTICS_H
