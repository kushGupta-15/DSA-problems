class Solution {
    void findProvince(int city, vector<int>& visited, vector<vector<int>>& adjCities) {
        visited[city] = 1;

        for(int adjCity : adjCities[city]) {
            if(!visited[adjCity]) {
                findProvince(adjCity, visited, adjCities);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalCities = isConnected.size();

        vector<vector<int>> adjCities(totalCities+1);

        for(int a = 0; a < totalCities; a++) {
            for(int b = 0; b < totalCities; b++) {
                if(isConnected[a][b] == 1) {
                    adjCities[a].push_back(b);
                    adjCities[b].push_back(a);
                }
            }
        }

        vector<int> visited(totalCities, 0);

        int provinces = 0;
        for(int city = 0; city < totalCities; city++) {
            if(!visited[city]) {
                provinces += 1;
                findProvince(city, visited, adjCities);
            }
        }

        return provinces;
    }
};