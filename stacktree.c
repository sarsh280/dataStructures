/*******************************************************************************************
* File Name          : stacktree.c
* Description        : Use Stack to traverse a binary tree
*
* Author:              Arshdeep Singh
* Date:                2022, March 27
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store a tree node
typedef struct treenode {
    int number;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

// stack structure
typedef struct stacknode {
    struct treenode *ptrTreeNode;
    struct stacknode *nextStackNode;
} Node;

// tree head
TreeNode *head = NULL;

// stack top
Node *top = NULL;

// tree functions
void addToBinaryTree(const int number);
void printBinaryTreeInOrder(TreeNode* head);

// stack functions
void push(TreeNode *);
TreeNode* pop();

int main(int argc, char* argv[]) {
        int number;                     // to store new number
        int i;                          // used in for loop as index

        // put all the numbers into the binary tree
        // numbers will be provided from command line
        for (i = 1; i < argc; i++) {
            number = atoi(argv[i]);
            addToBinaryTree(number);
        }

        // print the entire tree using In-Order
        // ptrTreeNode time you need to do it using stack
        printBinaryTreeInOrder(head);

        return 0;
}

// this is an implementation you can use to check your assignment 2 code
void addToBinaryTree(const int number) {
        TreeNode* p = head;
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        if (node == NULL) {
            return; // don't handle the error for now
        }
        node->number = number;
        node->left = NULL;
        node->right = NULL;

        if (head == NULL) {
            head = node;
            return;
        }
/*Duplicate is not allowed in binary tree, Its not been tested like in assignment 2
Duplicate elements can be eliminated by adding 1 more condition in a if statement
if(p->number == number) in this function
this is how it can be solved*/
        while (1) {
            if (p->number < number) {
                if (p->right == NULL) {
                    p->right = node;
                    break;
                }
                else {
                    p = p->right;
                }
            }
            else {
                if (p->left == NULL) {
                    p->left = node;
                    break;
                }
                else {
                    p = p->left;
                }
            }
            /*we can add if(p->number == number) then return the statement to remove the duplicate elements*/
		}
    return;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//
//============================= do not remove above comments  ==============================//

// FUNCTION      : push
//
// DESCRIPTION   :
//   a function will push a new stack node into a stack
//
// PARAMETERS    :
//   TreeNode* - the new tree node to store
//
// RETURNS       :
//   Nothing
void push(TreeNode *p) {
    // malloc a new stack node using the tree node
    // and push it into the stack

    Node *stack = malloc(sizeof(Node));
    stack->ptrTreeNode = p;
    stack->nextStackNode = NULL;
    if(top == NULL){
        top = stack;
        return;
    }
    Node * head = top;
    while(head->nextStackNode != NULL){
        head = head->nextStackNode;
    }
    head->nextStackNode = stack;
    // you code
}

// FUNCTION      : pop
//
// DESCRIPTION   :
//   a function will pop a tree node from the stack
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   the TreeNode* popped or NULL if the stack is empty
TreeNode* pop() {
    // you code
    if(top == NULL){
        return NULL;
    }
    Node *head = top;
    if(head->nextStackNode == NULL){
        Node *res = head;
        top = NULL;
        return res->ptrTreeNode;
    }
    while(head->nextStackNode->nextStackNode != NULL){
        head = head->nextStackNode;
    }

    Node *res = head->nextStackNode;
    head->nextStackNode = NULL;
    return res->ptrTreeNode;
}

// FUNCTION      : printBinaryTreeInOrder
//
// DESCRIPTION   :
//   a function will print the entire binary tree out using In-Order
//   using your stack. This is a good place to understand why recursion
//   can usually be changed to iteratives by using stacks
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   Nothing
void printBinaryTreeInOrder(TreeNode* head) {
    // add code to print data using In-Order starting at the "head" pointer
    // you need to use your stack to print it
    // any recursion call is not allowed
    // one number per line
    // printf("%d\n");

    if(head == NULL)
        return;
    
    TreeNode *currentTreeNode = head;
    while(1){
        if (currentTreeNode != NULL){
            push(currentTreeNode);
            currentTreeNode = currentTreeNode->left;
        }
        else{
            currentTreeNode = pop();
            if(currentTreeNode == NULL) break;
            printf("%d\n", currentTreeNode->number);
            currentTreeNode =  currentTreeNode->right;
        }
    }
}
