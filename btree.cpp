#include <iostream.h>
#include <stdlib.h>

class BTNode							//class BTNode
{
public:										
	BTNode()							//constructor
	{
		elem=0;
		parent=0;
		left=0;
		right=0;
	}
	
	void setElement(int x)					//getter and setters
	{
		elem=x;
	}

	void setParent(BTNode* x)
	{
		parent=x;
	}

	void setLeft(BTNode* x)
	{
		left=x;
	}

	void setRight(BTNode* x)
	{
		right=x;
	}

	int getElement() 
	{
		return elem;
	}

	BTNode* getParent() 
	{
		return parent;
	}

	BTNode* getLeft() 
	{
		return left;
	}

	BTNode* getRight() 
	{
		return right;
	}



private:										//class variables
	int elem;
	BTNode* parent;
	BTNode* left;
	BTNode* right;




};
class  BinaryTREE								//Class Binary Tree
{
	BTNode *top;
	BTNode *temporary;


public:
								
	BinaryTREE()								//Constructor
	{
		top=0;
	}

	void insert (BTNode* );
	int get(BTNode* );
	void addLeaf(BTNode* ,int );
	void preorder_traversal();
	void deletenode(BTNode* );
	void preorder_traversal(BTNode* );
	void postorder_traversal();
	void postorder_traversal(BTNode* );
	void levelorder_traversal();
	int levelorder_traversal(BTNode* ,int ,int );

};
void BinaryTREE::insert (BTNode* node)
	{															//Insert to the tree
		BTNode* tmp;
		int k;
		temporary=top;
		if (top==0)
		{ 
			top=new BTNode();
			top->setElement(node->getElement());//If tree is empty
			top->setParent(0);
			top->setLeft(node->getLeft());
			top->setRight(node->getRight());
			temporary=top;
		}
		else
		{
			while (temporary!=0)
			{
				tmp=temporary;
				if (temporary->getElement() > node->getElement())
				{
					temporary=temporary->getLeft();//if tree is not empty
					k=0;
				}
				else 
				{
					temporary=temporary->getRight();
					k=1; 
				}
			}
			
			temporary=tmp;
			addLeaf(node,k);
		
		}
	}

int BinaryTREE::get(BTNode* node)									//return the element for the node
	{

		return node->getElement();
	}


void BinaryTREE::deletenode(BTNode* node)							//delete node
	{
	int k=0;
		if ((node->getRight()==0)&&(node->getLeft()==0))
		{
			k++;
			if (node->getParent()->getRight()==node)
			{
				node->getParent()->setRight(0);//if the node has no childs
			}
			else if (node->getParent()->getLeft()==node)
			{
				node->getParent()->setLeft(0);
			}
		}
		else if	((node->getRight()!=0) && (node->getLeft()==0))
		{
			k++;
			if (node->getParent()->getRight()==node) 
			{	
				node->getParent()->setRight(node->getRight());
				node->getRight()->setParent(node->getParent());
			}
			else if (node->getParent()->getLeft()==node) //if node has a right child and no left childs
			{	
				node->getParent()->setLeft(node->getRight());
				node->getRight()->setParent(node->getParent());
			}
		}
		else if ((node->getLeft()!=0) && (node->getRight()==0))
		{
			k++;
			if (node->getParent()->getRight()==node) 
			{	
				node->getParent()->setRight(node->getLeft());
				node->getLeft()->setParent(node->getParent());
			}
			else if (node->getParent()->getLeft()==node) //if node has a left child and no right childs
			{	
				node->getParent()->setLeft(node->getLeft());
				node->getLeft()->setParent(node->getParent());
			}
		} 
		if (k!=0)
		{
			delete node;
		}
	}

void BinaryTREE::addLeaf(BTNode* node,int kindofson)
	{																//insert leave
		if (kindofson==0) 
		{
			node->setParent(temporary);
			temporary->setLeft(node);
		
		}
		else
		{
			node->setParent(temporary);
			temporary->setRight(node);
		
		}


	}														//preorder
void BinaryTREE::preorder_traversal()
	{
		BTNode *tmp;
			tmp=top;
			if (top==0) 
				cout <<"empty tree !!!"<<endl;
			else
			{
				cout <<" "<<tmp->getElement();
				if (top->getLeft()!=0) 
					preorder_traversal(top->getLeft());				
				if (top->getRight()!=0) 
					preorder_traversal(top->getRight());				
					
			}
		cout<<endl;
	}

void BinaryTREE::preorder_traversal(BTNode* node)					
	{
	
			cout <<" "<<node->getElement();
			if (node->getLeft()!=0) 
			{
				preorder_traversal(node->getLeft());
			}
			if (node->getRight()!=0) 
			{
				preorder_traversal(node->getRight());
			}						
	}


void BinaryTREE::postorder_traversal()
	{															//postorder
		BTNode *tmp;
			tmp=top;
			if (top==0) 
				cout <<"empty tree !!!"<<endl;
			else
			{	
				if (top->getLeft()!=0) 
					postorder_traversal(top->getLeft());	
				if (top->getRight()!=0)
					postorder_traversal(top->getRight());
				cout <<" "<<top->getElement();

					
			
					
			}
		cout<<endl;
	}

void BinaryTREE::postorder_traversal(BTNode* node)
	{															
	
		int f=0;	
			
			if (node->getLeft()!=0) 
			{
				postorder_traversal(node->getLeft());
			}
			if (node->getRight()!=0) 
			{
				postorder_traversal(node->getRight());
			}
			cout <<" "<<node->getElement();	
	}

void BinaryTREE::levelorder_traversal()
	{
																	//level order
		int m=0;
		int f=1;
		cout<<" ";
		while (f==1)
		{
			f=levelorder_traversal(top,m,0);
			m++;
		}		
			
	}

int BinaryTREE::levelorder_traversal(BTNode* node,int m,int level)
	{
		int f=0;
		int k1=0,k2=0;
		if (level==m) 
		{
			cout<<node->getElement()<<" "; 
			return 1;
		}
		if (level<m) 
		{
			if (node->getLeft()!=0) 
			{
				f=levelorder_traversal(node->getLeft(),m,level+1);
				k1=f;
			}
			if (node->getRight()!=0)
			{
				f=levelorder_traversal(node->getRight(),m,level+1);
				k2=f;

			}
		}
		return (k1>k2?k1:k2);
	}

void main()
{
BinaryTREE tree=BinaryTREE();
BTNode *node=new BTNode();
int x;
for (int i=1;i<=20;i++)
{
	x=rand()%21;
	node->setElement(x);
	tree.insert(node);
	node=new BTNode();
	cout<< "insert element"<<x <<endl;
}


cout<<"preorder print:\n";
tree.preorder_traversal();
cout<<"postorder print:\n";
tree.postorder_traversal();
cout<<"levelorder print:\n";
tree.levelorder_traversal();

}




