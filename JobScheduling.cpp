#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // id, value, deadline
    int job[5][3] = {
        {1, 50, 3},
        {2, 100, 2},
        {3, 40, 3},
        {4, 60, 1},
        {5, 80, 2}
    };

    // Sort jobs based on value in descending order
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (job[i][1] > job[j][1]) {
                swap(job[i], job[j]);
            }
        }
    }

    // Display sorted jobs
    for (int i = 0; i < 5; i++) {
        cout << job[i][0] << " " << job[i][1] << " " << job[i][2] << endl;
    }

    vector<int> schedule(4, -1); // Vector to hold scheduled job indices

    for (int i = 0; i < 5; i++) {
        for (int j = job[i][2]; j >= 1; j--) {
            if (schedule[j] == -1) {
                schedule[j] = i; // Schedule the job
                break;
            }
        }
    }
    cout << "\nScheduled Jobs:\n";

    int totalProfit = 0;
    for (int i = 1; i < 4; i++) {
        if (schedule[i] != -1) {
            cout << schedule[i] + 1 << " " << job[schedule[i]][1] << endl; // +1 for job id
            totalProfit += job[schedule[i]][1];
        }
    }
    cout << "\nTotal profit = " << totalProfit << endl;

    return 0;
}
