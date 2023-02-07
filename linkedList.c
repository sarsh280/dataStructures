/*******************************
* File Name          : linkedList.c
* Description        : Linked Lists
*                      This program uses linked lists to hold and print a list of words
*                      organized by order number assosciated with each word. Each word can
*                      consist of maximum 30 characters.
*
* Author:              ARSHDEEP SINGH
* Date:                01-02-2022
********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_DATA_ITEMS   10                               // the number of data items to be used in list
// should be less than or equal 10

// structure/typedef used for holding data
typedef struct {
    char name[30];
    int  order;
} inputData;

// definition of linked list data nodes
typedef struct LinkedListNode {
    char                            NameData[30];           // the name to be stored
    int                             order;                  // the order to be stored
    struct LinkedListNode* ptrNextNode;           // pointer to next node in list (NULL if the end)
} LinkedListNodeDef;

// prototypes
LinkedListNodeDef* AddToLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder);
LinkedListNodeDef* RemoveFromLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder);
void PrintLinkedList(LinkedListNodeDef* ptrHead);

// data used for test
// start iData
inputData iData[10] = {
    { "kiwi", 1 },
    { "water", 3 },
    { "carrot", 3 },
    { "pickels", 7 },
    { "chocolate", 5 },
    { "fish", 4 },
    { "candy", 7 },
    { "orange", 4 },
    { "airplane", 9 },
    { "butter", 5 }
};
// end iData
// end of data for assignment

// Correct order after inserting into list is:
// kiwi,1
// water,3
// carrot,3 -- will be removed
// orange,4
// fish,4
// butter,5
// chocolate,5
// pickels,7
// candy,7
// airplane,9

// Final output (care for the format! one word each line! and there should be no other output)
// kiwi,1
// water,3
// orange,4
// fish,4
// butter,5
// chocolate,5
// pickels,7
// candy,7
// airplane,9

void main(void) {
    int i;

    // define linked list head
    struct LinkedListNode* ptrHead = NULL;

    // Print out the input data
    printf("Data before Linked List is:\n");
    for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++) {
        printf("%s , %d\n", iData[i].name, iData[i].order);
    }

    // insert the data into Linked List
    for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++) {
        ptrHead = AddToLinkedList(ptrHead, iData[i].name, iData[i].order);
    }

    ptrHead = RemoveFromLinkedList(ptrHead, iData[2].name, iData[2].order);

    // now print out the list in order it is stored starting at head
    printf("\n");
    PrintLinkedList(ptrHead);
}

// FUNCTION      : AddToLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an order and 
//                 places them in a linked list organized by priority of order number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead   - variable to store address of ptrHead
//                 char *NameData               - Array of Characters with data 
//                 int DataOrder                - Order of the item
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef* AddToLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder) {
    // put code in here to add the item(s) to the linked list
    LinkedListNodeDef* node = malloc(sizeof(LinkedListNodeDef));    //Making Node

    strcpy(node->NameData, NameData);                               //Adding Data
    node->ptrNextNode = NULL;
    node->order = DataOrder;


    if (ptrHead == NULL) {
        return node;
    }

    LinkedListNodeDef* ptrTail = ptrHead;                           //Sorting the Linked_list
    LinkedListNodeDef* ptrPreNode = ptrTail;
    while (ptrTail->ptrNextNode != NULL) {
        if (ptrTail->order >= DataOrder) {
            ptrPreNode->ptrNextNode = node;
            node->ptrNextNode = ptrTail;
            return ptrHead;
        }
        else if (ptrTail->order == DataOrder) {
            LinkedListNodeDef* temp = ptrTail->ptrNextNode;
            ptrTail->ptrNextNode = node;
            node->ptrNextNode = temp;
            return ptrHead;
        }
        else {
            ptrPreNode = ptrTail;
            ptrTail = ptrTail->ptrNextNode;
        }
    }
    if (ptrTail->order > DataOrder) {
        ptrPreNode->ptrNextNode = node;
        node->ptrNextNode = ptrTail;
        return ptrHead;
    }
    ptrTail->ptrNextNode = node;
    return ptrHead;
}

// FUNCTION      : RemoveFromLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an order and 
//                 places them in a linked list organized by priority of order number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead   - variable to store address of ptrHead
//                 char *NameData               - Array of Characters with data 
//                 int DataOrder                - Order of the item
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef* RemoveFromLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataOrder) {
    // put code in here to add the item(s) to the linked list

    LinkedListNodeDef* ptrTail = ptrHead;
    LinkedListNodeDef* ptrPreNode = ptrTail;
    while (ptrTail->ptrNextNode != NULL) {
        if ((ptrTail->order == DataOrder) & (strcmp(ptrTail->NameData, NameData) == 0)) {
            ptrPreNode->ptrNextNode = ptrTail->ptrNextNode;
            free(ptrTail);
            return ptrHead;
        }
        ptrPreNode = ptrTail;
        ptrTail = ptrTail->ptrNextNode;
    }

    return ptrHead;
}

// FUNCTION      : PrintLinkedList()
// DESCRIPTION   : This function takes an input of the head of the linked list, then loops through
//                 and prints each word in the linked list until the ptrNextNode is NULL.
// PARAMETERS    : LinkedListNodeDef *ptrHead 
// RETURNS       : void
void PrintLinkedList(LinkedListNodeDef* ptrHead) {
    do {
        printf("%s , %d\n", ptrHead->NameData, ptrHead->order);
        ptrHead = ptrHead->ptrNextNode;
    } while (ptrHead != NULL);
}