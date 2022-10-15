#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
void deleteNode(struct Node** head_ref, struct Node* del)
{
	if (*head_ref == NULL || del == NULL)
		return;
	if (*head_ref == del)
		*head_ref = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return;
}
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}



void deleteGreaterNodes(struct Node** head_ref, int x)
{
	struct Node* ptr = *head_ref;
	struct Node* next;

	while (ptr != NULL) {
		next = ptr->next;
		if (ptr->data > x)
			deleteNode(head_ref, ptr);
		ptr = next;
	}
}
void deleteLesserNodes(struct Node** head_ref, int x)
{
	struct Node* ptr = *head_ref;
	struct Node* next;

	while (ptr != NULL) {
		next = ptr->next;
		if (ptr->data < x)
			deleteNode(head_ref, ptr);
		ptr = next;
	}
}


int main()
{
	struct Node* head = NULL;
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);
	push(&head, 12);
	push(&head, 14);
	push(&head, 16);
	push(&head, 18);

	printf("\n Original Linked list ");
	printList(head);

int x = 12;
deleteGreaterNodes(&head, x);
	printf("\n Modified Linked list - Greater ");
	printList(head);

struct Node* head2 = NULL;
	push(&head2, 2);
	push(&head2, 4);
	push(&head2, 8);
	push(&head2, 10);
	push(&head2, 12);
	push(&head2, 14);
	push(&head2, 16);
	push(&head2, 18);

deleteLesserNodes(&head2, x);
printf("\n Modified Linked list - Lesser ");
	printList(head2);

	getchar();
}
