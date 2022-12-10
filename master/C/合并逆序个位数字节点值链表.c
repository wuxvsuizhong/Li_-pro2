#include <stdio.h>
#include <stdlib.h>

struct Linknode {
    int val;
    struct Linknode *next;
};

struct Link {
    struct Linknode *root;
};

void LinkAppend(struct Link *l, int n) {
    struct Linknode *newNode =
        (struct Linknode *)calloc(1, sizeof(struct Linknode));
    newNode->val = n;
    newNode->next = NULL;
    if (l->root == NULL) {
        l->root = newNode;
    } else {
        struct Linknode *head = l->root;
        while (head->next)
            head = head->next;
        head->next = newNode;
    }
}

void LinkTravel(struct Link *l) {
    struct Linknode *head = l->root;
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void main() {
    struct Link l1 = {NULL};
    struct Link l2 = {NULL};
    for (int i = 0; i < 4; i++) {
        LinkAppend(&l1, 9);
    }

    LinkAppend(&l2, 1);

    LinkTravel(&l1);
    LinkTravel(&l2);
    return;
}