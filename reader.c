#include "reader.h"

int readerIDs[MAX_READERS];
char readerNames[MAX_READERS][50];
char readerCMNDs[MAX_READERS][20];
char readerBirthdates[MAX_READERS][11];
char readerGenders[MAX_READERS][10];
char readerEmails[MAX_READERS][100];
char readerAddresses[MAX_READERS][100];
char cardIssueDates[MAX_READERS][11];
char cardExpiryDates[MAX_READERS][11];
int numReaders;
/**
 * Thêm một độc giả mới vào thư viện.
 * @param readerID Mã độc giả
 * @param readerName Họ tên độc giả
 * @param readerCMND CMND của độc giả
 * @param readerBirthdate Ngày sinh của độc giả
 * @param readerGender Giới tính của độc giả
 * @param readerEmail Email của độc giả
 * @param readerAddress Địa chỉ của độc giả
 * @param issueDate Ngày lập thẻ
 * @param expiryDate Ngày hết hạn thẻ
 */
void addReader() {
    int readerID;
    char readerName[50], readerCMND[20], readerBirthdate[11], readerGender[10], readerEmail[100], readerAddress[100];
    char issueDate[11], expiryDate[11];

    printf("Nhap ma doc gia: ");
    scanf("%d", &readerID);
    getchar(); // Xử lý bộ nhớ đệm
    printf("Nhap ho ten doc gia: ");
    fgets(readerName, 50, stdin);
    readerName[strcspn(readerName, "\n")] = 0; // Loại bỏ ký tự xuống dòng
    printf("Nhap CMND cua doc gia: ");
    fgets(readerCMND, 20, stdin);
    readerCMND[strcspn(readerCMND, "\n")] = 0;
    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    fgets(readerBirthdate, 11, stdin);
    readerBirthdate[strcspn(readerBirthdate, "\n")] = 0;
    printf("Nhap gioi tinh (Nam/Nu/Khac): ");
    fgets(readerGender, 10, stdin);
    readerGender[strcspn(readerGender, "\n")] = 0;
    printf("Nhap email: ");
    fgets(readerEmail, 100, stdin);
    readerEmail[strcspn(readerEmail, "\n")] = 0;
    printf("Nhap dia chi: ");
    fgets(readerAddress, 100, stdin);
    readerAddress[strcspn(readerAddress, "\n")] = 0;
    printf("Nhap ngay lap the (dd/mm/yyyy): ");
    fgets(issueDate, 11, stdin);
    issueDate[strcspn(issueDate, "\n")] = 0;
    // Tính ngày hết hạn (48 tháng sau ngày lập thẻ)
    calculateExpiryDate(issueDate, expiryDate);
    printf("Ngay het han the: %s\n", expiryDate);

    if (numReaders < MAX_READERS) {
        readerIDs[numReaders] = readerID;
        strcpy(readerNames[numReaders], readerName);
        strcpy(readerCMNDs[numReaders], readerCMND);
        strcpy(readerBirthdates[numReaders], readerBirthdate);
        strcpy(readerGenders[numReaders], readerGender);
        strcpy(readerEmails[numReaders], readerEmail);
        strcpy(readerAddresses[numReaders], readerAddress);
        strcpy(cardIssueDates[numReaders], issueDate);
        strcpy(cardExpiryDates[numReaders], expiryDate);
        numReaders++;
        printf("Them doc gia thanh cong!\n");
    } else {
        printf("Dat so luong doc gia toi da!\n");
    }
}

/**
 * Tính toán ngày hết hạn của thẻ dựa trên ngày lập thẻ, thêm 48 tháng vào ngày lập thẻ.
 * @param issueDate Ngày lập thẻ (dd/mm/yyyy)
 * @param expiryDate Chuỗi để lưu trữ ngày hết hạn (được cập nhật trong hàm)
 */
void calculateExpiryDate(const char* issueDate, char* expiryDate) {
    struct tm tmIssueDate = {0};
    time_t tIssueDate;

    // Phân tích chuỗi ngày tháng thành struct tm
    sscanf(issueDate, "%d/%d/%d", &tmIssueDate.tm_mday, &tmIssueDate.tm_mon, &tmIssueDate.tm_year);
    tmIssueDate.tm_mon -= 1; // Tháng trong struct tm bắt đầu từ 0 (0-11)
    tmIssueDate.tm_year -= 1900; // Năm trong struct tm là số năm kể từ 1900

    // Chuyển đổi từ struct tm sang time_t
    tIssueDate = mktime(&tmIssueDate);

    // Tính toán ngày hết hạn thẻ: thêm 48 tháng
    struct tm *tmExpiryDate = localtime(&tIssueDate);
    tmExpiryDate->tm_mon += 48; // Thêm 48 tháng vào ngày lập thẻ

    // Chuẩn hóa ngày tháng nếu có sự thay đổi không hợp lệ
    mktime(tmExpiryDate);

    // Định dạng lại ngày tháng thành chuỗi theo định dạng dd/mm/yyyy
    strftime(expiryDate, 11, "%d/%m/%Y", tmExpiryDate);
}

/**
 * Hiển thị danh sách các độc giả trong thư viện.
 */
void viewReaders() {
    if (numReaders == 0) {
        printf("Khong co doc gia trong thu vien.\n");
    } else {
        printf("### Danh sach Doc gia ###\n");
        for (int i = 0; i < numReaders; i++) {
            printf("ID: %d, Ten: %s, CMND: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                   readerIDs[i], readerNames[i], readerCMNDs[i], readerBirthdates[i], readerGenders[i], readerEmails[i], readerAddresses[i], cardIssueDates[i], cardExpiryDates[i]);
        }
    }
}

/**
 * Chỉnh sửa thông tin của một độc giả.
 * @param readerID Mã độc giả cần chỉnh sửa
 * @param newName Tên mới của độc giả
 */
void editReader() {
    int readerID;
    char newName[50], newCMND[20], newBirthdate[11], newGender[10], newEmail[100], newAddress[100];
    int found = 0;

    printf("Nhap ID doc gia can chinh sua: ");
    scanf("%d", &readerID);

    for (int i = 0; i < numReaders; i++) {
        if (readerIDs[i] == readerID) {
            printf("Nhap ten moi cho doc gia: ");
            scanf("%s", newName);
            strcpy(readerNames[i], newName);

            printf("Nhap CMND moi cho doc gia: ");
            scanf("%s", newCMND);
            strcpy(readerCMNDs[i], newCMND);

            printf("Nhap ngay sinh moi cho doc gia (dd/mm/yyyy): ");
            scanf("%s", newBirthdate);
            strcpy(readerBirthdates[i], newBirthdate);

            printf("Nhap gioi tinh moi cho doc gia: ");
            scanf("%s", newGender);
            strcpy(readerGenders[i], newGender);

            printf("Nhap email moi cho doc gia: ");
            scanf("%s", newEmail);
            strcpy(readerEmails[i], newEmail);

            printf("Nhap dia chi moi cho đoc gia: ");
            scanf("%s", newAddress);
            strcpy(readerAddresses[i], newAddress);

            printf("Cap nhat doc gia thanh cong!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia.\n");
    }
}

/**
 * Xóa thông tin của một độc giả.
 * @param readerID Mã độc giả cần xóa
 */
void deleteReader() {
    int readerID;
    int found = 0;

    printf("Nhap ID doc gia can xoa: ");
    scanf("%d", &readerID);

    for (int i = 0; i < numReaders; i++) {
        if (readerIDs[i] == readerID) {
            for (int j = i; j < numReaders - 1; j++) {
                readerIDs[j] = readerIDs[j + 1];
                strcpy(readerNames[j], readerNames[j + 1]);
                strcpy(readerCMNDs[j], readerCMNDs[j + 1]);
                strcpy(readerBirthdates[j], readerBirthdates[j + 1]);
                strcpy(readerGenders[j], readerGenders[j + 1]);
                strcpy(readerEmails[j], readerEmails[j + 1]);
                strcpy(readerAddresses[j], readerAddresses[j + 1]);
                strcpy(cardIssueDates[j], cardIssueDates[j + 1]);
                strcpy(cardExpiryDates[j], cardExpiryDates[j + 1]);
            }
            numReaders--;
            printf("Doc gia da duoc xoa thanh cong!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia.\n");
    }
}

/**
 * Tìm kiếm độc giả theo số CMND.
 * @param cmnd Số CMND của độc giả cần tìm
 */
void searchReaderByCMND() {
    char cmnd[20];
    int found = 0;

    printf("Nhap CMND de tim kiem: ");
    scanf("%s", cmnd);

    printf("### Ket qua tim kiem ###\n");
    for (int i = 0; i < numReaders; i++) {
        if (strcmp(readerCMNDs[i], cmnd) == 0) {
            printf("ID: %d, Ten: %s, CMND: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                   readerIDs[i], readerNames[i], readerCMNDs[i], readerBirthdates[i], readerGenders[i], readerEmails[i], readerAddresses[i], cardIssueDates[i], cardExpiryDates[i]);
            found = 1;

            break;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia voi CMND %s.\n", cmnd);
    }
}

/**
 * Tìm kiếm độc giả theo tên.
 * @param name Tên độc giả cần tìm
 */
void searchReaderByName() {
    char name[50];
    int found = 0;

    printf("Nhap ten de tim kiem: ");
    scanf("%s", name);

    printf("### Ket qua tim kiem ###\n");
    for (int i = 0; i < numReaders; i++) {
        if (strcmp(readerNames[i], name) == 0) {
            printf("ID: %d, Ten: %s, CMND: %s, Ngay sinh: %s, Gioi tinh: %s, Email: %s, Dia chi: %s, Ngay lap the: %s, Ngay het han: %s\n",
                   readerIDs[i], readerNames[i], readerCMNDs[i], readerBirthdates[i], readerGenders[i], readerEmails[i], readerAddresses[i], cardIssueDates[i], cardExpiryDates[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia voi ten %s.\n", name);
    }
}