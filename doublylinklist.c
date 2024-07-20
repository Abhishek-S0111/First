#include<stdio.h>
#include<stdlib.h>

struct dllist{
    int data;
    struct dllist *next;
    struct dllist *prev;
};

void insert(struct dllist **);
void delete(struct dllist **);
void display(struct dllist *);


int main()
{
    int ch;
    struct dllist *root;
    root = NULL;

    while(1)
    {
        printf("Enter your choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert(&root);
            break;

            case 2: delete(&root);
            break;

            case 3: display(root);
            break;

            case 4: exit(0);

        }
    }
    return 0;
}

void insert(struct dllist **head)
{
    int val;
    struct dllist *temp = *head,*k;
    printf("Enter the element to insert:");
    scanf("%d",&val);
    if (*head == NULL)
    {
        *head = (struct dllist *)malloc(sizeof(struct dllist));
        (*head) ->prev = NULL;
        (*head) ->data = val;
        (*head) ->next = NULL;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        k = (struct dllist*)malloc(sizeof(struct dllist));
        k -> data = val;
        k -> prev = temp;
        k -> next = NULL;
        temp ->next = k;
        
    }
}

void delete(struct dllist **head)
{
    int d;
    struct dllist *temp = *head;
    printf("Enter the element that you want to delete:\n");
    scanf("%d",&d);
    while(temp != NULL)
    {
        if(temp -> data == d)
        {
            if(temp == *head)
            {
                *head = (*head) -> next;
                (*head) -> prev = NULL;
            }
            else
            {
                if(temp -> next ==NULL)
                {
                    temp -> prev -> next == NULL;
                }            
                else
                {
                    temp -> prev -> next = temp -> next;
                    temp -> next -> prev = temp -> prev;
                    temp ->next = temp ->prev = NULL; 
                }
                free(temp);
            }
            return;
        }
        temp = temp->next;
    }
}

void display(struct dllist *head)
{
    struct dllist *temp;
    temp = head;
    while(temp->next != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("%d",temp->data);
}
