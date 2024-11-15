#include<stdio.h>
#include "x.h"
#include<windows.h>
void textcolour(int colour_name)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour_name);}

struct contact{
	char name[30];
	char number[30];
	struct contact *prev;
	struct contact *nxt;
};
struct contact *head=NULL,*tail=NULL;
struct recent{
	char rname[30];
	char rnumber[30];
	struct recent *rprev;
	struct recent *rnxt;
};
struct recent *h=NULL,*t=NULL;

void c_create(){
	struct contact *temp;
	
	temp=(struct contact*)malloc(sizeof(struct contact));
	textcolour(1);
	printf("\n enter name:");
	scanf("%s",&temp->name);
	printf("\n enter mobile number:");
	scanf("%s",&temp->number);
	textcolour(7);

	
	
   temp->nxt=NULL;
   temp->prev=NULL;
   if(head==NULL){
   	head=temp;
   	tail=temp;

   }
   else{
   	tail->nxt=temp;
   	temp->prev=tail;
   	tail=temp;
   	
   }
}
void c_display(){
	struct contact *temp;
	textcolour(5);
temp=head;
	while(temp!=NULL){
		printf("\n %s------------%s",temp->name,temp->number);
		
		temp=temp->nxt;
	}
	textcolour(7);
}
void c_sort(){
	struct contact *temp=head;
	int c=0,i;
	while(temp!=NULL){
		temp=temp->nxt;
		c++;
	}
	temp=head;
	char s[100];
	char x[100];
	for(i=0;i<c;i++){
		temp=head;
		while(temp->nxt!=NULL){
			if(strcmp(temp->name,temp->nxt->name)>0){
				strcpy(s,temp->name);
				strcpy(temp->name,temp->nxt->name);
				strcpy(temp->nxt->name,s);
				strcpy(x,temp->number);
				strcpy(temp->number,temp->nxt->number);
				strcpy(temp->nxt->number,x);
			
			}
			temp=temp->nxt;
		}
	}
}
void r_calling(){
	int ch;
	textcolour(6);
	printf("\n enter the choice 1.name 2.number");
	textcolour(7);
	scanf("%d",&ch);
	switch(ch){
		case 1:r_calling_by_name();
		break;
		case 2:r_calling_by_number();
	break;
		default:printf("\n enter valid choice");
	}
}
void r_calling_by_name(){
	
	char n[100];
	textcolour(6);
	printf("\n enter the name to call whom");
		scanf("%s",n);
	printf("\n CALLING.......");
  textcolour(7);
	textcolour(7);
	scanf("%s",n);
	int p;
	p=find(n);
	if(p==1){
		printf("\n contact found in the list");
		struct recent *temp;
		temp=(struct recent*)malloc(sizeof(struct recent));
		strcpy(temp->rname,n);
		//printf("\n enter number");
		//scanf("%s",&temp->rnumber);
		strcpy(temp->rnumber,find1(n));
		temp->rnxt=NULL;
		temp->rprev=NULL;
		if(h==NULL){
		h=temp;
		t=temp;
	}
	else{
		t->rnxt=temp;
		temp->rprev=t;
		t=temp;
	}
	}
	else{textcolour(6);
		printf("\n contact not found enter number to call");
		textcolour(7);
	}
}
int find (char *s){
        struct contact *temp=head;
        while(temp!=NULL){
        	if(strcmp(s,temp->name)==0){
        		return 1;
			}
			temp=temp->nxt;
		}
}
char* find1 (char *s){
        struct contact *temp=head;
        while(strcmp(temp->name,s)!=0){
			temp=temp->nxt;
		}
		return temp->number;
}
void r_display()
{
	struct recent *my;
	my=t;
	while(my!=NULL){
		printf("\n %s-----%s",my->rname,my->rnumber);
		my=my->rprev;
	}
}
void r_calling_by_number(){
  struct recent *temp;
  temp=(struct recent *)malloc(sizeof(struct recent));
  textcolour(3);
  printf("\n enter number to call");
  scanf("%s",temp->rnumber)	;
  textcolour(8);
  printf("\n CALLING......");
  textcolour(7);
  strcpy(temp->rname,temp->rnumber);
  	temp->rnxt=NULL;
		temp->rprev=NULL;
		if(h==NULL){										
		h=temp;
		t=temp;
	}
	else{
		t->rnxt=temp;
		temp->rprev=t;
		t=temp;
	}
  
}
