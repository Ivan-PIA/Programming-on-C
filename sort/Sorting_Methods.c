#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"


#define ANSI_COLOR_RESET "\x1b[0m"

#define ANSI_COLOR_CYAN "\x1b[36m"

void header_print() { //Вывод заголовка программы
    printf(ANSI_COLOR_CYAN "\n████████████████████████████████████████████████████████████████████████████████");
    printf("\n██████───█────█────█───█───█─██─█────████─███─█───█───█─██─█────█────██───██████");
    printf("\n██████─███─██─█─██─██─███─██──█─█─███████──█──█─████─██─██─█─██─█─██──█─████████");
    printf("\n██████───█─██─█────██─███─██─█──█─█──████─█─█─█───██─██────█─██─█─██──█───██████");
    printf("\n████████─█─██─█─█─███─███─██─██─█─██─████─███─█─████─██─██─█─██─█─██──███─██████");
    printf("\n██████───█────█─█─███─██───█─██─█────████─███─█───██─██─██─█────█────██───██████");
    printf("\n██████───█────█─█─███─██───█─██─█────████─███─█───██─██─██─█────█────██───██████");
    printf("\n████████████████████████████████████████████████████████████████████████████████\n" ANSI_COLOR_RESET);
    printf("\n████████████████████████████████████████████████████████████████████████████████\n");
}   

int manuall_filling(int n, int first_mas[n]) { //Заполнение массива вручную
    for (int i = 0; i<n; i++) {
        printf("\nВведите %d  элемент массива: ", i+1);
        if((scanf("%d", &first_mas[i]))!=1){
            printf("\n\n\nОшибка! Вы ввели не цифру!\n\n\n");
            exit(0);
        }
    }
}

int random_filling(int n, int first_mas[n]) { //Заполнение массива случайнми числами
    for (int i = 0; i<n; i++) {
        first_mas[i] = rand() % 100-50;
    }
    printf("\n...Массив заполен случайными числами\n");
}

int fromfile_filling(int n, int first_mas[]) { //Заполнение массива значениями из файла

    int i,num;
    FILE *f;
    if((f=fopen("text","r"))!=NULL) {

        for ( i = 0; i <n; i++) {
            fscanf(f,"%d\n",&first_mas[i]); 
         
        }
    
        fclose(f);
    } 
    else
    	printf("В файле нет элементов!");


}

int mas_print(int n, int first_mas[n]) { //Вывод массива
    printf("\nВаш массив: ");
    for (int i = 0; i<n; i++) {
        printf("\n %d", first_mas[i]);
    }
}

int main() {

    srand(time(NULL));

    header_print(); 

    int n, y,i; //Размер массива
    int selector1=0, selector2, selector3; 
    //int first_mas[n]; //Обрабатываемый массив
     
    printf("\nВведите размер массива: ");
    y=scanf("%d", &n);
    int a=0;
    
    if(y!=1 || n<0){
        printf("Ошибка! Вы ввели не число\n");
        exit(0);
    }
    else
        {
          
        
    int first_mas[n];
    printf("\n████████████████████████████████████████████████████████████████████████████████\n");
    printf("\nВыберите способ заполения массива: \n 1 - Вручную, 2 - Случайными числами, 3 - из файла: ");
    
    
        //printf("\nВыберите способ заполения массива: \n 1 - Вручную, 2 - Случайными числами, 3 - из файла: ");
        if ((scanf ("%d", &selector1))!=1 || n<0){    
            //Выбор способа заполнения массива
            printf("Ошибка! Вы ввели не цифру.\n\n\n");
            exit(0);
        } 
        else {

        
        
    
    
    
    if (selector1 == 1) {

        manuall_filling(n, first_mas);

    }

    else if (selector1 == 2) {
        random_filling(n, first_mas);
    }

    else if (selector1 == 3) {
        fromfile_filling(n, first_mas);
    }
    else {
        printf("Ошибка! Введите нужную цифру.\n\n\n");
        exit(0);
    }
   
    
    printf("\n████████████████████████████████████████████████████████████████████████████████\n");
        printf("\nВывести сформированный массив (1 - да, 2 - нет): \n");
        if ((scanf ("%d", &selector2))!=1 || n<0){
        
            printf("Ошибка! Вы ввели не цифру.\n\n\n");
            exit(0);
        
        }    
    if (selector2!=1 && selector2!=2 ) {
        printf("Ошибка! Введите нужную цифру.\n\n\n");
        exit(0);
    }    
    if (selector2 == 1) { //Вывод сформированного массива по желанию пользователя
        mas_print(n, first_mas);
    }
    

    printf("\n\n████████████████████████████████████████████████████████████████████████████████\n");

   
        printf("Каким способом вы хотите отсортировать массив? \n1 - Метод Шелла; \n2 - Метод Хоара; \n3 - Сортировка Пузырьком; \n4 - Сортировка Шейкером; \n5 - Сортировка простым включением:\n");

        if((scanf("%d", &selector3))!=1 || n<0){
            printf("Ошибка! Вы ввели не цифру.\n\n\n");
            exit(0);
        }
        if (selector3!=1 && selector3!=2 && selector3!=3 && selector3!=4 && selector3!=5 ){
            printf("Ошибка! Введите нужную цифру.\n\n\n");
            exit(0);
    
        }
      
        printf("Перестановки и сравнения случайных чисел: ");
    if (selector3 == 1) {
        
        ShellSort(n, first_mas);
    }

    if (selector3 == 2) {

        QuickSort(first_mas, 0, n);
        printf("sum = %d\n", p_qs + c_qs);
    }

    if (selector3 == 3) {
        bubbleSort(first_mas, n);
    }

    if (selector3 == 4) {
        shakerSort(first_mas, n);
    }

    if (selector3 == 5) {
        InsertionSort(n, first_mas);
    }
    
    printf("\nОтсортированный массив: \n");
    mas_print(n, first_mas);
    
    printf("\nПерестановки и сравнения у массива по возрастанию: ");
     if (selector3 == 1) {
        
        ShellSort(n, first_mas);
    }

    if (selector3 == 2) {

        QuickSort(first_mas, 0, n);
        printf("sum = %d\n", p_qs + c_qs);
    }

    if (selector3 == 3) {
        bubbleSort(first_mas, n);
    }

    if (selector3 == 4) {
        shakerSort(first_mas, n);
    }

    if (selector3 == 5) {
        InsertionSort(n, first_mas);
    }
    printf("\nПерестановки и сравнения у массива по убыванию: ");
    
    ubuv(n, first_mas);
   // mas_print(n, first_mas);

    
     if (selector3 == 1) {
        
        ShellSort(n, first_mas);
    }

    if (selector3 == 2) {


        QuickSort(first_mas, 0, n);
        printf("sum = %d\n", p_qs + c_qs);
    }

    if (selector3 == 3) {
        bubbleSort(first_mas, n);
    }

    if (selector3 == 4) {
        shakerSort(first_mas, n);
    }

    if (selector3 == 5) {
        InsertionSort(n, first_mas);
    }

    //mas_print(n, first_mas);
    printf("\n\nГотово!\n");
    //printf("sum = %d\n", p_qs + c_qs);
    printf(ANSI_COLOR_CYAN"\n████████████████████████████████████████████████████████████████████████████████\n");
   
    printf("████████████████████Спасибо за использование нашей программы!███████████████████");
    printf("\n████████████████████████████████████████████████████████████████████████████████\n"ANSI_COLOR_RESET);
}//закрытие иначе при 1сканфе
}//закрытие иначе при 2сканфе
    
}
