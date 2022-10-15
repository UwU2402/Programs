#include <stdio.h>
#include <stdlib.h>

enum STATUS { RESET, INCREASING, DECREASING };

struct Node {
    int info;
    struct Node *link;
} * start;

void createList(int n) {
    struct Node *currNode, *newNode;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            start = (struct Node *)malloc(sizeof(struct Node));
            if (NULL == start) {
                printf("\nMemory cannot be allocated.");
            } else {
                int info;
                printf("\nInput info for Node #%d :", i);
                scanf("%d", &info);
                start->info = info;
                start->link = NULL;
                currNode = start;
            }
        } else {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            if (NULL == newNode) {
                printf("\nMemory cannot be allocated.");
            } else {
                int info;
                printf("Input info for Node #%d :", i);
                scanf("%d", &info);
                newNode->info = info;
                newNode->link = NULL;

                currNode->link = newNode;
                currNode = newNode;
            }
        }
    }
}

void displayList() {
    if (NULL == start) {
        printf("\nList is empty!");
        return;
    }

    struct Node *currNode = start;
    printf("\nLinked List : ");
    while (NULL != currNode) {
        printf("%d  ", currNode->info);
        currNode = currNode->link;
    }
    printf("\n");
}

struct Node *reverse(struct Node *preBegin, struct Node *end) {
    struct Node *pointer = preBegin == start ? start : preBegin->link,
                *returnNode = pointer, *tmp = end->link;

    while (NULL != pointer && pointer != end) {
        struct Node *next = pointer->link;
        pointer->link = tmp;
        tmp = pointer;
        pointer = next;
    }

    if (NULL != pointer) {
        pointer->link = tmp;
    }

    if (preBegin == start) {
        start = pointer;
    } else {
        preBegin->link = pointer;
    }

    return returnNode;
}

void reverseSequence() {
    if (NULL == start) return;

    struct Node *curr = start, *lastNode = start;

    // to track changes
    enum STATUS status = RESET;

    while (NULL != curr) {
        struct Node *next = curr->link;

        if (NULL == next) {
            reverse(lastNode, curr);
            break;
        }

        if (status == RESET) {
            if (curr->info < next->info) {
                status = INCREASING;
            } else if (curr->info > next->info) {
                status = DECREASING;
            } else {
                lastNode = curr;
            }
        } else if (status == INCREASING) {
            if (curr->info >= next->info) {
                lastNode = reverse(lastNode, curr);
                status = RESET;
            }
        } else if (status == DECREASING) {
            if (curr->info < next->info) {
                lastNode = reverse(lastNode, curr);
                status = RESET;
            }
        }

        curr = next;
    }
}

int main(void) {
    int n;

    printf("Enter number of nodes : ");
    scanf("%d", &n);

    createList(n);
    displayList();

    reverseSequence();
    printf("\nAfter reversing sequences : ");
    displayList();

    return 0;
}
