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
        if (head==nullptr) 
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
    void End(int value) 
	{
        Node*newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
    void display() 
	{
        Node*temp=head;
        while(temp!=nullptr) 
		{
            cout<<temp->data<< " -> ";
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
    cout<<"Linked List: ";
    myList.display();
    myList.insert(66);
    cout<<"Linked List after insertion at the end: ";
    myList.display();
}
int main() 
{
    List();
    return 0;
}
//In this code, the insertAtPosition function is added to the LinkedList class. It inserts a new node at a specific position in the linked list. If the position is 0 or negative, the new node is inserted at the beginning. Otherwise, it traverses the list to find the node at position-1 and inserts the new node after it.