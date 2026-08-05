#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int totalCost = 0;
        
        int startRow = startPos[0], homeRow = homePos[0];
        int startCol = startPos[1], homeCol = homePos[1];
        
        // add row costs 
        if (startRow < homeRow) {
            for (int r = startRow + 1; r <= homeRow; ++r) {
                totalCost += rowCosts[r];
            }
        } else if (startRow > homeRow) {
            for (int r = startRow - 1; r >= homeRow; --r) {
                totalCost += rowCosts[r];
            }
        }
        
        // add column costs
        if (startCol < homeCol) {
            for (int c = startCol + 1; c <= homeCol; ++c) {
                totalCost += colCosts[c];
            }
        } else if (startCol > homeCol) {
            for (int c = startCol - 1; c >= homeCol; --c) {
                totalCost += colCosts[c];
            }
        }
        
        return totalCost;
    }
};