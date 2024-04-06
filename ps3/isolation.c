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
