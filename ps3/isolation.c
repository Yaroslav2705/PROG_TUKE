#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }
    if (value < (*root)->value) {
        insert(&(*root)->left, value);
    } else {
        insert(&(*root)->right, value);
    }
}

int compareTrees(Node* tree1, Node* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }
    if (tree1 != NULL && tree2 != NULL) {
        return compareTrees(tree1->left, tree2->left) && compareTrees(tree1->right, tree2->right);
    }
    return 0;
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int i, j;
    int uniqueForms = 0;

    Node* roots[n];

    for (i = 0; i < n; i++) {
        roots[i] = NULL;

        for (j = 0; j < k; j++) {
            int value;
            scanf("%d", &value);
            insert(&roots[i], value);
        }

        int isUnique = 1;
        for (int m = 0; m < i; m++) {
            if (compareTrees(roots[m], roots[i])) {
                isUnique = 0;
                break;
            }
        }

        if (isUnique) {
            uniqueForms++;
        }
    }

    printf("%d\n", uniqueForms);

    for (i = 0; i < n; i++) {
        freeTree(roots[i]);
    }

    return 0;
}
