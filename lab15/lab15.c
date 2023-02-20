#include <stdio.h>

#include <string.h>

 


struct tov {
      char name[10];
      float c; 
      char shop[12];
} t1;


void input(FILE *);
void print(FILE *);
void app(FILE *);
void find(FILE *);




void input(FILE *tf)
{ char ch;
  int i;
printf("\n enter\n");
  do
  { printf("\n product: "); 
    scanf("%s", t1.name);
    printf(" price: "); 
    scanf("%f", &t1.c);
    printf(" shop: "); 
    scanf("%s", t1.shop);
    fwrite(&t1, sizeof(t1), 1, tf);

    printf("\n end enter?  1/0  ");
    scanf("%d",&i);
  } while (i!= 1);
  fclose(tf);
}


void print(FILE *tf)
{ int i;

  i=1;
  fread(&t1, sizeof(t1), 1, tf);
  while (!feof(tf))
  { printf("\n%d product:%s price:%6.2f  shop: %s", i, t1.name, t1.c, t1.shop);
    fread(&t1, sizeof(t1), 1, tf);
    i++;
  } fclose(tf);
  
}


void app(FILE *tf){
  char ch;
  int p;
  printf("\n  enter \n");
  do
  {  printf("\n product: "); scanf("%s", t1.name);
    printf(" price: "); scanf("%f", &t1.c);
    printf(" shop: "); scanf("%s", t1.shop);
    fwrite(&t1, sizeof(t1), 1, tf);
    printf(" end enter?  1/0 ");
    scanf("%d",&p);
  } while (p!= 1);
  fclose(tf);  
}


void find(FILE *tf)
{ char *c,tov[10];
  long int i;
  int j;
  int p;
  puts(" enter product: ");
  scanf("%s",tov);


  do{
      fread(&t1, sizeof(t1), 1, tf);

    if (strcmp(t1.name, tov)==0){
      printf(" product  %2s price %6.2f  shop  %s\n\n", t1.name, t1.c, t1.shop);
      
       } 

  }while(!feof(tf));
  fclose(tf);
}



int main(){
  int c;   FILE *tf;
  while (1)
  {
    printf("\n");
    puts("  1 create");
    puts("  2 watch list");
    puts("  3 add");
    puts("  4 search");
    puts("  0 exit");
    scanf("%d",&c);


switch(c)
    { case 1: 
        tf=fopen("PriceList.dat","wb");
        input(tf);  
        break;
      case 2:   
        tf=fopen("PriceList.dat","rb"); 
          print(tf); 
          break;
      case 3:
        tf=fopen("PriceList.dat","ab");
        app(tf);
        break;
      case 4: 
        tf=fopen("PriceList.dat","rb+");
        find(tf);
        break;
      case 0:
        return 0;
      default : 
        puts(" error");
     }
  }
  }
