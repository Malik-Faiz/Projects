          //      Project: NotePad or Text Editor     //
          
		  
		  //            Group Members     //
          /*    1. Malik Faiz ur Rehman FA20 BCS 069
          		2.Hammad Ahmad   FA20 BCS 007    */
          		
          		

/* Project Discription:          		
		We use Single linked list
			   Stack
			   Double Linked List
			   BST
			   File Handling
		in our Project. */
		
		
		

#include<iostream>
#include <cstring>
#include <string>
#include<algorithm>
#include <sstream> 
#include <bits/stdc++.h>
using namespace std;

struct node{
	string data;
	char info;
	node *next;
}*front=NULL,*end=NULL;
struct node1{
int val;
node1 *left;
node1 *right;
}*root=NULL;
void filecreate();
void Dataappend();
void BST(int);
void inorder(node1*);
void Stringtointeger();
void insert(string);
void display();
void Undo(node *);
void del(string);
void addBegin(string);
void addafter(string,string);
void pushinstack();
void push(char);
void pop();
void Clear();
void redo();

struct node *start=NULL,*last=NULL,*start11=NULL,*qadd;
int main(){
	int a,choice;
	string s,ss;
	while(1){
		cout<<"1-Insert Data in NotePad"<<endl;
		cout<<"2-Display data in Notepad"<<endl;
		cout<<"3.Delete data from any position"<<endl;
		cout<<"4.Add data from Begining"<<endl;
		cout<<"5.Add After data in Notepad"<<endl;
		cout<<"6.Undo"<<endl;
		cout<<"7.Redo"<<endl;
		cout<<"8.Clear Notepad"<<endl;
		cout<<"9.If Notpad contain Number.Number Push in BST"<<endl;
		cout<<"10.Data in cpp Notpad....Save in Original Notepad"<<endl;
		cin>>choice;
		if(choice==1){
			cout<<"Enter Data in Notepad: "<<endl;
			while(1){
				cin>>s;
				if(s=="Sstop")
					break;
				insert(s);
			}
		}
		if(choice==2) {
			display() ;
		}
		if (choice==3){
			cout<<"Enter Data to delete from Notepad: "<<endl;
			cin>>s;
			del(s);
		}
		if (choice==4){
			cout<<"Enter data in begining: "<<endl;
			while(1){
				cin>>s;
				if(s=="Sstop"){
					last->next=front;
					front=start;
					start=NULL;
					last=NULL;
					break;
				}
				addBegin(s);
			}
			}
		if(choice==5){
			cout<<"After the word, the data is inserted: "<<endl;
			cin>>ss;
			cout<<"Enter data: "<<endl;
			while(1){
				cin>>s;
				if(s=="Sstop"){
					start=NULL;
					last=NULL;
					break;
				}
				addafter(s,ss);
				
			}
		}
		if(choice==6){
			Undo(end);
		}
		if(choice==7){
			redo();
		}
		if (choice==8){
			Clear();
		}	
		if(choice==9){
			Stringtointeger();
			inorder(root);
			cout<<endl;
		}
		if(choice==10){
			cout<<endl<<"a.Create File"<<endl;
			cout<<"b.Append Data in Existing File"<<endl;
			char aaa;
			cin>>aaa;
			if(aaa=='a'){
				filecreate();
			}
			else if(aaa=='b'){
				Dataappend();
			}
		}
	}
	
}

void insert(string data){
	struct node *tmp;
	tmp=new(struct node);
	tmp->data=data;
	tmp->next=NULL;
	if(front==NULL){
		front=tmp;
		end=tmp;
	}
	else{
		end->next=tmp;
		end=tmp;
	}
}

void display(){
	struct node *q;
	q=front;
	while(q!=NULL){
		cout<<q->data<<" ";
		q=q->next;
	}
	cout<<endl;
	
	
}

void del(string data)
{
	struct node *tmp,*q;
	if(front->data==data)
	{
		tmp=front;
		front=front->next;	/*first element deleted*/
		delete(tmp);
		return;
	}
	q=front;
	while(q->next->next!=NULL)
	{
		if(q->next->data==data)	       /*element deleted in between*/
		{
			tmp=q->next;
			q->next=tmp->next;
			delete(tmp);
			return;
		}
		q=q->next;
	}
	if(q->next->data==data)		/*last element deleted*/
	{
		tmp=q->next;
		delete(tmp);
		end=q;
		end->next=NULL;
		return;
	}

	cout<<"Element "<<data<<" not found"<<endl;
}

void addBegin(string data){
	struct node *tmp,q;
	tmp= new (struct node);
	tmp->data=data;
	tmp->next=NULL;
	if(start==NULL){
		start=tmp;
		last=tmp;
	}
	else{
		last->next=tmp;
		last=tmp;
	}
	
}

void addafter(string data,string pos)
{
	struct node *tmp,*q,*q1;
	q=front;
	while(q->data!=pos){
		q=q->next;
	}
	
	if(q->data!=pos) 
	{
		cout<<"ELement "<<pos<<"is Not present in Notepad.You choose Wrong word"<<endl;
	}
	tmp=new(struct node);
	tmp->data=data;
	tmp->next=NULL;
	if(start==NULL){
		start=tmp;
		qadd=q->next;
		last=tmp;
		}
		else{
			last->next=tmp;
			last=tmp;
		}
		last->next=qadd;
		q->next=start;
}

void Undo(struct node *q){
	string ss=q->data;
	for(int j=ss.length()-1;j>=0;j--){
		push(ss[j]);
		break;
	}
	
   q->data = ss.substr(0, ss.length()-1); 
    
}
void redo(){
	pop();
}
void Clear(){
	front=NULL;
	end=NULL;
}
//*******************Stack**************//

void push(char data)
{
	struct node *q,*tmp;
	tmp=new(struct node);
	tmp->info=data;
	tmp->next=NULL;

	if(start11==NULL)	  start11=tmp;	/*if list is empty*/
	else    	/*element inserted at end*/
	{
		tmp->next=start11;
		start11=tmp;
	}
}
void pop(){
	if(start11==NULL) return;
	string re=end->data;
	char aa=start11->info;
	re.push_back(aa);
	end->data=re;
	start11=start11->next;	
}
void BST(int data){
	struct node1 *tmp,*q;
	tmp=new(struct node1);
	tmp->val=data;
	tmp->left=NULL;
	tmp->right=NULL;
	if(root==NULL){
		root=tmp;
	}
	else if(tmp->val>root->val && root->right==NULL) {
			root->right=tmp;
		}
	else if(tmp->val<root->val && root->left==NULL) {
			root->left=tmp;
			}
	else if(tmp->val==root->val && root->right==NULL) {
			root->right=tmp;
		}
	else if(tmp->val==root->val && root->left==NULL) {
			root->left=tmp;
			}	
	else{
		if (tmp->val==root->val){
			q=root;
			while(q->right!=NULL){
			q=q->right;
			if(tmp->val>q->val){
				while(q->right!=NULL)
				q=q->right;
				q->right=tmp;
				}
			else if(tmp->val<q->val){
				while(q->left!=NULL)
				q=q->left;
				q->left=tmp;
				}	
			}	
		}
		else if(tmp->val>root->val){
			q=root;
			while(q->right!=NULL ){
			q=q->right;
			if(tmp->val>q->val){
				while(q->right!=NULL)
				q=q->right;
				q->right=tmp;
				}
			else if(tmp->val<q->val){
				while(q->left!=NULL)
				q=q->left;
				q->left=tmp;
				}	
			}	
		}
		
		else if(tmp->val<root->val){
			q=root;
			while(q->left!=NULL){
				q=q->left;
			if(tmp->val>q->val){
				while(q->right!=NULL)
				q=q->right;
				q->right=tmp;
				}
			else if(tmp->val<q->val){
				while(q->left!=NULL)
				q=q->left;
				q->left=tmp;
				}
			}	
		
		}
			
	}
}
void Stringtointeger(){
	struct node *q;
	q=front;
	while(q!=NULL){
		if(q->data>="-999" and q->data<="999"){
			stringstream ss;
			string str=q->data;
			int num ;
			ss << str;
			ss >> num;
			BST(num);
		}
		q=q->next;
	}	
	
}

void inorder(struct node1 *ptr){
	if(root==NULL){
		cout<<"Tree is empty"<<endl;
	}
	if(ptr!=NULL){
		inorder(ptr->left);
		cout<<ptr->val<<" ";
		inorder(ptr->right);
	}
}

void filecreate(){
	
  	fstream file;
    file.open("Project.txt",ios::out);
    if(!file)
    {
       cout<<"Error in creating file!!!"<<endl;
    }
  
    cout<<"File created successfully."<<endl;
}

void Dataappend(){
	struct node *q;
	q=front;
	string project="";
	while(q!=NULL){
		project=project+" "+q->data;
		q=q->next;
	}
    fstream f;
    ofstream fout;
    ifstream fin;
    fin.open("Project.txt");
    fout.open ("Project.txt",ios::app);
    if(fin.is_open())
      	fout<<project<<endl<<endl;
      	cout<<"\n Data has been appended to file"<<endl;
     	 fin.close();
      	fout.close();
      	string word;
      	f.open("Project.txt");
      	while (f >> word) {
        	 cout << word << " ";
		}
  		cout<<endl;
}
