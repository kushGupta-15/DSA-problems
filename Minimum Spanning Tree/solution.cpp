class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n+1);
        parent.resize(n+1, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findUParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        
        return findUParent(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_u == ulp_v)
            return;
            
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) { 
        vector<pair<int, pair<int, int>>> st;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            st.push_back({wt, {u, v}});
        }
        
        sort(st.begin(), st.end());
        
        int mstWt = 0;
        DisjointSet ds(V);
        for(auto& it : st) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUParent(u) != ds.findUParent(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWt;
    }
};