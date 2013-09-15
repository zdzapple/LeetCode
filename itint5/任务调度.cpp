typedef int JobID;
/* deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
*/
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                   vector<JobID> &result) 
{
	vector<int> indegree(n + 1, 0);
	map<JobID, vector<JobID> > rmap;
	for (map<JobID, vector<JobID> >::const_iterator it = deps.begin();
		it != deps.end(); ++ it)
		{
			vector<JobID> vec = it->second;
			for (int i = 0; i < vec.size(); ++ i) 
			{
				if (rmap.find(vec[i]) == rmap.end()) {
					vector<int> postJobs;
					rmap[vec[i]] = postJobs;
				}
				rmap[vec[i]].push_back(it->first);
				indegree[it->first] ++;
			}
			
		}
	stack<int> preJobs;
	for (int i = 1; i <= n; ++ i)
		if (indegree[i] == 0)
			preJobs.push(i);
	int index = 0;
	for (int i = 0; i < n; ++ i)
	{
		if (preJobs.empty())
			return false;
		int preJob = preJobs.top();
		result[index ++] = preJob;
		preJobs.pop();
		if (rmap.find(preJob) == rmap.end())
			continue;
		vector<int> postJobs = rmap[preJob];
		for (int t = 0; t < postJobs.size(); ++ t)
		{
			indegree[postJobs[t]] --;
			if (indegree[postJobs[t]] == 0) {
				preJobs.push(postJobs[t]);
			}
		}
	}
	return true;
}

/* 太麻烦，还是错的
typedef int JobID;

bool allVisited(const vector<int> &vec, map<JobID, bool> &visited)
{
	for (int i = 0; i < vec.size(); ++ i)
	{
		if (visited[vec[i]] == false)
			return false;
	}
	return true;
}


 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）

bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                   vector<JobID> &result) 
{
	
	map<JobID, bool> visited;
	int index = 0;
	for (int i = 1; i <= n; ++ i)
	{
		visited[i] = false;
	}
	if (deps.empty()) {
		for (int i = 1; i <= n; ++ i)
			result[index ++] = i;
		return true;
	}
	while (true)
	{
		map<JobID, vector<JobID> >::const_iterator it = deps.begin();
		vector<JobID> toRemove;
		for (; it != deps.end(); ++ it)
		{
			JobID latterJob = it->first;
			if (visited[latterJob])
				continue;
			vector<JobID> preJobs = it->second;
			if (allVisited(preJobs, visited)) {
				visited[latterJob] = true;
				toRemove.push_back(latterJob);
				continue;
			}
			vector<JobID>::const_iterator preJobsIt = preJobs.begin();
			while (preJobsIt != preJobs.end()) 
			{
				JobID preJob = *preJobsIt;
				if (visited[preJob] == true) {
					preJobsIt ++;
					continue;
				}
				map<JobID, vector<JobID> >::const_iterator findResult = deps.find(preJob);					
				if (findResult == deps.end() || allVisited(findResult->second, visited)) {					
					toRemove.push_back(preJob);
					visited[preJob] = true;									
				}
				preJobsIt ++;
			}	
		}
		if (toRemove.empty()) {
			return false;
		}
		for (int removeIndex = 0; removeIndex < toRemove.size(); ++ removeIndex)
		{			
			result[index ++] = toRemove[removeIndex];
		}
		for (int i = 0; i < n; ++ i)
			if (visited[i] == false)
				continue;
		return true;
	}
	return false;
}

map是const类型的，所以iterator要const_iterator
刚开始，节点i的map[i] == null, 不代表这个节点的入度就为0
**/
