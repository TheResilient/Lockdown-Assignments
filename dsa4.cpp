#include<iostream>
using namespace std;

struct  queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct  queue *q)
{
    if(q->r==q->size-1) return 1;
    return 0;
}

int isEmpty(struct  queue *q)
{
    if(q->r==q->f) return 1;
    return 0;
}



void enqueue(struct queue *q, int val){
    if(!isFull(q)){
        q->r++;
        q->arr[q->r]=val;
    }
    else{printf("Queue is full");}
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is empty. ");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    printf("Enter size of Queue\n");
    int s;
    cin>>s;
    q.size=s;
    q.f=q.r=-1;
    q.arr=new (int);
    int n;
    int len=0;
    while(n!=0){
        
        printf("1.For enqueue\n2.For dequeue\n3.To quit\n");
        cin>>n;
        if(n==1){
            if(isFull(&q)==1){
                printf("queue is full!\n");
                
            }
            else{
                int m;
                printf("Enter value to be enqueued:\n");
                cin>>m;
                enqueue(&q, m);
                len++;
            }
        }
        else if(n==2){
            if(isEmpty(&q)==1){
                printf("queue is empty!\n");
                
            }
            else{
                printf("Dequeued queue\n");
                dequeue(&q);
                len--;
            }
        }
        else break;
    }
        
    int i=0;
    cout<<"Resulted queue is: ";
    if(len>0 && len<=q.size){
        while(i<len){
            cout<<" "<<q.arr[i]<<", ";
            i++;
        }
    }
    else{printf("empty");}
    return 0;
}


// if(isFull(&q)==1) {
//             printf("Queue is full!");
//             break;
//         }
// else if(isEmpty(&q)==1){
//             printf("Queue is Empty!");
//             break;
//         }

//===============================================================================================
