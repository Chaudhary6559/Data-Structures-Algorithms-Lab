#include <iostream>
using namespace std;
class Node 
{
public:
    int data;
    Node*next;
    Node(int value):data(value),next(nullptr) {}
};
class LinkedList 
{
public:
    Node* head;
    LinkedList():head(nullptr) {}
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
    myList.insert(41);
    myList.insert(23);
    myList.insert(63);
    myList.insert(43);
    myList.insert(58);
    myList.insert(78);
    cout<<"Linked List: ";
    myList.display();
}
int main() 
{
    List();
    return 0;
}
/*The insertAtBeginning function is added to the LinkedList class, and it inserts a new node at the beginning of the 
linked list. The function sets the next pointer of the new node to the current head of the list and then updates the 
head to point to the new node. This effectively inserts the new node at the beginning.*/ 