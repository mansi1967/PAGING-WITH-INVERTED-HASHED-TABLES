#include<stdio.h>
#include<stdlib.h>
#define size 100
int wfm=0;
int hit;

struct node
{
    int wpg;
    int pid;
    int frameno;
    struct node *next;
};

struct node *chain[size];

int freefrmno(){++wfm;returnwfm;}

void init()
{
    int i;
for(i = 0; i< size; i++)
        chain[i] = NULL;
}

void insert(int value,intwpcs)
{ 
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
newNode->wpg = value;
newNode->pid=wpcs;
newNode->frameno=freefrmno();
newNode->next = NULL;
printf("\npageno %d of process pid %d is now inserted at frameno %d",newNode->wpg,newNode->pid,newNode->frameno);
int key=value%100;
    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {//add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}


int search(int value,intwpcs)
{
    int key = value % size;
    struct node *temp = chain[key];
    while(temp)
    {
        if(temp->wpg == value && temp->pid==wpcs)
            return temp->frameno;
        temp = temp->next;
    }
    return 0;
}
void print()
{
    int i;
for(i = 0; i< size; i++)
    {
        struct node *temp = chain[i];
printf("chain[%d]-->",i);
        while(temp)
        {
printf("%d, %d -->",temp->wpg,temp->pid);
            temp = temp->next;
        }
printf("NULL\n");
    }
}

int main()
{
init(); 
printf("\n\nwelcome to paging, you are the Operating system where  You decide  the process you want to execute.");
printf("\nOn demand , we pagers will supply");
printf("\nAs you are the OS(THE KING) of the your device .I request you to give out few details so we can page");
printf("\nwhat is the main memory size(max 1000)?:");
    int mm;
scanf("%d",&mm);//1GB is 2^30: 1073741824
printf("\nenter page size: then we can know how to divide code(min 10):");
    int pgsz;
scanf("%d",&pgsz);//like 4kb thats 4096
    int nfrm=(mm/pgsz);//no of frames available in mm
printf("\ncongrats!did you know that you have %d frames in main memory",nfrm);
    int np;
    int hit=nfrm;
    int s=1;
    while (s){
printf("\n\nwelcome by paging with inverted hash tables ,a solution\n");
printf("\ndo you want to page(1) or we can exit(0),enter:");
    int w;
scanf("%d",&w);
    if (w==0){break;
    }
printf("\nPaging time ,it is!");
printf(" \n what is the page of the process that you want : page:? process?(denoted by pid):" );
    int wpg,pid;
scanf("%d %d",&wpg,&pid);
    if(search(wpg,pid)==0){printf("\nwe have to insert the page,its not there in MM");insert(wpg,pid);}
else{printf("\nthe page is already inserted at %d frameno in Main memory",search(wpg,pid));}
    //printf("pageno %d of process pid %d is now inserted at frameno %d",newNode->wpg,newNode->pid,newNode->frameno);   
}  
print();
    return 0;
}

