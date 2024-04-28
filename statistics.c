#include "statistics.h"

/**
 * Thống kê số lượng sách trong thư viện.
 */
int countBooks() {
    return numBooks;
}

/**
 * Thống kê sách theo thể loại (Genre).
 */
void countBooksByGenre() {
    if (numBooks == 0) {
        printf("Không có sách trong thư viện.\n");
    } else {
        // Khởi tạo mảng để lưu số lượng sách theo từng thể loại
        int genreCount[MAX_BOOKS] = {0};

        // Đếm số lượng sách theo từng thể loại
        for (int i = 0; i < numBooks; i++) {
            for (int j = 0; j < numBooks; j++) {
                if (strcmp(bookGenres[i], bookGenres[j]) == 0) {
                    genreCount[i]++;
                }
            }
        }

        // In ra số lượng sách theo từng thể loại
        printf("### Thống kê sách theo thể loại ###\n");
        for (int i = 0; i < numBooks; i++) {
            // Đảm bảo không in lại thể loại đã in trước đó
            int printed = 0;
            for (int j = 0; j < i; j++) {
                if (strcmp(bookGenres[i], bookGenres[j]) == 0) {
                    printed = 1;
                    break;
                }
            }
            if (!printed) {
                printf("Thể loại: %s, Số lượng sách: %d\n", bookGenres[i], genreCount[i]);
            }
        }
    }
}

/**
 * Thống kê số lượng độc giả.
 */
int countReaders() {
    return numReaders;
}

/**
 * Thống kê số lượng độc giả theo giới tính.
 */
void countReadersByGender() {
    int countMale = 0;
    int countFemale = 0;
    int countOthers = 0;

    for (int i = 0; i < numReaders; i++) {
        if (strcmp(readerGenders[i], "Nam") == 0) {
            countMale++;
        } else if (strcmp(readerGenders[i], "Nữ") == 0) {
            countFemale++;
        } else {
            countOthers++;
        }
    }

    printf("Số lượng độc giả Nam: %d\n", countMale);
    printf("Số lượng độc giả Nữ: %d\n", countFemale);
    printf("Số lượng độc giả Khác: %d\n", countOthers);
}

/**
 * Thống kê số sách đang được mượn.
 */
int countBorrowedBooks() {
    int totalBorrowed = 0;
    for (int i = 0; i < numReaders; i++) {
        totalBorrowed += numBorrowedBooks[i];
    }
    return totalBorrowed;
}
/**
 * Kiểm tra xem một độc giả có trễ hạn không dựa trên ngày hiện tại.
 * @param readerID Mã độc giả
 * @param currentDate Ngày hiện tại
 * @return Trả về true nếu độc giả trễ hạn, ngược lại trả về false
 */
bool isOverdue(int readerID, const char* currentDate) {
    // Tìm ngày hết hạn của thẻ độc giả
    char expiryDate[11]; // dd/mm/yyyy
    for (int i = 0; i < numReaders; i++) {
        if (readerIDs[i] == readerID) {
            strcpy(expiryDate, cardExpiryDates[i]);
            break;
        }
    }

    // So sánh ngày hết hạn với ngày hiện tại
    if (strcmp(currentDate, expiryDate) > 0) {
        // currentDate lớn hơn expiryDate, độc giả trễ hạn
        return true;
    } else {
        // currentDate nhỏ hơn hoặc bằng expiryDate, độc giả không trễ hạn
        return false;
    }
}
/**
 * Thống kê danh sách độc giả bị trễ hạn.
 */
void overdueReaders() {
    time_t now;
    struct tm *currentTime;
    char currentDate[11]; // dd/mm/yyyy

    // Lấy thời gian hiện tại từ hệ thống
    time(&now);
    currentTime = localtime(&now);

    // Format ngày hiện tại thành chuỗi "dd/mm/yyyy"
    strftime(currentDate, 11, "%d/%m/%Y", currentTime);

    printf("Danh sách độc giả bị trễ hạn:\n");

    for (int i = 0; i < numReaders; i++) {
        // Kiểm tra xem độc giả có trễ hạn không
        if (isOverdue(readerIDs[i], currentDate)) {
            printf("ID: %d, Tên: %s\n", readerIDs[i], readerNames[i]);
        }
    }
}

