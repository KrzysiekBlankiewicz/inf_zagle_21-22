#include <iostream>
#include <vector>

using namespace std;

pair<vector<int>, int> shrtstPath(int start, int dest, vector<vector<int> > graph, vector<int> visited)
{
	vector<int> path {start, dest};
	return path;
}


int main(int argc, char** argv) {
	
	int numberOfNodes, start, dest;
	vector<vector<int>> graph;
	
	file>>numberOfNodes;
	graph.resize(numberOfNodes);
		
	for(vector<int> i:graph)
		i.resize(numberOfNodes, -1);
		
	//na podstawie pliku uzupe³nij graph
		
		
	vector<int> path;
	cin>>start>>dest;
	if(start<numberOfNodes && dest<numberOfNodes)
		path=shrtsPath(start, dest, graph, vector<int>());
	
	
	//cout<<
	
	return 0;
}
