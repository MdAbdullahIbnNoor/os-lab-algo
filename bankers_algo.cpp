#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes\n";
    cin >> n;
    cout << "Enter number of resources\n";
    cin >> m;

    int need[n][m], res[m], alloc[n][m], cneed[n][m], avail[m];
    queue<int> q;
    for (int i = 0; i < n; i++) q.push(i);

    cout << "Number of resources system have\n";
    for (int i = 0; i < m; i++) {
        cout << "R" << i + 1 << " :";
        cin >> res[i];
        avail[i] = res[i];
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << "Maximum number of resources needed by P" << i + 1 << " :";
        for (int j = 0; j < m; j++) {
            cin >> need[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << "Allocated resources for P" << i + 1 << " :";
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
            cneed[i][j] = need[i][j] - alloc[i][j];
            avail[j] -= alloc[i][j];
        }
        cout << endl;
    }

    // We'll store the available resources after each allocation
    int available[n + 1][m];
    for (int i = 0; i < m; i++) available[0][i] = avail[i];

    vector<int> v;
    int flag = 0, k = 1;

    while (!q.empty()) {
        flag = 0;
        int i = q.front();
        q.pop();

        for (int j = 0; j < m; j++) {
            if (avail[j] < cneed[i][j]) {
                break;
            } else {
                flag++;
            }
        }

        if (flag == m) { // Process can be allocated
            for (int j = 0; j < m; j++) {
                avail[j] += alloc[i][j];
                available[k][j] = avail[j];
            }
            k++;
            v.push_back(i);
        } else {
            q.push(i);
        }

        // Safety check to avoid infinite loop
        if (q.size() == n) {
            cout << "The system is not in a safe state.\n";
            return 1;
        }
    }

    cout << "Process table is:\nPid\tMax Need\tAllocated\tNeed\t\tAvailable\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t";
        for (int j = 0; j < m; j++) cout << need[i][j] << ' ';
        cout << "\t\t";
        for (int j = 0; j < m; j++) cout << alloc[i][j] << ' ';
        cout << "\t\t";
        for (int j = 0; j < m; j++) cout << cneed[i][j] << ' ';
        cout << "\t\t";
        for (int j = 0; j < m; j++) cout << available[k-1][j] << ' ';
        cout << endl;
    }

    cout << "Safe sequence is: ";
    for (auto i : v) cout << "P" << i + 1 << " ";
    cout << endl;

    return 0;
}
