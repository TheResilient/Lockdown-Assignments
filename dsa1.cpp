#include<iostream>

using namespace std;

class Node {
  public:
    int key;
    int data;
    Node *next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class SinglyLinkedList {
  public:
    Node *head;

  SinglyLinkedList() {
    head = NULL;
  }
  SinglyLinkedList(Node *n) {
    head = n;
  }

  Node *nodeExists(int k) {
    Node *temp = NULL;
    Node *ptr = head;
    while (ptr != NULL) {
      if (ptr->key == k) {
        temp = ptr;
      }
      ptr= ptr->next;

    }
    return temp;
  }

  void Add_at_end_Node(Node *n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended" << endl;
      } else {
        Node *ptr = head;
        while (ptr->next != NULL) {
          ptr = ptr -> next;
        }
        ptr->next = n;
        cout << "Node Appended" << endl;
      }
    }

  }

  void Add_at_begin_Node(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
    } else {
      n -> next = head;
      head = n;
      cout << "Node Prepended" << endl;
    }
  }

  void insert_Node_After(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {
      if (nodeExists(n -> key) != NULL) {
        cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
      } else {
        n -> next = ptr -> next;
        ptr -> next = n;
        cout << "Node Inserted" << endl;
      }
    }
  }

  void firstDelete() {
    struct Node *delptr1;
    if(head == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        delptr1 = head;
        head = head->next;
        free(delptr1);
    }
  }

  void lastDelete(){
    struct Node *delLast2, *preNode;
    if(head == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        delLast2 = head;
        preNode = head;

        while(delLast2->next != NULL)
        {
            preNode = delLast2;
            delLast2 = delLast2->next;
        }
        if(delLast2 == head)
        {
            head = NULL;
        }
        else
        {
            preNode->next = NULL;
        }

        free(delLast2);
    }
  }


  void deleteNodeByKey(int k) {
    if (head == NULL) {
      cout << "Singly Linked List already Empty. Cant delete" << endl;
    }
    else if (head != NULL) {
      if (head->key == k) {
        head = head->next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      }
      else {
        Node *temp = NULL;
        Node *prevptr = head;
        Node *currentptr = head->next;
        while (currentptr != NULL) {
          if (currentptr->key == k) {
            temp = currentptr;
            currentptr = NULL;
          }
          else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        if (temp != NULL) {
          prevptr -> next = temp -> next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        }
        else {
          cout << "Node Doesn't exist with key value : " << k << endl;
        }
      }
    }
  }

   int search(int key)
   {
     Node* c=head;
      while(c!=NULL)
      {
          if(c->key==key)
          {
              return true;
          }
          c=c->next;
      }
      return false;
   }



  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List"<<endl;
    } else {
      cout << "Singly Linked List Values : "<<endl;
      Node * temp = head;

      while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
      }
      cout<< endl;
    }

  }

};

int main() {

SinglyLinkedList s;
int option;
int key1, k1, data1, k2;
do {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. firstDelete()" << endl;
    cout << "6. lastDelete()" << endl;
    cout << "7. Search()" << endl;
    cout << "8. print()" << endl;
    cout << endl;
    cout << "Enter here: ";
    cin >>option;
    Node * n1 = new Node();

    switch (option) {
    case 0:
      break;

    case 1:
      cout << "Append Node Operation" <<"\nEnter key & data of the Node to be Added at last" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.Add_at_end_Node(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation" <<"\nEnter key & data of the Node to be Added at start" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.Add_at_begin_Node(n1);
      break;

    case 3:
      cout << "Insert Node After Operation" <<"\nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insert_Node_After(k1, n1);
      break;

    case 4:
      cout << "Delete Node By Key Operation -"<< "\nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);
      break;

    case 5:
        s.firstDelete();
        cout << "First Node Deleted"<< endl;
        break;

    case 6:
        s.lastDelete();
        cout << "Last Node Deleted"<< endl;
        break;

    case 7:
        cout<<"Enter key that is to be searched: "<<endl;
        cin>>k2;
        if(s.search(k2)==true){
            cout<<"Found in list"<<endl;
        }
        else{
            cout<<"Not Found in list"<< endl;
        }
        break;

    case 8:
      s.printList();
      break;
    }

  } while (option != 0);

  return 0;
}

