#include<stdio.h>
#include"ticket.h"


int main() {
    struct Ticket* head = NULL;

    // Add seats to the linked list
    for (int i = 1; i <= 10; i++) {
        addTicket(&head, i);
    }

    // Display available and booked seats
    displaySeats(head);

    // Book and cancel seats
    bookTicket(head, 5);
    bookTicket(head, 8);
    cancelTicket(head, 5);
    bookTicket(head, 3);

    // Display updated available and booked seats
    displaySeats(head);

    return 0;
}
