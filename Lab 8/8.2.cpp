#include <iostream>
using namespace std;
class Node 
{
public:
    int data;
    Node* next;
    Node(int value):data(value), next(nullptr){}
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
    void Beginning(int value) 
	{
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
    void display() 
	{
        Node* temp=head;
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
    myList.Beginning(1);
    cout<<"Linked List after insertion at the beginning: ";
    myList.display();
}
int main() 
{
    List();
    return 0;
}
/*In this code, the insert function is responsible for inserting a new node at the end of the linked list. 
It traverses the list to find the last node and then appends the new node to the next pointer of the last node.*/