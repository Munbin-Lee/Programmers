#include <string>
#include <vector>

#include <bits/stdc++.h>
using namespace std;

struct Person {
    int name;
    int idx = 0;
    int correct = 0;
    vector<int> random;
    
    Person(int name, vector<int> random) : name(name), random(random) {}
};

vector<int> solution(vector<int> answers) {
    vector<Person*> people = {
        new Person(1, {1, 2, 3, 4, 5}),
        new Person(2, {2, 1, 2, 3, 2, 4, 2, 5}),
        new Person(3, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5})
    };
    
    int maxCorrect = 0;
    vector<int> res;
    for (int answer : answers) {
        for (auto &person : people) {
            if (person->random[person->idx] == answer) {
                person->correct++;
                if (person->correct > maxCorrect) {
                    maxCorrect = person->correct;
                    res = {person->name};
                } else if (person->correct == maxCorrect) {
                    res.emplace_back(person->name);
                }
            }
            person->idx++;
            person->idx %= (int) person->random.size();
        }
    }
    assert(res.size()>=1);
    sort(res.begin(), res.end());
    return res;
}