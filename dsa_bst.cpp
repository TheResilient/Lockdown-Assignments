#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class bst{
    public:
    bst *right;
    bst *left;
    int data;
    bst(int value){
        data=value;
        left=right=NULL;
    }
};

class binarysearch {
    public:
    bst *insertion(bst *root, int data){
        if(root==NULL){
            return new bst(data);
        }
        if(data==root->data){
            return root;
        }
        if(data> root->data) root->right=insertion(root->right, data);
        else root->left=insertion(root->left, data);
        return root;
    }

    bst* search(bst * root, int data){
        
        if(root==NULL || root->data == data){
            return root;
        }
        if(data>root->data) return search(root->right, data);
        return search(root->left, data);
    }

    bst *minvaluenode(bst *root){
        bst* current = root;
        while(current->left!=NULL){
            current = current->left;
        }
        return current;
    }

    bst* deletenode(bst* root,int data){
        if(root==NULL) return root;
        if(data<root->data) deletenode(root->left, data);
        else if(data>root->data) deletenode(root->right, data);
        else{
            if(root->left==NULL){
                bst* temp= root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                bst* temp= root->left;
                free(root);
            }
            bst* temp=minvaluenode(root->right);
            root->data=temp->data;
            root->right= deletenode(root->right, temp->data);
        }
        return root;

    }

    int heightoftree(bst* root){
        if(root==NULL) return 0;
        int leftheight, rightheight;
        leftheight=heightoftree(root->left);
        rightheight=heightoftree(root->right);
        if(leftheight>rightheight) return (leftheight+1);
        else return(rightheight+1);
    }

    bst *mirror(bst *root){
        if(root==NULL) return root;
        else{
            bst* temp;
            mirror(root->left);
            mirror(root->right);
            temp=root->left;
            root->left=root->right;
            root->right=temp;
            return root;
        }
    }

    bst *copy(bst *root){
        if(root==NULL) return NULL;
        bst* temp=new bst(root->data);
        temp->left=copy(root->left);
        temp->right=copy(root->right);
        return temp;

    }

    void printleafnodes(bst* root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            printf("%d ",root->data);
            return;
        }
        if(root->left) printleafnodes(root->left);
        if(root->right) printleafnodes(root->right);
    }

    void printlevelorder(bst* root){
        if(root==NULL) return;
        queue<bst*>q;
        q.push(root);
        while(q.empty()==false){
            int nodecount=q.size();
            while(nodecount>0){
                bst* node= q.front();
                printf("%d ", node->data);
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                nodecount--;
            }
            cout<<endl;
        }
    }


    void inorder(bst* root){
        if(root!=NULL){
            inorder(root->left);
            printf("%d ", root->data);
            inorder(root->right);
        }
    }

    void nonrecursive_inorder(bst* root){
        stack<bst*>s;
        bst* current= root;
        while(current!=NULL || s.empty()==false){
            while(current!=NULL){
                s.push(current);
                current=current->left;
            }
            current=s.top();
            s.pop();
            printf("%d ", current->data);
            current=current->right;
        }
    }
};

int main() {
    binarysearch s;
    int option;
    int data;
    bst *root= NULL;    
    bst *root1= NULL;    
    bst *root2= NULL;    
    do {
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. insertion in bst:" << endl;
        cout << "2. search data is present or not: " << endl;
        cout << "3. inorder traversal " << endl;
        cout << "4. height of a tree" << endl;
        cout << "5. delete data for bst:" << endl;
        cout << "6. print inorder traversal of mirror of bst " << endl;
        cout << "7. print copy of bst" << endl;
        cout << "8. print leaf nodes" << endl;
        cout << "9. print non recursive inorder traversal" << endl;
        cout << "10. "<<endl;
        cout << "Enter here: ";
        cin >>option;
        

        switch (option) {
        case 0:
        break;

        case 1:
        printf("enter data to be inserted: ");
        cin>>data;
        root=s.insertion(root, data);
        break;

        case 2:
        cin>>data;
        if(s.search(root, data)) printf("data %d found !!\n", data);
        else printf("data %d not found in bst!!\n");
        break;

        case 3:
        printf("your inorder traversal of bst is: ");
        s.inorder(root);
        cout<<endl;
        break;

        case 4:
        printf("height of the bst is: ");
        printf("%d\n",s.heightoftree(root));
        break;

        case 5:
        printf("enter data to be deleted: ");
        cin>>data;
        root=s.deletenode(root, data);
        printf("%d deleted from bst!!\n");
        break;

        case 6:
        printf("mirror of bst is with inorder traversal is: ");
        root1=s.copy(root);
        s.inorder(s.mirror(root1));
        cout<<endl;
        break;

        case 7:
        printf("copy of bst with is inorder traversal is: ");
        root2=s.copy(root);
        s.inorder(root2);
        cout<<endl;
        break;

        case 8:
        printf("leaf nodes of bst are: ");
        s.printleafnodes(root);
        cout<<endl;
        break;
        
        case 9:
        printf("non recursive inorder traversal of bst: ");
        s.nonrecursive_inorder(root);
        cout<<endl;
        break;

        case 10:
        break;
        }

    } while (option != 0);
