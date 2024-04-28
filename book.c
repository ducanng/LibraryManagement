#include "book.h"

int bookISBNs[MAX_BOOKS];
char bookTitles[MAX_BOOKS][50];
char bookAuthors[MAX_BOOKS][50]; // Tác giả
char bookPublishers[MAX_BOOKS][50]; // Nhà xuất bản
int bookPublicationYears[MAX_BOOKS]; // Năm xuất bản
char bookGenres[MAX_BOOKS][50]; // Thể loại
float bookPrices[MAX_BOOKS]; // Giá sách
int bookQuantities[MAX_BOOKS]; // Số lượng sách
int numBooks;

/**
 * Hiển thị danh sách các sách trong thư viện.
 */
void viewBooks() {
    if (numBooks == 0) {
        printf("Khong co sach trong thu vien.\n");
    } else {
        printf("### Danh sach Sach ###\n");
        for (int i = 0; i < numBooks; i++) {
            printf("ISBN: %d, Ten sach: %s, Tac gia: %s, Nha xuat ban: %s, Nam xuat ban: %d, The loai: %s, Gia sach: %.2f, So luong sach: %d\n",
                   bookISBNs[i], bookTitles[i], bookAuthors[i], bookPublishers[i], bookPublicationYears[i], bookGenres[i], bookPrices[i], bookQuantities[i]);
        }
    }
}

/**
 * Thêm một quyển sách mới vào thư viện.
 * @param ISBN Mã ISBN của sách mới
 * @param title Tiêu đề của sách mới
 * @param author Tác giả của sách mới
 * @param publisher Nhà xuất bản của sách mới
 * @param publicationYear Năm xuất bản của sách mới
 * @param genre Thể loại của sách mới
 * @param price Giá sách của sách mới
 * @param quantity Số lượng sách mới
 */
void addBook() {
    int ISBN, publicationYear, quantity;
    char title[50], author[50], publisher[50], genre[50];
    float price;

    printf("Nhap ma ISBN cua sach: ");
    scanf("%d", &ISBN);
    printf("Nhap ten sach: ");
    scanf("%s", title);
    printf("Nhap tac gia: ");
    scanf("%s", author);
    printf("Nhap nha xuat ban: ");
    scanf("%s", publisher);
    printf("Nhap nam xuat ban: ");
    scanf("%d", &publicationYear);
    printf("Nhap the loai: ");
    scanf("%s", genre);
    printf("Nhap gia sach: ");
    scanf("%f", &price);
    printf("Nhap so luong sach: ");
    scanf("%d", &quantity);

    if (numBooks < MAX_BOOKS) {
        bookISBNs[numBooks] = ISBN;
        strcpy(bookTitles[numBooks], title);
        strcpy(bookAuthors[numBooks], author);
        strcpy(bookPublishers[numBooks], publisher);
        bookPublicationYears[numBooks] = publicationYear;
        strcpy(bookGenres[numBooks], genre);
        bookPrices[numBooks] = price;
        bookQuantities[numBooks] = quantity;
        numBooks++;
        printf("Them sach thanh cong!\n");
    } else {
        printf("Da dat toi so luong sach toi da!\n");
    }
}

/**
 * Chỉnh sửa thông tin của một quyển sách.
 * @param ISBN Mã ISBN của sách cần chỉnh sửa
 */
void editBook() {
    int ISBN;
    int found = 0;

    printf("Nhap ma ISBN cua sach can chinh sua: ");
    scanf("%d", &ISBN);

    for (int i = 0; i < numBooks; i++) {
        if (bookISBNs[i] == ISBN) {
            printf("Nhap thong tin moi cho sach:\n");
            printf("Ten sach: ");
            scanf("%s", bookTitles[i]);
            printf("Tac gia: ");
            scanf("%s", bookAuthors[i]);
            printf("Nha xuat ban: ");
            scanf("%s", bookPublishers[i]);
            printf("Nam xuat ban: ");
            scanf("%d", &bookPublicationYears[i]);
            printf("The loai: ");
            scanf("%s", bookGenres[i]);
            printf("Gia sach: ");
            scanf("%f", &bookPrices[i]);
            printf("So luong sach: ");
            scanf("%d", &bookQuantities[i]);
            printf("Cap nhat sach thanh cong!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach.\n");
    }
}

/**
 * Xóa thông tin của một quyển sách.
 * @param ISBN Mã ISBN của sách cần xóa
 */
void deleteBook() {
    int ISBN;
    int found = 0;

    printf("Nhap ma ISBN cua sach can xoa: ");
    scanf("%d", &ISBN);

    for (int i = 0; i < numBooks; i++) {
        if (bookISBNs[i] == ISBN) {
            for (int j = i; j < numBooks - 1; j++) {
                bookISBNs[j] = bookISBNs[j + 1];
                strcpy(bookTitles[j], bookTitles[j + 1]);
                strcpy(bookAuthors[j], bookAuthors[j + 1]);
                strcpy(bookPublishers[j], bookPublishers[j + 1]);
                bookPublicationYears[j] = bookPublicationYears[j + 1];
                strcpy(bookGenres[j], bookGenres[j + 1]);
                bookPrices[j] = bookPrices[j + 1];
                bookQuantities[j] = bookQuantities[j + 1];
            }
            numBooks--;
            printf("Xoa sach thanh cong!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach.\n");
    }
}

/**
 * Tìm kiếm sách theo mã ISBN.
 * @param ISBN Mã ISBN của sách cần tìm
 */
void searchBookByISBN() {
    int ISBN;
    int found = 0;

    printf("Nhap ma ISBN de tim kiem: ");
    scanf("%d", &ISBN);

    printf("### Ket qua tim kiem ###\n");
    for (int i = 0; i < numBooks; i++) {
        if (bookISBNs[i] == ISBN) {
            printf("ISBN: %d, Ten sach: %s, Tac gia: %s, Nha xuat ban: %s, Nam xuat ban: %d, The loai: %s, Gia sach: %.2f, So luong sach: %d\n",
                   bookISBNs[i], bookTitles[i], bookAuthors[i], bookPublishers[i], bookPublicationYears[i], bookGenres[i], bookPrices[i], bookQuantities[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ma ISBN %d.\n", ISBN);
    }
}

/**
 * Tìm kiếm sách theo tên sách.
 * @param title Tiêu đề của sách cần tìm
 */
void searchBookByTitle() {
    char title[50];
    int found = 0;

    printf("Nhap ten sach de tim kiem: ");
    scanf("%s", title);

    printf("### Ket qua tim kiem ###\n");
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(bookTitles[i], title) == 0) {
            printf("ISBN: %d, Ten sach: %s, Tac gia: %s, Nha xuat ban: %s, Nam xuat ban: %d, The loai: %s, Gia sach: %.2f, So luong sach: %d\n",
                   bookISBNs[i], bookTitles[i], bookAuthors[i], bookPublishers[i], bookPublicationYears[i], bookGenres[i], bookPrices[i], bookQuantities[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ten %s.\n", title);
    }
}
