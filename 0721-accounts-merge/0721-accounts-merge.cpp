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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mapAccNode;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string account = accounts[i][j];
                if(mapAccNode.find(account) == mapAccNode.end()) {
                    mapAccNode[account] = i;
                } else {
                    ds.unionByRank(i, mapAccNode[account]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it : mapAccNode) {
            string account = it.first;
            int node = ds.findUParent(it.second);

            mergedMail[node].push_back(account);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0)
                continue;
            
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMail[i]) {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};