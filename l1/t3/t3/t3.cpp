#include <iostream>
#include <fstream>

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

std::istream& operator>>(std::istream& stream, All& example) {
    for (int i = 0; i < 3; i++) {
        stream >> example.years[i].year;
        std::string p1, p2;

        stream >> p1 >> p2;
        example.years[i].first.semestr = p1 + " " + p2;

        stream >> example.years[i].first.student1.surname;
        stream >> example.years[i].first.student1.marks[0]
            >> example.years[i].first.student1.marks[1]
            >> example.years[i].first.student1.marks[2];

        stream >> example.years[i].first.student2.surname;
        stream >> example.years[i].first.student2.marks[0]
            >> example.years[i].first.student2.marks[1]
            >> example.years[i].first.student2.marks[2];

        stream >> example.years[i].first.student3.surname;
        stream >> example.years[i].first.student3.marks[0]
            >> example.years[i].first.student3.marks[1]
            >> example.years[i].first.student3.marks[2];


        stream >> p1 >> p2;
        example.years[i].second.semestr = p1 + " " + p2;

        stream >> example.years[i].second.student1.surname;
        stream >> example.years[i].second.student1.marks[0]
            >> example.years[i].second.student1.marks[1]
            >> example.years[i].second.student1.marks[2];

        stream >> example.years[i].second.student2.surname;
        stream >> example.years[i].second.student2.marks[0]
            >> example.years[i].second.student2.marks[1]
            >> example.years[i].second.student2.marks[2];

        stream >> example.years[i].second.student3.surname;
        stream >> example.years[i].second.student3.marks[0]
            >> example.years[i].second.student3.marks[1]
            >> example.years[i].second.student3.marks[2];
    }

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const All& example) {
    for (int i = 2; i >= 0; i--) {
        stream << example.years[i].year << " ";

        stream << example.years[i].first.semestr << " ";

        stream << example.years[i].first.student1.surname << " "
            << example.years[i].first.student1.marks[0] << " "
            << example.years[i].first.student1.marks[1] << " "
            << example.years[i].first.student1.marks[2] << " ";

        stream << example.years[i].first.student2.surname << " "
            << example.years[i].first.student2.marks[0] << " "
            << example.years[i].first.student2.marks[1] << " "
            << example.years[i].first.student2.marks[2] << " ";

        stream << example.years[i].first.student3.surname << " "
            << example.years[i].first.student3.marks[0] << " "
            << example.years[i].first.student3.marks[1] << " "
            << example.years[i].first.student3.marks[2] << " ";


        stream << example.years[i].second.semestr << " ";

        stream << example.years[i].second.student1.surname << " "
            << example.years[i].second.student1.marks[0] << " "
            << example.years[i].second.student1.marks[1] << " "
            << example.years[i].second.student1.marks[2] << " ";

        stream << example.years[i].second.student2.surname << " "
            << example.years[i].second.student2.marks[0] << " "
            << example.years[i].second.student2.marks[1] << " "
            << example.years[i].second.student2.marks[2] << " ";

        stream << example.years[i].second.student3.surname << " "
            << example.years[i].second.student3.marks[0] << " "
            << example.years[i].second.student3.marks[1] << " "
            << example.years[i].second.student3.marks[2] << "\n";
    }

    return stream;
}

int main()
{
    setlocale(LC_ALL, "ru");
    All test;
    std::ifstream file("text.txt");
    file >> test;
    file.close();
    std::ofstream new_file("text2.txt", std::ios_base::out);
    if (new_file.is_open()) {
        new_file << test;
        std::cout << "Загружены данные из text.txt -> text2.txt!\n";
        new_file.close();
    }
}