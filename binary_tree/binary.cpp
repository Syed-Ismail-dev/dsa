#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class binary{
    private:

    int i;
    public:
    binary( ){

        i = -1;
    }
    node* create(const vector<int>vec){
        i++;
        if (i >= vec.size() || vec[i] == -1)
        {
            return nullptr;
        }
        node* temp = new node(vec[i]);
        temp->left = create( vec);
        temp->right = create( vec);
        return temp;
    }

    void preorder(node* head){
        if (head== nullptr)
        {
            return;
        }
        cout<<head->data<<" " ;
        preorder(head->left);
        preorder(head->right);

    }
    void inorder(node* head){
        if (head== nullptr)
        {
            return;
        }
        inorder(head->left);
        cout<<head->data<<" " ;
      
        inorder(head->right);

    }
    void postorder(node* head){
        if (head== nullptr)
        {
            return;
        }
        postorder(head->left);
        
      
        postorder(head->right);
        cout << head->data << " ";
    }
    void levelorder(node* head){
        queue<node*>q;
        q.push(head);
        while (q.size() > 0)
        {
            node* curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
            
        }
        cout<<endl;
    }
};

int main(){
    vector<int>preserie = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
        binary test;
        node* root = test.create(preserie);
        cout<<"preorder:";
        test.preorder(root);
        cout<<endl;
        cout<<"inorder:";
        test.inorder(root);
        cout<<endl;
        cout<<"postorder:";
        test.postorder(root);
        cout<<endl;
        cout<<"levelorder:";
        test.levelorder(root);
        cout<<endl;


    return 0;
}