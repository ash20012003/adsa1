#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
using namespace std;

class TimeMap {
    unordered_map<string, map<int, string>> hash;
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        hash[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if (hash.count(key) == 0) return "";
        if (hash[key].count(timestamp) > 0) return hash[key][timestamp];

        // Check if query ts is less than the lowest ts in hash.
        for (auto t: hash[key]) {
            if (timestamp < t.first) return "";
            break;
        }
        
        auto it = hash[key].lower_bound(timestamp);
        return (--it)->second;
    }
};

int main(){
    int key = 2;
    TimeMap t;
    t.set("2","3",6);
    t.set("2","17",15);
    t.set("2","13",15);
    t.set("2","6",12);
    t.set("2","9",1);
    t.set("2","2",7);
    t.set("2","10",19);
    cout<<t.get("2",1)<<endl;
    cout<<t.get("2",13)<<endl;
}