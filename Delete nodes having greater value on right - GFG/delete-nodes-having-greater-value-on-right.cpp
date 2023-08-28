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
    Node *compute(Node *head)
    {
        stack<int>st;
        vector<int>vec;
        Node* temp=head;
        while(temp){
            vec.push_back(temp->data);
            temp=temp->next;
        }
        Node* dummy=new Node(0);
        Node* curr=dummy;
        int maxi=0;
        st.push(vec[vec.size()-1]);
        for(int i=vec.size()-2;i>=0;i--){
           if(st.top()<=vec[i]){
               st.push(vec[i]);
           }
        }
        while(!st.empty()){
            Node* newNode=new Node(st.top());
            st.pop();
            curr->next=newNode;
            curr=curr->next;
        }
        return dummy->next;
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