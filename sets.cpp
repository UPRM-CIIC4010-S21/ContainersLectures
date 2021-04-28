#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Student {

    private:
    int id;
    string firstName;
    string lastName;

    public:
    int getId() { return id; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    Student(int id, string fn, string ln): id(id), firstName(fn), lastName(ln) {}



};

int countUnique(const vector<Student> &students)
{

}

int main() {

    vector<Student> testStudents;
    testStudents.push_back( Student(10, "Bienve", "Velez"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(32, "Amanda", "Vazquez"));
    testStudents.push_back( Student(32, "Amanda", "Davis"));
    testStudents.push_back( Student(65, "Joshua", "Vazquez"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz"));
    testStudents.push_back( Student(54, "Fatima", "Puig"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(76, "Rey", "Cotto"));

    cout << "Count of Unique Students: " << countUnique(testStudents) << endl;


}