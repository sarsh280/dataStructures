/*******************************************************************************************
* File Name          : queue.c
* Description        : Queue
*                      This program should implement a queue to enqueue/dequeue a list of
*                      positive numbers
*
* Author:              Arshdeep Singh
* Date:                2022, March 27
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structure used for holding data
typedef struct node {
    int number;
    struct node *next;
} Node;

// queue head and tail
Node *head = NULL;
Node *tail = NULL;

// queue functions
void enqueue(const int number);
int dequeue();

int main(int argc, char *argv[]) {
        int number;             // to store new number
        int i;                  // used in for loop as index

        // put all the numbers into the binary tree
        // numbers will be provided from command line
        for (i = 1; i < argc; i++) {
            // if it is a dequeue operation
            if (!strcmp(argv[i], "dequeue")) {
                printf("%s ", argv[i]);
                printf("%d\n", dequeue(head));
            } else {
                number = atoi(argv[i]);
                printf("enqueue %d\n", number);
                enqueue(number);
            }
        }
        return 0;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//
//============================= do not remove above comments  ==============================//

// FUNCTION      : enqueue
//
// DESCRIPTION   :
//   This function will add a new number into a queue
//
// PARAMETERS    :
//   number - the number that is to be stored in the queue
//
// RETURNS       :
//   Nothing
void enqueue(const int number) {
    Node *queue = malloc(sizeof(Node));
    queue->number = number;
    queue->next = NULL;

    if(head == NULL && tail == NULL){
        head = queue;
        tail = queue;
    }
    tail->next = queue;
    tail = queue;
}

// FUNCTION      : dequeue
//
// DESCRIPTION   :
//   This function will dequeue a number from a queue
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   the number dequeued or -1 if the queue is empty
int dequeue() {
    if(head == NULL && tail == NULL){
        return -1;
    }
    Node * res = head;

    if(head == tail){
        head = NULL;
        tail = NULL;
        return res->number;
    }
    head = head->next;
    return res->number;
}

