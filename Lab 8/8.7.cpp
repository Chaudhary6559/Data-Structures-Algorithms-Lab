#include <iostream>
using namespace std;
class Node 
{
public:
    int data;
    Node*next;
    Node(int value):data(value),next(nullptr){}
};
class LinkedList 
{
public:
    Node*head;
    LinkedList():head(nullptr){}
    void insert(int value) 
	{
        Node*newNode=new Node(value);
        if(head==nullptr) 
		{
            head=newNode;
        } 
		else 
		{
            Node*temp=head;
            while(temp->next!=nullptr) 
			{
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    Node*findMiddle() 
	{
        if(head==nullptr) 
		{
            return nullptr;
        }
        Node*slow=head;
        Node*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr) 
		{
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void display() 
	{
        Node*temp=head;
        while(temp!=nullptr) 
		{
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};
void List() 
{
    LinkedList myList;
    myList.insert(13);
    myList.insert(25);
    myList.insert(34);
    myList.insert(37);
    myList.insert(55);
    myList.insert(52);
	myList.insert(75);
    cout<<"Original Linked List: ";
    myList.display();
    Node* middleNode=myList.findMiddle();
    if(middleNode!=nullptr) 
	{
        cout<<"Middle Node: "<<middleNode->data<<endl;
    } 
	else 
	{
        cout<<"The list is empty. No middle node."<<endl;
    }
}
int main() 
{
    List();
    return 0;
}
//In this code, the findMiddle function in the LinkedList class uses two pointers (slow and fast) to traverse the linked list. The slow pointer advances one node at a time, while the fast pointer advances two nodes at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle node. The display function is used to print the elements of the linked list for verification.