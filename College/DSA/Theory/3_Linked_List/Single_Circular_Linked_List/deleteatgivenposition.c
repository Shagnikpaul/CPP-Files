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

	// Else the new node will be
	// last node and will contain
	// the reference of head node
	else {
		temp->info = data;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

// Function to delete an element
// at a specified index in the list
void deleteAtIndex()
{
	// Stores the index at which
	// the element is to be deleted
	int pos, i = 1;
	struct node *temp, *position;
	temp = last->next;

	// If list is empty
	if (last == NULL)
		printf("\nList is empty.\n");

	// Else
	else {

		// Input Data
		printf("\nEnter index : ");
		scanf("%d", &pos);

		// Traverse till the node to
		// be deleted is reached
		while (i <= pos - 1) {
			temp = temp->next;
			i++;
		}

		// After the loop ends, temp
		// points at a node just before
		// the node to be deleted

		// Reassigning links
		position = temp->next;
		temp->next = position->next;

		free(position);
	}
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
int main()
{
	addatlast();
	addatlast();
	addatlast();
	deleteAtIndex();
	viewList();

	return 0;
}
