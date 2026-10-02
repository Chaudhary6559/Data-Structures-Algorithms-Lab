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
    Node* head;
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
    void reverse() 
	{
        Node*current=head;
        Node*previous=nullptr;
        Node*nextNode=nullptr;
        while(current!=nullptr) 
		{
            nextNode=current->next;
            current->next=previous;
            previous=current;
            current=nextNode;
        }
        head=previous;
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
    myList.insert(34);
    myList.insert(55);
    myList.insert(52);
	myList.insert(75);
    cout<<"Original Linked List: ";
    myList.display();
    myList.reverse();
    cout<<"Reversed Linked List: ";
    myList.display();
}
int main() 
{
    List();
    return 0;
}
//In this code, the reverse function in the LinkedList class iterates through the list, reversing the direction of each link. It uses three pointers (current, previous, and nextNode) to keep track of the current, previous, and next nodes during the reversal process. The display function is used to print the elements of the linked list before and after the reversal for verification.





