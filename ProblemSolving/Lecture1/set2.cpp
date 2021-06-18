#include <iostream>
#include <set>
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
    set<Student> S;
    set<Student>::iterator it;
    Student e;
    e.height = 150; e.weight = 50; S.insert(e);
    e.height = 180; e.weight = 80; S.insert(e);
    e.height = 170; e.weight = 60; S.insert(e);

    for(it = S.begin(); it != S.end(); it++){
        cout << "(" << it->height << ", " << it->weight << ")" << endl;
    }
    return 0;
}