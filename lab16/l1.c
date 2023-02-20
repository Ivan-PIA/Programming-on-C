#include <stdio.h>
#include <stdlib.h>


typedef struct list{
    int data;
    struct list *down;
    struct list *left;

}list;


int main(){
    int a,l;
    list *tmp=(list*)malloc(sizeof(list));
    list  *head=tmp;
    list *head1=NULL;

    printf("Enter list1:\n");
        do{
        list *node=(list*)malloc(sizeof(list));
        scanf("%d",&a);
        node->data=a;
        node->left=NULL;
        node->down=NULL;        
        tmp->down=node;
        tmp = tmp->down;

    }while(a!=0);
       
    list *tmp1;
    
       tmp = head->down;
    while (tmp!=NULL){
        printf("%d ",tmp->data);
        tmp=tmp->down;

    
    }
    
    tmp1=head->down;
    
    printf("Enter list2:\n");
    tmp = NULL;
    
   
    do{
        list *node=(list*)malloc(sizeof(list));
        scanf("%d",&a);
        node->data=a;
        node->down=NULL;        
        node->left=tmp;

        tmp = node;

        if (tmp1 != NULL){
            //printf("Связал верх и низ %d, %d",node->data,tmp1->data);
            tmp->down=tmp1;
            tmp1 = tmp1->down;
        }
            else{
            tmp->down = NULL;
            }

    }while(a!=0);
    
    head1=tmp;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp=tmp->left;
    }

    
    head1=head1->left;
    printf("Your element:%d\n", head1->data);


while (1){

     printf("\nВведите управление:");
     scanf("%d",&l);
    

    if(l==4){
        if (head1->left==NULL){
            printf("Вы вышли за список");
            break;}
        head1 =head1->left;
        printf("Element:%d ",head1->data);
        
    }
    if(l==2){
        if (head1->down==NULL){
            printf("Вы вышли за список");
            break;}
        head1=head1->down;
        printf("Element:%d ",head1->data);
    }
    if(l==6){
        if (head1->down==NULL){
            printf("Вы вышли за список");
            break;}
        head1=head1->down;
        printf("Element:%d ",head1->data);
    }
}


}


       

  







