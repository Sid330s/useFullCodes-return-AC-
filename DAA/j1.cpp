#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
Node *newNode(int data)
{
  Node *temp = new Node;
  temp->next = temp;
  temp->data = data;
}
int getPosition(int n)
{
	Node *head = newNode(1);
	Node *prev = head;
	for (int i = 2; i <= n; i++)
	{
		prev->next = newNode(i);
		prev = prev->next;
	}
	prev->next = head;
	Node *ptr1 = head, *ptr2 = head;
	while (ptr1->next != ptr1)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		ptr2->next = ptr1->next;
		free(ptr1);
		ptr1 = ptr2->next;
	}
	return ptr1->data;
}

int main()
{
	int t,n;
  cin>>t;
  while(t--){
    cout<<"Enter n: "<<endl;
    cin>>n;
    cout<<"Last Man: "<<getPosition(n)<<endl;
  }
	return 0;
}
