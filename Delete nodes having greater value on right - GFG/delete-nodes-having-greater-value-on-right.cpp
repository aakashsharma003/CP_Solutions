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
    Node* reverseList(Node* &head){
        Node* prev = NULL;
        Node* cur = head;
         Node* Next = NULL;
        while(cur != NULL){
            Node* Next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = Next;
        }

       return prev;
    }

    Node *compute(Node *head)
    {
       head = reverseList(head); 
       
       Node* ptr = new Node(head->data);
       Node* cur = head;
       while(cur != NULL){
           if(cur->data >= ptr->data){
           ptr->next = cur;
           ptr = ptr->next;
           }
           cur = cur->next;
       }
       ptr->next = NULL;
      
       head = reverseList(head);
       return head;
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