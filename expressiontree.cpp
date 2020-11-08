#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class expression_tree{
    public:
    expression_tree *right;
    expression_tree *left;
    char data;
    bool visited;
};

class construction{
    public:

    // char pf[100];
    int top=-1;
    expression_tree* b[100];

    int r(char inputch) {
        if (inputch == '+' || inputch == '-' || inputch == '*' || inputch== '/')
            return (-1);
        else if (inputch >= 'A' || inputch <= 'Z')
            return (1);
        else if (inputch >= 'a' || inputch <= 'z')
            return (1);
        else
            return (-100);
    }

    void push(expression_tree *tree) {
        top++;
        b[top] = tree;
    }

    expression_tree *pop() {
        top--;
        return (b[top + 1]);
    }

    expression_tree* add_postfix_expression(expression_tree* p, char* a){
        char s;
        s=a[0];
        expression_tree *p1, *p2;
        int flag;
        for(int i=1; s!=0; i++){
            flag=r(s);
            if(flag==1){
                p= new expression_tree;
                p->data=s;
                p->left=NULL;
                p->right=NULL;
                push(p);
            }
            else{
                p1=pop();
                p2=pop();
                p=new expression_tree;
                p->data=s;
                p->left=p2;
                p->right=p1;
                push(p);
            }
            s=a[i];
        }
        return p;
    }


    char* add_prefix_expression(expression_tree** p, char* a){
        if(*a=='0') return NULL;
        while(true){
            char* q= NULL;
            if(*p== NULL){
                expression_tree *nn= new expression_tree();
                nn->data=*a;
                nn->left=NULL;
                nn->right=NULL;
                *p=nn;
            }
            else{
                if(*a>= 'a' && *a<='z') return a;
                q=add_prefix_expression(&(*p)->left, a+1);
                q=add_prefix_expression(&(*p)->right,q+1);
                return q;
                
            }
        }
    }
    
    
    void inorder(expression_tree* p){
        if(p==NULL) return;
        else {
            inorder(p->left);
            printf("%c ", p->data);
            inorder(p->right);
        }
    }

    void nonrecursive_inorder(expression_tree* root){
        stack<expression_tree*>s;
        expression_tree* current= root;
        while(current!=NULL || s.empty()==false){
            while(current!=NULL){
                s.push(current);
                current=current->left;
            }
            current=s.top();
            s.pop();
            printf("%c ", current->data);
            current=current->right;
        }
    }

    void nonrecursive_preorder(expression_tree* root){
            stack<expression_tree*>s;
            expression_tree* current= root;
            while(current!=NULL || s.empty()==false){
                while(current!=NULL){
                    printf("%c ", current->data);
                    s.push(current);
                    current=current->left;
                }
                current=s.top();
                s.pop();
                current=current->right;
            }
        }

    void nonrecursive_postorder(expression_tree* root) {
		expression_tree* temp= root;
        while (temp && temp->visited == false)
        {
            if (temp->left && temp->left->visited == false) 
            temp = temp->left; 
            else if (temp->right && temp->right->visited == false) 
                temp = temp->right; 
            else { 
                printf("%c ", temp->data); 
                temp->visited = true; 
                temp = root; 
            } 
        }
        
	}
        

    

    void postorder(expression_tree* p){
        if(p==NULL) return;
        else{
            postorder(p->left);
            postorder(p->right);
            printf("%c ", p->data);
        }
    }
    void preorder(expression_tree* p){
        if(p==NULL) return;
        else{
            printf("%c ", p->data);
            preorder(p->left);
            preorder(p->right);
        }
    }


};

int main() {
    construction obj;
    
    expression_tree* s= NULL;
    
    char a[]="*+ab-cd";
    obj.add_prefix_expression(&s,a);

    obj.nonrecursive_inorder(s);
    cout<<endl;
    obj.nonrecursive_postorder(s);
    cout<<endl;
    obj.nonrecursive_preorder(s);
    
    cout<<endl;
    cout<<endl;
    construction obj1;
    expression_tree* s1=NULL;
    char a1[]="abc*+d+";
    s1=obj1.add_postfix_expression(s1, a1);
    obj1.inorder(s1);
    cout<<endl;
    obj1.postorder(s1);
    cout<<endl;
    obj1.preorder(s1);
    return 0;
}