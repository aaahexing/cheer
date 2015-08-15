#include <map>
#include <queue>
#include <vector>
#include <string>

using namesapce std;

class vertex {
	int indegree;
	string val;
	int countNum;
	map<string, vertex*> adList;          //indicating the vertices adjacent to this vertex;
	vertex(string val, int indegree = 0, int countNum = 0, map<string, vertex*> adList):this->val(val), this->indegree(indegree), this->countNum(countNum), this->adList(adList) {
	}
}

//assume that the graph is already created
//output: 0 represents legal sort and -1 represents error occur
//time complexity: O(|E|+|V|)
//space complexity: O(|E|)
int topologicalSort(vector<vertex *> graph) {
	queue<vertex *> q;
	q.clear();

	int count = 0;
	for (int i = 0; i < graph.size(); i++) {
		if(graph[i]->indegree == 0)
			q.push(graph[i]);
	}

	while (!q.empty()) {
		vertex * tmp = q.front();
		q.pop();
		tmp->indegree = ++count;
		for (map<string, vertex*>::iterator itr = tmp->adList.begin(); itr != tmp->adList.end(); itr++) {
			itr->indegree--;
			if(itr->indegree == 0)
				q.push(itr);
		}
	}

	if (count != graph.size()) {
		cout<<"topological sort can't be done since cycle in the input graph"<<endl;
		return -1;
	}

	return 0;
}
