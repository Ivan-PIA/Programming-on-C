#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

void ShellSort(int n, int mass[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}
int randomarr(int N,int mass[]){
	int i; 
	printf("Random arrey: ");
	srand(time(NULL));
	 		for(i=0;i<N;i++){
				mass[i]=rand()%20;
				printf("%d ",mass[i]);}
	printf("\n");
}

int enterarr(int N, int mass[]){
	int i;
	printf("Input the array elements:\n");
	    for (int i = 0; i < N; i++)
		scanf("%d", &mass[i]);

}

int infile(int N, int mass[]){
    int i,num;
    FILE *f;
    if((f=fopen("text","r"))!=NULL) {


        for ( i = 0; i <N; i++) {
            fscanf(f,"%d\n",&mass[i]); 
         
        }

    
        fclose(f);
    } 
    else
    	printf("В файле нет элементов!");


}

int main(){
    int i,N,choise;
        printf("Введите размер массива: ");
        scanf("%d", &N);

    int mass[N];

    printf("Введите цифру если хотите вывод массива\n1-рандомный массив\n2-ввод в терминале\n3-из файла\n");
    scanf("%d",&choise);

        if (choise==1)
            randomarr(N,mass);

        if (choise==2)
            enterarr(N,mass);

        if (choise==3)
            infile(N,mass);

        ShellSort(N, mass);

        printf("Sorted array: ");
        for ( i = 0; i < N; i++)
            printf("%d ", mass[i]);
        printf("\n");

}