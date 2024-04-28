//
// Created by ducan on 4/26/2024.
//

#ifndef LIBRARYMANAGEMENT_BOOK_H
#define LIBRARYMANAGEMENT_BOOK_H

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Global arrays to store book information
extern int bookISBNs[MAX_BOOKS];
extern char bookTitles[MAX_BOOKS][50];
extern char bookAuthors[MAX_BOOKS][50]; // Tác giả
extern char bookPublishers[MAX_BOOKS][50]; // Nhà xuất bản
extern int bookPublicationYears[MAX_BOOKS]; // Năm xuất bản
extern char bookGenres[MAX_BOOKS][50]; // Thể loại
extern float bookPrices[MAX_BOOKS]; // Giá sách
extern int bookQuantities[MAX_BOOKS]; // Số lượng sách
extern int numBooks;

void viewBooks();
void addBook();
void editBook();
void deleteBook();
void searchBookByISBN();
void searchBookByTitle();

#endif //LIBRARYMANAGEMENT_BOOK_H
