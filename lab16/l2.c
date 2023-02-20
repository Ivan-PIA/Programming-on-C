#include <stdio.h>
#include <stdlib.h>


typedef struct list
{ int info;
struct list *next;
}list;

typedef struct st{
    list *up;
    list *down;
    struct st *right; 
}st;

  list *t1, *p1, *t2, *p2;  
   st *s,*t,*p;

  int  main()
{
    int a,n;
    int y,c;
    printf("->");
    scanf("%d",&a);
    n=1;
    if (a==0)
            printf("list pust");
    else{
            while(a!=0){
                t=(st*)malloc(sizeof(st));
                  
                t->right=NULL; 
                t->down=NULL;

                t1=(list*)malloc(sizeof(list));
                t1->next=NULL;
                t1->info=a;
                
                if(s==0)
                    s=t;
                else{
                    p->right=t;
                    p1->next=t1;
                }
    scanf("%d",&a);
    n++;
    if(a!=0){
        t2=(list*)malloc(sizeof(list));
        t2->next=0;
        t2->info=a;
        t->down=t2;
        if(n!=2)
            p2->next=t2;
            p=t;    
            p2=t2;    
            p1=t1;
   scanf("%d",&a);
   n++;
    }
            }

   t2->next=s->down;
   
   y=1;
   while(y==1){

    printf("\nvvod upravleniya\n");
    n=0;
    p=s;
    p1=0;
    p2=0;
    scanf("%d",&c);
    while(c!=1){

    if (c==2){ 
        if(n==0){
            if (p->down!=0){
                printf("vniz\n");
                p2=p->down;
            }
            else 
                printf("Pusto down\n");
    n=2;
        }
        else
            printf("No down\n");
    }
    

    if(c==6){
        if (n==0){
            if(p!=0){
                printf("->");
                p=p->right;
	        }
	    else 
            printf("end");
	}
    if(n==1){
        if(p1!=0){
            printf("|| %d ||",p1->info);
            p1=p1->next;
	    }
	    else 
            printf("end up");
	}
    if(n==2){
        if(p2!=0){
            printf("| %d |",p2->info);
            p2=p2->next;}
	    else 
            printf("end down");
	}
    }
    scanf("%d",&c);
    }

   printf("\nbegin ?(1/0)");
   scanf("%d",&y);
    }
    }
	return 0;
}