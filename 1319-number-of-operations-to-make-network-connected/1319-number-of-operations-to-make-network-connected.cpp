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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int countExtras = 0;

        for(vector<int>& connection : connections) {
            int u = connection[0];
            int v = connection[1];

            if(ds.findUParent(u) == ds.findUParent(v)) {
                countExtras++;
            } else {
                ds.unionByRank(u, v);
            }
        }

        int components = 0;
        for(int node = 0; node < n; node++) {
            if(ds.findUParent(node) == node) {
                components++;
            }
        }

        if(countExtras >= components-1)
            return components-1;
        return -1;
    }
};

