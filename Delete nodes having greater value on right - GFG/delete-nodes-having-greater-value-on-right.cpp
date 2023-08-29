//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
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



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    vector<int> ngr(vector<int>& arr){
        int n = arr.size();
        vector<int> ans;
        stack<int> s;
        for(int i = n-1; i >= 0; i--){
            if(s.size() == 0) ans.push_back(-1);
            else if(!s.empty() && s.top() > arr[i]) ans.push_back(s.top());
            else if(!s.empty() && s.top() <= arr[i]){
                while(!s.empty() && s.top() <= arr[i]){
                    s.pop();
                }
                if(s.empty()) ans.push_back(-1);
                else{
                    ans.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    Node *compute(Node *head)
    {
          Node* curr = head;
        vector<int> temp;
        while(curr){
            temp.push_back(curr->data);
            curr = curr->next;
        }
        
        vector<int> t1 = ngr(temp);
        
        Node* res = new Node(-1);
        Node* ans = res;
        vector<pair<int, int>> v;
        
        for(int i = 0; i < t1.size(); i++){
            v.push_back({t1[i], temp[i]});
        }
        
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == -1){
                Node* t2 = new Node(v[i].second);
                ans->next = t2;
                ans = t2;
            }
        }
        
        return res->next;
    }
    
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends