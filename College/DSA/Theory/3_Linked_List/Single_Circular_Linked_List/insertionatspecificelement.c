// C program for the above operation

#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct node {
	int info;
	struct node* next;
};

// Pointer to last node in list
struct node* last = NULL;

// Function to add a new node
// at the end of the list
void addatlast()
{
	// Stores number to be inserted
	int data;

	// Initialize a new node
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	// Input data
	printf("\nEnter data to be inserted : \n");
	scanf("%d", &data);

	// If the new node is the
	// only node in the list
	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}

	// Else the new node will be the
	// last node and will contain
	// the reference of head node
	else {
		temp->info = data;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

// Function to insert after any
// specified element
void insertafter()
{
	// Stores data and element after
	// which new node is to be inserted
	int data, value;

	// Initialize a new node
	struct node *temp, *n;

	// Input data
	printf("\nEnter number after which"
		" you want to enter number: \n");
	scanf("%d", &value);
	temp = last->next;

	do {

		// Element after which node is
		// to be inserted is found
		if (temp->info == value) {
			n = (struct node*)malloc(sizeof(struct node));

			// Input Data
			printf("\nEnter data to be"
				" inserted : \n");
			scanf("%d", &data);
			n->info = data;
			n->next = temp->next;
			temp->next = n;

			// If temp is the last node
			// so now n will become the
			// last node
			if (temp == last)
				last = n;
			break;
		}
		else
			temp = temp->next;
	} while (temp != last->next);
}

// Function to print the list
void viewList()
{
	// If list is empty
	if (last == NULL)
		printf("\nList is empty\n");

	// Else print the list
	else {
		struct node* temp;
		temp = last->next;
		do {
			printf("\nData = %d", temp->info);
			temp = temp->next;
		} while (temp != last->next);
	}
}

// Driver Code
int main()
{
	// Initialize the list
	addatlast();
	addatlast();
	addatlast();

	// Function Call
	insertafter();

	// Print list
	viewList();

	return 0;
}
