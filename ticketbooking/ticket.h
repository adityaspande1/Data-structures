#include <stdio.h>
#include <stdlib.h>

// Definition for a ticket node
struct Ticket {
    int seatNumber;
    int isBooked;
    struct Ticket* next;
};

// Function to create a new ticket node
struct Ticket* createTicket(int seatNumber) {
    struct Ticket* newTicket = (struct Ticket*)malloc(sizeof(struct Ticket));
    if (newTicket == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newTicket->seatNumber = seatNumber;
    newTicket->isBooked = 0;
    newTicket->next = NULL;
    return newTicket;
}

// Function to add a ticket to the end of the linked list
void addTicket(struct Ticket** head, int seatNumber) {
    struct Ticket* newTicket = createTicket(seatNumber);

    if (*head == NULL) {
        *head = newTicket;
    } else {
        struct Ticket* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTicket;
    }
}

// Function to book a ticket by seat number
void bookTicket(struct Ticket* head, int seatNumber) {
    while (head != NULL) {
        if (head->seatNumber == seatNumber) {
            if (head->isBooked == 0) {
                head->isBooked = 1;
                printf("Seat %d is booked.\n", seatNumber);
            } else {
                printf("Seat %d is already booked.\n", seatNumber);
            }
            return;
        }
        head = head->next;
    }
    printf("Seat %d not found.\n", seatNumber);
}

// Function to cancel a booked ticket by seat number
void cancelTicket(struct Ticket* head, int seatNumber) {
    while (head != NULL) {
        if (head->seatNumber == seatNumber) {
            if (head->isBooked == 1) {
                head->isBooked = 0;
                printf("Seat %d is canceled.\n", seatNumber);
            } else {
                printf("Seat %d is not booked.\n", seatNumber);
            }
            return;
        }
        head = head->next;
    }
    printf("Seat %d not found.\n", seatNumber);
}

// Function to display the list of available and booked seats
void displaySeats(struct Ticket* head) {
    printf("Available Seats: ");
    while (head != NULL) {
        if (head->isBooked == 0) {
            printf("%d ", head->seatNumber);
        }
        head = head->next;
    }
    printf("\n");

    printf("Booked Seats: ");
    head = head;
    while (head != NULL) {
        if (head->isBooked == 1) {
            printf("%d ", head->seatNumber);
        }
        head = head->next;
    }
    printf("\n");
}

