#include "func.c"
#include "head.h"





int main(int argc, char *argv[]){
    int p;
    if(argc<2){
        printf("Error! Введите пожалуйста аргумент!\n");
        return 1;
    }
    else if(sscanf(argv[1],"%d",&p)!=1){
        printf("Введите аргумент-число!\n");
        return 1;
    }
    int x,result,i,j=0;
    char l;
   
   
    int n= atoi(argv[1]);

    int *mass;

    mass=malloc(sizeof(int)*10);

    printf("Числа с замечательным свойством в диапозоне от %d до %d\n",i,n);
    for(i=0;i<n;i++){
        
        mass[j]=remarkable(i,n);
        if(mass[j]!=-1){
            printf("%d\n",mass[j]);
            j++;
        }
    }
    int y=0;
    char ans[100];

    while(1){
    printf("Вызвать функцию нахождения суммы цифр числа? y/n ");

    scanf("%s",&l);
    
    if (l=='y'){
        
        printf("Введите число: \n");

        scanf("%s",ans);

        while(sscanf(ans,"%d",&x)!=1){
            
            printf("Вы ввели не число. Повторите попытку.\n");
            
            scanf("%s",ans);
        }

        result=sum_numbers(x);
        printf("Сумма цифр: %d\n",result);
        for(j=0;j<10;j++){
            if (pow(result,3)==mass[j]){
                printf("Кстати, это число замечательное!\n");
            }
        }    
    }
    else if (l=='n'){
        printf("Спасибо за использование программы)\n");
        break;
    }
    
    
    else {
        printf("\nВы ввели некорректные данные! Повторите попытку.\n\n");
        continue;
    }
    }
free(mass);
return 0;
}