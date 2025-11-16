#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Train {
    string number;
    string time;
    string station;
};

int main() {
    vector<Train> trains;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Train t;
        cin >> t.number >> t.time >> t.station;
        trains.push_back(t);
    }
    for (auto &t : trains)
        cout << t.number << " " << t.time << " " << t.station << endl;
    string q;
    cin >> q;
    for (auto &t : trains)
        if (t.number == q)
            cout << t.number << " " << t.time << " " << t.station << endl;
}
