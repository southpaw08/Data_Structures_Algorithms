#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *link; //only Node* link for c++
};


struct Node *head; //globl variable, can be accessed anywhere


/* Print using recursion */
void print_rec(struct Node* curr)
{
	
	if(curr == NULL)
	{
		printf("\n");
		return;
	}
	printf("%d ", curr->data);
	print_rec(curr->link);
}

/* Reverse print using recursion */
void print_rec_reverse(struct Node* curr)
{
	if(curr == NULL)
	{
		printf("\n");
		return;
	}
	print_rec_reverse(curr->link);
	printf("%d ", curr->data);
    //printf("\n");
}

/* Insert at the beginning of the list */
void insert_at_beg(int x)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->link = head;
	head = temp;
}

/* Reverse a linked list using iterative method */
void reverse_iterative()
{
	struct Node *prev, *curr, *next;
	prev = NULL;
	curr = head;
	while(curr != NULL)
	{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

/* Reverse a linked using recursive method */
void reverse_recursive(struct Node *p)
{
	if(p->link == NULL)
	{
		head = p;
		return;
	}
	reverse_recursive(p->link);
	struct Node*q=p->link;
	q->link = p;
	p->link = NULL;
}
/* Delete node at pos n */
void delete(int n)
{
	struct Node* temp = head;
	if(n == 1)
	{
		head = temp->link;
		free(temp);
		return;
	}
	for(int i=0; i < n-2; i++)
	{
		temp = temp->link;
	}
	struct Node* del_node = temp->link;
	temp->link = del_node->link;
	free(del_node);
	
}

/* Insert at the end of list */
void insert_at_end(int data)
{
	struct Node* new_elem = (struct Node*)malloc(sizeof(struct Node));
	new_elem->data = data;
	new_elem->link = NULL;

	if(head == NULL)
	{
		//temp->data = data;
		//temp->link = head;
		head = new_elem;
		//return;
	}
	else
	{
		struct Node* temp = head;
		while(temp->link!=NULL)
		{
			temp = temp->link;
		}
		temp->link = new_elem;
	}
}
void insert_at_pos(int data, int pos)
{
	struct Node* new_elem = (struct Node*)malloc(sizeof(struct Node));
	new_elem->data = data;
	new_elem->link = NULL;
	
	//if data needs to be inserted at the beginning of list
	if(pos == 1)
	{
		new_elem->link = head;
		head = new_elem;
		return;
	}
	struct Node* temp = head;
	for(int i = 0; i < pos-2; i++)
	{
		temp = temp->link;
	}
	new_elem->link = temp->link;
	temp->link = new_elem;
}
/* Print the list */
void print_list()
{
	struct Node* temp = head;
	printf("List is :");
    while(temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main()
{
	head = NULL;  //empty list
	int elem = 0, data = 0;
	#if 0
	printf("Number of elements in linked list?\n");
	scanf("%d",&elem);
	for(int i = 0; i < elem; i++)
	{
		printf("Please enter the data\n");
		scanf("%d",&data);
		insert_at_beg(data);
		print_list();
	}	
	#endif
	
	#if 0
	insert_at_pos(2,1); //List: 2
	insert_at_pos(3,2); //List: 2,3
	insert_at_pos(4,1); //List:4,2,3 
	insert_at_pos(5,2); //List:4,5,2,3
	print_list();
	#endif
	
	
    insert_at_end(1);		
    insert_at_end(16);		
    insert_at_end(5);		
    insert_at_end(8);		
    insert_at_end(10);
    printf("Before reversing: \n");		
	print_list();
	
	#if 0
	int pos;
	printf("Enter a postion to be deleted\n");
	scanf("%d", &pos);
	delete(pos);
	#endif
	//reverse_iterative();
	reverse_recursive(head);
	printf("After reversing the list: \n");
	print_rec(head);
	printf("Reverse print using recursion: \n");
	//print_rec_reverse(head);
}
