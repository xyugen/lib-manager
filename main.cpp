#include <stdio.h>
#include <string.h>

#define SIZE 54
#define BOOKFNAME "book_records.txt"
#define BORROWERFNAME "borrower_records.txt";
#define BOOKTFNAME "book_records.temp.txt"
#define BORROWERTFNAME "borrower_records.temp.txt";

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

FILE *openFile(const char *fileName, const char *mode) {
    FILE *fp;

    fp = fopen(fileName, mode);
    if (fp == NULL)
    {
        printf("Failed to open file %s!\n", fileName);
    }

    return fp;
}

void addBook(Book book) {
    FILE *fp = openFile(BOOKFNAME, "a");
    printf("Record stored successfully!\n");

    fwrite(&book, sizeof(book), 1, fp);

    fclose(fp);
}

void readBook()
{
    FILE *fp = openFile(BOOKFNAME, "r");

    printf("\t\t\t\tBOOK LIST\n"
           "ID\tTitle\t\t\t\tAuthor\t\t\t\tAvailable\n");

    Book book;
    while (fread(&book, sizeof(book), 1, fp))
    {
        printf("%d\t%s\t\t\t%s\t\t\t\t", book.book_id, book.title, book.author);
        printf("%s", book.available ? "Yes\n" : "No\n");
    }
    printf("End of file.\n\n");

    fclose(fp);
}

void rmBook(Book bookID)
{
    FILE *fp = openFile(BOOKFNAME, "r");
    FILE *temp = openFile(BOOKTFNAME, "w");

    Book bookRec;
    int choice;
    while (fread(&bookRec, sizeof(bookRec), 1, fp))
    {
        if (bookID.book_id != bookRec.book_id)
        {
            fwrite(&bookRec, sizeof(bookRec), 1, temp);
        } else {
            printf("Are your sure you want to remove book \"%s\"?\n"
                   "[1] YES\n"
                   "[0] NO\n"
                   "Choice: ", bookRec.title);
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Book removed successfully!\n");
            } else {
                fwrite(&bookRec, sizeof(bookRec), 1, temp);
                printf("Book not removed.\n");
            }
        }
    }

    fclose(fp);
    fclose(temp);

    remove(BOOKFNAME);
    rename(BOOKTFNAME, BOOKFNAME);
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
                "[2] Book List\n"
                "[3] Remove Book\n"
                "[4] Issue Book\n"
                "[5] Issued Book List\n\n"
                "[0] Exit\n"
                "==========================\n");

        printf("Choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &book.book_id);
                getchar();

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
                readBook();
                break;
            case 3:
                printf("Enter book ID you want to remove: ");
                scanf("%d", &book.book_id);

                rmBook(book);
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (choice != 0);

    return 0;
}
