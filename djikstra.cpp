#include<iostream>
#include<set>
#include<list>
#include<algorithm>
using namespace std;

typedef struct nodes {
   int dest;
   int cost;
}node;

class Graph {
   int n;
   list<node> *adjList;
   private:
      void showList(int src, list<node> lt) {
         list<node> :: iterator i;
         node tempNode;

         for(i = lt.begin(); i != lt.end(); i++) {
            tempNode = *i;
            cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<") ";
         }
         cout << endl;
      }
   public:
      Graph() {
         n = 0;
      }

      Graph(int nodeCount) {
         n = nodeCount;
         adjList = new list<node>[n];
      }

      void addEdge(int source, int dest, int cost) {
         node newNode;
         newNode.dest = dest;
         newNode.cost = cost;
         adjList[source].push_back(newNode);
      }

      void displayEdges() {
         for(int i = 0; i<n; i++) {
            list<node> tempList = adjList[i];
            showList(i, tempList);
         }
      }

      friend void dijkstra(Graph g, int *dist, int *prev, int start);
};

void dijkstra(Graph g, int *dist, int *prev, int start) {
   int n = g.n;

   for(int u = 0; u<n; u++) {
      dist[u] = INT8_MAX;   
      prev[u] = -1;    
   }

   dist[start] = 0;   
   set<int> S;       
   list<int> Q;

   for(int u = 0; u<n; u++) {
      Q.push_back(u); 
   }

   while(!Q.empty()) {
      list<int> :: iterator i;
      i = min_element(Q.begin(), Q.end());
      int u = *i; 
      Q.remove(u);
      S.insert(u);
      list<node> :: iterator it;

      for(it = g.adjList[u].begin(); it != g.adjList[u].end();it++) {
         if((dist[u]+(it->cost)) < dist[it->dest]) { 
            dist[it->dest] = (dist[u]+(it->cost));
            prev[it->dest] = u;
         }
      }
   }
}

main() {
    int n;
    printf("Enter number of edges in a graph: ");
    cin>>n;
    Graph g(n);
    int dist[n], prev[n];
    int start = 0;
    int option;
    while(true){
        printf("\nEnter 0 to break or 1 to add more edge\n");
        cin>>option;
        if(option==0) break;
        int start, destination, cost;
        printf("\nEnter starting point: ");
        cin>>start;
        printf("Enter destination point: ");
        cin>>destination;
        printf("Enter cost of travelling: ");
        cin>>cost;
        g.addEdge(start, destination, cost);
        printf("edge added\n\n");
        
    }
    
    dijkstra(g, dist, prev, start);
    printf("Distances from source to all other nodes are: \n");
    for(int i = 0; i<=n; i++)
        if(i != start)
            cout<<start<<" to "<<i<<", Cost: "<<dist[i]<<" Previous: "<<prev[i]<<endl;
}
