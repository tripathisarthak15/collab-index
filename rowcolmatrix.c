// Online C compiler to run C program online

#include <stdio.h>
#include <stdlib.h>
#define size 20

int arr[size][size],rnn=0,i,j; 
void iparray() {
    printf("Enter number of rows and columns: "); 
    scanf("%d", &rnn);
    
    for(i=0;i<rnn;i++)
    {
        for(j=0;j<rnn;j++)
        {
            printf("Enter element at %d%d position: ", i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}

void display()
{   
    int ch;
    while(1)
    {
     
    printf("\n\n1. Display Row Matrix\n2. Display Column Matrix\n PRESS 3 to exit\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1: printf("\nROW MATRIX\n");
            for(i=0;i<rnn;i++)
            {
                for(j=0;j<rnn;j++)
                    {
                    printf(" %d ",arr[i][j]);
                    }}
                    break;
        case 2: printf("\nCOLUMN MATRIX\n");
            for(i=0;i<rnn;i++)
            {
                for(j=0;j<rnn;j++)
                    {
                    printf(" %d ",arr[j][i]);
                    }}
                    break;
                    
        default: exit(0); break;
                    
      }
}}
int main() {
    iparray();
    display();
    return 0;
}
