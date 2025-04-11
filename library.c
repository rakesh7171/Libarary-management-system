#include <stdio.h>    // For standard I/O functions
#include <stdlib.h>   // For system functions like exit()
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50

// Structure for Book Information
struct Book {
    int bookID;
    char title[100];
    char author[100];
    int quantity;
};

// Structure for Member Information
struct Member {
    int memberID;
    char name[100];
    int booksIssued;
};

// Function to Add a Book
void addBook(struct Book library[], int *bookCount) {
    printf("\nEnter Book ID: ");
    scanf("%d", &library[*bookCount].bookID);
    printf("Enter Book Title: ");
    getchar(); // To consume the newline character from previous input
    fgets(library[*bookCount].title, 100, stdin);
    library[*bookCount].title[strcspn(library[*bookCount].title, "\n")] = '\0'; // Remove newline
    printf("Enter Author Name: ");
    fgets(library[*bookCount].author, 100, stdin);
    library[*bookCount].author[strcspn(library[*bookCount].author, "\n")] = '\0'; // Remove newline
    printf("Enter Book Quantity: ");
    scanf("%d", &library[*bookCount].quantity);
    (*bookCount)++;
    printf("\nBook Added Successfully!\n");
}

// Function to Display All Books
void displayBooks(struct Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nNo Books Available.\n");
        return;
    }
    printf("\nBooks Available in Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("\nBook ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n", library[i].bookID, library[i].title, library[i].author, library[i].quantity);
    }
}

// Function to Add a Member
void addMember(struct Member members[], int *memberCount) {
    printf("\nEnter Member ID: ");
    scanf("%d", &members[*memberCount].memberID);
    printf("Enter Member Name: ");
    getchar(); // To consume the newline character from previous input
    fgets(members[*memberCount].name, 100, stdin);
    members[*memberCount].name[strcspn(members[*memberCount].name, "\n")] = '\0'; // Remove newline
    members[*memberCount].booksIssued = 0;
    (*memberCount)++;
    printf("\nMember Added Successfully!\n");
}

// Function to Issue Book to Member
void issueBook(struct Book library[], int bookCount, struct Member members[], int memberCount) {
    int bookID, memberID;
    printf("\nEnter Member ID: ");
    scanf("%d", &memberID);
    printf("Enter Book ID: ");
    scanf("%d", &bookID);

    int bookFound = -1, memberFound = -1;

    // Find the book and check availability
    for (int i = 0; i < bookCount; i++) { if (library[i].bookID == bookID && library[i].quantity > 0) {
            bookFound = i;
            break;
        }
    }

    // Find the member
    for (int i = 0; i < memberCount; i++) {
        if (members[i].memberID == memberID) {
            memberFound = i;
            break;
        }
    }

    if (bookFound != -1 && memberFound != -1) {
        library[bookFound].quantity--;
        members[memberFound].booksIssued++;
        printf("\nBook Issued Successfully!\n");
    } else {
        printf("\nBook or Member not found.\n");
    }
}

// Main Function
int main() {
    struct Book library[MAX_BOOKS];
    struct Member members[MAX_MEMBERS];
    int bookCount = 0, memberCount = 0;
    int choice;

    do {
        printf("\nLibrary Management System Menu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Add Member\n");
        printf("4. Issue Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                addMember(members, &memberCount);
                break;
            case 4:
                issueBook(library, bookCount, members, memberCount);
                break;
            case 5:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice, Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}