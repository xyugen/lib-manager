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


    return 0;
}
