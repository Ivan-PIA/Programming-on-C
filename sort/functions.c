#include "head.h"

int ShellSort(int n, int first_mas[])
{
    int i, j, step,p=0,c=0, sum=0;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {    
            tmp = first_mas[i];
            p+=1;
            for (j = i; j >= step; j -= step)
            {
                if (tmp < first_mas[j - step]){
                      c+=1;
                    first_mas[j] = first_mas[j - step];
                      p+=1;                
                }
                else
                    break;
            }
            first_mas[j] = tmp;
              p+=1;
        }
printf("p:%d ",p);
printf("c:%d ",c);
sum=c+p;
printf("sum:%d",sum);
}

//--

int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void QuickSort(int *A, int start, int end){
int sum=0;
c_qs+=1; 
    if(start>=end){
     
    return;}
    int key=start,i=start,j=end,temp;
    c_qs+=1;
    while(i<=j){
        
        while (i<=end && A[i]<=A[key]){
          
          i++;}c_qs+=1;
        while (j>start && A[j]>=A[key]){
          
          j--;}c_qs+=1;
          c_qs+=1;
        if(i>j){
          
          swap(&A[key],&A[j]);
          p_qs+=2;
          }
        else{  
          swap(&A[i],&A[j]);
          p_qs+=2;}
    }
    QuickSort(A,start,j-1);
    QuickSort(A,j+1,end);
  
}

//--

void bubbleSort(int *MAS, int n)
{
  int k,c=0,p=0,sum=0;;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = (n - 1); j > i; j--) 
    {
      if (MAS[j - 1] > MAS[j])
      {
        c+=1;
        k = MAS[j - 1];
        p+=1; 
        MAS[j - 1] = MAS[j];
        p+=1;
        MAS[j] = k;
        p+=1;
      }
      else
          c+=1;
    }
  }
printf("p:%d ",p);
printf("c:%d ",c);
sum=c+p;
printf("sum:%d",sum);  
}

//--

void shakerSort(int *mass, int n)
{

  int left = 0, right = n - 1; 
  int flag = 1,c=0,p=0,sum=0;  
  while ((left < right) && flag > 0)
  {
    c+=1;
    flag = 0;
    for (int i = left; i<right; i++) 
    { 
      if (mass[i]>mass[i + 1]) 
      { 
              
        int t = mass[i];
        p+=1;
        mass[i] = mass[i + 1];
        p+=1;
        mass[i + 1] = t;
        p+=1;
        flag = 1;     
      }c+=1;
    }
    right--; 
    for (int i = right; i>left; i--)  
    {
      if (mass[i - 1]>mass[i]) 
      { 
        c+=1;           
        double t = mass[i];
        p+=1;
        mass[i] = mass[i - 1];
        p+=1;
        mass[i - 1] = t;
        p+=1;
        flag = 1;    
      }
    }
    left++;
  }
printf("p:%d ",p);
printf("c:%d ",c);
sum=c+p;
printf("sum:%d",sum);   
}

void InsertionSort(int n, int mass[])
{
    int newElement, location, c=0, p=0,sum=0;

    for (int i = 1; i < n; i++)
    {
        newElement = mass[i];
        p+=1;
        location = i - 1;
        while (location >= 0 && mass[location] > newElement)
        {   
            c+=1;
            mass[location + 1] = mass[location];
            p+=1;
            location = location - 1;
            p+=1;
        }
        mass[location + 1] = newElement;
        p+=1;
    }
printf("p:%d ",p);
printf("c:%d ",c);
sum=c+p;
printf("sum:%d",sum);    
}



int ubuv(int n,int first_mas[]){
  int i,j,k;
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
        if(first_mas[i]<first_mas[j]){
          k=first_mas[i];
          first_mas[i]=first_mas[j];        
          first_mas[j]=k;
        }

}