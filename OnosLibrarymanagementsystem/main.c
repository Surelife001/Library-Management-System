#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char title[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    int issued;
} Book;

void initializeBooks(Book books[], int *bookCount) {
    *bookCount = 0;
}

void addBook(Book books[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &books[*bookCount].id);
    printf("Enter book title: ");
    scanf(" %[^\n]", books[*bookCount].title);
    printf("Enter book author: ");
    scanf(" %[^\n]", books[*bookCount].author);
    books[*bookCount].issued = 0;
    (*bookCount)++;

    printf("Book added successfully.\n");
}

void viewBooks(Book books[], int bookCount) {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("ID\tTitle\t\tAuthor\t\tStatus\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", books[i].id, books[i].title, books[i].author, books[i].issued ? "Issued" : "Available");
    }
}

void issueBook(Book books[], int bookCount) {
    int id, found = 0;

    printf("Enter book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            found = 1;
            if (books[i].issued) {
                printf("Book is already issued.\n");
            } else {
                books[i].issued = 1;
                printf("Book issued successfully.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

void returnBook(Book books[], int bookCount) {
    int id, found = 0;

    printf("Enter book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            found = 1;
            if (!books[i].issued) {
                printf("Book is not issued.\n");
            } else {
                books[i].issued = 0;
                printf("Book returned successfully.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int bookCount;
    int choice;

    initializeBooks(books, &bookCount);

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                viewBooks(books, bookCount);
                break;
            case 3:
                issueBook(books, bookCount);
                break;
            case 4:
                returnBook(books, bookCount);
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
