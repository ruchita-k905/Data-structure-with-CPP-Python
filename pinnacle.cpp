#include<iostream>
#include<string>
using namespace std;
class node
{
    public:
    string prn;
    string name;
    node *next;

    node(string gprn,string gname)
    {
        prn=gprn;
        name=gname;
        next=NULL;
    }

};

node *head=NULL;

void addpresident(string prn,string name)
{
    node *gnode=new node(prn,name);
    if (head==NULL)
    {
        head=gnode;
        gnode->next=NULL;

    }
}

void addsecretory(string prn,string name)
{
    node *gnode=new node(prn,name);
    if (head==NULL)
    {
        cout<<"President need to be added before secretory\n";
    }
    else{
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=gnode;
    }
}

void addm(string prn,string name)
{
    node *gnode=new node(prn,name);
    if(head==NULL)
    {
        cout<<"President need to be added before members"<<endl;
    }
    else{
        node *temp=head;
        gnode->next=temp->next;
        temp->next=gnode;
    }
}

void display(node *n)
{
    cout<<"List of members : "<<endl;
    node *t=n;
    while(t!=NULL)
    {
        cout<<t->prn<<"  "<<t->name<<endl;
        t=t->next;
    }
}
void count(node *n)
{
    int count=0;
    node *t=n;
    while(t!=NULL)
    {
        count=count+1;
        t=t->next;
    }
    cout<<"total members : "<<count<<endl;
}

int main()
{
    addpresident("111","president");
    cout<<"President added"<<endl;
    addm("101","m1"); addm("102","m2"); addm("103","m3");
    addsecretory("222","Secretory");
    cout<<"Secretory added\n";
    display(head);
    count(head);
    return 0;
}