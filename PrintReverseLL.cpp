/*
Print a given linked list in reverse order. You need to print the tail first and head last. You can’t change any pointer in the linked list, just print it in reverse order.
Input format : Linked List elements (separated by space and terminated by -1)

Output format : Linked List elements in reverse order (separated by space)

Sample Input 1 :
1 2 3 4 5 -1
Sample Output 1 :
5 4 3 2 1
Sample Input 2 :
1 2 3 -1
Sample Output 2 :
3 2 1
*/

// Print a given linked list in reverse order. Tail first. You cant change any pointer in the linked list
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
    print_linkedlist_spl(head);
    return 0;
}
void print_linkedlist_spl(node*head)
{
    //write your code here
     if (head == NULL)  
    return;  
  
    // print the list after head node  
    print_linkedlist_spl(head->next);  
  
    // After everything else is printed, print head  
    cout << head->data << " ";  
    
}
