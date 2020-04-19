#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d):data(d),next(NULL){}
};

//TODO:break cyclicll

//to check linkedlist is cyclic or not
bool isCyclicll(node* head){
    if(head==NULL){
        return false;
    }
    node* fast=head;
    node* slow=head;
    while(fast){
        fast=fast->next;
        if(fast!=NULL){
			fast = fast->next;
			slow = slow->next;
			if(fast == slow){
				return true;
			}
		}
    }
    return false;
}

//convert linkedlist to circular linkedlist
void cyclicll(node* &head, node* &tail){
//    node* temp=head;
//    while(temp->next!=NULL){
//        temp=temp->next;
//    }
//    temp->next=head;

//or

    tail->next=head;
}

//print linkedlist if its not circular
void printll(node* head){
    if(head==NULL){
        return;
    }
    node* temp=head;
    while(temp){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}

//insert data/values in linkedlist
void insertLL(node* &head,node* &tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=tail=temp;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node(data);
        tail=temp->next;
    }
}

//create linkedlist
void create(node* &head,node* &tail){
    cout<<"input data"<<endl;
    int data;
    cin>>data;
    while(data>0){
        insertLL(head,tail,data);
        cin>>data;
    }
}

//to break cyclic ll
void BreakCycle(node* head){
	node* fast = head;
	node* slow = head;
	while(fast){
		fast = fast->next->next;
		slow=slow->next;
		if(fast == slow){
			break;
		}
	}
	node* p = head;
	while(p->next!=fast){
		p = p->next;
	}

	slow = head;
	while(slow!=fast){
		p = fast;
		fast=fast->next;
		slow = slow->next;
	}
	p->next = NULL;
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    create(head,tail);
    cout<<endl;
    printll(head);
    cout<<endl;
    cyclicll(head,tail);
    if(isCyclicll(head)){
        cout<<"cyclic";
    }
    else{
        cout<<"not cyclic";
    }

}
