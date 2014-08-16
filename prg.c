/*PROGRAM TO CREATE A LINKED LIST AND PERFORMING DIFFERENT ACTIONS*/
#include<stdio.h>
struct node									//defining node as structure
	{
		int info;
		struct node *link;
	}*newptr2,*newptr,*start,*rear,*save,*save1,*curr,*nptr;		//declaring necessary pointers pointing to the node
	
struct node *create(int n)							//declaring a function of type node to allocate a new node		
	{
		struct node *temp;						//temporary pointer to store a node
		temp=(struct node*)malloc(sizeof(struct node));
		temp->info=n;
		temp->link=NULL;
		return temp;
	}
void insert(struct node *ptr)							//function to insert a single node to the linked list
	{
		if(start==NULL)							/*checking weather the list is empty or not...if found empty assigning start and rearthe 											first node*/
                start=rear=ptr;							
		else
	     {  rear->link=ptr;
		rear=ptr;
	      }
	}
void delete()									//function to delete a node from begining  
	{
		if(start==NULL)							//checking wether the list is empty or not
			{ 	printf("!!!the list is empty!!");
			  	exit(0);
			}
		else
			{	
				save1=start;
				start=start->link;
				
			}
	}
					
void display(struct node *np)							//function to display the node
	{
		if(np==NULL)
		printf("\nthe list is empty");
		while(np!=NULL)
		{
			printf("%d-->",np->info);		
			np=np->link;
		}
	}
void ins_as_u_wish(struct node *nptr,struct node *usrnode,int u)		//function to insert the node at required position
	{
		
		curr=nptr;
		while((curr->info!=u)&&(curr->link!=NULL))			//reaching the required pointer 
		{
 			curr=curr->link;
		}
		if(curr==NULL)
			{
				printf("\n!!!ops....ur entry is not in the list....please chech once again and enter a correct entry!!!...aborting!!!!!\n");
				exit(0);
			}
		usrnode->link=curr->link;					//inserting node after the required position
		curr->link=usrnode;
		
	}
main()
{
		start=rear=NULL;
		int ch,info,choice,item;
		printf(">>>do you wish to enter the choice menu...then press 1.....\n");	//displaying the list of actions that can be carried out
		scanf("%d-->",&choice);
	while(choice==1)
	{
		printf("!!!THE MENU!!!\n1.Enlist\n2.Display\n3.Delete\n4.Insert at the place u wish to\n");
		scanf("%d",&ch);
		switch(ch)
			{
				case 1: printf("\nEnter the information\n");
					scanf("%d",&info);
					newptr=create(info);
					if(newptr==NULL)					//checking the list for space
					{
						printf("\n>>>aborting<<<<<\n");
						exit(0);
					}
					insert(newptr);
					break;
				case 2: printf("the node looks like---->\n");
					display(start);
				        break;
				case 3: delete();
					break;
				case 4: printf("please enter the info part of the node after u want to insert ur node\n");
				        scanf("%d-->",&item);
					printf("please enter the info part of the node  u want to insert  in ur node\n");
					scanf("%d",&info);
					newptr2=create(info);	
					ins_as_u_wish(start,newptr2,item);
			}

		printf(">>>do you wish to continue...if yes...VOILA..press 1!!!\n");
	        scanf("%d",&choice);
	}
}			

