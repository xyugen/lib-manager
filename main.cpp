#include <stdio.h>

#define SIZE 54

typedef struct
{
    int book_id;
    char title[SIZE], author[SIZE];
    bool available;
} Book;

typedef struct
{
    int borrower_id;
    char name[SIZE], borrowed_books[100];
} Borrower;

int main() {
    int choice;
    do {
        printf("===== Library System =====\n"
                "[1] Add Book\n"
                "[2] Remove Book\n"
                "[3] Issue Book\n"
                "[4] Issued Book List\n\n"
                "[0] Exit\n"
                "==========================\n");

        printf("Choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (choice != 0);

    return 0;
}
