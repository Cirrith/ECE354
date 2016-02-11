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
* Pair Partner: Cheng-Hsiang
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
    int length;

    if(argc != 2)
    {
        printf("The Input Arguments was bad\n");
        exit(1);
    }


   /* Open a file for reading */
    input = fopen(argv[1], "r"); //Read-only

    if(input == NULL)
    {
        printf("Error in File Opening\n");
        exit(1);
    }


    /* Read the numbers from the file, into an array */
    for(length = 0; fgets(buffer, 100, input) != NULL; length++)
    { 
        inputs[length] = atoi(buffer);
    }

    fclose(input);


   /* Print the array */
    printf("Array: ");
    print_array(inputs, length);
    printf("\n");


    /* Create a linked list with the integers from the array */
    struct node *head = create_list(inputs, length);
    

    /* Print the linked list */
    printf("Linked List: ");
    print_list(head);
    printf("\n");


    /* Repeatedly prompt the user for a number to be searched.
    *  Search the array for the number and print out the result as shown in the specs.
    *  Search the linked list for the number and print out the result as shown in the specs.
    *  Stop prompting when the user enters 'q' (just the character q without the single quotes).
    */
    char in[256];
    while(1)
    {
        printf("Enter an element to be searched in the list and array: ");
        scanf(" %s", in);

        if(in[0] == 'q')
            break;

        int index_array = search_array(inputs, length, atoi(in));
        int index_list = search_list(head, atoi(in));

        if(index_array == -1 || index_list == -1)
        {
            printf("\nElement %d not found in array.\n", atoi(in));
	    printf("\nElement %d not found in list.\n\n", atoi(in));
        }
        else
        {
            printf("\nElement %d found in the array at index: %d\n", atoi(in), index_array);
            printf("\nElement %d found in the list at index: %d\n\n", atoi(in), index_list);
        }
    }


    /* Create a sorted list(in ascending order) from the unsorted list */
    struct node* sorted_list = create_sorted_list(head);


    /* Print the sorted list */
    printf("\nSorted Linked List: ");
    print_list(sorted_list);
    printf("\n");


    /* Copy the sorted list to an array with the same sorted order */
    int sorted_array[MAX_INTS];

    int sorted_length = copy_list_to_array(sorted_list, sorted_array);


    /* Print out the sorted array */
    printf("Sorted Array: ");
    print_array(sorted_array, sorted_length);    
    printf("\n");


    /* Print the original linked list again */
    printf("Original Linked List: ");
    print_list(head);
    printf("\n");


    /* Print the original array again */
    printf("Original Array: ");
    print_array(inputs, length);
    printf("\n");


    /* Open a file for writing */
    output = fopen("sorted_numbers.txt", "w");

    if(output == NULL)
    {
       printf("The output file is NULL\n");
    }


    /* Write the sorted array to a file named "sorted_numbers.txt" */
    printf("Sorted Length = %d\n", sorted_length);

    int j;
    for(j = 0; j < sorted_length; j++)
    {
        fprintf(output, "%d\n", sorted_array[j]);
    }


    /* Print out the number of integers written to the file */
    printf("We printed %d integers to file\n", j);

    fclose(output);

    return 0;
}
/**
 * This function takes in an integer array and the size of the integer 
 * array then it uses the add_item_at_start(struct node *head, int data)
 * function to create a list.
 *
 * @param intarray[ ]: An integer array to be used for creating the list
 * @param len: The length of the integer array
 * @return The head of the created linked list.
 */
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

/**
 * This function takes in a pointer pointing to the head of a linked
 * list and an integer to be added at the beginning of the list.
 *
 * @param head: The pointer to the head of the linked list to be addded an item to.
 * @param data: The integer to be added to the beginning of the list.
 * @return The head of the newly updated linked list.
 */
struct node* add_item_at_start(struct node *head, int data)
{
    struct node* start = (struct node*)malloc(sizeof(struct node));
    (*start).data = data;
    
    (*start).next = head;

    return start;
}


/**
 * This function takes in a pointer pointing to the head of a linked
 * list and an integer to be searched in the list. It searches the linked list
 * and see if the integer is found. Position value ranges from 1 to n.
 *
 * @param head: The pointer to the head of the linked list to be searched.
 * @param element: The integer to be searched in the list.
 * @return The position of the element being found in the list, otherwise returns -1.
 */
int search_list(struct node *head, int element) //****************
{
    struct node *current;
    current = head;

    int i = 0;
    while((*current).next != NULL) //Move through list with current
    {
        if((*current).data == element)
        {
            return ++i; //Element found in body of list
        }
        current = (*current).next;
        i++;
    }
    
    if((*current).data == element)
    {
        return ++i; //Element found at end of list
    }

    return -1; //Element not found

}
/**
 * This function takes in an integer array, the number of integers, and  
 * the integer to be searched in the array. It searches the array 
 * and see if the integer is found.
 *
 * @param integers []: An integer array to be searched.
 * @param numints: The number of integers in the integer array.
 * @param element: The integer to be searched in the integer array.
 * @return The position of the element being found in the array, otherwise returns -1.
 */
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
/**
 * This function takes in a pointer to the head of the list, and a pointer 
 * to the integer array. It copies the content of the linked list to the array  
 * and count how many integers being copied to the array.
 *
 * @param head []: The head to the linked list.
 * @param array: A pointer pointing to the first integer in the integer array.
 * @return The number of integers being copied from the list to the array.
 */
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
/**
 * This function takes in a pointer to the head of the linked list to be sorted 
 * and return the head of the sorted linked list.
 *
 * @param head []: The head to the linked list going to be sorted.
 * @return The head of the sorted linked list.
 */
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
