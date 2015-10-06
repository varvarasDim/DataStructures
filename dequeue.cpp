#include <iostream.h>
class dequeueNODE			//Class DequeueNODE
{
public:
	dequeueNODE(int x)		//Constructor
	{
		elem=x;
		previous=0;
		next=0;
	}

	void setx(int x)					//Getters and setters
	{
		elem=x;
	}

	int getx()
	{
		return elem;
	}

	void setNext(dequeueNODE *nd)
	{
		next=nd;
	}

	dequeueNODE* getNext()
	{
		return next;
	}

	void setPrevious(dequeueNODE *nd)
	{
		previous=nd;
	}

	dequeueNODE* getPrevious()
	{
		return previous;
	}

private:
	int elem;
	dequeueNODE *next;
	dequeueNODE *previous;


};

class dequeueLIST							//Class dequeueLIST
{
public:	
	dequeueLIST()							//constructor
	{
		head=0;
		tail=0;
	}
	~dequeueLIST()							//delete list
	{
		int k=0;
		while (tail!=0)
		{
			k=eject();
		//	cout<<k<<endl;
		}
		
		cout<<"@@ List Deleted @@"<<endl;

	}

	void inject(int x)							//Inject at the back of the dequeue
	{
		dequeueNODE *tmp;
		tmp=tail;
		tail=new dequeueNODE(x);
		if (head==0) 
		{
			head=tail;
		}
		else
		{
			tmp->setNext(tail);
			tail->setPrevious(tmp);
		}
	}

	int pop()									//pop from the front of the dequeue
		{
			int elem = head->getx(); 
			dequeueNODE *tmp = head->getNext();
			if(head == tail)
			{ 
				head = 0;
				tail = 0;
			}
			else
			{
				tmp->setPrevious(0); 
				delete head;
				head = tmp;
			}
			return elem;
		}


	int eject()									//eject from the back of the dequeue
	{
		dequeueNODE *tmp;
		int elem=0;
		if (tail!=0) 
			elem=tail->getx();
		if (tail==head)
		{
			if (tail!=0) 
			{    
				delete tail;
				tail=0;
				head=0;
			}
			else 
			{
				cout << "list is empty " <<endl;
			}

		}
		else
		{
			tmp=tail->getPrevious();
			delete tail;
			tail=tmp;
		}
		return elem;
	}


	void push(int x)									//push from the front of the dequeue
		{
			dequeueNODE *tmp = new dequeueNODE(x);
			if(head == 0)
			{
				head = tmp; 
				tail =tmp;
			}
			else
			{
				head->setPrevious(tmp);
				tmp->setNext(head);
				head = tmp;
			}
		}




	int first()												//return the first integer of the dequeue - head
	{
		int elem=0;
		if (head==0) {
			cout<< "list is empty "<<endl;
		}
		else
		{
			elem=head->getx();
		}

	return elem;
	}

	int last()												//return the last integer of the dequeue - tail
	{
		int elem=0;
		if (tail==0)
		{
			cout<< "list is empty "<<endl;
		}
		else
		{
			elem=tail->getx();
		}
	
	return elem;
	}
	
	
	void printlist()										//print all items
	{
		dequeueNODE *nd;
		nd=head;
			if (head==0) 
			{ 
				cout << "list is empty "<<endl;
			}
			else 
			{ 
				do {
					cout <<" element=" <<nd->getx() <<endl;
					nd=nd->getNext();
				} while (nd!=tail->getNext());
			}
	}

private:												//vars head and tail
	dequeueNODE *head;	
	dequeueNODE *tail;


};


void main()
{
	dequeueLIST list=dequeueLIST();
	int i;
	cout <<"test\n";
	for (i=1;i<5;i++) 
	{
		list.inject(i*2);
	}

	list.printlist();

	list.push(10);
	list.push(11);
	cout <<endl;
	list.printlist();
	cout <<"_______________" <<endl;
	cout<< "pop element:" <<list.pop() <<endl;
	cout<< "pop element:" <<list.pop() <<endl;
	list.printlist();
	cout <<"_______________" <<endl;
	for (i=1;i<4;i++){
	cout <<"eject element :" <<list.eject()<<endl;
	cout <<" first="<<list.first()<<" last="<<list.last()<<endl;
	cout <<"_______________"<<endl;
	list.printlist();
	}


}