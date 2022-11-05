#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
void enter_students(vector<string> &students);
void create_new_assignment(vector<string> &students,vector<string> &assignments,vector<int> &grades);
void enter_grades(vector<string> &students,string assignment_name,vector<int> &grades);
void print_students(vector<string> &students);
void view_gradbook(vector<string> &students,vector<string> &assignments,vector<int> &grades);
int find_students_assignment_grade(int student_index,string student_name,int assignment_index,vector<string> &students,vector<string> &assignments, vector<int> &grades);

int main() {
    vector<string> assignments;
    vector<string> students;
    vector<int> grades;
    bool entered_students=false;
    int input;
    while (true){
    cout << "Welcome to the Main Menu.\n\nEnter 1 to set up a new class\nEnter 2 to add an assignment to the gradebook\nEnter 3 to view the class roster\nEnter 4 to view the gradebook\n";
    cin >> input;
    switch (input) {
        case 1:
            if (entered_students == false) {
                enter_students(students);
                entered_students = true;
            } else {
                cout << "You have already set up a class and are unable to select this option. \n\n";
                break;
            }
            break;
        case 2:
            create_new_assignment(students, assignments, grades);
            break;
        case 3:
            print_students(students);
            break;
        case 4:
            view_gradbook(students,assignments,grades);
            break;
        default:
            cout << "You didn't enter a valid option. " << endl;
    }
    }
    return 0;
}
void enter_students(vector<string> &students){
    string name;
    cout << "You will enter the first name for each student. Enter \"done\" whenever you are finished.\n\n";
    while (name!="done") {
        cout << "Enter another student's first name: ";
        cin >> name;
        if (name != "done") {
            students.push_back(name);
        }
    }
}
void create_new_assignment(vector<string> &students,vector<string> &assignments,vector<int> &grades){
    string assignment_name;
    cin.ignore();
    cout << "\nWhat is the name of the assignment you are adding? ";
    getline(cin, assignment_name);
    assignments.push_back(assignment_name);
    enter_grades(students,assignment_name,grades);
}
void enter_grades(vector<string> &students,string assignment_name,vector<int> &grades){
    cout << "\nYou will enter each student's grade for " << assignment_name <<". "    << endl;
    int grade;
    for (int i = 0;i<students.size(); i++) {
        cout << "Enter the grade for " << students.at(i) << ": ";
        cin >> grade;
        grades.push_back(grade);
    }
    cout << "\nThe scores have been added. ";
}

void print_students(vector<string> &students){
    cout << "\n\nClass Roster: \n\n";
    for (string name:students){
        cout << name << endl;
    }
    cout << endl;
}

void view_gradbook(vector<string> &students,vector<string> &assignments,vector<int> &grades){
    int index = 0;

    if (assignments.size()==0){
        cout << "There are currently no assignments entered. \n\nYou will now be returned to the main menu.\n" <<endl;
        return;
    }
    cout << setw(5)<<"Student";

    for (int i=0; i < assignments.size();i++){
        string assignment=assignments.at(i);
        cout <<setw(10) <<assignment;
    }

    cout << "\n"<<endl;
    while (index < students.size()){
        string current_student = students.at(index);
        int assignment_index=0;
        cout <<setw(5)<<current_student;
        while (assignment_index<assignments.size()) {
            int grade = find_students_assignment_grade(index, current_student, assignment_index, students, assignments,grades);
            cout <<setw(10) <<right <<grade;
            assignment_index+=1;
        }
        cout << endl;
        index+=1;
    }

}

int find_students_assignment_grade(int student_index,string student_name,int assignment_index,vector<string> &students,vector<string> &assignments, vector<int> &grades){
    int grade_index;
    if (assignment_index == 0){
        grade_index = assignment_index + student_index;
    }
    else{
        grade_index = assignment_index*students.size()+student_index;

    }
    int grade= grades.at(grade_index);
    return grade;
}
