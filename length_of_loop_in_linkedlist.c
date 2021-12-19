/*
    Find length of loop in linked list
    Qualcomm question
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int countNode(struct Node* n)
{
    int res = 1;
    struct Node* temp = n;
    while(temp->next != n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}

int countNodeinLoop(struct Node *list)
{
    struct Node *slow_p = list, *fast_p = list;
    while(slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        
        if(slow_p == fast_p) return countNode(slow_p);
    }
    return 0;
}


struct Node* newNode(int key)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;

    return temp;
}

int main()
{
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);


    head->next->next->next->next = head->next; 


    printf("%d \n", countNodeinLoop(head));
    return 0;

}