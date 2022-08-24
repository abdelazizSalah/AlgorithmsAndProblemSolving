//#include<bits/stdc++.h>
//using namespace std;
//#define fast ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0); 
//using ll = long long; 
//vector<vector<int>> graphList;
//vector<int> Time;
//vector<bool> vis;
//pair<int , bool> TopologicalSort(int node, int src, bool Dep)
//{
//	int cntr = Time[node];
//	for (auto it : graphList[node])
//		if (it == src)
//		{
//			Dep |= true;
//			continue;
//		}
//		else if (!vis[it])
//		{
//			vis[it] = true;
//			auto p = TopologicalSort(it, src, false);
//			Dep |= p.second; 
//			cntr += p.first; 
//		}
//
//	if (Dep)
//		cntr -= Time[node]; 
//	return { cntr , Dep };
//}
//
//
//void solve()
//{
//	int noOfNodes, noOfDependencies;
//	int cntr = 1;
//	while (cin >> noOfNodes >> noOfDependencies && noOfNodes != 0)
//	{
//		graphList = vector<vector<int>>(noOfNodes + 1);
//		Time = vector<int>(noOfNodes + 1);
//		//reading the value of each node
//		for (int i = 1; i <= noOfNodes; i++)
//			cin >> Time[i];
//
//		//forming the graph and its edges => directed 
//		for (int i = 0; i < noOfDependencies; i++)
//		{
//			int u, v; cin >> u >> v;
//			graphList[u].push_back(v);
//		}
//
//		int noOfQueries; cin >> noOfQueries;
//		cout << "Case #" << cntr++ << ":\n";
//		while (noOfQueries--)
//		{
//			vis = vector<bool>(noOfNodes + 1);
//			vis[0] = true;
//			bool DependOn = false;
//			ll maxDiff = 0;
//			//apply topological sort on the src node 
//			int src; cin >> src;
//			vis[src] = true;
//			maxDiff = TopologicalSort(src, -1, DependOn).first;
//
//			ll Diff = maxDiff = 0;
//			//apply on the other nodes to get the max 
//			for (int i = 0; i < noOfNodes; i++)
//				if (!vis[i])
//				{
//					vis[i] = true;
//					DependOn = false;
//					Diff = TopologicalSort(i, src, DependOn).first;
//					maxDiff += Diff;
//				}
//			cout << maxDiff << "\n";
//		}
//		cout << "\n";
//	}
//}
//
//
///*
////============================================================================
//Accepted Solution
//// Name        : UVA_10461.cpp
//// Author      : Moaz
//// Version     :
//// Copyright   :
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int jobNumbers, sumJobTimes;
//
//int getMinJobTime(int queryJob, vector <int> jobTime, vector<vector<int> > beforeDependencies) {
//	int minJobTime = -jobTime[queryJob];
//	queue<int> minJobTimes;
//	vector<bool> visitedJobs(jobNumbers, false);
//
//	minJobTimes.push(queryJob);
//	visitedJobs[queryJob] = true;
//
//	while (!minJobTimes.empty()) {
//		int currentJob = minJobTimes.front();
//		minJobTimes.pop();
//		minJobTime += jobTime[currentJob];
//
//		for (int i = 0; i < beforeDependencies[currentJob].size(); i++) {
//			int nextJob = beforeDependencies[currentJob][i];
//			if (!visitedJobs[nextJob]) {
//				minJobTimes.push(nextJob);
//				visitedJobs[nextJob] = true;
//			}
//		}
//	}
//	return minJobTime;
//}
//
//int getMaxJobTime(int queryJob, vector<int> jobTime,
//		vector<vector<int> > afterDependencies) {
//	int maxJobTime = sumJobTimes;
//	queue<int> maxJobTimes;
//	vector<bool> visitedJobs(jobNumbers, false);
//
//	maxJobTimes.push(queryJob);
//	visitedJobs[queryJob] = true;
//
//	while (!maxJobTimes.empty()) {
//		int currentJob = maxJobTimes.front();
//		maxJobTimes.pop();
//		maxJobTime -= jobTime[currentJob];
//
//		for (int i = 0; i < afterDependencies[currentJob].size(); i++) {
//			int nextJob = afterDependencies[currentJob][i];
//			if (!visitedJobs[nextJob]) {
//				maxJobTimes.push(nextJob);
//				visitedJobs[nextJob] = true;
//			}
//		}
//	}
//	return maxJobTime;
//}
//
//int main() {
//
//	int caseNumber = 1, dependecyNumbers, jobX, jobY, queryNumbers, queryJob;
//
//	cin >> jobNumbers >> dependecyNumbers;
//
//	while (jobNumbers != 0 || dependecyNumbers != 0) {
//
//		sumJobTimes = 0;
//		vector<int> jobTime(jobNumbers);
//		vector<vector<int> > beforeDependencies(jobNumbers);
//		vector<vector<int> > AfterDependencies(jobNumbers);
//
//		for (int i = 0; i < jobNumbers; i++) {
//			cin >> jobTime[i];
//			sumJobTimes += jobTime[i];
//		}
//
//		while (dependecyNumbers--) {
//			cin >> jobX >> jobY;
//			jobX--, jobY--;
//
//			beforeDependencies[jobX].push_back(jobY);
//			AfterDependencies[jobY].push_back(jobX);
//		}
//		cin >> queryNumbers;
//
//		cout << "Case #" << caseNumber++ << ":" <<endl;
//		while (queryNumbers--) {
//			cin >> queryJob;
//			queryJob--;
//
//			cout<< getMaxJobTime(queryJob, jobTime, AfterDependencies)
//							- getMinJobTime(queryJob, jobTime,
//									beforeDependencies) << endl;
//		}
//
//		cout<<endl;
//		cin >> jobNumbers >> dependecyNumbers;
//	}
//	return 0;
//}
//*/
//int main()
//{
//	fast;
//	solve();
//	return 0;
//}