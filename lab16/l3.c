
#include <stdio.h>


typedef struct elem {
    struct elem* left;
    int num;
    struct elem* right;
} elem;

void pathInfo(elem e,int y) {
    if (e.right != NULL && y == 1)
        printf("6\n");

    if (e.left != NULL && y == 0)
        printf("4\n");

    if (e.right != NULL && y == 0)
        printf("2\n");

    printf("\n\n");
}



int main() {
    
    elem mas1[100],mas2[100];
    int c=0;
    int n=0,k=0;
    int t = 0;
    int temp;
    
    while (1) {
        scanf("%d", &temp);
        if (temp == 0) {
            break;
        }
        mas2[n++].num = temp;
    }
    while (1) {
        scanf("%d", &temp);
        if (temp == 0) {
            break;
        }
        mas1[k++].num = temp;
    }
    n--;
    k--;
    if (n > k) {
        while (n>k)
           mas2[++k].num = 0;
    }
    temp = k;
    if (n >= k) {
        for (int i = k; i >= 0; i--) {
            if (i == 0) {
                mas2[i].right = &mas1[i];
                mas2[i].left = NULL;
            }
            else {
                mas2[i].right = &mas1[i];
                mas2[i].left = &mas2[i - 1];
            }
        }
    }
    if (n < k) {
        while (n < temp) {
            mas2[temp].left = &mas2[temp - 1];
            mas2[temp--].right = NULL;
        }
        for (int i = temp; i >= 0; i--) {
            if (i == 0) {
                mas2[i].right = &mas1[i];
                mas2[i].left = NULL;
            }
            else {
                mas2[i].right = &mas1[i];
                mas2[i].left = &mas2[i - 1];
            }
        }
    }
    printf("%d", n);
    for (int i = 0; i <= n; i++){
        if (i == n) {
            mas1[i].right = NULL;
            mas1[i].left = NULL;
        }
        else {
            mas1[i].right = &mas1[i+1];
            mas1[i].left = NULL;
        }
    }

    int pos = 1, y=0, o;
    elem a = mas2[k];

    while (pos) {
        o = 0;
        printf("\nВозможные направления: \n");
        pathInfo(a, y);

        printf("Элемент: %d\n", a.num);
        printf("Введите направление: ");
        scanf("%d", &pos);
        if (pos == 2 && y == 0) {
            a = *a.right;
            o = 1;
            y = 1;
        }

        if (pos == 6 && y == 1) {
            a = *a.right;
            o = 1;
        }

        if (pos == 4 && y == 0) {
            if(&a != NULL){
            a = *a.left;
            o = 1;
            } else { printf("4 end\n");}
        }
        if (o == 0) {
            printf("Ошибка вы ввели не верный путь");
            // break;
        }
        if (a.left == NULL && a.right == NULL) {
            printf("Ваш элемент: %d\n", a.num);
            printf("Идти некуда");
            // break;
        }
    }
}