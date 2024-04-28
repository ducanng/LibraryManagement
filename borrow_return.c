#include "borrow_return.h"

int borrowedBooks[MAX_READERS][MAX_BORROWED_BOOKS];
int numBorrowedBooks[MAX_READERS];

/**
 * Mượn sách.
 * @param readerID Mã độc giả
 * @param ISBN Mã ISBN của sách cần mượn
 */
void borrowBook() {
    int readerID, ISBN;
    int readerIndex = -1;
    int bookIndex = -1;

    printf("Nhap ma doc gia: ");
    scanf("%d", &readerID);
    printf("Nhap ma ISBN cua sach can muon: ");
    scanf("%d", &ISBN);

    // Tìm chỉ số của độc giả
    for (int i = 0; i < numReaders; i++) {
        if (readerIDs[i] == readerID) {
            readerIndex = i;
            break;
        }
    }

    // Tìm chỉ số của sách
    for (int i = 0; i < numBooks; i++) {
        if (bookISBNs[i] == ISBN) {
            bookIndex = i;
            break;
        }
    }

    // Kiểm tra xem độc giả và sách có tồn tại không
    if (readerIndex == -1) {
        printf("Khong tim thay doc gia.\n");
        return;
    }
    if (bookIndex == -1) {
        printf("Khong tim thay sach.\n");
        return;
    }

    // Kiểm tra xem độc giả đã mượn số lượng sách tối đa chưa
    if (numBorrowedBooks[readerIndex] >= MAX_BORROWED_BOOKS) {
        printf("Doc gia đa muon so luong sach toi da.\n");
        return;
    }

    // Kiểm tra xem sách có sẵn không
    for (int i = 0; i < numBorrowedBooks[readerIndex]; i++) {
        if (borrowedBooks[readerIndex][i] == ISBN) {
            printf("Sach da duoc muon boi doc gia nay.\n");
            return;
        }
    }

    // Mượn sách
    borrowedBooks[readerIndex][numBorrowedBooks[readerIndex]] = ISBN;
    numBorrowedBooks[readerIndex]++;
    printf("Muon sach thanh cong!\n");
}

/**
 * Trả sách.
 * @param readerID Mã độc giả
 * @param ISBN Mã ISBN của sách cần trả
 */
void returnBook() {
    int readerID, ISBN;
    int readerIndex = -1;
    int bookIndex = -1;

    printf("Nhap ma doc gia: ");
    scanf("%d", &readerID);
    printf("Nhap ma ISBN cua sach can tra: ");
    scanf("%d", &ISBN);

    // Tìm chỉ số của độc giả
    for (int i = 0; i < numReaders; i++) {
        if (readerIDs[i] == readerID) {
            readerIndex = i;
            break;
        }
    }

    // Tìm chỉ số của sách
    for (int i = 0; i < numBooks; i++) {
        if (bookISBNs[i] == ISBN) {
            bookIndex = i;
            break;
        }
    }

    // Kiểm tra xem độc giả và sách có tồn tại không
    if (readerIndex == -1) {
        printf("Khong tim thay doc gia.\n");
        return;
    }
    if (bookIndex == -1) {
        printf("Khong tim thay sach.\n");
        return;
    }

    // Kiểm tra xem độc giả đã mượn sách này chưa
    int found = 0;
    for (int i = 0; i < numBorrowedBooks[readerIndex]; i++) {
        if (borrowedBooks[readerIndex][i] == ISBN) {
            found = 1;
            for (int j = i; j < numBorrowedBooks[readerIndex] - 1; j++) {
                borrowedBooks[readerIndex][j] = borrowedBooks[readerIndex][j + 1];
            }
            numBorrowedBooks[readerIndex]--;
            printf("Tra sach thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("Doc gia khong muon sach nay.\n");
    }
}
