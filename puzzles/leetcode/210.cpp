/************************
Course Schedule II : https://leetcode.com/problems/course-schedule-ii/
**/

class Vertex {
public:
	int indegree;
	int topNum;
	list<int> adjacent;
	Vertex(int indeg = 0, int top = -1) {
		indegree = indeg;
		topNum = top;
		adjacent.clear();
	}
};

//toplogical sort
//time complexity: O(m+n)
//space complexity: O(n)
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<Vertex> vertexs(numCourses);
	vector<int> ret;
	createGraph(vertexs, prerequisites);
	toplogicalSort(vertexs, ret);
	if (ret.size() != numCourses) {
		ret.clear();
	}
	return ret;
}

void createGraph(vector<Vertex> & vertexs, vector<pair<int, int>> & prerequisites) {
	for (int i = 0; i < prerequisites.size(); i++) {
		vertexs[prerequisites[i].first].indegree++;
		vertexs[prerequisites[i].second].adjacent.push_back(prerequisites[i].first);
	}
}

void toplogicalSort(vector<Vertex> & vertexs, vector<int> & res) {
	queue<int> q;
	for (int i = 0; i < vertexs.size(); i++) {
		if (vertexs[i].indegree == 0) {
			q.push(i);
			res.push_back(i);
		}
	}

	int count = 0;
	while (!q.empty()) {
		Vertex v = vertexs[q.front()];
		q.pop();
		v.topNum = count++;
		for (list<int>::iterator itr = v.adjacent.begin(); itr != v.adjacent.end(); itr++) {
			vertexs[*itr].indegree--;
			if(vertexs[*itr].indegree == 0 && vertexs[*itr].topNum == -1) {
				q.push(*itr);
				res.push_back(*itr);
			}
		}
	}
}