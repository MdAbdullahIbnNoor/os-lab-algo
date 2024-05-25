#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findNext(vector<int> &pages, vector<int> &frames, int total_pages, int current_idx) {
    int result = -1, farthest = current_idx;
    for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = current_idx; j < total_pages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == total_pages) {
            return i;
        }
    }
    return (result == -1) ? 0 : result;
}

void optimalPageReplacement(vector<int> &pages, int total_pages, int frame_count) {
    vector<int> frames;
    int hits = 0;

    for (int i = 0; i < total_pages; i++) {
        if (find(frames.begin(), frames.end(), pages[i]) != frames.end()) {
            hits++;
            continue;
        }
        if (frames.size() < frame_count) {
            frames.push_back(pages[i]);
        } else {
            int j = findNext(pages, frames, total_pages, i + 1);
            frames[j] = pages[i];
        }
    }

    cout << "Hits = " << hits << endl;
    cout << "Misses = " << total_pages - hits << endl;
}

int main() {
    int total_pages;
    cout << "Enter the number of pages: ";
    cin >> total_pages;

    vector<int> pages(total_pages);
    cout << "Enter sequence: ";
    for (auto &page : pages) {
        cin >> page;
    }

    int frame_count;
    cout << "Enter frame number: ";
    cin >> frame_count;

    optimalPageReplacement(pages, total_pages, frame_count);

    return 0;
}
