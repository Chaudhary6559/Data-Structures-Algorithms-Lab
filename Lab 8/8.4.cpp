#include <iostream>
using namespace std;
class Node 
{
public:
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};
class LinkedList 
{
public:
    Node* head;
    LinkedList():head(nullptr){}
    void insert(int value) 
	{
        Node* newNode=new Node(value);
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
    void Position(int value, int position) 
	{
        Node*newNode=new Node(value);
        if(position<=0) 
		{
            newNode->next=head;
            head=newNode;
        } 
		else 
		{
            Node*temp=head;
            for(int i=1;i<position&&temp!=nullptr;++i) 
			{
                temp=temp->next;
            }
            if(temp!=nullptr) 
			{
                newNode->next=temp->next;
                temp->next=newNode;
            } 
			else 
			{
                cout<<"Invalid position. Node not inserted."<<endl;
            }
        }
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
    cout<<"Linked List: ";
    myList.display();
    myList.Position(99, 2);
    cout<< "Linked List after insertion at position 2: ";
    myList.display();
}
int main() 
{
    List();
    return 0;
}
//This code defines a function insertAtPosition in the LinkedList class, which inserts a new node with a given value at a specified position in the linked list. The position is zero-indexed, and if the position is less than or equal to 0, the new node is inserted at the beginning of the list. The function then traverses the list to find the node at position-1 and inserts the new node after it. The display function is used to print the elements of the linked list for verification.
