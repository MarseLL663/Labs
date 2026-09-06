#include <iostream>
#include <fstream>

struct Student {
    std::string surname;
    int marks[3] = {5, 5, 5};
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

void ShowIvanovAndSidorov(Year& first_year) {
    if (first_year.second.student1.surname == "Иванов") {
        std::cout << first_year.second.student1.surname << " : " << first_year.year << ", " << first_year.second.semestr << ", оценки: " << first_year.second.student1.marks[0] << " " << first_year.second.student1.marks[1] << " " << first_year.second.student1.marks[2] << "\n";
    }
    if (first_year.second.student2.surname == "Сидоров") {
        std::cout << first_year.second.student2.surname << " : " << first_year.year << ", " << first_year.second.semestr << ", оценки: " << first_year.second.student2.marks[0] << " " << first_year.second.student2.marks[1] << " " << first_year.second.student2.marks[2] << "\n";
    }
    if (first_year.second.student3.surname == "Сидоров") {
        std::cout << first_year.second.student3.surname << " : " << first_year.year << ", " << first_year.second.semestr << ", оценки: " << first_year.second.student3.marks[0] << " " << first_year.second.student3.marks[1] << " " << first_year.second.student3.marks[2] << "\n";
    }

    if (first_year.first.student1.surname == "Иванов") {
        std::cout << first_year.first.student1.surname << " : " << first_year.year << ", " << first_year.first.semestr << ", оценки: " << first_year.first.student1.marks[0] << " " << first_year.first.student1.marks[1] << " " << first_year.first.student1.marks[2] << "\n";
    }
    if (first_year.first.student2.surname == "Сидоров") {
        std::cout << first_year.first.student2.surname << " : " << first_year.year << ", " << first_year.first.semestr << ", оценки: " << first_year.first.student2.marks[0] << " " << first_year.first.student2.marks[1] << " " << first_year.first.student2.marks[2] << "\n";
    }
    if (first_year.first.student3.surname == "Сидоров") {
        std::cout << first_year.first.student3.surname << " : " << first_year.year << ", " << first_year.first.semestr << ", оценки: " << first_year.first.student3.marks[0] << " " << first_year.first.student3.marks[1] << " " << first_year.first.student3.marks[2] << "\n";
    }
}

void ShowAllStudentsAverage(Year& first_year) {
    std::cout << first_year.first.student1.surname << " : " << (first_year.first.student1.marks[0] + first_year.first.student1.marks[1] + first_year.first.student1.marks[2]) / 3.0f << "\n";
    std::cout << first_year.first.student2.surname << " : " << (first_year.first.student2.marks[0] + first_year.first.student2.marks[1] + first_year.first.student2.marks[2]) / 3.0f << "\n";
    std::cout << first_year.first.student3.surname << " : " << (first_year.first.student3.marks[0] + first_year.first.student3.marks[1] + first_year.first.student3.marks[2]) / 3.0f << "\n\n";
    std::cout << first_year.second.student1.surname << " : " << (first_year.second.student1.marks[0] + first_year.second.student1.marks[1] + first_year.second.student1.marks[2]) / 3.0f << "\n";
    std::cout << first_year.second.student2.surname << " : " << (first_year.second.student2.marks[0] + first_year.second.student2.marks[1] + first_year.second.student2.marks[2]) / 3.0f << "\n";
    std::cout << first_year.second.student3.surname << " : " << (first_year.second.student3.marks[0] + first_year.second.student3.marks[1] + first_year.second.student3.marks[2]) / 3.0f << "\n";
}

void ShowAllStudentsAverageWithContext(const Year& first_year) {
    std::cout << first_year.year << ", " << first_year.first.semestr << ", " << first_year.first.student1.surname << " : " << (first_year.first.student1.marks[0] + first_year.first.student1.marks[1] + first_year.first.student1.marks[2]) / 3.0f << "\n";
    std::cout << first_year.year << ", " << first_year.first.semestr << ", " << first_year.first.student2.surname << " : " << (first_year.first.student2.marks[0] + first_year.first.student2.marks[1] + first_year.first.student2.marks[2]) / 3.0f << "\n";
    std::cout << first_year.year << ", " << first_year.first.semestr << ", " << first_year.first.student3.surname << " : " << (first_year.first.student3.marks[0] + first_year.first.student3.marks[1] + first_year.first.student3.marks[2]) / 3.0f << "\n";
    std::cout << first_year.year << ", " << first_year.second.semestr << ", " << first_year.second.student1.surname << " : " << (first_year.second.student1.marks[0] + first_year.second.student1.marks[1] + first_year.second.student1.marks[2]) / 3.0f << "\n";
    std::cout << first_year.year << ", " << first_year.second.semestr << ", " << first_year.second.student2.surname << " : " << (first_year.second.student2.marks[0] + first_year.second.student2.marks[1] + first_year.second.student2.marks[2]) / 3.0f << "\n";
    std::cout << first_year.year << ", " << first_year.second.semestr << ", " << first_year.second.student3.surname << " : " << (first_year.second.student3.marks[0] + first_year.second.student3.marks[1] + first_year.second.student3.marks[2]) / 3.0f << "\n";
}

int main()
{
    setlocale(LC_ALL, "ru");
    All all_years;
    GetResultsForYear(all_years);

    ShowIvanovAndSidorov(all_years.years[0]);
    ShowIvanovAndSidorov(all_years.years[1]);
    ShowIvanovAndSidorov(all_years.years[2]);

    std::cout << "\nСредний баллы:" << "\n\n";
    ShowAllStudentsAverage(all_years.years[0]);
    std::cout << "\nCредняя успеваемость с указанием года и семестра:" << "\n\n";
    ShowAllStudentsAverageWithContext(all_years.years[2]);

    delete[] all_years.years;
}