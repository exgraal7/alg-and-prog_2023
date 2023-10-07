#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

Course make_course(std::string& course_name, std::string& semester_str, std::string& finished_str){
    Course course;
    course.name = course_name;
    course.semester = std::stoi(semester_str);
    course.finished = (finished_str == "1");
    return course;
}

Student make_student(std::string& line){
    Student student;
    std::stringstream ss(line);
    std::getline(ss, student.name, ';');
    std::getline(ss, student.group, ';');

    std::string course_name;
    while (std::getline(ss, course_name, ';')) {
        std::string semester_str;
        std::getline(ss, semester_str, ';');
        std::string finished_str;
        std::getline(ss, finished_str, ';');
        student.courses.push_back(make_course(course_name, semester_str, finished_str));
    }

    return student;
}

bool is_debtor(const Student& student, int cur_semester, int max_debt){
    int debt_counter = 0;
    for (int i = 0; i < student.courses.size(); i++){
        if (student.courses[i].semester < cur_semester && student.courses[i].finished == false){
            debt_counter++;
        }
    }
    return debt_counter > max_debt;
}

bool is_upper(Student& stud1, Student& stud2){
    if (stud1.group == stud2.group){
        return stud1.name < stud2.name;
    }
    else {
        return stud1.group < stud2.group;
    }
}

void print(std::vector<Student>& students){
    std::string cur_group = "";

    if (students.empty()){
        std::cout << "Empty list!";
    }
    for (int i = 0; i < students.size(); i++){
        if (cur_group != students[i].group){
            cur_group = students[i].group;
            std::cout << cur_group << "\n";
        }
        std::cout << "- " << students[i].name << "\n";
    } 
}
int main()
{
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  

    std::vector<Student> students(stud_count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
                 students.end(),
                 std::back_inserter(expulsion_candidates),
                 [cur_semester, max_debt](const Student& student){
                     return is_debtor(student, cur_semester, max_debt);
                 });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}
