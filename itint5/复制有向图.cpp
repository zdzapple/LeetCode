/**
struct GraphNode {
    int data;
    vector<GraphNode*> neighbors;
    GraphNode(int data) : data(data) {}
};
**/
GraphNode *cloneGraph(GraphNode *node) 
{
	if (node == NULL)
		return NULL;
	map<GraphNode *, GraphNode*> m;
	GraphNode *result = new GraphNode(node->data);
	queue<GraphNode *> q;
	q.push(node);
	m[node] = result;
	while (!q.empty())
	{
		GraphNode *current = q.front();
		q.pop();
		for (int i = 0; i < current->neighbors.size(); ++ i)
		{
			GraphNode *child = current->neighbors[i];
			if (m.find(child) == m.end()) {
				GraphNode *newChild = new GraphNode(child->data);
				m[child] = newChild;
				m[current]->neighbors.push_back(newChild);
				q.push(child);
			} else {
				m[current]->neighbors.push_back(m[child]);
			}
			
		}
	}
	return result;
}