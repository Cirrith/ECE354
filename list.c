#include <stdio.h>
#include <stdlib.h>

#define MAX_INTS 1000

/* Title: P1 - list.c
* Description: Create a linked list & array from a provided file with numbers in it
*
* Author: Ryan Bambrough
* Email: rbambrough@wisc.edu
* CS Login: bambrough
* Section: 1
*
* Pair Partner: Jason Hsu
* Email: hsu39@wisc.edu
* CS Login: cheng-hsiang
* Section: 1
*/


/* A node in the linked list */
struct node {
    int data;
    struct node *next;
};


// Function Declarations
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
    /* Setup files and check arguments */
    FILE *input;
    FILE *output;
    char buffer[100];
    int inputs[MAX_INTS];
    int length = 0;

    if(argc != 2)
    {
        printf("The Input Arguments was bad");
        exit(1);
    }


   /* Open a file for reading */
    input = fopen(argv[1], "r"); //Read-only

    if(input == NULL)
    {
        printf("Error in File Opening");
        exit(1);
    }


    /* Read the numbers from the file, into an array */
    for(length; fgets(buffer, 100, input) != NULL; length++)
    { 
        inputs[length] = atoi(buffer);
    }

    fclose(input);


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

        int index_array = search_array(inputs, length, atoi(in));
        int index_list = search_list(head, atoi(in));

        if(index_array == -1 || index_list == -1)
        {
            printf("\nElement %d not found in array.", atoi(in));
	    printf("\nElement %d not found in list.", atoi(in));
        }
        else
        {
            printf("\nElement %d found in the array at index: %d", atoi(in), index_array);
            printf("\nElement %d found in the list at index: %d", atoi(in), index_list);
        }
    }


    /* Create a sorted list(in ascending order) from the unsorted list */
    struct node* sorted_list = create_sorted_list(head);


    /* Print the sorted list */
    print_list(sorted_list);


    /* Copy the sorted list to an array with the same sorted order */
    int sorted_array[MAX_INTS];

    int sorted_length = copy_list_to_array(sorted_list, sorted_array);


    /* Print out the sorted array */
    print_array(sorted_array, sorted_length);    


    /* Print the original linked list again */
    print_list(head);


    /* Print the original array again */
    print_array(inputs, length);


    /* Open a file for writing */
    output = fopen("sorted_numbers.txt", "w");

    if(output == NULL)
    {
       printf("The output file is NULL");
    }


    /* Write the sorted array to a file named "sorted_numbers.txt" */
    printf("Sorted Length = %d\n", sorted_length);

    int j;
    for(j = 0; j < sorted_length; j++)
    {
        fprintf(output, "%d\n", sorted_array[j]);
    }


    /* Print out the number of integers written to the file */
    printf("We printed %d integers to file", j);

    fclose(output);


}

struct node* create_list(int intarray[], int len)
{
    if(len == 0)
    {
        return NULL;
    }

    struct node *head;	//Keep head to return
    head = (struct node*)malloc(sizeof(struct node));
    (*head).data = intarray[0];

    struct node *current = head; //Pointer staying at end of list
    (*current).next = NULL;

    int i;
    for( i = 1; i < len; i++) //Create list
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

int search_list(struct node *head, int element) //****************
{
    struct node *current;
    current = head;

    int i = 0;
    while((*current).next != NULL) //Move through list with current
    {
        if((*current).data == element)
        {
            return i; //Element found in body of list
        }
        current = (*current).next;
        i++;
    }
    
    if((*current).data == element)
    {
        return i++; //Element found at end of list
    }

    return -1; //Element not found

}

int search_array(int integers[], int numints, int element)
{
    int i;
    for(i = 0; i < numints; i++)
    {
        if(integers[i] == element) //Move through array
        {
            return i; //Element found
        }
    }
    
    return -1; //Element not found
}

int copy_list_to_array(struct node *head, int *array)
{
    struct node *current;
    current = head;

    int i = 0;

    while((*current).next != NULL) //Move through 
    {
        array[i] = (*current).data;
        i++;
        current = (*current).next;
    }
    
    array[i] = (*current).data;
    i++;
    return i;
}

struct node* create_sorted_list(struct node *head)
{
    if(head == NULL) //No head means no list
    {
        printf("Input to 'create_sorted_list' equals null");
        return NULL;
    }

    struct node *current;
    current = head;

    if((*current).next == NULL) //One item list
    {
        return head;
    }

    struct node *sorted_head = NULL;

    while((*current).next != NULL)
    {
        sorted_head = add_item_sorted(sorted_head, (*current).data); //Add at correct position
        current = (*current).next;
    }

    add_item_sorted(sorted_head, (*current).data); //Take care of last item

    return sorted_head;
    
}

/**
* Given a head and data to insert will move through list and insert a new node with the data
* at the appropriate position. Ascending Order
*
* @param sorted_head - Pointer to top node of the sorted list
* @param data - Value of node to be inserted, will be compared against other data in list
* @return Pointer to head of sorted_list with newly added node
*/
struct node* add_item_sorted(struct node *sorted_head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node)); //Create node with data
    struct node *past = NULL;
    (*new).data = data;

    if(sorted_head == NULL) //First item in list to be added
    {
       (*new).next = NULL;
       return new;
    }	
    else
    {
      struct node* current;
      current = sorted_head;

      while( (*current).next !=NULL) //Move through list
      {	
	 
	 if(data > (*current).data) //Item should be put later in list
 	 {
 	    past = current;
	    current = (*current).next;
	 }
	 else
	 {
            if(past != NULL) //Check if the first item in list
            {
	        (*past).next = new;
            }

	    (*new).next = current;
	    break; 
	 }
      }
      if( data > (*current).data) //Reached end of list, insert at end
      {
          (*current).next = new;
          (*new).next = NULL;
          return sorted_head;
      }
      else
      {
          if(past == NULL) //Check if the first item in list
          {
              (*new).next = current;
              return new;
          }
          else //Second to last item
          {
              (*past).next = new;
              (*new).next = current;
              return sorted_head;
          }
      }
    }
}

/**
* Prints out all the elements in a list
*
* @param head - Pointer to top node of linked list
*
*/
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

/**
* Prints out all the elements in an array
*
* @param integers - Array of integers to be printed
* @param len - Number of elements to be printed.
*
*/
void print_array(int integers[], int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("| %d ", integers[i]);
    }
    printf("|\n");
}
