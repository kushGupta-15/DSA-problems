class DisjointSet {
    vector<int> parent, rnk;   

public:                        
    DisjointSet(int size) {
        parent.resize(size + 1, 0);
        rnk.resize(size + 1, 0);

        for (int node = 0; node <= size; node++) {
            parent[node] = node;   
        }
    }

    int findUParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int src, int dest) {
        int upSrc = findUParent(src);    
        int upDest = findUParent(dest);  

        if (upSrc == upDest) {
            return; 
        }

        if (rnk[upSrc] < rnk[upDest]) {
            parent[upSrc] = upDest;
        } else if (rnk[upDest] < rnk[upSrc]) {
            parent[upDest] = upSrc;
        } else { 
            parent[upDest] = upSrc;
            rnk[upSrc] += 1;
        }
    }
};

class Solution {
public:
    int countConnected(int V, vector<vector<int>>& edges) {
        DisjointSet ds(V);

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (ds.findUParent(u) != ds.findUParent(v)) {
                ds.unionByRank(u, v);
            }
        }

        int count = 0;
        for (int node = 0; node < V; node++) {
            if (ds.findUParent(node) == node) {
                count++;
            }
        }

        return count;
    }
};