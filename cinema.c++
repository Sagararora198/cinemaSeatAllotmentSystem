#include<bits/stdc++.h>
// #include<string.h>
using namespace std;
struct node
{
    int seatNo;
    int status;
    string name;
    struct node* prev;
    struct node* next;
};
struct node *temp,*tail,*head;

void create()
{
    int i = 1;
    temp = new node;
    temp->seatNo = 1;
    temp->status = 0;
    temp->name = "null";
    tail = head = temp;
    for (int i = 2; i <=70; i++)
    {
        node * new_node = new node;
        new_node->seatNo = i;
        new_node->status = 0;
        new_node->name = "null";
        tail->next=new_node;
        new_node->prev = tail;
        tail=new_node;
        tail->next=head;
        head->prev=tail;


        
    }
    
    
}








void seataval()
{
    
    temp = head;
    int count=0;
    while (temp->next!=head)
    {
        if (temp->seatNo/10==0)
        {
            cout<<"S0"<<temp->seatNo<<" :";
            
        }
        else
        {
            cout<<"S"<<temp->seatNo<<" :";
        }
        if (temp->status==0)
        {
            cout<<"|___|";
        }
        else
        {
            cout<<"|_B_|";
        }
        count++;
        if (count%7==0)
        {
            cout<<endl;
            
        }
        temp=temp->next;
        
        
        
    }
    cout<<"S"<<temp->seatNo<<" :";
    if (temp->status==0)
    {
        cout<<"|___|";

    }
    else{
        cout<<"|_B_|";
    }
    
    
}
void book()
{
    int x;
    string y;
    label:
        cout<<"\nEnter seat number to be booked\n";
        cin>>x;
        cout<<"Enter your name\n";
        cin>>y;
    if (x<1||x>70)
    {
        goto label;
    }
    temp = new node;
    temp = head;
    while (temp->seatNo!=x)
    {
        temp = temp->next;
    }
    if (temp->status==1)
    {
        cout<<"Seat is already booked by "<<temp->name<<".\n";
    }
    else
    {
        temp->status=1;
        temp->name = y;
        cout<<"Seat "<<x<<" Booked";
    }
    
    
        

}
void cancel()
{
    int x;
    string y;
    label1:
        cout<<"Enter seat number to cancel booking\n";
        cin>>x;
        cout<<"Enter your name to proceed\n";
        cin>>y;
    if (x<1||x>70)
    {
        cout<<"Enter correct seat number\n";
        goto label1;
    }
    temp = new node;
    temp = head;
    while (temp->seatNo!=x)
    {
        temp = temp->next;
    }
    if (temp->status==0)
    {
        cout<<"Seat is not booked yet\n";
    }
    else{
        if (temp->name==y)
        {
            temp->status=0;
            cout<<"Seat Cancelled\n";
        }
        else
        {
            cout<<"Wrong name is given seat cannot be cancelled\n";
        }
        
    }
    
        
}
int main()
{
    create();
    int choice;
    char conti;
    do
    {
        cout<<"Enter choice\n1. Check Availability\n2. Book seat\n3. Cancel seat"<<endl;
        cin>>choice;
        switch (choice)
        {
        case (1):
            seataval();
            break;
        
        case (2):
            book();
            break;
        case (3):
            cancel();
            break;    
        }
        cout<<"\npress 'Y' to continue and 'N' to exit: ";
        cin>>conti;
    } while (conti=='Y'||conti=='y');
    
}