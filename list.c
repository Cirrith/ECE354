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

    FILE *input;
    char buffer[100];
    int inputs[MAX_INTS];
    int length = 0;

    if(argc != 2)
    {
        printf("The Input Arguments was bad");
        exit(0);
    }

   /* Open a file for reading */

    input = fopen(argv[1], "r");

    if(input == NULL)
    {
        printf("Error in File Opening");
        exit(0);
    }

    /* Read the numbers from the file, into an array */

    for(length; fgets(buffer, 100, input) != NULL; length++)
    { 
        inputs[length] = atoi(buffer);
    }

   /* Print the array */

    print_array(inputs, length);
    

    /* Create a linked list with the integers from the array */

    struct node *head = create_list(inputs, length);
    
    /* Print the linked list */

    print_list(head);

    /* Repeatedly prompt the user for a number to be searched.
    *  Search the array for the number and print out the result as shown in the specs.
    *  Search the linked list for the number and print out the result as shown in the specs.
    *  Stop prompting when the user enters 'q' (just the character q without the single quotes).
    */
    char in[256];
    while(1)
    {
        printf("\nEnter an element to be searched in the list and array: ");
        scanf(" %s", &in);

        if(in[0] == 'q')
            break;

        int index = search_array(inputs, length, atoi(in));

        if(index == -1)
        {
            printf("\nElement %d not found in array.", atoi(in));

        }
        else
        {
            printf("\nElement %d found in the array at index: %d", atoi(in), index);

        }
    }

printf("You say hello and I say goodbye");


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
    if(len == 0)
    {
        return NULL;
    }

    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    (*head).data = intarray[0];

    struct node *current = head;
    (*current).next = NULL;

    int i;
    for( i = 1; i < len; i++)
    {
        struct node *next = (struct node*)malloc(sizeof(struct node));
        (*next).data = intarray[i];
        (*next).next = NULL;

        (*current).next = next;

        current = next;     
    }

    return head;

}


struct node* add_item_at_start(struct node *head, int data)
{
    struct node* start = (struct node*)malloc(sizeof(struct node));
    (*start).data = data;
    
    (*start).next = head;

    return start;
}

int search_list(struct node *head, int element)
{
    /* TODO: Complete this function */
}

int search_array(int integers[], int numints, int element)
{

    // Check what happens if there are more than on copy of the searched element

    int i;
    for(i = 0; i < numints; i++)
    {
        if(integers[i] == element)
        {
            return i;
        }
    }
    
    return -1;
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
