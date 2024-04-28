#include <stdio.h>
#include "library.h"

int main() {
    int choice;
    int running = 1;
    while (running) {
        printf("\n=========================\n");
        printf("MENU\n");
        printf("1. Quan li doc gia\n");
        printf("2. Quan li sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Thong ke co ban\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        printf("=========================\n");

        switch (choice) {
            case 1:
                readerManagement();
                break;
            case 2:
                bookManagement();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                basicStatistics();
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("Lựa chọn không hợp lệ, hãy thử lại.\n");
        }
    }
}
