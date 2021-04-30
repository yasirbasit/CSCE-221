// Write a C++ recursive function that counts 
// the number of nodes in a singly linked list. 
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int da = 0, Node *p = NULL) {
        this -> data = da;
        this -> next = p;
    }
};

class List{
private:
	Node *head,*tail;
public:
	List(){head = tail = NULL;};
	~List(){delete head; delete tail;};
	void print() {
	    Node *p = head;
	    while (p != NULL) {
	        cout << p -> data << " \a";
	        p = p->next;
	    }
	    cout << endl;
	};
	void Insert(int da) {
	    if (head == NULL) {
	        head = tail = new Node(da);
	        head -> next = NULL;
	        tail -> next = NULL;
	    } else {
	        Node *p = new Node(da);
	        tail -> next = p;
	        tail = p;
	        tail -> next = NULL;
	    }
	};
	Node* first() {return head;};
	bool is_empty(){return head==tail;};
};

int count_node(Node* n) {
	if(n == NULL)
		return 0;
	else
		return 1 + count_node(n -> next);
}

// int count_node(List ll) {
// 	if(ll.is_empty())
// 		return 0;
// 	else if{
// 		Node* temp = ll.first()->next;
// 		ll.first()->next=temp->next;
// 		delete temp;
// 		return 1+count_node(ll);
// 	}
// }

int main() {
    List l1;
    l1.Insert(1);l1.Insert(2);l1.Insert(3);l1.Insert(4);
    l1.Insert(5);l1.Insert(6);l1.Insert(7);
    l1.print();
    cout << "the number of nodes: " << count_node(l1.first()) << endl;
    // cout << "test: " << count_node(l1) << endl;
    system("pause");
	return 0;
}