

#include <stdio.h>
#include <string.h>

int file(char *mass){
    int i=0,c=0,k=0;
    FILE *f;
    if((f=fopen("text.txt","r"))!=NULL) {


        while(!feof(f)) {
            
            fscanf(f,"%c",&mass[i]);
            i++;
 
            } 
            mass[i-1] = '\0';

            printf("%s\n",mass);
            
            for(i=0;i<strlen(mass);i++){
                
            if(mass[i]!=' ' && mass[i+1]==' '){
                
                c=c+1;
            }
         
            }
            c+=1;
        
        fclose(f);
    } 
    else
    	printf("В файле нет элементов!");




return c;
}

int main(){

    char mass[100];
    int c=file(mass);
    printf("\nin file word: %d\n\n",c);

}
