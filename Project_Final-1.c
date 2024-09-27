#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
#include<windows.h>
#include<math.h>
#include<time.h>


struct node{
    float quantity;
    float price;
    char name[20];
    int ID;
    struct node *next;

}*head;

struct customerNode{
    //int phone;
    char name1[100];
    char addr[100];
    char data[15];
    char ProName[20];
    char Qua[10];
    float tPro;
    //float pri;
    struct customerNode *next;
};
struct customerNode *front =NULL;
struct customerNode *rear =NULL;

/*struct CPhone{

    struct CPhone *next;
};*/

struct Total{
    char Name1[50];
    char Quan[10];
    int ID;
    float sell;
    float sellTotal;
    struct Total *next;
}*root;

struct user{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
    struct user *prt;
}*S;

///All function  are here
void Admin();
//Main interface for shop add item delete item etc.

void Customer();
//Mainly provide service and delivered pay slip

void user();
//For making new admin information

void login();
//Admin login to main interface

void createList();
//create list of items in shop

void display();
//display items in shop

void AddItem();
//Add new items in shop

int UniCode();
//provide a unique code for Admin login

void DeleteItem();
//Delete items from shop

//void checkIn();
//provide main pay slip to user


typedef struct node Node;
typedef struct customerNode CNode;
typedef struct Total Tnode;


float SellTotal=0.0;

int UniCode(){
    int U;
    srand(time(NULL));
    U=rand();
    return U;
}

void Admin(){
    int n,uni,z;
    char Email[30],name[30]="ishtiaque354",pass[30]="12345#";
    system("cls");
    z=UniCode();
    printf("\t\t\t\t|####################################################|\t\n");
    printf("\t\t\t\t|                                                    |\t\n");
    printf("\t\t\t\t|          Welcome To Authentication System          |\t\n");
    printf("\t\t\t\t|            Your Unique Code is required            |\t\n");
    printf("\t\t\t\t|   Your Unique Code Provide on mobile or computer   |\t\n");
    printf("\t\t\t\t|                                                    |\t\n");
    printf("\t\t\t\t|                      %d                         |\t\n",z);
    printf("\t\t\t\t|####################################################|\t\n");
    printf("\n\n\t\t\t\t1. Sign up----New Admin\n\n");
    printf("\n\n\t\t\t\t2. Login----Existing Admin\n\n");
    printf("\n\n\t\t\t\t3. Exit\n\n");
    printf("\n\n\t\t\t\tEnter your Choice:");
    scanf("%d",&n);
    switch(n){
        case 1: user();
                //adminPage();
                break;
        case 2: /*printf("|\n\n\t\t\t\tEnter Username: ");
                scanf("%s",&name);
                printf("|\n\n\t\t\t\tEnter your password:");
                scanf("%s",&pass);
                printf("|\n\n\t\t\t\tEnter Your unique Code: ");
                scanf("%d",&uni);
                login(name,pass,uni,z);*/
                adminPage();
                break;

        case 3: exit(0);
                return 0;
    }
}

void login(char Uname[30],char Upass[30],int Uni,int Z)
{
    char UserName[30]="ishtiaque354";
    char Pass[30]="12345#";
    int v1,v2;
    v1=strcmp(Uname,UserName);
    v2=strcmp(Pass,Upass);
    if( v1==0&&v2==0&&Uni==Z){
           adminPage();
    }
    else{
        printf("\n\n\t\t\t\tLogin failed!!!\n");
        exit(0);
            }
}

void user(){
    struct user *info;
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];

    S=(struct user*)malloc(sizeof(struct user));
    if(S==NULL){
        printf("\n\n\t\t\t\tAdmin Invalid.");
    }
    printf("\n\n\t\t\t\tEnter Your Full name: ");
    scanf("%s",&fullName);
    printf("\n\n\t\t\t\tEnter Your E-mail: ");
    scanf("%s",&email);
    printf("\n\n\t\t\t\tEnter Your password: ");
    scanf("%s",&password);
    printf("\n\n\t\t\t\tEnter Your User Name: ");
    scanf("%s",&username);
    printf("\n\n\t\t\t\tEnter Your Phone Number(+88): ");
    scanf("%s",&phone);

    strcpy(S->fullName,fullName);
    strcpy(S->email,email);
    strcpy(S->password,password);
    strcpy(S->username,username);
    strcpy(S->phone,phone);
    S->prt=NULL;

    adminPage();

}

void UserInfo(){

    printf("\n\n\t\t\t\tAdmin name: %s",S->fullName);

    printf("\n\n\t\t\t\tAdmin E-mail: %s",S->email);

    printf("\n\n\t\t\t\tPhone Number(+88): %s",S->phone);

}


void Customer(){
    int N,X;
    char Ch[5];
    printf("\n\n\t\t\t\t1.Buy Items.\n\n\t\t\t\t2.Information About Admin\n\n\t\t\t\t3.Restart Programme.\n\n\t\t\t\t4.Exit");
    printf("\n\n\t\t\t\tEnter your choice: ");
    scanf("%d",&N);
    switch(N){
        case 1: display();
                buy();
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                scanf("%s",&Ch);
                if(strcmp(Ch,"#")==0){
                        Customer();
                }
                break;
        case 2: UserInfo();
                break;
        case 3: mainFunc();
                break;


        printf("\n\n\t\t\t\tPress # to back to main menu: ");
        scanf("%s",&Ch);
        if(strcmp(Ch,"#")==0){
                mainFunc();
        }
    }
}

void buy(){
    float total,pay,back;

    Node* current = head;

    CNode *node=front;
    char Qua[10],Qua2[10];
    char str[10],str1[10];
    char *ptr,*ptr1;
    float value=0.0,value1=0.0;
    float remaining=0.0;
    char name[20],qua[20];
    int X,n=0,i=0;
    system("cls");
    display();
    printf("\n\n\t\t\t\tPlease Enter product ID that you Want to Buy: ");
    scanf("%d",&n);
         // Initialize current
    while (current != NULL)
            {
                system("cls");
                if (current->ID==n){

                    //ProductShow(current->name,current->price);
                    printf("\n\n\t\t\t\tFound These Details:\n");
                    printf("\n\t\t\t\tProduct Name: %s",current->name);
                    printf("\n\t\t\t\tProduct Price(Per KG or per product): %0.2f",current->price);
                    printf("\n\n\t\t\t\tPlease Enter Product Quantity You want to Buy(%0.1f kg remaining): ",current->quantity);
                    scanf("%s",&Qua);
                    CNode *node;
                    char ch[20];
                    int n;
                    printf("\n\n\t\t\t\t1.New Customer.\n\n\t\t\t\t2.Existing Customer.\n\n\t\t\t\tChoice: ");
                    scanf("%d",&n);
                    switch(n){
                        case 1: enqueue(current->name,Qua);
                                break;
                        case 2:printf("\n\n\t\t\t\tEnter your name: ");
                                scanf("%s",&ch);
                                while(node!=NULL){
                                    if(strcmp(node->name1,ch)==0){
                                        goto Process;
                                    //break;
                                    }
                                    else{
                                        node=node->next;
                                        printf("\n\t\t\t\tInvalid.");
                                        //CustomerInfo(name,qua);
                                        break;
                                    }
                                    default: printf("\n\t\t\t\tInvalid.");
                                        mainFunc();
                                    }
                    }
                    strcpy(str, Qua);
                    value = atof(str);
                    //printf("decimal %ld\n", value);
                    //strcpy(str1,current->quantity);
                    value1 = current->quantity;
                    remaining=fabs(value-value1);
                    if(value>current->quantity && current->quantity==0.0){
                                    printf("\n\n\t\t\t\tTotal product is finished.");
                                    break;
                            }
                    else if(value<=current->quantity){
                        goto Process;
                    }
                    //sprintf(Qua2,"%d %s", Qua2, remaining);*/
                    //strcpy(current->quantity,Qua2);
                    Process:
                        system("cls");
                        total=value*current->price;
                        sellinfo(current->name,current->ID,str,total);
                        printf("\n\n\t\t\t\tYou have to pay %0.2f tk only.",total);
                        PayAgain:
                            printf("\n\n\t\t\t\tCustomer paid: ");
                            scanf("%f",&pay);
                            if(pay<total){
                                printf("\n\t\t\t\tInvalid.");
                                goto PayAgain;
                                Sleep(500);
                            }
                            back=fabs(total-pay);
                            printf("\n\n\t\t\t\tCustomer Will Be Returned %0.2f Taka Only.\n",back);
                            current->quantity=remaining;
                            for(int i=1;i<=45;i++){
                                    Sleep(35);
                                    printf(".");
                                }
                                    Sleep(25);
                                    printf(".");
                                    Sleep(30);
                                    printf("T");
                                    Sleep(30);
                                    printf("H");
                                    Sleep(30);
                                    printf("A");
                                    Sleep(30);
                                    printf("N");
                                    Sleep(30);
                                    printf("K");
                                    Sleep(30);
                                    printf(" ");
                                    Sleep(30);
                                    printf("Y");
                                    Sleep(30);
                                    printf("O");
                                    Sleep(30);
                                    printf("U");
                            for(int i=1;i<=45;i++){
                                    Sleep(35);
                                    printf(".");
                                }
                                break;

                            }
                         current = current->next;
                }

        if(current->ID!=n)
                printf("\n\n\t\t\t\tNot Found.");

}


void enqueue(char Proname[20],char qua[20])
{
    CNode *temp;
    temp=(CNode*)malloc(sizeof (CNode));
    char Phone[15];
    char name[100];
    char addr[100],str1,str2;
    printf("\n\n\t\t\t\tPlease Enter Your Name: ");
    scanf("%s",&name);
    printf("\n\n\t\t\t\tPlease Enter Your Phone Number(+88): ");
    scanf("%s",&Phone);
    printf("\n");
    printf("\n\n\t\t\t\tPlease Enter Your Address(Short addr): ");
    scanf("%s",&addr);
    //scanf("%d",&x);
    strcpy(temp->name1,name);
    strcpy(temp->addr,addr);
    strcpy(temp->data,Phone);
    strcpy(temp->ProName,Proname);
    strcpy(temp->Qua,qua);

    temp->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front =rear =temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

void Customerdisplay()
{
    CNode *temp;
    temp=front;
    printf("\n");
    while(temp!=NULL)
    {

        printf("\n\t\t\t\tCustomer name: %s\n",temp->name1);
        printf("\n\t\t\t\tAddress: %s\n",temp->addr);
        printf("\n\t\t\t\tPhone: %s\n",temp->data);
        printf("\n\t\t\t\tProduct that Buy: %s\n",temp->ProName);
        printf("\n\t\t\t\tProduct Quantity(updated): %s\n",temp->Qua);
        //printf("\n\t\t\t\tTotal Tk: %0.2f\n",temp->pri);
        temp=temp->next;
    }
}

void dequeue()
{
    struct CNode *temp;
    if(front==NULL)
    {
        printf("\n\n\t\t\t\tQueue Information is empty.\n");
    }
    temp=front;
    front=front->next;
    free(temp);
}

void adminPage(){
    int n;
    struct Total *temp;
    char Ch[5],Element[20];
    system("cls");
    printf("\n\t\t\t\t1.Display all items in Store\t\t\t\n");
    printf("\n\t\t\t\t2.Create a list of Items in the Store\t\t\t\n");
    printf("\n\t\t\t\t3.Add new items\t\t\t\n");
    printf("\n\t\t\t\t4.Delete items\t\t\t\n");
    printf("\n\t\t\t\t5.Search items\t\t\t\n");
    printf("\n\t\t\t\t6.Total Sell\t\t\t\n");
    printf("\n\t\t\t\t7.Customer information\t\t\t\n");
    printf("\n\t\t\t\t8.Sells information\t\t\t\n");
    printf("\n\t\t\t\t9.Restart Programme.\t\t\t\n");
    printf("\n\t\t\t\t10.Exit\t\t\t\n");
    printf("\n\n\t\t\t\tEnter your choice(1 to 10):");
    scanf("%d",&n);
    switch(n){
    again:
        case 1:display();
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                scanf("%s",&Ch);
                if(strcmp(Ch,"#")==0){
                        adminPage();
                        break;
                }
        case 2: createList();
                //display();
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                scanf("%s",&Ch);
                if(strcmp(Ch,"#")==0){
                        adminPage();
                        break;
                }

        case 3: AddItem();
                display();
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                scanf("%s",&Ch);
                if(strcmp(Ch,"#")==0){
                        adminPage();
                        break;
                }
        case 4:display();
                deleteItem();
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                scanf("%s",&Ch);
                if(strcmp(Ch,"#")==0){
                        adminPage();
                        break;
                }
                //Delete_Main_Item();
               // break;
        case 5: printf("\n\t\t\t\tEnter Product name: ");
                scanf("%s",&Element);
                search(head, Element);
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                scanf("%s",&Ch);
                if(strcmp(Ch,"#")==0){
                        adminPage();
                         break;
                }
            //display();
                //break;
        case 6: printf("\n\n\t\t\t\tTotal Sell in store: %0.2f",SellTotal);
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                scanf("%s",&Ch);
                if(strcmp(Ch,"#")==0){
                        adminPage();
                        break;
                        }
        case 7: Customerdisplay();
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                scanf("%s",&Ch);
                if(strcmp(Ch,"#")==0){
                        adminPage();
                        break;
                        }
        case 8: //sellinfo();
                ShowSell();
                printf("\n\n\t\t\t\tPress # to back to main menu: ");
                        scanf("%s",&Ch);
                        if(strcmp(Ch,"#")==0){
                                adminPage();
                                break;
                                }
        case 9: mainFunc();
                break;

        case 10: exit(0);
        default:
            printf("\n\n\t\t\t\tInvalid\t\t\t\n");
            adminPage();
            //BEEP(750, 300);
            goto again;

    }
        //createList();
        //display();
}

void createList(){
    int N,ID;
    float price;
    char product[20];
    float Qua;
    Node *newnode,*temp;

    printf("\n\t\t\t\tTotal Number of Unique product: ");
    scanf("%d",&N);
    head=(Node*)malloc(sizeof(Node));

    if(head==NULL){
            printf("The list is empty.");
            exit(0);
        }
    else{
        printf("\n\t\t\t\tEnter the product ID: ");
        scanf("%d",&ID);
        printf("\n\t\t\t\tEnter the product name: ");
        scanf("%s",&product);
        printf("\n\t\t\t\tEnter the product Quantity(total): ");
        scanf("%f",&Qua);
        printf("\n\t\t\t\tEnter the product price(per KG or product): ");
        scanf("%f",&price);

        strcpy(head->name,product);
        head->quantity=Qua;
        head->ID=ID;
        head->price=price;
        head->next=NULL;
        display();
        printf("\n\n");
        temp=head;
        for(int i=2;i<=N;i++){
            newnode=(Node*)malloc(sizeof(Node));
            if(newnode==NULL){
                printf("Enable to allocate memory.");
                break;
            }
            else{
                printf("\n\n\t\t\t\tEnter the product ID: ");
                scanf("%d",&ID);
                printf("\n\t\t\t\tEnter the product name: ");
                scanf("%s",&product);
                printf("\n\t\t\t\tEnter the product Quantity(total): ");
                scanf("%f",&Qua);
                printf("\n\t\t\t\tEnter the product price(per KG or product): ");
                scanf("%f",&price);

                strcpy(newnode->name,product);
                newnode->quantity=Qua;
                newnode->ID=ID;
                newnode->price=price;
                newnode->next=NULL;

                temp->next=newnode;
                temp=temp->next;

                display();
            }
        }
    }
}
void display(){
    int i=1;
    Node *temp;
    if(head==NULL){
        printf("\n\t\t\tThe list is Empty.");
        exit(0);
    }
    else{
        temp=head;
        printf("\n\t|||--------Product ID---------||--------Name--------| |--------Quantity--------| |--------price--------|||");
        printf("\n\t|||---Unique ID per product---||----Product name----| |--------Total Qua-------| |-----per kg price----|||");
        printf("\n");
        while(temp!=NULL){
            printf("\n\t|||--------%d---------||--------%d.%s--------| |--------%0.1f kg/pc--------| |--------%0.2f--------|||",temp->ID,i,temp->name,temp->quantity,temp->price);
            temp=temp->next;
            i++;
        }
    }
}




void sellinfo(char name[20],int id,char qua[10],float total){

    Tnode *newnode=NULL,*temp=NULL;
    Node *node=head;
    float X=0;
    newnode=(Tnode*)(malloc(sizeof(Tnode)));
    temp=root;

    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        strcpy(newnode->Name1,name);
        strcpy(newnode->Quan,qua);
        newnode->ID=id;
        float Y=node->price;
        newnode->sell=total;
        X=newnode->sell;
        newnode->sellTotal=(X+total);
        newnode->next=NULL;

        temp=root;
        while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
        temp->next=newnode;

    }

}

void ShowSell(){
    struct Total *temp;
    temp=root;
    if(root==NULL){
        printf("\n\n\t\t\t\tSells Info is empty.");
    }
    while(temp!=NULL){
        printf("\n\n\t\t\t\tProduct name is: %s",temp->Name1);
        printf("\n\n\t\t\t\tProduct ID: %d",temp->ID);
        printf("\n\n\t\t\t\tProduct Total Sell: %0.2f",temp->sell);

        printf("\n\n\t\t\t\tTotal Sell in store: %0.2f",temp->sellTotal);
        temp=temp->next;
    }
}


void AddItem(){
    int N,ID;
    float price;
    char product[20];
    float Qua;
    Node *newnode,*temp;

    printf("\n\t\t\t\tTotal Number of Unique product: ");
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
            newnode=(Node*)malloc(sizeof(Node));
        if(head==NULL){
            printf("The list is empty.");
            exit(0);
        }
        else{
            printf("\n\t\t\t\tEnter the product ID: ");
            scanf("%d",&ID);
            printf("\n\t\t\t\tEnter the product name: ");
            scanf("%s",&product);
            printf("\n\t\t\t\tEnter the product Quantity(total): ");
            scanf("%s",&Qua);
            printf("\n\t\t\t\tEnter the product price(per KG or product): ");
            scanf("%f",&price);
            strcpy(newnode->name,product);
            newnode->quantity=Qua;
            newnode->ID=ID;
            newnode->price=price;
            newnode->next=NULL;

            temp=head;
            while(temp!=NULL && temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            temp=newnode;
        }

for(int i=1;i<=45;i++){
            Sleep(30);
            printf(".");
        }


            Sleep(15);
            printf(".");
            Sleep(25);
            printf("D");
            Sleep(20);
            printf("a");
            Sleep(20);
            printf("t");
            Sleep(20);
            printf("a");
            Sleep(25);
            printf(" ");
            Sleep(25);
            printf("i");
            Sleep(30);
            printf("n");
            Sleep(30);
            printf("s");
            Sleep(30);
            printf("e");
            Sleep(30);
            printf("r");
            Sleep(30);
            printf("t");
            Sleep(30);
            printf("e");
            Sleep(30);
            printf("d");
            Sleep(30);
            printf(" ");
            Sleep(30);
            printf("S");
            Sleep(30);
            printf("u");
            Sleep(30);
            printf("c");
            Sleep(30);
            printf("e");
            Sleep(30);
            printf("s");
            Sleep(30);
            printf("s");
            Sleep(30);
            printf("f");
            Sleep(30);
            printf("u");
            Sleep(30);
            printf("l");
            Sleep(30);
            printf("l");
            Sleep(30);
            printf("y");
            Sleep(30);
            printf(".");

        for(int i=1;i<=45;i++){
                Sleep(30);
            printf(".");
        }
        Sleep(100);
    }

}

void deleteItem(){
   char nameToDelete[50];
   struct node *temp, *prev;
   temp = head;

   printf("\n\n\t\t\t\tWhat is the name you wish to delete?\n");
   printf("\n\n\t\t\t\tEnter name of the item: ");
   scanf("%s", nameToDelete);

   // First, locate the node.
   for ( ; temp->next != NULL; temp = temp->next )
   {
      if(strcmp(nameToDelete, temp->name)==0)
      {
         break;
      }
      prev = temp;
   }

   // Now take action to deleting it.
   if ( temp != NULL )
   {
      if ( temp == head )
      {
         head = temp->next;
      }
      else
      {
         prev->next = temp->next;
      }

      free(temp);
      printf("\n\n\t\t\t\t%s was deleted successfully\n", nameToDelete);
   }
   display();
}

void search(Node* head, char x[20])
{
    Node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (strcmp(current->name,x)==0){
            printf("\n\t\t\t\tfound");
            printf("\n\t\t\t\tProduct Name: %s",current->name);
            printf("\n\t\t\t\tProduct ID: %d",current->ID);
            printf("\n\t\t\t\tProduct Total Quantity: %0.1f",current->quantity);
            printf("\n\t\t\t\tProduct Price(Per KG): %0.3f",current->price);
            break;
        }
        current = current->next;
    }
    if(strcmp(current->name,x)==1)
        printf("\n\n\t\t\t\tNot Found.");

}

void mainFunc(){
    int n;
    system("cls");
        time_t t;
        time(&t);
        printf("\t\t\tCurrent Date/Time = %s\n\n", ctime(&t));
        printf("\t\t\t\t|---------------------------------------------------|\t\t\n");
        printf("\t\t\t\t|                    R-Store                        |\t\t\n");
        printf("\t\t\t\t|    All Copyright is reserved by Ishtiaque Ahmed   |\t\t\n");
        printf("\t\t\t\t|             Fully Modern Technology               |\t\t\n");
        printf("\t\t\t\t|---------------------------------------------------|\t\t\n\n\n");
        printf("\t\t\t\t1.Admin Login\t\t\n\t\t\t\t2.Customer\t\t\n");
        printf("\t\t\t\tEnter Your Choice (1 or 2): ");
        choice:
            scanf("%d",&n);
            switch(n){
                case 1: Admin();
                        break;
                case 2: Customer();
                        break;
                default: printf("\t\t\t\tinvalid\t\t\n\t\t\t\tEnter valid number.\n\n");
                        goto choice;
            }

}

int main(int argc, char* argv[])
{
    int n;
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t-------------------------------------------------\t\t\n");
    printf("\t\t\t\t|                                               |\t\t\n");
    printf("\t\t\t\t|                      WELCOME                  |\t\t\n");
    printf("\t\t\t\t|                        To                     |\t\t\n");
    printf("\t\t\t\t|                   Revolution Store            |\t\t\n");
    printf("\t\t\t\t|                                               |\t\t\n");
    printf("\t\t\t\t-------------------------------------------------\t\t\n");
    printf("\n\n\t\t\t\tLoading.");
    for(int j=0; j<40; j++)
    {
        Sleep(60);
        printf(".");
    }
    _sleep(1000);
    mainFunc();
    getch();
    return 0;
}


