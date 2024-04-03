/*#include <stdio.h>
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 10

char* generateRandomWord() {
    static char words[][MAX_WORD_LENGTH] = {
        "apple", "banana", "orange", "grape", "mango",
        "kiwi", "cherry", "peach", "pear", "apricot"
    };

    srand(time(NULL));
    int randomIndex = rand() % (sizeof(words) / sizeof(words[0]));

    return words[randomIndex];
}

RandomNode* createRandomNode(int value) {
    RandomNode* newNode = (RandomNode*)malloc(sizeof(RandomNode));
    if (newNode != NULL) {
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void addRandomValue(RandomNode** root, int value) {
    if (*root == NULL) {
        *root = createRandomNode(value);
        return;
    }
    if (value < (*root)->value) {
        addRandomValue(&(*root)->left, value);
    } else {
        addRandomValue(&(*root)->right, value);
    }
}

int compareRandomTrees(RandomNode* tree1, RandomNode* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }
    if (tree1 != NULL && tree2 != NULL) {
        return compareRandomTrees(tree1->left, tree2->left) && compareRandomTrees(tree1->right, tree2->right);
    }
    return 0;
}

void freeRandomTree(RandomNode* root) {
    if (root != NULL) {
        freeRandomTree(root->left);
        freeRandomTree(root->right);
        free(root);
    }
}

int main() {
    int randomCount, valueCount;
    scanf("%d %d", &randomCount, &valueCount);

    int randomIndex, valueIndex;
    int uniqueRandomForms = 0;

    RandomNode* randomRoots[randomCount];

    for (randomIndex = 0; randomIndex < randomCount; randomIndex++) {
        randomRoots[randomIndex] = NULL;

        char randomTreeName[MAX_WORD_LENGTH];
        strcpy(randomTreeName, generateRandomWord());

        printf("RandomTree %d: %s\n", randomIndex + 1, randomTreeName);

        for (valueIndex = 0; valueIndex < valueCount; valueIndex++) {
            int value;
            scanf("%d", &value);
            addRandomValue(&randomRoots[randomIndex], value);
        }

        int isUnique = 1;
        for (int m = 0; m < randomIndex; m++) {
            if (compareRandomTrees(randomRoots[m], randomRoots[randomIndex])) {
                isUnique = 0;
                break;
            }
        }

        if (isUnique) {
            uniqueRandomForms++;
        }
    }

    printf("%d\n", uniqueRandomForms);

    for (randomIndex = 0; randomIndex < randomCount; randomIndex++) {
        freeRandomTree(randomRoots[randomIndex]);
    }

    return 0;
}
