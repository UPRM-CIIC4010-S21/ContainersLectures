#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>


using namespace std;

class Student {

    private:
    int id;
    string firstName;
    string lastName;

    public:
    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    Student(int id, string fn, string ln): id(id), firstName(fn), lastName(ln) {}

    bool operator< (const Student &s) const { return this->getId() < s.getId(); }

};

void dumpStudent(Student s)
{
    cout << s.getFirstName() << " " << s.getLastName() << endl;
}

double integrate(double a, double b, function<double(double)> f)
{

    int numIntervals = 3;
    double result = 0;
    double deltaX = (b - a) / numIntervals;

    for (int i=0; i<numIntervals; i++) {
        double xLeft = a + i * deltaX;
        double nextArea = ((f(xLeft) + f(xLeft+ deltaX)) / 2) * deltaX;
        result += nextArea;
    }
    return result;

}

int main() 
{

    vector<Student> testStudents;
    testStudents.push_back( Student(10, "Bienve", "Velez"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(32, "Amanda", "Vazquez"));
    testStudents.push_back( Student(65, "Joshua", "Vazquez"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz"));
    testStudents.push_back( Student(54, "Fatima", "Puig"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(76, "Rey", "Cotto"));

    cout << "For each function using standalone function" << endl;
    for_each(testStudents.begin(), testStudents.end(), dumpStudent);

    cout << "For each function using lambda expression" << endl;
    for_each(testStudents.begin(), testStudents.end(), 
        [](Student s) { cout << s.getFirstName() << " " << s.getLastName() << endl; });

    vector<Student>::iterator pos;
    pos = find_if(testStudents.begin(), testStudents.end(), 
                [](Student s) {
                    return (s.getFirstName()[0] == 'a' || s.getFirstName()[0] == 'A');
                }
    );

    cout << "First student with name starting with A is: " << pos->getId() << ": " << pos->getFirstName() << endl;

    pos = find_if(pos+1, testStudents.end(), 
                [](Student s) {
                    return (s.getFirstName()[0] == 'a' || s.getFirstName()[0] == 'A');
                }
    );

    cout << "Second student with name starting with A is: " << pos->getId() << ": " << pos->getFirstName() << endl;

    Student bienve(1000, "Bienve", "Velez");
    bool found = binary_search(testStudents.begin(), testStudents.end(), bienve);
    cout << (found ? "Bienve Found" : "Bienve Not Found") << endl;

    cout << "Integral of x^2 frm 1 to 2 is: " << integrate(1,2,[](double x) { return x*x; }) << endl;

    cout << "Integral of ln(x) frm 1 to 3 is: " << integrate(1,3,[](double x) { return log(x); }) << endl;

    cout << "Integral of cos^2(x)sen^2(x) frm 1 to 3 is: " << integrate(1,3,
    [](double x) { return sin(2*x)*sin(2*x)*cos(2*x)*cos(2*x); }
    ) << endl;

    cout << "Integral of sin(x) frm 0 to Pi is: " << integrate(0,M_PI,
    [](double x) { return sin(x); }
    ) << endl;
}