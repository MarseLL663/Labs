#include <iostream>
#include <fstream>
#include <string>

struct Student {
    std::string surname;
    int marks[3] = { 5, 5, 5 };
};

struct Semestr {
    std::string semestr;
    Student student1, student2, student3;
};

struct Year {
    int year;
    Semestr first, second;
};

struct All {
    Year* years = new Year[3];
};

void GetResultsForYear(All& all_elements) {
    std::ifstream file("test.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл test.txt\n";
        return;
    }
    for (int i = 0; i < 3; i++) {
        file >> all_elements.years[i].year;

        std::string part1 = "", part2 = "";
        file >> part1;
        part1 += " ";
        file >> part2;
        all_elements.years[i].first.semestr = part1 + part2;

        file >> all_elements.years[i].first.student1.surname;
        file >> all_elements.years[i].first.student1.marks[0];
        file >> all_elements.years[i].first.student1.marks[1];
        file >> all_elements.years[i].first.student1.marks[2];

        file >> all_elements.years[i].first.student2.surname;
        file >> all_elements.years[i].first.student2.marks[0];
        file >> all_elements.years[i].first.student2.marks[1];
        file >> all_elements.years[i].first.student2.marks[2];

        file >> all_elements.years[i].first.student3.surname;
        file >> all_elements.years[i].first.student3.marks[0];
        file >> all_elements.years[i].first.student3.marks[1];
        file >> all_elements.years[i].first.student3.marks[2];

        file >> part1;
        part1 += " ";
        file >> part2;
        all_elements.years[i].second.semestr = part1 + part2;

        file >> all_elements.years[i].second.student1.surname;
        file >> all_elements.years[i].second.student1.marks[0];
        file >> all_elements.years[i].second.student1.marks[1];
        file >> all_elements.years[i].second.student1.marks[2];

        file >> all_elements.years[i].second.student2.surname;
        file >> all_elements.years[i].second.student2.marks[0];
        file >> all_elements.years[i].second.student2.marks[1];
        file >> all_elements.years[i].second.student2.marks[2];

        file >> all_elements.years[i].second.student3.surname;
        file >> all_elements.years[i].second.student3.marks[0];
        file >> all_elements.years[i].second.student3.marks[1];
        file >> all_elements.years[i].second.student3.marks[2];
    }
    file.close();
}

void ShowIvanovAndSidorov(All& all_elements) {
    for (int i = 2; i >= 0; i--) {
        if (all_elements.years[i].second.student1.surname == "Иванов" || all_elements.years[i].second.student1.surname == "Сидоров") {
            std::cout << all_elements.years[i].second.student1.surname << " : " << all_elements.years[i].year << ", " << all_elements.years[i].second.semestr << ", оценки: " << all_elements.years[i].second.student1.marks[0] << " " << all_elements.years[i].second.student1.marks[1] << " " << all_elements.years[i].second.student1.marks[2] << "\n";
        }
        if (all_elements.years[i].second.student2.surname == "Иванов" || all_elements.years[i].second.student2.surname == "Сидоров") {
            std::cout << all_elements.years[i].second.student2.surname << " : " << all_elements.years[i].year << ", " << all_elements.years[i].second.semestr << ", оценки: " << all_elements.years[i].second.student2.marks[0] << " " << all_elements.years[i].second.student2.marks[1] << " " << all_elements.years[i].second.student2.marks[2] << "\n";
        }
        if (all_elements.years[i].second.student3.surname == "Иванов" || all_elements.years[i].second.student3.surname == "Сидоров") {
            std::cout << all_elements.years[i].second.student3.surname << " : " << all_elements.years[i].year << ", " << all_elements.years[i].second.semestr << ", оценки: " << all_elements.years[i].second.student3.marks[0] << " " << all_elements.years[i].second.student3.marks[1] << " " << all_elements.years[i].second.student3.marks[2] << "\n";
        }

        if (all_elements.years[i].first.student1.surname == "Иванов" || all_elements.years[i].first.student1.surname == "Сидоров") {
            std::cout << all_elements.years[i].first.student1.surname << " : " << all_elements.years[i].year << ", " << all_elements.years[i].first.semestr << ", оценки: " << all_elements.years[i].first.student1.marks[0] << " " << all_elements.years[i].first.student1.marks[1] << " " << all_elements.years[i].first.student1.marks[2] << "\n";
        }
        if (all_elements.years[i].first.student2.surname == "Иванов" || all_elements.years[i].first.student2.surname == "Сидоров") {
            std::cout << all_elements.years[i].first.student2.surname << " : " << all_elements.years[i].year << ", " << all_elements.years[i].first.semestr << ", оценки: " << all_elements.years[i].first.student2.marks[0] << " " << all_elements.years[i].first.student2.marks[1] << " " << all_elements.years[i].first.student2.marks[2] << "\n";
        }
        if (all_elements.years[i].first.student3.surname == "Иванов" || all_elements.years[i].first.student3.surname == "Сидоров") {
            std::cout << all_elements.years[i].first.student3.surname << " : " << all_elements.years[i].year << ", " << all_elements.years[i].first.semestr << ", оценки: " << all_elements.years[i].first.student3.marks[0] << " " << all_elements.years[i].first.student3.marks[1] << " " << all_elements.years[i].first.student3.marks[2] << "\n";
        }
    }
}

void AddStudent(std::string names[], double sums[], int counts[], int& unique_count, const Student& student) {
    if (student.surname.empty()) return;

    int index = -1;
    for (int k = 0; k < unique_count; k++) {
        if (names[k] == student.surname) {
            index = k;
            break;
        }
    }

    if (index == -1) {
        index = unique_count;
        names[index] = student.surname;
        unique_count++;
    }

    sums[index] += student.marks[0] + student.marks[1] + student.marks[2];
    counts[index] += 3;
}

void ShowAllStudentsAverage(All& all_elements) {
    std::string names[6];
    double sum_marks[6] = { 0 };
    int count_marks[6] = { 0 };
    int unique_count = 0;

    for (int i = 0; i < 3; i++) {
        AddStudent(names, sum_marks, count_marks, unique_count, all_elements.years[i].first.student1);
        AddStudent(names, sum_marks, count_marks, unique_count, all_elements.years[i].first.student2);
        AddStudent(names, sum_marks, count_marks, unique_count, all_elements.years[i].first.student3);

        AddStudent(names, sum_marks, count_marks, unique_count, all_elements.years[i].second.student1);
        AddStudent(names, sum_marks, count_marks, unique_count, all_elements.years[i].second.student2);
        AddStudent(names, sum_marks, count_marks, unique_count, all_elements.years[i].second.student3);
    }

    for (int i = 0; i < unique_count; i++) {
        std::cout << names[i] << " : " << (sum_marks[i] / count_marks[i]) << "\n";
    }
}

void ShowAllStudentsAverageWithContext(All& all_elements, int year, std::string semestr) {
    for (int i = 0; i < 3; i++) {
        if (all_elements.years[i].year == year && (all_elements.years[i].first.semestr == semestr)){
            std::cout << all_elements.years[i].year << ", " << all_elements.years[i].first.semestr << ", " << all_elements.years[i].first.student1.surname << " : " << (all_elements.years[i].first.student1.marks[0] + all_elements.years[i].first.student1.marks[1] + all_elements.years[i].first.student1.marks[2]) / 3.0f << "\n";
            std::cout << all_elements.years[i].year << ", " << all_elements.years[i].first.semestr << ", " << all_elements.years[i].first.student2.surname << " : " << (all_elements.years[i].first.student2.marks[0] + all_elements.years[i].first.student2.marks[1] + all_elements.years[i].first.student2.marks[2]) / 3.0f << "\n";
            std::cout << all_elements.years[i].year << ", " << all_elements.years[i].first.semestr << ", " << all_elements.years[i].first.student3.surname << " : " << (all_elements.years[i].first.student3.marks[0] + all_elements.years[i].first.student3.marks[1] + all_elements.years[i].first.student3.marks[2]) / 3.0f << "\n";
        }
        else if (all_elements.years[i].year == year && (all_elements.years[i].second.semestr == semestr)) {
            std::cout << all_elements.years[i].year << ", " << all_elements.years[i].second.semestr << ", " << all_elements.years[i].second.student1.surname << " : " << (all_elements.years[i].second.student1.marks[0] + all_elements.years[i].second.student1.marks[1] + all_elements.years[i].second.student1.marks[2]) / 3.0f << "\n";
            std::cout << all_elements.years[i].year << ", " << all_elements.years[i].second.semestr << ", " << all_elements.years[i].second.student2.surname << " : " << (all_elements.years[i].second.student2.marks[0] + all_elements.years[i].second.student2.marks[1] + all_elements.years[i].second.student2.marks[2]) / 3.0f << "\n";
            std::cout << all_elements.years[i].year << ", " << all_elements.years[i].second.semestr << ", " << all_elements.years[i].second.student3.surname << " : " << (all_elements.years[i].second.student3.marks[0] + all_elements.years[i].second.student3.marks[1] + all_elements.years[i].second.student3.marks[2]) / 3.0f << "\n";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    All all_years;
    GetResultsForYear(all_years);

    std::cout << "--- 1) Иванов и Сидоров в обратном порядке ---\n";
    ShowIvanovAndSidorov(all_years);

    std::cout << "\n--- 2) Средние баллы всех студентов ---\n";
    ShowAllStudentsAverage(all_years);

    std::cout << "\n--- 3) Успеваемость с указанием года и семестра ---\n";
    ShowAllStudentsAverageWithContext(all_years, 2017, "осенний семестр");

    delete[] all_years.years;
    return 0;
}
