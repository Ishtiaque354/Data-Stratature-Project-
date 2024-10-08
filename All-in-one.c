#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createList(int N);
void displayList();
void insertFirst();
void insertNode();
void insertLast();
void deleteFirst();
void deleteNode();
void deleteLast();
int serachNode();
int totalNode();

int main()
{
    int n,X,Z,key,Index,total;
    printf("Enter the total node number: ");
    scanf("%d",&n);
    createList(n);
    printf("\n\tThe all data in the link list: \n");
    displayList();

    operation:
                printf("\nThe operation of the link list.\n");
                printf("1. Insert First\n2. Insert specific\n3. Insert last\n4. Delete First\n5. Delete specific\n6. Delete last\n7. Search Data\n8. Total number of Node.\n");
                printf("Select 1-8 \n\nEnter your choice: ");
                scanf("%d",&X);
                switch(X)
                {
                    case 1: printf("\nInsert Data in First.\n");
                            insertFirst();
                            displayList();
                            break;

                    case 2: printf("\nInsert data in specific position.\n");
                            insertNode();
                            displayList();
                            break;
                    case 3: printf("\nInsert Data in last.\n");
                            insertLast();
                            displayList();
                            break;

                    case 4: printf("\nDelete First Data from the list.\n");
                            deleteFirst();
                            displayList();
                            break;

                    case 5: printf("Delete specific Node Data.\n");
                            deleteNode();
                            displayList();
                            break;
                    case 6: printf("\nDelete data from last.\n");
                            deleteLast();
                            displayList();
                            break;
                    case 7: printf("\nSearch Element in the link-list.\n");
                            printf("Enter the data to Search: ");
                            scanf("%d",&key);
                            Index=searchNode(key);
                            if(Index>=0){
                                printf("%d found in %d index or position.",key,Index);
                            }

                            break;

                    case 8: total=totalNode();
                            printf("Total number of Node in the link-list: %d",total);
                            break;
                }
                printf("\nDo you want to continue with link list operation.\n1. Yes\n2. No\nEnter Your choice: ");
                             scanf("%d",&Z);
                             if(Z==1){
                                    printf("\nDo operation in th same list\n1. Sure\n2. Create new list\nEnter Your choice: ");
                                        scanf("%d",&Z);
                                        if(Z==1)
                                        {
                                            goto operation;
                                        }
                                        else
                                            goto New_list;
                             }
                             else
                                exit(0);
    New_list:
                printf("\nEnter total number of Node in new list: ");
                scanf("%d",&n);
                createList(n);
                displayList();
                goto operation;

    return 0;
}

typedef struct node Node;
void createList(int N){
    int data;
    Node *newnode,*temp;

    head=(Node*)malloc(sizeof(Node));
    if(head==NULL){
        printf("The list is empty.");
        exit(0);
    }
    else{
        printf("\nEnter the data of node-1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;

        temp=head;
        for(int i=2;i<=N;i++){
            newnode=(Node*)malloc(sizeof(Node));
            if(newnode==NULL){
                printf("Enable to allocate memory.");
                break;
            }
            else{
                printf("\nEnter the data of node-%d: ",i);
                scanf("%d",&data);
                newnode->data=data;
                newnode->next=NULL;

                temp->next=newnode;
                temp=temp->next;
            }
        }
    }
}

void displayList(){
    Node *temp;
    if(head==NULL){
        printf("The list is Empty.");
        exit(0);
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("\t\t\tData: %d\n",temp->data);
            temp=temp->next;
        }
    }
}

int searchNode(int key){
    int index=1;
    Node *curnode;
    if(head==NULL){
        printf("The list is Enpty.");
        exit(0);
    }
    curnode=head;
    while(curnode!=NULL&&curnode->data!=key){
        index++;
        curnode=curnode->next;
    }
    if(curnode->data==key){
        return index;
    }
    else if(curnode->data!=key){
        printf("Not found or data is not present in the list.");
        exit(0);
        }
}

int totalNode(){
    int tNode=0;
    Node *temp;
    if(head==NULL){
        printf("The list is empty.");
        exit(0);
    }
    else{
        temp=head;
        while(temp!=NULL){
            tNode++;
            temp=temp->next;
        }
    }
    return tNode;
}
void insertFirst(){
    int data;
    Node *newnode,*temp;
    if(head==NULL){
        printf("The list is empty.");
        exit(0);
    }
    else{
        newnode=(Node*)malloc(sizeof(Node));
        if(newnode==NULL){
            printf("Empty.");
            exit(0);
        }
        printf("\nEnter Newnode Data: ");
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;

        newnode->next=head;
        head=newnode;

        printf("\nData inserrted sucessfully.\n");

    }

}

void insertLast(){
    int data;
    Node *newnode,*temp;
    if(head==NULL){
        printf("Empty.");
        exit(0);
    }
    else{
        newnode=(Node*)malloc(sizeof(Node));
        printf("\nEnter the data to insert last: ");
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;

        temp=head;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=newnode;
        temp=newnode;

        printf("\nData inserted successfully in the last.\n");
    }
}

void insertNode(){
    int data,posi,i=1;
    Node *newnode,*temp;
    if(head==NULL){
        printf("Empty.");
        exit(0);
    }
    else{
        newnode=(Node*)malloc(sizeof(Node));
        printf("\nEnter position to insert data: ");
        scanf("%d",&posi);
        printf("\nEnter data for the newnode: ");
        scanf("%d",&data);

        newnode->data=data;
        newnode->next=NULL;

        temp=head;
        while(i!=posi-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;

        printf("\nData insert successfully in %d position.\n\n",++i);
    }
}

void deleteFirst(){
    Node *temp;
    if(head==NULL){
        printf("The list is Empty.");
        exit(0);
    }
    else{
        temp=head;
        head=temp->next;

        free(temp);
        printf("\nData delete successfully.\n");
    }

}

void deleteNode(){
    int posi,i=1;
    Node *temp,*prev;
    if(head==NULL){
        printf("The list is Empty.");
        exit(0);
    }
    printf("\nEnter the data delete position: ");
    scanf("%d",&posi);
    temp=head;
    while(i<=posi-1){
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    free(temp);

    printf("Data delete from %d position.\n",++i);

}
void deleteLast(){
    Node *prev,*temp;
    if(head==NULL){
        printf("The list is Empty.");
        exit(0);
    }
    else{
        temp=head;
        while(temp!=NULL && temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        free(temp);
        prev->next=NULL;
        printf("Data delete from last.\n");
    }

}
