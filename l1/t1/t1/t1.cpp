#include <iostream>
#include <fstream>
#include <string>

struct Student {
    std::string name;
    int Age = 0, Class = 0;
};

std::ostream& operator<<(std::ostream& stream, Student& student) {
    stream << "Имя: " << student.name << "\tВозраст: " << student.Age << "\tКласс: " << student.Class << std::endl;
    return stream;
}

std::istream& operator>>(std::istream& stream, Student& student) {
    std::cout << "Имя: ";
    stream >> student.name;
    while (true)
    {
        std::cout << "Возраст: ";
        if (!(stream >> student.Age)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else break;
    };
    while (true)
    {
        std::cout << "Класс: ";
        if (!(stream >> student.Class)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else break;
    };
    return stream;
}

void LoadStudentsInFile(std::string file_name = "students.txt", int count = 1)
{
    Student* arr = new Student[count];
    std::ofstream file(file_name, std::ios_base::out);
    for (int i = 0; i < count; i++)
    {
        Student student;
        std::cin >> student;
        file << student.name << " " << student.Age << " " << student.Class << std::endl;
    };
}

Student* GetStudentsFromFile(std::string file_name = "students.txt", int count = 1)
{
    Student* arr = new Student[count];
    std::ifstream file(file_name);
    file.clear();
    for (int i = 0; i < count; i++)
    {
        Student student;
        file >> student.name >> student.Age >> student.Class;
        arr[i] = student;
    };
    return arr;
}

void FindHighestGirl(Student arr[], int count = 1)
{
    Student HighestGirl = arr[0];
    for (int i = 0; i <= count - 1; i++)
        if (HighestGirl.Age < arr[i].Age) HighestGirl = arr[i];
    std::cout << HighestGirl.name << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    LoadStudentsInFile("students.txt", 5);
    Student* arr = new Student[5];
    arr = GetStudentsFromFile("students.txt", 5);
    FindHighestGirl(arr, 5);
    return 0;
}