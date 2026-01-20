#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double a, b, c;
    
  
    cout << "Enter  a, b, c (a != 0): ";
    cin >> a >> b >> c;
    
    
    if (a == 0) {
        cout << "Error: 'a' must not be zero!" << endl;
        return 1;
    }
    
    
    double D = b * b - 4 * a * c;
    
    if (D < 0) {
        cout << "No real roots exist." << endl;
        return 0;
    }
    
    
    double sqrtD = sqrt(D);
    double t1 = (-b + sqrtD) / (2 * a);
    double t2 = (-b - sqrtD) / (2 * a);
    
    vector<double> roots;
    
    
    if (t1 > 0) {
        double root = sqrt(t1);
        roots.push_back(root);
        roots.push_back(-root);
    } else if (t1 == 0) {
        roots.push_back(0.0);
    }
    
   
    if (t2 > 0) {
        double root = sqrt(t2);
        
        if (find(roots.begin(), roots.end(), root) == roots.end()) {
            roots.push_back(root);
        }
        if (find(roots.begin(), roots.end(), -root) == roots.end()) {
            roots.push_back(-root);
        }
    } else if (t2 == 0) {
        
        if (find(roots.begin(), roots.end(), 0.0) == roots.end()) {
            roots.push_back(0.0);
        }
    }
    
   
    if (roots.empty()) {
        cout << "No real roots exist." << endl;
    } else {
        
        sort(roots.begin(), roots.end());
        
        cout << "Real roots found: ";
        for (size_t i = 0; i < roots.size(); i++) {
            cout << roots[i];
            if (i < roots.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Total number of real roots: " << roots.size() << endl;
    }
    
    return 0;
}