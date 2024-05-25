#include <iostream>
using namespace std;

int main() {
    int n1, n2, m[20], po[20], p[20], flag;
    cout << "Enter the number of partitions:" << endl;
    cin >> n1;
    cout << "Enter memory size for each partition:" << endl;
    for (int i = 0; i < n1; i++) {
        cout << "Partition " << i + 1 << ":\t";
        cin >> m[i];
        po[i] = i + 1;
    }

    cout << "Enter the number of processes:" << endl;
    cin >> n2;
    cout << "Enter memory size for each process:" << endl;
    for (int i = 0; i < n2; i++) {
        cout << "Process " << i + 1 << ":\t";
        cin >> p[i];
    }

    for (int i = 0; i < n2; i++) {
        flag = 0;
        for (int j = 0; j < n1; j++) {
            if (p[i] <= m[j]) {
                cout << "\nProcess " << i + 1 << " whose memory size is " << p[i] << " KB is allocated at memory partition " << po[j];
                m[j] -= p[i];
                break;
            } else {
                flag++;
            }
        }
        if (flag >= n1) {
            cout << "\nProcess " << i + 1 << " whose memory size is " << p[i] << " KB cannot be allocated";
        }
    }
    return 0;
}
