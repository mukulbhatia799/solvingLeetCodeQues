class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        // we just have to stay on the smallest value so that we can get maximum points and we will take the currentEnergy from bigger values.
        if(currentEnergy < enemyEnergies[0]) return 0;
        long long int sum = currentEnergy; 
        for(int i = 1; i < enemyEnergies.size(); i++) 
            sum += enemyEnergies[i];
        long long int answer = sum/enemyEnergies[0];
        return answer;

    }
};