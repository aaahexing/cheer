/********************************
Clone Graph: https://leetcode.com/problems/clone-graph/

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. 

OJ's undirected graph serialization: 
Nodes are labeled uniquely. 
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node. 

As an example, consider the serialized graph {0,1,2#1,2#2,2}. 

The graph has a total of three nodes, and therefore contains three parts as separated by #. 
1.First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
2.Second node is labeled as 1. Connect node 1 to node 2.
3.Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following: 
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
**/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

//time limit exceeded.....
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> m;
        return cloneGraph(node, m);
    }
    
    UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node, unordered_map<int, UndirectedGraphNode *> & m) {
        UndirectedGraphNode * ret = NULL;
        if (node == NULL) {
            return NULL;
        }
        
        ret = new UndirectedGraphNode(node->label); 
        m[node->label] = ret;
        for (int i = 0; i < (node->neighbors).size(); i++) {
            UndirectedGraphNode * neighbor = (node->neighbors)[i];
            if (m.count(neighbor->label)) {
                (ret->neighbors).push_back(m[neighbor->label]);
            } else {
                (ret->neighbors).push_back(cloneGraph(neighbor));
            }
        }
        
        return ret;
    }
};