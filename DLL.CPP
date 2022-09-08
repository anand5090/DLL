#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class DLL
{
    private:
    struct node
    {
    node *pre;
    int item;
    node *next;
    };
    node *start;
    public:
    DLL()
    {
        start=NULL;
    }
    void insertAtFirst(int data);
      void insertAtLast(int data);
      void insertAftervalue(int value, int data);
      void viewList();
      void deleteAtfirst();
      void deleteAtlast();
      void deleteNode(int value);
};
void DLL ::deleteNode(int value)
{
    
    node *t;
    t=start;
    while(t->item!=value)
    {
        t=t->next;
    }
   if(t!=NULL)
    {
        t->pre->next=t->next;
        t->next->pre=t->pre;
        delete t;
    }
    else
    {
        cout<<"Invalid value";
    }
}
void DLL ::deleteAtlast()
{
    node *t1,*t2;
    if(start==NULL)
    {
        cout<<"List is Empty";
    }
   // else if(start->next==NULL)
    //{
      //start=NULL;
     // delete start;
   // }
else
{
    t1=start;
    while(t1->next!=NULL)
    {
    t1=t1->next;
    }
    t2=t1->pre;
    t2->next=NULL;
    delete t1;
}
}
void DLL ::deleteAtfirst()
{
    node *t;
    if(start==NULL)
    {
    cout<<"List is empty";
    }
    else{
        t=start;
        start=start->next;
        start->pre=NULL;
        delete t;

    }
}
void DLL ::insertAtFirst(int data)
{
    node *n=new node;
    n->item=data;
    n->pre=NULL;
    n->next=start;
    if(start)
    start->pre=n;
    start=n;
}
void DLL ::insertAtLast(int data)
{
    node *t,*n;
    n=new node;
    n->item=data;
    n->next=NULL;
    t=start;
    while(t->next!=NULL)
    t=t->next;
    n->pre=t;
    t->next=n;

}
void DLL::insertAftervalue(int value,int data)
{
    node *t,*n;
    t=start;
    while(t)
    {
        if(t->item==value)
        break;
        t=t->next;
     }
     if(t!=NULL)
     {
        n=new node;
        n->item=data;
        n->pre=t;
        n->next=t->next;
        t->next->pre=n;
        t->next=n;
     }
     else
     {
        cout<<"Eithr list is empty or Value is Found";
     }
}
    void DLL ::viewList()
    {
        if(start==NULL)
        {
            cout<<"List is Empty";
        }
        else{
      node *t;
      t=start;
      while(t)
      {
        cout<<t->item<<"  ";
        t=t->next;
      }
    }
    }
int main()
{
   DLL l1;
    l1.insertAtFirst(20);
    l1.insertAtFirst(10);
    l1.insertAtFirst(40);
    l1.insertAtFirst(50);
    l1.insertAtLast(60);
    l1.insertAftervalue(40,100);
       //l1.deleteAtfirst();
     //  l1.deleteNode(40);
  //     l1.deleteAtlast();
    l1.viewList();
}
/*
cout<<"\n1 InsertAtFirst";
cout<<"\n2 InsertAtLast";
cout<<"\n3 deletAtFirst";
cout<<"\n4 deleteAtlast";
cout<<"\n5 InsertAfter";
cout<<"\n6 deleteNode";
cout<<"\n7 viewList";
cout<<"\n0 Exit";
int choice,item,data,value;
DLL list1;
do{
    cout<<"\nEnter Your choice";
    cin>>choice;
    switch (choice)
    {
    case 1: 
    cout<<"Enter Element";
    cin>>item;
    list1.insertAtFirst(item);
     break;
     case 2: 
    cout<<"Enter Element";
    cin>>item;
    list1.insertAtLast(item);
     break;
     case 3:
     list1.deleteAtfirst();
     break;
     case 4:
     list1.deleteAtlast();
     break;
     case 5: 
    cout<<"Enter  the  'Value'   After which    'data' is insert";
    cin>>value>>data;
    list1.insertAftervalue(value,data);
     break;
     case 6:
     cout<<"Enter the value to delete";
     cin>>value;
     list1.deleteNode(value);
     break;
     case 7:
     list1.viewList();
     break;
    }

}while(choice !=0);
}*/