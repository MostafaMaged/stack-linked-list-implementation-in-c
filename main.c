#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int data;
    struct Node *next;
}Node;

Node *top = NULL;

void Push(int);
void Pop();
int Top();
bool IsEmpty();
void Print(Node*);

int main()
{
    int choice = -1;
    int data = 0;

    while(1){
        printf("choose what u want to do : \n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.top\n");
        printf("4.isEmpty\n");
        printf("5.print\n");
        printf("6.exit\n");
        printf("your choice : ");

        scanf("%d", &choice);

        if(choice != 6){

             switch(choice){
                case 1:
                    printf("Enter data: ");
                    scanf("%d", &data);
                    Push(data);
                    break;
                case 2:
                    if(IsEmpty()){
                        printf("stack is empty\n");
                    }else{
                        Pop();
                    }
                    break;
                case 3:
                    if(IsEmpty()){
                        printf("stack is empty\n");
                    }else{
                        printf("top is : %d\n", Top());
                    }

                    break;
                case 4:
                    if(IsEmpty()){
                        printf("stack is empty\n");
                    }else{
                        printf("stack is not empty\n");
                    }
                    break;
                case 5:
                    Print(top);
                    printf("\n");
                    break;
                default:
                    printf("you entered invalid choice .\n");
            }
        }
        else{
            break;
        }
    }


    return 0;
}

void Push(int data){
    Node *newData = malloc(sizeof(Node));
    newData->data = data;
    newData->next = top;
    top = newData;
}

void Pop(){
    if(IsEmpty()){
        printf("stack is empty.\n");
        return;
    }
    Node *temp = top;
    top = top->next;
    free(temp);
}

int Top(){
    if(IsEmpty()){
        printf("stack is empty.\n");
        return;
    }
    return top->data;
}

bool IsEmpty(){
    return top == NULL;
}

void Print(Node *temp){
    if(IsEmpty()){
        printf("stack is empty.");
        return;
    }
    if(temp == NULL) return;
    Print(temp->next);
    printf("%d\t", temp->data);
}

