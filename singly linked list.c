#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true = 1;
#define false = 0;


typedef struct sllist { //contains 2 things: value and a next pointer
    int val;
    struct sllist* next;
}sllnode;

sllnode* create(int x){
        sllnode* node = malloc(sizeof(sllnode)); //allocate memory for new node
        if (!node){
            exit(2);  //checking whether malloc is successful
        }
        node->val = x; //set value of node to x
        node->next = NULL; //set next of node to NULL (first element of linked list)
        return node; //return the newly created node
    }

bool find(sllnode* head, int value){
    sllnode* finder = head; //create a traversal pointer
    while (finder != NULL){
        if (finder->val == value){
            return 1;
        } else {
            finder = finder->next;
        }
    }
    return 0;
}

sllnode* insert(sllnode* head, int value){
    sllnode* newnode = malloc(sizeof(sllnode)); //make new node
    if (!newnode){
            exit(2);  //checking whether malloc is successful
        }
    newnode->val = value; //new node's value
    newnode->next = head;
    head = newnode;
    return head;
}

void destroy(sllnode* head){
    sllnode* current = head;
    if (current == NULL){
        free(current);
    } else {
        destroy(current->next);
        free(current);
    }

}

int main(void){
    sllnode *newlist = create(6);
    printf("%i\n", newlist->val);
    newlist = insert(newlist, 33);
    newlist = insert(newlist, 3453);
    printf("%i\n", newlist->val);
    printf("%i\n",find(newlist,33));
    printf("%i\n",find(newlist,3453));
    destroy(newlist);
}
