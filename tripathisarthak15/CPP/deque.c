#include<stdio.h>
#include<stdlib.h>
#define size 10

int q[size],front=-1,rear=-1;

void rear_insert()
{
    int el; 
    if(front == 0 && rear == size-1)
    {
        printf("Overflow!\n");
        return;
    }

    else if(front ==-1)
    {
        front = 0; rear = 0;
    }
    
    else if(rear == size -1)
    rear = 0;

    else
    rear++;

    printf("\nEnter a Element: "); scanf("%d", &el);

    q[rear]=el;
}

void front_insert()
{
    int el;
    if(front == 0 && rear == size-1)
    {
        printf("Overflow!\n");
        return;
    }

    else if(front == -1)
    {
        front = 0; rear = 0;
    }

    else if(front == 0)
    front = size - 1;

    else 
    front--;


    printf("\nEnter a Element: "); scanf("%d", &el);

    q[front]=el;
}

void front_delete()
{
    if(front == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Element Deleted is %d", q[front]);

    if(front == rear)
    {   front = -1;
        rear=-1;
    }
    else
        if(front == size-1)
            front = 0;
        else
            front = front+1;
}

void rear_delete()
{
    if(front == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Element Deleted is %d", q[rear]);

    if(front == rear)
    {
        front = -1;
        rear=-1;
    }

    else
        if(rear == 0)
            rear=size-1;
        else
        
            rear=rear-1; 
}

void display()
{   
    int front_pos = front,rear_pos = rear;
     
    if(front == -1)
    {   printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if( front_pos <= rear_pos )
    {   
        while(front_pos <= rear_pos)
        {
            printf("%d ",q[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while(front_pos <= size-1)
        {   printf("%d ",q[front_pos]);
            front_pos++;    
        }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {   
            printf("%d ",q[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

void ip_restricted()
{
    while(1)
    {   int ch;
        printf("\n--Input Restricted Selected--\n\n1. Input at rear\n2. Delete from Front\n3. Delete from Rear\n4. Display Current Elements\n5. Exit from Program\n\nEnter your choice:  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: rear_insert(); break;
            case 2: front_delete(); break;
            case 3: rear_delete(); break;
            case 4: display(); break;
            case 5: exit(0); break;
            default: printf("\n--Invalid Input--"); break;
        }
    }
}

void op_restricted()
{
    while(1)
    {   int ch;
        printf("\n--Output Restricted Selected--\n\n1. Input at rear\n2. Input at Front\n3. Delete from front\n4. Display Current Elements\n5. Exit from Program\n\nEnter your choice:  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: rear_insert(); break;
            case 2: front_insert(); break;
            case 3: front_delete(); break;
            case 4: display(); break;
            case 5: exit(0); break;
            default: printf("\n--Invalid Input--"); break;
        }
    }
}

int main()
{   int choice;
    printf("--Types of Double Ended Queue--\n1. Input Restricted\n2. Output Restricted\n\nEnter Choice: "); scanf("%d",&choice);

    switch(choice)
    {
        case 1: ip_restricted(); break;
        case 2: op_restricted(); break;
        default: printf("\n--Wrong Input--Try Again--\n"); 
                    main();
                    break;
    }

    

    
}