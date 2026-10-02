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
    void deleteNode(int value) 
	{
        Node*current=head;
        Node*previous=nullptr;
        while(current!=nullptr&&current->data!=value) 
		{
            previous=current;
            current=current->next;
        }
        if (current!=nullptr) 
		{
            if(previous!=nullptr) 
			{
                previous->next=current->next;
            } 
			else 
			{
                head=current->next;
            }
            delete current;
        } 
		else 
		{
            cout<<"Node with value "<<value<<" not found. No deletion performed."<<endl;
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
    myList.deleteNode(55);
    cout<<"Linked List after deleting node with value 55: ";
    myList.display();
}
int main() 
{
    List();
    return 0;
}
//In this code, the deleteNode function in the LinkedList class deletes a node with a specified value from the linked list. It traverses the list to find the node to be deleted, updates the next pointer of the previous node (or the head if the node to be deleted is the head), and deallocates the memory for the deleted node. The display function is used to print the elements of the linked list for verification.





