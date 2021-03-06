#include <iostream>
using namespace std;

class node{
public:
	int data;
	node * next;
	// constructor
	node(int d) : data(d) , next(NULL) { }

	// destructor
	~node(){
		if(next!=NULL)
			delete next;
	}
};

void insertBack(node* &head, int d){
	node * temp = new node(d);
	if(head == NULL){
		head = temp;
		return;
	}
	node * ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
	//temp->next = NULL; no  need since we already created constructor
}

node * takeInput(int n){
	node * head = NULL;
	int d;
	int i = 0;
	while(i < n){
		cin>>d;
		insertBack(head,d);
		i++;
	}

	return head; 
	//sending value of head or data(which is address of 1st node of ll) inside head to head in main
}

void print(node*head){
    if(head == NULL)    return;
	node * temp = head;
	while(temp->next!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data;
}

void deleteAtK(node* &head, int k){
	if(head == NULL)	return;
	node*temp = head, *prev = head,*it;
	if(k == 0){
		head = temp->next;
	}else{
		int i = 0;
		while(temp && i < k){
			prev = temp;
			temp = temp->next;
			i++;
		}
		prev->next = temp->next;
	}
	temp = NULL; // very important: always set pointer to NULL before deleting it
	// otherwise it can cause memory leak
	delete temp;
}

int main(){
	int n,q;
	cin>>n>>q;
	node *head;
	head = takeInput(n); 
	while(q--){
		int k;
		cin>>k;
		deleteAtK(head,k);
		print(head);
		cout<<endl;
	}
	return 0;
}