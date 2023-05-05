/*
Kuyruk(queue) veri yapýsýnda verilen dizinin içerisinde bitiþik
olarak birbirinin tekrar eden tüm karakterleri kaldýran C kodunu
yazýnýz. Algoritma, sonuçta birbirini tekrar eden hiçbir kopya
kalmayana kadar kuyruktan bitiþik kopyalarý kaldýrmaya devam
etmelidir.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    char data;
    struct queue* next;
} queue;

int size = 0;
queue* root = NULL;
queue* root2 = NULL;
queue* root3 = NULL;
queue* temp;

void enqueue(char x, queue** root) {
    if (size == 0) {
        *root = (queue*)malloc(sizeof(queue));
        (*root)->data = x;
        (*root)->next = NULL;
        size++;
    }
    else {
        temp = (queue*)malloc(sizeof(queue));
        temp->data = x;
        temp->next = *root;
        size++;
        *root = temp;
    }
}

void yazdir(queue* root) {
    temp = root;
    printf("\n");
    while (temp != NULL) {
        printf("%c --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void tekrarisil() {
    queue* temp;
    queue* temp2;
    int kontrol = 1;
    int h = 0;

    for (int i = 0; i < kontrol; i++) {
        kontrol = 0;

        int size1 = size;
        while (size1 >= 2) {
            temp = root;
            for (int i = 0; i < size1 - 2; i++) {
                temp = temp->next;
            }

            if (temp->data == temp->next->data) {
                temp->next->data = '\0';
                temp->data = '\0';
                size1 -= 1;
                kontrol++;
            }
            else {
                size1--;
            }
        }

        size1 = size;
        while (size1 > 1) {
            temp = root;
            temp2 = root2;
            h = 0;
            for (int i = 0; i < size1 - 2; i++) {
                temp = temp->next;
            }

            if (temp->next->data != '\0') {
                if (h == 0) {
                    enqueue(temp->next->data, &root2);
                    h++;
                    kontrol++;
                }
            }

            if (temp->data != '\0') {
                enqueue(temp->data, &root2);
            }

            size1 -= 2;
        }
        yazdir(root2);
        root = root2;
        size = 0;
        temp = root2;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        root2 = root3;
    }
}

int main() {
    char input[] = "ABDAADBDAABB";

    int i = 0;
    while (input[i] != '\0') {
        enqueue(input[i], &root);
        i++;
    }
    yazdir(root);
    tekrarisil();

    return 0;
}