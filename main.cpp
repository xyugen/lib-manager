#include <stdio.h>
#include <string.h>

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

void addBook(Book book) {

}

void rmNewline(char *input)
{
    int length = strlen(input);
    if (input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
    }
}

int main() {
    int choice;
    Book book;
    Borrower borrower;
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
                printf("Enter book ID: ");
                scanf("%d", book.book_id);

                printf("Enter book title: ");
                fgets(book.title, SIZE, stdin);
                rmNewline(book.title);

                printf("Enter book author: ");
                fgets(book.author, SIZE, stdin);
                rmNewline(book.author);

                book.available = true;

                addBook(book);
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
