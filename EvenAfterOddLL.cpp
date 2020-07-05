/*
Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
Note: Input and Output has already managed for you. You don't need to print the elements, instead return the head of updated LL.
Input format:
Linked list elements (separated by space and terminated by -1)
Output format:
Print the elements of updated Linked list. 
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
1 11 3 6 8 0 9 -1
Sample Output 2 :
1 11 3 9 6 8 0
*/

//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
#include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
node* arrange_LinkedList(node* head)
{
    //write your code here
  /*  if (head == NULL) return NULL;
        node * odd = head, * even = head->next, * evenHead = even;
        while (even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;*/
    
    node * odd = NULL, * oddTail = NULL;
		node * even = NULL, * evenTail = NULL;
		node * curr = head;

		while (curr != NULL)
		{
			if ((curr->data & 1) != 0) // current node is odd
			{
				// handle head for first odd node
				if (odd == NULL) {
					odd = oddTail = curr;
				}
				else
				{
					oddTail->next = curr;
					oddTail = oddTail->next;
				}
			}
			else // current node is even
			{
				// handle head for first even node
				if (even == NULL) {
					even = evenTail = curr;
				}
				else
				{
					evenTail->next = curr;
					evenTail = curr;
				}
			}
			curr = curr->next;
		}

		// if list contains at-least one even node
		if (even != NULL)
		{
			head = even;
			evenTail->next = odd;
		}
		// special case - list contains all odd nodes
		else {
			head = odd;
		}

		// null to terminate the list, 
		// else it will go in infinite loop
		if (oddTail != NULL) {
			oddTail->next = NULL;
		}

		return head;
}
