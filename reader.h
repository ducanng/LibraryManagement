#ifndef LIBRARYMANAGEMENT_READER_H
#define LIBRARYMANAGEMENT_READER_H
#include <stdio.h>
#include <string.h>
#include <time.h>
// Định nghĩa hằng số
#define MAX_READERS 100

// Định nghĩa cấu trúc thẻ độc giả
extern int readerIDs[MAX_READERS];
extern char readerNames[MAX_READERS][50];
extern char readerCMNDs[MAX_READERS][20];
extern char readerBirthdates[MAX_READERS][11];
extern char readerGenders[MAX_READERS][10];
extern char readerEmails[MAX_READERS][100];
extern char readerAddresses[MAX_READERS][100];
extern char cardIssueDates[MAX_READERS][11];
extern char cardExpiryDates[MAX_READERS][11];

extern int numReaders;

void viewReaders();
void calculateExpiryDate(const char* issueDate, char* expiryDate);
void addReader();
void editReader();
void deleteReader();
void searchReaderByCMND();
void searchReaderByName();


#endif //LIBRARYMANAGEMENT_READER_H
