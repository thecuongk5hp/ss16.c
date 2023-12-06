#include <stdio.h>
#include <stdlib.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    float price;
    char category[50];
};

void inputBooks(struct Book books[], int n) {
    printf("Nhap thong tin sach:\n");
    for (int i = 0; i < n; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%d", &books[i].id);
        printf("Ten sach: ");
        scanf("%s", books[i].name);
        printf("Tac gia: ");
        scanf("%s", books[i].author);
        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        printf("The loai: ");
        scanf("%s", books[i].category);
    }
}

void saveBooksToFile(struct Book books[], int n) {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %s %.2f %s\n", books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
    }
    fclose(file);
    printf("Luu thong tin sach vao file thanh cong.\n");
}

void displayBooksFromFile() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    struct Book book;
    printf("Thong tin sach tu file:\n");
    while (fscanf(file, "%d %s %s %f %s", &book.id, book.name, book.author, &book.price, book.category) != EOF) {
        printf("Ma sach: %d\n", book.id);
        printf("Ten sach: %s\n", book.name);
        printf("Tac gia: %s\n", book.author);
        printf("Gia tien: %.2f\n", book.price);
        printf("The loai: %s\n", book.category);
        printf("--------------------\n");
    }
    fclose(file);
}

int main() {
    struct Book books[100];
    int choice, n = 0;
    
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Hien thi thong tin sach tu file\n");
        printf("4. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &n);
                inputBooks(books, n);
                break;
            case 2:
                saveBooksToFile(books, n);
                break;
            case 3:
                displayBooksFromFile();
                break;
            case 4:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Chuc nang khong hop le.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}