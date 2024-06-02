#include <bits/stdc++.h>
using namespace std;

class Abhimanyu {
public:
    Abhimanyu(int power, int skips, int energy) 
        : p(power), a(skips), b(energy) {}

    bool solve(vector<int> &arr) {
        if (a >= 11) // Base case: if Abhimanyu has enough skips to pass all the circles
            return true;

        int cur_p = p, skp = a, enrg = b;
        for (int i = 0; i < 11; i++) {
            // k3 and k7 power regenerate case
            if (i == 3 || i == 7) {
                arr[i] += (arr[i - 1] / 2);
            }
            // If Abhimanyu has less power than enemy
            if (cur_p < arr[i]) {
                // If Abhimanyu can recharge
                if (cur_p != p && p >= arr[i] && enrg > 0) {
                    enrg--;
                    cur_p = p;
                    cur_p -= arr[i];
                }
                // If Abhimanyu can skip
                else if (skp > 0) {
                    skp--;
                }
                // If Abhimanyu cannot defeat
                else {
                    return false;
                }
            }
            // If Abhimanyu has more power than the enemy
            else {
                cur_p -= arr[i];
            }
        }
        return true;
    }

private:
    int p;
    int a;
    int b;
};

int main() {
    vector<int> arr1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    Abhimanyu abhimanyu1(10, 10, 0);
    cout << (abhimanyu1.solve(arr1) ? "Yes" : "No") << endl;

    vector<int> arr2 = {50, 40, 30, 20, 50, 60, 70, 80, 90, 100, 110}; 
    Abhimanyu abhimanyu2(60, 2, 3);
    cout << (abhimanyu2.solve(arr2) ? "Yes" : "No") << endl;

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
