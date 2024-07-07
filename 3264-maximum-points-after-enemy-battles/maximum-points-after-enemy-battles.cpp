class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        // we just have to stay on the smallest value so that we can get maximum points and we will take the currentEnergy from bigger values.
        int i = 0, j = enemyEnergies.size()-1;
        long long int points = 0;
        while(i <= j) {
            if(enemyEnergies[i] <= currentEnergy) {
                points += currentEnergy/enemyEnergies[i];
                currentEnergy = currentEnergy % enemyEnergies[i];
            }
            else if(points > 0) {
                currentEnergy += enemyEnergies[j--];
            }
            else break;
        }

        return points;
    }
};