#include <iostream>
using namespace std;

int main() {
    int i, j, k, n, l, m[10], p[10], po[20], flag, z, y, temp, temp1;

    cout << "Enter number of memory partitions: ";
    cin >> n;

    cout << "\nEnter memory size for\n";
    for (i = 0; i < n; i++) {
        cout << "Partition " << i + 1 << " : ";
        cin >> m[i];
        po[i] = i + 1;
    }

    cout << "\nEnter number of processes: ";
    cin >> j;

    cout << "\nEnter memory size for\n";
    for (i = 0; i < j; i++) {
        cout << "Process " << i + 1 << " : ";
        cin >> p[i];
    }

    // Sorting memory partitions and keeping track of original indices
    for (y = 0; y < n; y++) {
        for (z = y + 1; z < n; z++) {
            if (m[y] > m[z]) {
                temp = m[y];
                m[y] = m[z];
                m[z] = temp;

                temp1 = po[y];
                po[y] = po[z];
                po[z] = temp1;
            }
        }
    }

    // Allocation
    for (i = 0; i < j; i++) {
        flag = 0;
        for (k = 0; k < n; k++) {
            if (p[i] <= m[k]) {
                cout << "\nProcess " << i + 1 << " whose memory size is " << p[i] << "KB allocated at memory partition: " << po[k];
                m[k] -= p[i];
                break;
            } else {
                flag++;
            }
        }
        if (flag == n) {
            cout << "\nProcess " << i + 1 << " whose memory size is " << p[i] << "KB can't be allocated";
        }
    }

    return 0;
}
