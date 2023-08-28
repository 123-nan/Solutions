//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    vector<int>ans;
    Node *curr=head;
    while(curr!=NULL)
    {
        ans.push_back(curr->data);
        curr=curr->next;
    }
    set<int>s;
    for(auto it:ans)
    {
        s.insert(it);
    }
    vector<int>res(s.begin(),s.end());
    int size=res.size();
    Node *root=new Node(res[0]);
    Node *p=root;
    for(int i=1;i<size;i++)
    {
        Node *n=new Node(res[i]);
        p->next=n;
        p=n;
    }
    return root;
}