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
    bool hasLoop() 
	{
        Node*slow=head;
        Node*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr) 
		{
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) 
			{
                removeLoop(slow);
                return true;
            }
        }
        return false;
    }
    void removeLoop(Node* loopNode) 
	{
        Node*ptr1=head;
        Node*ptr2=loopNode;
        while (ptr1->next!=ptr2->next) 
		{
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr2->next=nullptr;
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
    myList.head->next->next->next->next->next=myList.head->next;

    bool hasLoop=myList.hasLoop();
    cout<<"Does the linked list have a loop? "<<(hasLoop?"Yes":"No")<<endl;
    cout<<"Linked List after removing the loop: ";
    myList.display();
}
int main() 
{
    List();
    return 0;
}
//In this code, the hasLoop function detects if there is a loop and calls the removeLoop function to break the loop. The removeLoop function uses two pointers (ptr1 and ptr2) to find the start of the loop and sets the next pointer of the node before the start of the loop to nullptr.





