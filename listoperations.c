//Mina Ünal
//201180042


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating the struct
struct Student
{
	char name[50];
	char gender;
	struct Student *next;
};

struct Student *insertNode(char *name, char gender, struct Student *list)
{
	struct Student *s;
	// Allocate memory for node (malloc operation)
	s = malloc(sizeof(struct Student));
	if (s == NULL)
	{
		printf("Memory allocation failed.");
		return list;
	}
	strcpy(s->name, name);
	s->gender = gender;
	s->next = list; // list is the start of the list
	list = s;

	return list;
}

struct Student *Seperating(struct Student *list) //function that lists and combines males and females separately.
{

	int count = 0;
	int count2 = 0;
	struct Student *temp = list;
	struct Student *x;
	struct Student *y;
	struct Student *xx;
	struct Student *yy;

	while (temp != NULL)
	{

		if (count != 0 && count2 != 0)
		{

			if (temp->gender == 'M')
			{

				y->next = temp; //the new node is male.
				y = y->next;    //going through the males list.
				temp = temp->next; //main list continues.
				y->next = NULL; //The gender of the new upcoming node is unknown. But it should point null at the end.
			}

			else
			{

				x->next = temp;  //the new node is female.
				x = x->next;   //going through the females list.
				temp = temp->next;  //main list continues.
				x->next = NULL;  //The gender of the new upcoming node is unknown. But it should point null at the end.
			}
		}
		else
		{
			if (temp->gender == 'M')
			{
				if (count2 == 0) //the first node's gender is determined only once.
				{
					y = temp;    //the list that i keep for males.
					yy = y;      //the head of the males list. (then i will access to the males list with yy.)
					count2++;    
					temp = temp->next; //temp node i keep so as not to lose the whole list.
				}
				else
				{

					y = temp;   //deciding with which gender the list will continue after assigning the first nodes.
					temp = temp->next; //switch to other node.
				}
			}
			else
			{
				if (count == 0)  //the first node's gender is determined only once.
				{
					x = temp;  //the list that i keep for females.
					xx = x;    //the head of the females list. (then i will access to the females list with yy.)
					count++;
					temp = temp->next;  //temp node i keep so as not to lose the whole list as well.
				}

				else
				{
					x = temp;   //deciding with which gender the list will continue after assigning the first nodes.
					temp = temp->next; //switch to other node.
				}
			}
		}
	}
	printf("\n");


	// combining
	temp = xx; //holding in a temp the head of the girls, so the list.
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = yy; //connecting males to females.
	list = xx; //assigning the whole list.

	printf("\n");
	return list; 

}
// Sorting function
struct Student *sortList(struct Student *list)
{   
	list=Seperating(list); //ordered list
	// Females
	struct Student *temp = list;
	struct Student *temp2;
	struct Student *a;
	struct Student *males;
	struct Student *bridgenode; // bridge node for linking the first male node.
	int count = 1;
    int i;

	while (temp->next->gender == 'F')  // finding number of nodes in the list.
	{ 
		temp = temp->next;
		count++;
	}
	temp = list;


	while (temp->next->gender != 'M')  
	{ 
		temp = temp->next;
	}
	males = temp->next; // temporarily holding "males" list to not get lost it because of the next step.
	temp->next = NULL;  // assigning to null to the first of Male element because of ending condition of females.
	temp = list;


    //FEMALE SORTING

	for (i = 0; i < count ; i++)  //a for loop to correctly position each node.
	{   
		temp2=list;
		while(temp2->next!=NULL) //ending condition.
		{
			
			if (strcmp(temp2->name, temp2->next->name) > 0)  //if the previous node comes later than the next node alphabetically.
			{

				a=temp2->next;   //the copy of the node that I will position at the beginning.
				if(temp2->next->next==NULL){ //if temp nodes' position is just before the last node.
					temp2->next=NULL;   //After the last node go beginning, the new last node->next should be set to null.
					(a->next = list); //node inserted to the beginning is connected to the list.
				
					list = a; // head node set as list.
					break; //last step of while loop. it must go to the for loop again. Then it points the list.
				}
				else{
				temp2->next=temp2->next->next; //if temp nodes' position is NOT before the last node.
				
				 (a->next = list); //node inserted to the beginning is connected to the list.
				
					list = a; // head node set as list.
				}							
			}
			else{
			temp2=temp2->next; //if function is not provided or nodes are equal, go to the next step and check again.
			}
		}
	}

	// MALE SORTING

	temp = males; //head of the males assigns to the temp.

	count = 0;
	while (temp->next != NULL)
	{ // finding number of elements in the list.
		temp = temp->next;
		count++;
	}
	count++;
	temp = males;

	// The same operations for females are proceeding for males as well, only if strcmp ensures the "<" condition.
	for (i = 0; i < count ; i++)
	{
		temp2=males;
		while(temp2->next!=NULL)
		{
			if (strcmp(temp2->name, temp2->next->name) < 0)
			{

				a=temp2->next;
				if(temp2->next->next==NULL){
					temp2->next=NULL;
					(a->next = males);
				
					males = a;
					break;
				}
				else{
				temp2->next=temp2->next->next;
				
				 (a->next = males);
				
					males = a;
				}				
			}
			else{
			temp2=temp2->next;
			}
		}
	}

	printf("\n");


    //keeping the head of the node that I hold the females in the bridgenode to connect it to the males later.
	bridgenode = list;
	while (bridgenode->next != NULL)
	{
		bridgenode = bridgenode->next;
	} //done for females.
	
	bridgenode->next = males; //then connecting to the males list.
	return list;
}


// Printing function
void printList(struct Student *list)
{
	while (list != NULL)
	{
		printf("%s\t%c\n", list->name, list->gender);
		list = list->next;
	}
}

int main()
{
	// Creating an Initial Node Variable
	struct Student *head = NULL;

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

    //call to sorting function
	head = sortList(head);

	printList(head);
}
