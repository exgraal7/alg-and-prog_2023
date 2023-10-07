#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

Student make_student (std::string& line){
    std::string name;
    std::string group;
    for (int i = 0; i < line.size(); i++){
        if (line[i] == ';'){
            name = line.substr(0, i);
            group = line.substr(i+1, line.size());
            break;
        }
    }
    return {name, group};
}

bool is_upper (Student& stud1, Student& stud2){
    if (stud1.group == stud2.group){
        return stud1.name < stud2.name;
    }
    else {
        return stud1.group < stud2.group;
    }
}

void print (std::vector <Student>& students){
    std::string cur_group = "";

    if (students.empty()){
        std::cout << "Empty list!";
    }
    for (int i=0; i < students.size(); i++){
        if (cur_group != students[i].group){
            cur_group = students[i].group;
            std::cout << cur_group << "\n";
        }
         std::cout << "- " << students[i].name << "\n";
    } 
}
int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1); 
    
    std::vector<Student> students(count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::sort(students.begin(), students.end(), is_upper);
    
    print(students);
}
