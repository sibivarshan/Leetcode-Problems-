#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/* 
        This function calculates the maximum average pass ratio after distributing extra students.
        It uses a max-heap (priority queue) to repeatedly assign students to the class with the 
        highest potential gain in the pass ratio.
        
        Key Idea:
        - Each class has a pass ratio: passed / total.
        - Adding a student to a class increases the ratio, but the gain decreases with each student.
        - Use a max-heap to efficiently track the class with the highest potential gain.
        
        Parameters:
        - classes: A vector of {passed, total} for each class.
        - extraStudents: The number of students to distribute.
        
        Returns:
        - The maximum average pass ratio after distributing extra students.
        */

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<std::pair<double, int>> maxHeap; // max heap initialization

        int n = classes.size();
        for(int i=0;i<n;i++){
            if (classes[i][0]<classes[i][1]){

                // gain is a double thus , forcing the pass to be a double since pass is an int in the vector.
                double gain = ((double)classes[i][0]+1)/(classes[i][1]+1) - ((double)classes[i][0]/classes[i][1]);
                maxHeap.push({gain,i});
            }
        }
        while (extraStudents > 0 && !maxHeap.empty()){
            auto [val, i] = maxHeap.top();
            maxHeap.pop();
            classes[i][0]+=1; // add the extra student to the max gain class.
            classes[i][1]+=1;
            extraStudents-=1; // decrement the students

            // type casting the numerator to get the division result as double
            double gain = ((double)classes[i][0]+1)/(classes[i][1]+1) - ((double)classes[i][0]/classes[i][1]);
            maxHeap.push({gain,i});
        }
        double total = 0;
        for(int j=0;j<n;j++){
            // calculate the total avg.
            total = total + ((double)classes[j][0]/classes[j][1]);
        }
        return total/n;
    }
};