#include "library.h"

/**
 * Quản lí độc giả trong thư viện.
 * Cho phép xem danh sách độc giả, thêm, chỉnh sửa, xóa thông tin độc giả,
 * và tìm kiếm độc giả theo CMND hoặc tên.
 */
void readerManagement() {
    int choice;

    do {
        printf("\n### Quan li doc gia ###\n");
        printf("1. Xem danh sach doc gia\n");
        printf("2. Them doc gia\n");
        printf("3. Chinh sua thong tin doc gia\n");
        printf("4. Xoa thong tin doc gia\n");
        printf("5. Tim kiem doc gia theo CMND\n");
        printf("6. Tim kiem doc gia theo ten\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewReaders();
                break;
            case 2:
                addReader();
                break;
            case 3:
                editReader();
                break;
            case 4:
                deleteReader();
                break;
            case 5:
                searchReaderByCMND();
                break;
            case 6:
                searchReaderByName();
                break;
            case 0:
                printf("Quay lai menu chinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);
}

void bookManagement() {
    int choice;

    do {
        printf("\n### Quản lý Sách ###\n");
        printf("1. Xem danh sách sách\n");
        printf("2. Thêm sách mới\n");
        printf("3. Chỉnh sửa thông tin sách\n");
        printf("4. Xóa sách\n");
        printf("5. Tìm kiếm sách theo ISBN\n");
        printf("6. Tìm kiếm sách theo tiêu đề\n");
        printf("0. Trở về menu chính\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewBooks();
                break;
            case 2:
                addBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                searchBookByISBN();
                break;
            case 6:
                searchBookByTitle();
                break;
            case 0:
                printf("Đang trở về menu chính...\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng nhập một số từ 0 đến 6.\n");
        }
    } while (choice != 0);
}

/**
 * Thực hiện thống kê cơ bản.
 */
void basicStatistics() {
    printf("### Thong ke co ban ###\n");
    printf("a. So luong sach trong thu vien\n");
    printf("b. So luong sach theo the loai\n");
    printf("c. So luong doc gia\n");
    printf("d. So luong doc gia theo gioi tinh\n");
    printf("e. So sach dang duoc muon\n");
    printf("f. Danh sach doc gia bi tre han\n");
    printf("x. Thoat\n");
    printf("Chon thong ke (a-f hoac x de thoat): ");

    char choice;
    scanf(" %c", &choice);
    switch (choice) {
        case 'a':
            printf("So luong sach trong thu vien: %d\n", countBooks());
            break;
        case 'b':
            printf("Thong ke so luong sach theo the loai:\n");
            countBooksByGenre();
            break;
        case 'c':
            printf("So luong doc gia: %d\n", countReaders());
            break;
        case 'd':
            printf("Thong ke so luong doc gia theo gioi tinh:\n");
            countReadersByGender();
            break;
        case 'e':
            printf("So sach dang duoc muon: %d\n", countBorrowedBooks());
            break;
        case 'f':
            printf("Danh sach doc gia bi tre han:\n");
            overdueReaders();
            break;
        case 'x':
            printf("Thoat.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
    }
}