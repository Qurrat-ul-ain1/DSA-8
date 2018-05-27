#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include<iostream>
#include<iomanip>
using namespace std;
class Graph {
private:
      bool** adjMatrix;
      int numVertices;
public:
      Graph(int numVertices) {
            this->numVertices = numVertices;
            adjMatrix = new bool*[numVertices];
            for (int i = 0; i < numVertices; i++) {
                  adjMatrix[i] = new bool[numVertices];
                  for (int j = 0; j < numVertices; j++)
                        adjMatrix[i][j] = false;
          }
    }
 
      void addEdge(int i, int j) {
                  adjMatrix[i][j] = true;
                  adjMatrix[j][i] = true;
    }
 
      void removeEdge(int i, int j) {
                  adjMatrix[i][j] = false;
                  adjMatrix[j][i] = false;
    }
 
      bool isEdge(int i, int j) {
                  return adjMatrix[i][j];
    }

    void toString() {
      for (int i = 0; i < numVertices; i++) {
                  cout << i << " : ";
                  for (int j = 0; j < numVertices; j++)
                        cout << adjMatrix[i][j] << " ";
                  cout << "\n";
      }

    }
 
    ~Graph() {
            for (int i = 0; i < numVertices; i++)
                  delete[] adjMatrix[i];
            delete[] adjMatrix;
    }
};

void PrintMat(int **mat, int n)
{
	int i, j;
 
	cout<<"\n\n"<<setw(4)<<"";
	for(i = 0; i < n; i++)
		cout<<setw(3)<<"("<<i+1<<")";
	cout<<"\n\n";
 
	// Print 1 if the corresponding vertexes are connected otherwise 0.
	for(i = 0; i < n; i++)
	{
		cout<<setw(3)<<"("<<i+1<<")";
		for(j = 0; j < n; j++)
		{
			cout<<setw(4)<<mat[i][j];
		}
		cout<<"\n\n";
	}
}


int main(){
	char w;
	line:
	cout<<"press U for Adding Edges to the Undirected Graph\n";
	cout<<"\npress D for Adding Edges to the Directed Graph \n";
	cout<<"\npress W for Adding Edges to the Weighted Graph\n";
	cout<<"\npress E to Exit\n ";
	cout<<"\nEntre your choice\n";
	cin>>w;
	switch(w){
		case 'u':
		{
			 	 int u,d,w=0,y=0;
       cout<<"how many vertics"<<endl;
       	cin>>u;
       	Graph g(u);
	   while(y!=u){
       	
		   cout<<"add edges "<<endl;
       	cin>>u>>d;
       	g.addEdge(u,w);
       	
       	y++;

	   }
       	g.toString();
		   	   
	   break;
}
	   case'd':
	   	
	   	int i, v, e, j, v1, v2;
 
	cout<<"Enter the number of vertexes of the graph: ";
	cin>>v;
 
	int **graph;
	graph = new int*[v];
 
	for(i = 0; i < v; i++)
	{
		graph[i] = new int[v];
		for(j = 0; j < v; j++)graph[i][j] = 0;
	}
 
	cout<<"\nEnter the number of edges of the graph: ";
	cin>>e;
 
	for(i = 0; i < e; i++)
	{
		cout<<"\nEnter the vertex pair for edge "<<i+1;
		cout<<"\nV(1): ";
		cin>>v1;
		cout<<"V(2): ";
		cin>>v2;
 
		graph[v1-1][v2-1] = 1;
		graph[v2-1][v1-1] = 1;
	}

	PrintMat(graph, v);
    break;

	case 'w':
    {
	    int vertices, edges, v1, v2, weight;

 cout<<"Enter the Number of Vertices -\n";

 cin>>vertices;
cout<<vertices;
cout<<"Enter the Number of Edges -\n";

 cin>>edges;

 vector< list< pair<int, int> > > adjacencyList(vertices + 1);

 cout<<"Enter the Edges V1 -> V2, of weight W\n";

 for (int i = 1; i <= edges; ++i) {

cin>> v1, v2, weight;


 adjacencyList[v1].push_back(make_pair(v2, weight));

 }

 cout<<"\nThe Adjacency List-\n";


 for (int i = 1; i < adjacencyList.size(); ++i) {

 cout<<"adjacencyList ", i;

 list< pair<int, int> >::iterator itr = adjacencyList[i].begin();

 while (itr != adjacencyList[i].end()) {

 cout<< (*itr).first, (*itr).second;

 ++itr;

 }

cout<<"\n";

 }break;
 
}
goto line;
   case 'e':
	exit;
}

 return 0;}

