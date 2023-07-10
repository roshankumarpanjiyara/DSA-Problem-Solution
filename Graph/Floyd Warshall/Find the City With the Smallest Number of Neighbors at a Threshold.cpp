#include <bits/stdc++.h> 
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) 
{
	// Write your code here 
	vector<vector<int>> dist(n, vector<int>(n, 1e9));

	for(auto vec : edges){
		int u = vec[0];
		int v = vec[1];
		int w = vec[2];

		dist[u][v] = w;
		dist[v][u] = w;
	}

	for(int i = 0;i<n;i++){
		dist[i][i] = 0;
	}
	for(int k = 0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(dist[i][k] != 1e9 && dist[k][j] != 1e9){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	int countMax = INT_MAX;
	int city = -1;

	for(int i = 0;i<n;i++){
		int count = 0;
		for(int j = 0;j<n;j++){
			if(dist[i][j] <= distanceThreshold){
				count++;
			}
		}
		if(countMax >= count){
			countMax = count;
			city = i;
		}
	}

	return city;
}
