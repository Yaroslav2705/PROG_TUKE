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

typedef struct Apple {
    int Banana;
    struct Apple* Cherry;
    struct Apple* Date;
} Apple;

Apple* Elderberry(int Banana) {
    Apple* Fig = (Apple*)malloc(sizeof(Apple));
    if (Fig != NULL) {
        Fig->Banana = Banana;
        Fig->Date = NULL;
        Fig->Cherry = NULL;
    }
    return Fig;
}

void Grape(Apple** Kiwi, int Banana) {
    if (*Kiwi == NULL) {
        *Kiwi = Elderberry(Banana);
        return;
    }
    if (Banana < (*Kiwi)->Banana) {
        Grape(&(*Kiwi)->Cherry, Banana);
    } else {
        Grape(&(*Kiwi)->Date, Banana);
    }
}

int Lemon(Apple* Mango, Apple* Nectarine) {
    if (Mango == NULL && Nectarine == NULL) {
        return 1;
    }
    if (Mango != NULL && Nectarine != NULL) {
        return Lemon(Mango->Cherry, Nectarine->Cherry) && Lemon(Mango->Date, Nectarine->Date);
    }
    return 0;
}

void Orange(Apple* Peach) {
    if (Peach != NULL) {
        Orange(Peach->Cherry);
        Orange(Peach->Date);
        free(Peach);
    }
}

int main() {
    int Quince, Raspberry;
    scanf("%d %d", &Quince, &Raspberry);

    int Strawberry, Tangerine;
    int UgliFruit = 0;

    Apple* Vanilla[Quince];

    for (Strawberry = 0; Strawberry < Quince; Strawberry++) {
        Vanilla[Strawberry] = NULL;

        for (Tangerine = 0; Tangerine < Raspberry; Tangerine++) {
            int Watermelon;
            scanf("%d", &Watermelon);
            Grape(&Vanilla[Strawberry], Watermelon);
        }

        int Ximenia = 1;
        for (int Yuzu = 0; Yuzu < Strawberry; Yuzu++) {
            if (Lemon(Vanilla[Yuzu], Vanilla[Strawberry])) {
                Ximenia = 0;
                break;
            }
        }

        if (Ximenia) {
            UgliFruit++;
        }
    }

    printf("%d\n", UgliFruit);

    for (Strawberry = 0; Strawberry < Quince; Strawberry++) {
        Orange(Vanilla[Strawberry]);
    }

    return 0;
}
