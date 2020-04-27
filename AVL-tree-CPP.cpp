#include<iostream>
//#include<stdlib.h>
using namespace std;
	
class node
{
	public: int data,h;
		node *left;
		node *right;

	
	node *insert(node *,int);
	node  *Delete(node *,int);
	void inorder(node *);
	void preorder(node *);
	int balance(node *);
	int height(node *);
	node *RR(node *);
	node *LL(node *);
	node *LR(node *);
	node *RL(node *);
};

node *root=NULL;

int main()
{
	int z,ch,num,s,i;
	node *o;
	do
	{
	
		cout<<"Enter your Choice:";
		cout<<"\n1.Insert\n2.Delete\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter the number of Elements:";
				cin>>s;
				for(i=0;i<s;i++)
				{
					cout<<"Enter the Number:";
					cin>>num;
					root=o->insert(root,num);
				}
				o->inorder(root);
				cout<<endl;
				o->preorder(root);
				break;
			case 2: cout<<"Enter the Number";
				cin>>num;
				root=o->Delete(root,num);
				cout<<endl;
				o->inorder(root);
				cout<<endl;
				o->preorder(root);
				break;
			
			default:cout<<"Invalid Option!!!";
		}
		cout<<"\nEnter 1 to continue:";
		cin>>z;
	}while(z==1);
	return 0;
}

node * node::insert(node *root,int num)
{
	int b;
	if(root==NULL)
	{
		node *pnew=new node();
		pnew->data=num;
		pnew->left=pnew->right=NULL;
		pnew->h=1;	
		root=pnew;
		return pnew;
	}
	if(num < root->data)
		root->left=insert(root->left,num);
	else if(num > root->data)
		root->right=insert(root->right,num);
	
	root->h=( height(root->left) > height(root->right)?height(root->left):height(root->right))+1;
	b=balance(root);
	//cout<<root->data<<"  b="<<b<<endl;	
	
	if(b < -1 && root->right->data < num)
		root=RR(root);

	if(b > 1 && root->left->data > num)
		root=LL(root);

	if(b > 1 && root->left->data < num)
		root=LR(root);

	if(b < -1 && root->right->data > num)
		root=RL(root);

	return root;
}

void node::inorder(node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int node::balance(node *node)		
{
	int b;
	if(node==NULL)
		return 0;
	b=height(node->left) - height(node->right);
	return b;
}

int node::height(node *node)
{
	if(node==NULL)
		return 0;
	return node->h;
}

node * node::RR(node *x)
{
	cout<<"RR\n";
	node *t;
	t=x->right;
	x->right=t->left;
	t->left=x;
	x->h=( height(x->left) > height(x->right)?height(x->left):height(x->right))+1;
	t->h=( height(t->left) > height(t->right)?height(t->left):height(t->right))+1;
	return t;
}

node *node::LL(node *x)
{
	cout<<"LL\n";
	node *t;
	t=x->left;
	x->left=t->right;
	t->right=x;
	x->h=( height(x->left) > height(x->right)?height(x->left):height(x->right))+1;
	t->h=( height(t->left) > height(t->right)?height(t->left):height(t->right))+1;
		
	return t;
}

node *node::LR(node *x)
{
	cout<<"LR\n";
	node *t,*p;
	t=x->left;
	p=t->right;
	x->left=p->right;
	p->right=x;
	t->right=p->left;
	p->left=t;
	t->h=( height(t->left) > height(t->right)?height(t->left):height(t->right))+1;
	x->h=( height(x->left) > height(x->right)?height(x->left):height(x->right))+1;
	p->h=( height(p->left) > height(p->right)?height(p->left):height(p->right))+1;
	
	return p;
}

node *node::RL(node *x)
{
	cout<<"RL\n";
	node *t,*p;
	t=x->right;
	p=t->left;
	x->right=p->left;
	p->left=x;
	t->left=p->right;
	p->right=t;
	t->h=( height(t->left) > height(t->right)?height(t->left):height(t->right))+1;
	x->h=( height(x->left) > height(x->right)?height(x->left):height(x->right))+1;
	p->h=( height(p->left) > height(p->right)?height(p->left):height(p->right))+1;
	
	return p;
	
}
void node::preorder(node *root)
{
	if(root==NULL)
		return;
	else
	{
		cout<<root->data<<" ";
		preorder(root->left);
		
		preorder(root->right);
	}
}

node * node::Delete(node *root, int num)
{

	if(root==NULL)
		return NULL;
	if(root->data > num)
		root->left=Delete(root->left,num);
	else if(root->data <num)
		root->right=Delete(root->right,num);
	//cout<<"dfat  "<<root->data;
	if(root->data==num)
	{
		node *temp,*tp;
		if( root->left==NULL || root->right==NULL)
		{
			
			temp=root->left!=NULL?root->left:root->right;		
			return temp;
		}
		else
		{
			temp=root->left;
			tp=temp;
			if(temp->right!=NULL)
			{
				while(temp->right!=NULL)
				{
					tp=temp;
					temp=temp->right;
				}
				root->data=temp->data;
				tp->right=temp->left;
			}
			else
			{
				root->data=temp->data;
				root->left=temp->left;
			}
			//return root;
		}
	}
	root->h=root->h-1;
	cout<<root->data<<" h--> "<<root->h<<" ";
	
	int b;
	b=balance(root);
	cout<<root->data<<" b--> "<<b<<endl;

	if(b < -1 && balance(root->right) <= 0)
		root=RR(root);

	if(b > 1 && balance(root->left) >=0)
		root=LL(root);

	if(b > 1 && balance(root->left) < 0)
		root=LR(root);

	if(b < -1 && balance(root->right) > 0)
		root=RL(root);

	return root;
}
