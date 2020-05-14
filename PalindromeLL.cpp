/*
heck if a given linked list is palindrome or not. Return true or false.
Indexing starts from 0.
Input format : Linked list elements (separated by space and terminated by -1)

Sample Input 1 :
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
0 2 3 2 5 -1
Sample Output 2 :
false
*/

//Check if a linked list is a palindrome
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
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}

bool check_palindrome(node* head)
{
    //write your code here
    
    if(head == NULL)
        return true;
    
    node * p = head;
    node * prev = new node(head->data);
 
    while(p->next != NULL){
        node * temp = new node(p->next->data);
        temp->next = prev;
        prev = temp;
        p = p->next;
    }
 
    node * p1 = head;
    node * p2 = prev;
 
    while(p1!=NULL){
        if(p1->data != p2->data)
            return false;
 
        p1 = p1->next;
        p2 = p2->next;
    }
 
    return true;
    
}
