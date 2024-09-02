#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <ctime>

using namespace std;

class Student {
public:
    string name;
    tm birth_date;

    Student(const string& name, int year, int month, int day) : name(name) {
        birth_date = {0};
        birth_date.tm_year = year - 1900;  // tm_year is year since 1900
        birth_date.tm_mon = month - 1;     // tm_mon is 0-based
        birth_date.tm_mday = day;
    }

    int operator-(const Student& other) const {
        time_t t1 = mktime(const_cast<tm*>(&birth_date));
        time_t t2 = mktime(const_cast<tm*>(&other.birth_date));
        return abs(difftime(t1, t2) / (60 * 60 * 24));
    }
};

pair<Student, Student> find_min_age_difference(const vector<Student>& students) {
    int min_diff = INT_MAX;
    pair<Student, Student> min_pair = {students[0], students[1]};

    int n = students.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff = students[i] - students[j];
            if (diff < min_diff) {
                min_diff = diff;
                min_pair = {students[i], students[j]};
            }
        }
    }

    return min_pair;
}

int main() {
    int n;
    cin >> n;
    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        string name;
        int year, month, day;
        cin >> name >> year >> month >> day;
        students.emplace_back(name, year, month, day);
    }

    auto min_pair = find_min_age_difference(students);
    int min_diff = min_pair.first - min_pair.second;

    cout << min_pair.first.name << "和" << min_pair.second.name << "年龄相差最小，为" << min_diff << "天。" << endl;

    return 0;
}
