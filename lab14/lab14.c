#include <stdio.h>
#include <stdlib.h>


int file(char mass[20]){
    int i=0, c=0;
    FILE *f;
    if((f=fopen("text.txt","r"))!=NULL) {
        

        while(!feof(f)) {
       
            fscanf(f,"%s",mass);
            c++;
        }
        fclose(f);
    
    } 
    else
    	printf("В файле нет элементов!");
    c=c-1;

return c;
}

int main(){

    char mass[20];
    int c=file(mass);
    printf("in file %d words\n",c);

}
