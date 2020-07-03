#include<bits/stdc++.h>
using namespace std;

//linkedlist node
class node{
public:
    int data;
    node* next;
    node(int d):data(d),next(NULL){}
};

//lenght of LL
int Lenghtll(node* head){
    if(head==NULL){
        return 0;
    }
    int lenght=0;
    node* temp=head;
    while(temp){
        temp=temp->next;
        lenght++;
    }
    return lenght;
}

//delete at end
void DeleteEnd(node* &head, node* &tail){
    if(head==NULL){
        return;
    }
    else if(head->next==NULL){
        delete head;
        head=tail=NULL;
    }
    else{
        node* temp= head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp=NULL;
        delete tail;
        tail=temp;
    }
}


//delete at front
void DeleteFront(node* &head,node* &tail){
    if(head==NULL){
        return;
    }
    else if(head->next==NULL){
        delete head;
        head=tail=NULL;
    }
    else{
        node* temp=head;
        head=head->next;
        delete temp;
    }
}

//delete from givven position
void DeleteMid(node* &head, node* tail, int pos){
    if(pos==0){
        DeleteFront(head,tail);
        return;
    }else if(pos>=Lenghtll(head)){
        DeleteEnd(head,tail);
        return;
    }
    else{
        int jump=1;
        node* temp=head;
        while(jump<=pos-1){
            temp=temp->next;
            jump++;
        }
        node* temp1=temp->next;
        temp->next=temp->next->next;
        delete temp1;
    }
}




//to find mid of Linklist
node* FindMid(node* head){
    if(head==NULL){
        return NULL;
    }
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


//print Linklist
void printLL(node* head){
    if(head==NULL){
        cout<<"END";
        return;
    }
    cout<<head->data<<"-->";
    printLL(head->next);
}

//insert at front
void InsertFront(node* &head,node* &tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=tail=temp;
    }else{
        node* temp=new node(data);
        temp->next=head;
        head=temp;
    }
}

//insert at end of linkedlist
void InsertEnd(node* &head,node* &tail,int data){
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

//to insert at any position of linkedlist
void InsertMid(node* &head,node* &tail,int pos,int data){
    if(pos==0){
        InsertFront(head,tail,data);
    }
    else if(pos>=Lenghtll(head)){
        InsertEnd(head,tail,data);
    }
    else{
        int jump=1;
        node* temp=head;
        while(jump<=pos-1){
            temp=temp->next;
            jump++;
        }
        //like A-->B-->C-->D-->NULL
        //want to put new node F btw B & C
        //Ex- A-->B-->F-->C-->D-->NULL
        //so point F-->next=B-->next(and B-->next==C)
        //And B-->next should point F. So, B-->next=F;
        node* Cache=new node(data);
        Cache->next=temp->next;
        temp->next=Cache;
    }
}

//insert at front
void Insert(node* &head,node* &tail,int data){
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

//call insert funtion to create linkedlist
node* Create(node* &head, node* &tail){
    int data;
    cout<<"input data"<<endl;
    cin>>data;
    while(data>0){
        Insert(head,tail,data);
        cin>>data;
    }
}

node* searchKey(node* head,int key){
    if(head==NULL){
        return NULL;
    }
    node* temp=head;
    while(temp){
        if(temp->data==key){
            return temp;
        }
        else{
            temp=temp->next;
        }
    }
    return NULL;
}

int main(){
    //linkedlist head and tail
    node* head=NULL;
    node* tail=NULL;

    Create(head,tail);
//    InsertFront(head,tail,data);
//    InsertEnd(head,tail,data);
//    InsertMid(head,tail,3,100);
    printLL(head);
    cout<<endl;
    node* middle=FindMid(head);cout<<"middle value "<<middle->data;
    node* temp=searchKey(head,5);
    if(temp){
        cout<<endl<<"found"<<temp->data;
    }


}
