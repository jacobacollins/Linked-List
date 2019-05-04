/*Jacob Collins*/
/*CS 241 lab-07*/
/*  11/14/2016 */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


/* Alloc a new node with given data. */
struct ListNode* createNode(int data) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Insert data at appropriate place in a sorted list, return new list head. */
struct ListNode* insertSorted(struct ListNode* head, int data)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *new_node = createNode(data);

    while (curr) {
        if (data < curr->data) {
            new_node->next = curr;
            if (prev)
                prev->next = new_node;
            return (prev ? head : new_node);
        }
        prev = curr;
        curr = curr->next;
    }
    if (head) {
        new_node->next = NULL;
        prev->next = new_node;
    } else {
        head = new_node;
    }

    return head;
}
/* Remove data from list pointed to by headRef, changing head if necessary.
* Make no assumptions as to whether the list is sorted.
* Memory for removed node should be freed.
* Return 1 if data was present, 0 if not found. */
int removeItem(struct ListNode** headRef, int data)
{
    while (*headRef && (*headRef)->data != data)
        headRef = &(*headRef)->next;

    if (*headRef)
    {
        struct ListNode *tmp = *headRef;
        free(tmp);
        *headRef = tmp->next;

        return 1;
    }
    return 0;
}
/* Insert data at head of list, return new list head. */
struct ListNode* pushStack(struct ListNode* head, int data)
{
	int dataPush = data;

    struct ListNode * tempPush = (struct  ListNode*)malloc(sizeof(struct ListNode));
    tempPush->data = dataPush;
    tempPush->next = head;
    
    return tempPush;
}

/* Remove and return data from head of non-empty list, changing head.
 * Memory for removed node should be freed. */
int popStack(struct ListNode** headRef)
 {
struct ListNode* head;
int result;
head = *headRef;

result = head->data; 
*headRef = head->next; 
free(head); 
return(result); 
}

/* Return length of the list. */
int listLength(struct ListNode* head)
 {
int count = 0;
struct ListNode* current = head;
while (current != NULL) {
count++;
current=current->next;
}
return(count);
}


/* Print list data on single line, separated with spaces and ending
 * with newline. */
void printList(struct ListNode* head)
{
    struct ListNode *curr = head;

    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    putchar('\n');
}
/* Free memory used by the list. */
void freeList(struct ListNode* head)
{
    struct ListNode *p = head;
    struct ListNode *tmp = NULL;

    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }

    head = NULL;
}



/* Reverse order of elements in the list */
void reverseList(struct ListNode** headRef)
{
    struct ListNode* prev   = NULL;
    struct ListNode* current = *headRef;
    struct ListNode* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *headRef = prev;
}