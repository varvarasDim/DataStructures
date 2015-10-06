#include <iostream.h>
#include <stdlib.h>
#define MAX 4
class TNode
{										//Class TNode
private:
	int element;			
	TNode* parent;
	TNode* child[MAX];
	
public:
	TNode()								//constructor
	{
		element=0;
		parent=0;
		for (int i=0;i<MAX;i++) 
			child[i]=0;
		
	}
	
	void setElement(int o)				//getters and setters
	{
		element=o;
	}

	void setParent(TNode* p)
	{
		parent=p;
	}

	void setChild(TNode* l,int i)
	{
		child[i]=l;
	}

	int getElement() 
	{
		return element;
	}

	TNode* getParent() 
	{
		return parent;
	}

	TNode* getChild(int i) 
	{
		return child[i];
	}

	


};

class  KTREE
{										//Class K-tree
	TNode *top;
	TNode *point;


public:

	KTREE()
	{
		top=0;
	}
	void insert (TNode* ,int );
	int get(TNode* );
	void addLeaf(TNode* node,int );
	void preorder_traversal();
	void preorder_traversal(TNode* );
	void postorder_traversal();
	void KTREE::postorder_traversal(TNode* );
	void KTREE::levelorder_traversal();
	int KTREE::levelorder_traversal(TNode* ,int ,int );

};
void KTREE::insert (TNode* node,int ch)
	{
		TNode* tmp;
														//insert to tree
		point=top;
		if (top==0)
		{ 
			top=new TNode();
			top->setElement(node->getElement());
			top->setParent(0);
			for (int i=0;i<MAX;i++)
				top->setChild(node->getChild(i),i);
			point=top;
		}
		else
		{
			while (point!=0)
			{
			tmp=point;
			point=point->getChild(ch);
			}
			
			point=tmp;
			addLeaf(node,ch);
		
		}
	}

int KTREE::get(TNode* node)
	{													//return element for node

		return node->getElement();
	}


	
void KTREE::addLeaf(TNode* node,int kindofson)
	{
			node->setParent(point);							//add leaf
			point->setChild(node,kindofson);
		
		

	}

void KTREE::preorder_traversal()
	{
		TNode *tmp;													//pre order
			tmp=top;
			if (top==0) 
				cout <<"empty tree !!!"<<endl;
			else
			{	
				cout <<tmp->getElement()<<" ";
				for (int i=0;i<MAX;i++)
					if (top->getChild(i)!=0) 
						preorder_traversal(top->getChild(i));				
			}
		cout<<endl;
	}

void KTREE::preorder_traversal(TNode* node)
	{
			cout <<" "<<node->getElement();
			for (int i=0;i<MAX;i++)
				if (node->getChild(i)!=0) 
				{
					cout <<" ";
					preorder_traversal(node->getChild(i));
				}
			
			
	}


void KTREE::postorder_traversal()
	{														//postorder

		TNode *tmp;
		tmp=top;
		int i;
			if (top==0) 
				cout <<"empty tree !!!"<<endl;
			else
			{	
				for (i=0;i<MAX;i++)
				{
					if (top->getChild(i)!=0) 
						postorder_traversal(top->getChild(i));

				}
					cout <<" "<<top->getElement();
			}
		cout<<endl;
	}

void KTREE::postorder_traversal(TNode* node)
	{
	
		int f=0;
			for (int i=0;i<MAX;i++)
				if (node->getChild(i)!=0) 
				{
					postorder_traversal(node->getChild(i));
				}
			cout <<" "<<node->getElement();
			
	}

void KTREE::levelorder_traversal()
	{
														//level order
		int m=0;
		int f=1;
			while (f==1)
			{
				f=levelorder_traversal(top,m,0);
				m++;
			}		
			
		cout<<endl;
	}

int KTREE::levelorder_traversal(TNode* node,int m,int level)
	{
		int f=0;
		int con=0;
		if (level==m)
		{
			cout<<node->getElement()<<" "; 
			return 1;
		}
		if (level<m) 
		{
			for (int i=0;i<MAX;i++)
			if (node->getChild(i)!=0) 
			{
				f=levelorder_traversal(node->getChild(i),m,level+1);
				if (f==1) 
					con=1;
			}
			
		}
		return (con==1?1:0);
	}



void main()
{
	KTREE tree=KTREE();
	TNode *node=new TNode();
	int x;
	for (int i=0;i<=15;i++)
	{
		x=rand()%21;
		node->setElement(x);
		tree.insert(node,(i-1)%MAX);
		node=new TNode();
		cout<< "insert element"<<x <<endl;
	}
	cout<<"preorder print:\n";
	tree.preorder_traversal();
	cout<<"postorder print:\n";
	tree.postorder_traversal();
	cout<<"levelorder print:\n";
	tree.levelorder_traversal();

}









