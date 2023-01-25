#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Creating the struct
struct Student
{
 char name[50];
 char gender;
 struct Student * next;
};

struct Student * insertNode (char *name, char gender, struct Student * list)
{
 struct Student *s;
 //Allocate memory for node (malloc operation)
 s = malloc (sizeof (struct Student));
 if (s == NULL)
 {
 printf ("Memory allocation failed.");
 return list;
 }
 strcpy(s->name, name);
 s->gender = gender;
 s->next = list; //list is the start of the list
 list = s;

 return list;
}

//Sorting function
struct Student * sortList (struct Student *list)
{
char firstgender=list->gender;
struct Student * temp=list;
struct Student *a;
struct Student *b;
int count=1;
int count2=0;
int i,j;


while(temp->next->gender==firstgender){
	temp=temp->next;
	count++;
}
temp=list;

for(i=0; i<count-1; i++){
	for(j=0; j<count-i-1; j++){
	if(strcmp(temp->name,temp->next->name)>0){
		a=temp; //merve
		b=temp->next->next; //tugce
		temp=temp->next;
		temp->next=a;
		temp->next->next=b;
		
       if(temp->next==list && count2==0){
    
	   	list=temp;
	   	count2++;
	   	
	   		}
	   	
		}
	
		temp=temp->next;
		printf("%s,%s,%s\n", temp->name,temp->next->name,temp->next->next->name);
		
	}
	
temp=list;

}
printf("%d,%d\n",i,j);
printf("\n");
printList(list);



}
struct Student * Seperating(struct Student *list){
	
	int count=0;
	int count2=0;
	struct Student *temp=list;
	struct Student *x;
	struct Student *y;
	struct Student *xx;
 	struct Student *yy;
	
	while(temp!=NULL){
		
	if (count!=0 && count2!=0){
	
	   if(temp->gender=='M'){
	   	
	   	y->next=temp;
	   	y=y->next;
	   	temp=temp->next;
	   	y->next=NULL;
	   }
	   
	   else{
	  
	   x->next=temp;
	 
	   x=x->next;
      
	   temp=temp->next;
	    x->next=NULL;
	
	}
}
	else{
		if(temp->gender=='M' ){
		    if(count2==0){
			y=temp;
			yy=y;
			count2++;
			temp=temp->next;
		}
		else{
			
			y=temp;
			temp=temp->next;
			
		}
	}
		else{
			if(count==0){
			x=temp;
			xx=x;
			count++;	
			temp=temp->next;
			}
			
			else{
			x=temp;
			temp=temp->next;
			}
			
		}			
	}
}
printf("\n");
//combining
temp=xx;
while(temp->next!=NULL){
	temp=temp->next;
}
temp->next=yy;
list=xx;
printList(list);
printf("\n");
sortList(list);

}
//Printing function
void printList (struct Student * list)
{
 while (list != NULL)
 {
 printf ("%s\t%c\n", list->name, list->gender);
 list = list->next;
 }
}

int main ()
{
 //Creating an Initial Node Variable
 struct Student * head=NULL;

 head = insertNode("Cenk", 'M', head);

    head = insertNode("Ceyda", 'F', head);

    head = insertNode("Esra", 'F', head);

    head = insertNode("Okan", 'M', head);

    head = insertNode("Tugce", 'F', head);

    head = insertNode("Mehmet", 'M', head);

    head = insertNode("Ayse", 'F', head);

    head = insertNode("Merve", 'F', head);

    head = insertNode("Sedat", 'M', head);

    head = insertNode("Ahmet", 'M', head);
    head = insertNode("Zehra", 'F', head);
    head = insertNode("Sude", 'F', head);

//head = sortList(head);
 printList(head);
 Seperating(head);
 
}

