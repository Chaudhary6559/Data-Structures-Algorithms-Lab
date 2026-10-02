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
                return true;
            }
        }
        return false;
    }
    void createLoop(int position) 
	{
        if(position<=0||head==nullptr) 
		{
            return;
        }
        Node*loopNode=head;
        while(loopNode->next!=nullptr)
		{
            loopNode=loopNode->next;
        }
        Node*temp=head;
        for(int i=1;i<position&&temp!=nullptr;++i) 
		{
            temp=temp->next;
        }
        if(temp!=nullptr) 
		{
            loopNode->next=temp;
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
    myList.insert(37);
    myList.insert(55);
    myList.insert(52);
	myList.insert(75);
    cout<<"Original Linked List: ";
    myList.display();
    bool hasLoop=myList.hasLoop();
    cout<<"Does the linked list have a loop? "<<(hasLoop?"Yes":"No")<<endl;
    myList.createLoop(2);
    hasLoop=myList.hasLoop();
    cout<< "After creating a loop, does the linked list have a loop? "<<(hasLoop?"Yes":"No")<<endl;
}

int main() {
    List();
    return 0;
}

//In this code, the hasLoop function in the LinkedList class uses two pointers (slow and fast) to traverse the linked list. If there's a loop, the fast pointer will eventually catch up with the slow pointer. The createLoop function is used to create a loop in the linked list for testing purposes. The display function is used to print the elements of the linked list for verification.





