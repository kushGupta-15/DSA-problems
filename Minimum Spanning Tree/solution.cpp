class DisjointSet {
    vector<int> size, parent;
public:
    // constructor call - resize the vector created to access index
    DisjointSet(int n) {
        size.resize(n+1);
        parent.resize(n+1, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // find ultimate parent 
    int findUParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        
        return parent[node] = findUParent(parent[node]);
    }
    
    // adds the smallest edge component to the bigger edge component 
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
        
        // new data structure created 
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            st.push_back({wt, {u, v}});
        }
        
        // sort by weight
        sort(st.begin(), st.end());
        
        int mstWt = 0;
        DisjointSet ds(V);
        for(auto& it : st) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            // if not same ultimate parent means its not included in data structure so add it and increase the mst by the wt
            if(ds.findUParent(u) != ds.findUParent(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWt;
    }
};