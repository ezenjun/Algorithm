#include <iostream>
#include <string>
#include <map>
using namespace std;

class Student{
    public:
        double height, weight;
        bool operator<(const Student &s) const{
            if(height != s.height) 
                return height<s.height;
            return weight < s.weight;
        }
};

int main(){
    map<Student, string> mp;
    map<Student, string>::iterator it;
    Student e;
    e.height = 150; e.weight = 50; mp[e] = "Andy";
    e.height = 180; e.weight = 80; mp[e] = "Brody";
    e.height = 170; e.weight = 60; mp[e] = "Charls";

    for(it = mp.begin(); it != mp.end(); it++){
        cout << it->second << "(" << it->first.height << ", " << it->first.weight << ")" << endl;
    }
}