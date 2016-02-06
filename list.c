#include <stdio.h>
#include <stdlib.h>

#define MAX_INTS 1000

/* A node in the linked list */
struct node {
    int data;
    struct node *next;
};

struct node* create_list(int intarray[], int len);

struct node* add_item_at_start(struct node *head, int data);

int search_array(int integers[], int numints, int element);

int search_list(struct node *head, int element);

struct node* create_sorted_list(struct node *head);

struct node* add_item_sorted(struct node *head, int data);

int copy_list_to_array(struct node *head, int *array);

void print_list(struct node *head);

void print_array(int integers[], int len);


int main(int argc, char *argv[])
{
    /* TODO: Complete the main method according to the steps outlined */

    /* Open a file for reading */

    /* Read the numbers from the file, into an array */

    /* Print the array */

    /* Create a linked list with the integers from the array */
    
    /* Print the linked list */


    /* Repeatedly prompt the user for a number to be searched.
    *  Search the array for the number and print out the result as shown in the specs.
    *  Search the linked list for the number and print out the result as shown in the specs.
    *  Stop prompting when the user enters 'q' (just the character q without the single quotes).
    */

    /* Create a sorted list(in ascending order) from the unsorted list */

    /* Print the sorted list */

    /* Copy the sorted list to an array with the same sorted order */

    /* Print out the sorted array */    

    /* Print the original linked list again */

    /* Print the original array again */


    /* Open a file for writing */

    /* Write the sorted array to a file named "sorted_numbers.txt" */

    /* Print out the number of integers written to the file */

}

struct node* create_list(int intarray[], int len)
{
    /* TODO: Complete this function */ 
}


struct node* add_item_at_start(struct node *head, int data)
{
    /* TODO: Complete this function */
}

int search_list(struct node *head, int element)
{
    /* TODO: Complete this function */
}

int search_array(int integers[], int numints, int element)
{
    /* TODO: Complete this function */
}

int copy_list_to_array(struct node *head, int *array)
{
    /* TODO: Complete this function */
}

struct node* create_sorted_list(struct node *head)
{
    /* TODO: Complete this function */
}

struct node* add_item_sorted(struct node *sorted_head, int data)
{
    /* TODO: Complete this function */
}

void print_list(struct node *head)
{
    if (head == NULL) {
        printf("Linked List is Empty.\n");
    } else {
        struct node *temp = head;
        printf("head->");
        while (temp != NULL) {
            printf("|%d|->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void print_array(int integers[], int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("| %d ", integers[i]);
    }
    printf("|\n");
}
