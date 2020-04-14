#include<bits/stdc++.h>
using namespace std;

//linklist node
class node{
public:
    int data;
    node* next;
    node(int d):data(d),next(NULL){}
};

void printLL(node* head){
    if(head==NULL){
        cout<<"END";
        return;
    }
    cout<<head->data<<"-->";
    printLL(head->next);
}

node* Insert(node* &head,node* &tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=tail=temp;
    }
    else{
        node* temp=new node(data);
        tail->next=temp;
        tail=temp;
    }
}

node* Create(node* &head, node* &tail){
    int data;
    cout<<"input data"<<endl;
    cin>>data;
    while(data>0){
        Insert(head,tail,data);
        cin>>data;
    }
//    return head;
    //cout<<head->data<<head->next->data;
}

int main(){
    //linklist head and tail
    node* head=NULL;
    node* tail=NULL;
    //function to create linklist
    head=Create(head,tail);
    printLL(head);
}
