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


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        vector<int>ans;
    Node *curr=head;
    while(curr!=NULL)
    {
        ans.push_back(curr->data);
        curr=curr->next;
    }
   int start=0,end=k-1;
        while(start<end)
        {
            swap(ans[start],ans[end]);
            start++;
            end--;
        }
        start=k,end=ans.size()-1;
        while(start<end)
        {
            swap(ans[start],ans[end]);
            start++;
            end--;
        }
       int i=0,j=ans.size()-1;
       while(i<j)
       {
           swap(ans[i],ans[j]);
           i++;
           j--;
       }
        
        
    int size=ans.size();
    Node *root=new Node(ans[0]);
    Node *p=root;
    for(int i=1;i<size;i++)
    {
        Node *n=new Node(ans[i]);
        p->next=n;
        p=n;
    }
    return root;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends