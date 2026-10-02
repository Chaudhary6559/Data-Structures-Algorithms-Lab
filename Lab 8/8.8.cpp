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
    Node*Nth(int n) 
	{
        if(head==nullptr||n<= 0) 
		{
            return nullptr;
        }
        Node*fast=head;
        Node*slow=head;
        for(int i=0;i<n;++i) 
		{
            if(fast==nullptr) 
			{
                return nullptr;
            }
            fast=fast->next;
        }
        while(fast!=nullptr) 
		{
            slow=slow->next;
            fast=fast->next;
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
    int n=3;
    Node* nthNode=myList.Nth(n);
    if(nthNode!=nullptr) 
	{
        cout<<"The "<<n<<"rd node from the end: "<<nthNode->data<<endl;
    } 
	else 
	{
        cout<<"Invalid input or list is shorter than "<<n<<" nodes."<<endl;
    }
}
int main() 
{
    List();

    return 0;
}
//In this code, the findNthFromEnd function in the LinkedList class uses two pointers (slow and fast). The fast pointer is initially moved n nodes ahead. Then, both pointers are moved one node at a time until the fast pointer reaches the end of the list. At this point, the slow pointer will be pointing to the nth node from the end. The display function is used to print the elements of the linked list for verification.





