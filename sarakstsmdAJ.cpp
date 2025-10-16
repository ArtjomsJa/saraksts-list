#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
    {
    int data;
    Node *link;
    };

//--------------create node -----//
Node *CreateNode ()             
{
    Node *newNode; 
    newNode = new Node;            
    cout<<"\nIevadiet skaitli, kuru pievienot: ";
    cin>>newNode->data; 
    newNode->link=NULL; 
    return newNode; 
}

//-------izvadisana----//

void PrintList (Node *head)
{ 
    Node *cur;
    cout<<"Saraksta elementi:\n";
    cur=head; 
    while (cur!=NULL)
    {
    cout<<cur->data<<" ";  
    cur=cur->link; 
    }
}

//----------------pievienosana sakuma-------------//

Node *AddFirst(Node *head){
    Node *cur;
    cur=CreateNode();
    cur->link=head;
    head=cur;
    return head;
}

//----------------pievienosana beigas-------------//

Node *AddLast(Node *head){
    Node *cur, *newNode;
    newNode=CreateNode();
    if(head){
        cur=head;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=newNode;
}
    if(!head){head=newNode;}
    return head;
}

//-----------------meklesana-------------------//
Node *findNode(Node *head, int x){
    Node *cur;
    cur=head;
    while(cur && cur->data!=x){
        cur=cur->link;
    }
    return cur;
}

//----------------pēc norādītā mezgla-----------------//

void AddAfter(Node *head){
    Node *find, *newNode;
    int x;
    cout<<"\nIevadiet pēc kura skaitli pievienot jauno mezglu: ";cin>>x;
    find=findNode(head, x);

    if(find && find->data==x){
        newNode = CreateNode();
        newNode->link=find->link;  
        find->link=newNode;
    }
    else cout<<"\nŠāda elementa veida nav";
}

//-----------------meklesana prev-------------------//
Node *findPrev(Node *head, int x){
    Node *cur, *prev;
    cur=head;
    while(cur && cur->data!=x){
        prev=cur;
        cur=cur->link;
    }
    return prev;
}

//----------------pirms norādītā mezgla-----------------//
Node *AddBefore(Node *head){
    Node *find, *newNode, *prev;
    int x;
    cout<<"\nIevadiet pirms kura skaitli pievienot jauno mezglu: ";cin>>x;
    find=findNode(head, x);
    if(find && find->data==x){
    if(find==head) head=AddFirst(head);
    else{
        newNode=CreateNode();
        prev=findPrev(head, x);
        prev->link=newNode;
        newNode->link=find;
    }}
    else cout<<"\nŠāda elementa veida nav"; return head;
}

//---------------------delete sakuma---------------------//

Node *DeleteFirst(Node *head){
Node *save;

save=head->link;
delete head;
head=save;
return head;
}

//---------------------beigas---------------------//

Node *DeleteLast(Node *head){
Node *cur;

if (!head->link) {
    delete head; 
    return NULL;
}
cur=head;
while(cur->link->link){
    cur=cur->link;
}
delete cur->link;
cur->link = NULL;
return head;

}

//-------------------------delete pec---------------//

Node *DeleteAfter(Node *head){
    Node *cur, *find, *save;
    int x;
    cout<<"Norādiet, pēc kāda skaitļa izdzēst mezglu: ";cin>>x;
    find=findNode(head,x);
    if(!find) {cout<<"Jūsu sarakstā nav tada elementa";
    return head;}
    if(find->link==NULL){
        cout<<"Šis ir pēdējais elements sarakstā, nākamo nevar izdzēst.";
        return head;
    }
    save=find->link;
    find->link=find->link->link;
    delete save;
    cout<<"\nMezgls tika izdzēsts pēc norādītā mezgla\n";
    return head;

}

//-------------------------delete pirms---------------//

Node *DeleteBefore(Node *head){
    Node *cur, *prev, *prev2, *save;
    int x;
    cout<<"Norādiet, pirms kāda skaitļa izdzēst mezglu: ";cin>>x;

    if (!head) {
        cout << "Saraksts ir tukšs\n";
        return head;
    }

    if (head->data == x) {
        cout << "Nav mezgla pirms norādītā pirmā elementa.\n";
        return head;
    }

    prev2 = nullptr;
    prev = nullptr;
    cur = head;

    while (cur && cur->data != x) {
        prev2 = prev;   
        prev = cur;     
        cur = cur->link;
    }

    if (!cur) {
        cout << "Jūsu sarakstā nav tāda elementa\n";
        return head;
    }

    if (!prev2) {
        save = head->link;
        delete head;
        return save;
    }

    // vienkarsi
    prev2->link = cur;  // -prev
    delete prev;
    
    return head;
}

//==================elementu sk=================//

int skaits(Node *head){
    int skaits=0;
    Node *cur;
    cur=head;
    if(!head) return 0;
    while(cur!=NULL){
        skaits++;
        cur=cur->link;
    }
    return skaits;
}

//===================dzesana visur===============//

Node* DeleteAll(Node* head) {
    Node *cur, *save;
    cur = head;

    if (!head) {
        cout << "Saraksts jau ir tukšs.\n";
        return NULL;
    }

    while (cur != NULL) {
        save = cur;
        cur = cur->link;
        delete save;
    }

    cout << "Visa saraksta elementi tika izdzēsti.\n";
    return NULL;
}

int main(){
Node *head=NULL, *cur;
int izvele, n;

do
{  //system("cls");
    cout<<"\nArtjoms Jaloveckis\n";
    cout<<"==============================================";
    cout<<"\n1.Pievienot Head";
    cout<<"\n2.Pievienot mezglu sakumā";
    cout<<"\n3.Pievienot mezglu beigās";
    cout<<"\n4.Pievienot mezglu pēc norādītā mezgla";
    cout<<"\n5.Pievienot mezglu pirms norādītā mezgla";
    cout<<"\n6.Dzēst mezglu no sakuma";
    cout<<"\n7.Dzēst mezglu no gala";
    cout<<"\n8.Dzēst mezglu pēc norādītā mezgla";
    cout<<"\n9.Dzēst mezglu pirms norādītā mezgla";
    cout<<"\n10.Saraksta elementu skaita noteikšana.";
    cout<<"\n11.Visa saraksta dzēšana";
    cout<<"\n12.Parādīt sarakstu";
    cout<<"\n0.Iziet\n";
    cout<<"==============================================";
    cout<<"\nIzvēle: ";
    cin>>izvele;
    

    switch(izvele)
    {
        case 1: if(!head) head=CreateNode();
        else cout<<"\nJums jau ir 'head'";
        /*system("pause>nul");*/ break;

        case 2: head=AddFirst(head);
        cout<<"\nSakumā tiek pievienots mezgls";break;
        //system("pause>nul"); break;

        case 3: head=AddLast(head);
        cout<<"\nBeigās tiek pievienots mezgls";break;
        //system("pause>nul"); break;

        case 4: AddAfter(head);break;
        //system("pause>nul"); break;

        case 5: head=AddBefore(head);break;
        //system("pause>nul"); break;

        case 6: if(!head){cout<<"Jūsu sarakstā nav elementu";}
        else{
            head=DeleteFirst(head);
            cout<<"\nMezgls tika izdzēsts no sakuma";}
        break;
        //system("pause>nul"); break;

        case 7:if(!head){cout<<"Jūsu sarakstā nav elementu";}
        else{ 
            head=DeleteLast(head);
            cout<<"\nMezgls tika izdzēsts no gala";}
        break;
        //system("pause>nul"); break;

        case 8:
            head=DeleteAfter(head);break;
        //system("pause>nul"); break;

        case 9: 
            head=DeleteBefore(head);break;
        //system("pause>nul"); break;

        case 10: n=skaits(head);
        cout<<"\nSarakstā ir "<<n<<" elementi";
        break;
        //system("pause>nul"); break;

        case 11:
        if (!head) cout << "\nSaraksts ir tukšs. Nav ko dzēst.";
        else head = DeleteAll(head);
        break;

        case 0: cout<<"\nExit";
        system("pause>nul"); break;

        case 12: PrintList(head);
        /*system("pause>nul");*/ break;

        default: cout<<"\nNepareiza izvēle";
        system("pause>nul");
    }
}
while(izvele!=0);

system("pause>nul");
return 0;   

}