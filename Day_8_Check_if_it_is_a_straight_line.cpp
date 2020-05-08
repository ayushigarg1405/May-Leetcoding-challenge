/*
Question:

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

Solution Approach:
Making use of cross product to find of two points lie on same line.

Solution:

*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size()<=2)
            return true;
        
        int first_x = coordinates[0][0];
        int first_y = coordinates[0][1];
        int second_x = coordinates[1][0];
        int second_y = coordinates[1][1];
        
        for(int i=2;i<coordinates.size();i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if((second_y - first_y)*(first_x - x)!=(first_y - y)*(second_x - first_x))
                return false;
        }
        return true;
    }
};
