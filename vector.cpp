#include "mylibrary.h"

int inputMark(){
    int value;
    while (true) {
        if (std::cin >> value && value <= 10 && value > -2) {
            return value;
        }
        else {
            std::cout << "Iveskite pazymi nuo 1 iki 10 (0 - pabaigti, -1 - generuoti atsitiktinai)" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}



int main()
{
    srand(time(NULL));

    std::vector<Student> grupe;
    std::string names[5] = { "name1", "name2", "name3", "name4", "name5" };
    float galutinisVid = 0;
    float mediana = 0;

    while (true) {
        Student student;
        std::cout << "Iveskite studento varda:(0 - pabaigti, -1 - generuoti atsitiktinai)\n";
        std::cin >> student.name;
        if (student.name == "0") break;
        if (student.name == "-1") {
            student.name = names[rand() % 5];
        }
        std::cout << "Iveskite studento pavarde:\n";
        std::cin >> student.name;
        std::cout << "Iveskite pazymius (0 - pabaigti, -1 - generuoti atsitiktinai)\n";
        while (true) {
            int pazymys = inputMark();
            if (pazymys == -1) {
                int randPazymys = rand() % 10 + 1;
                student.marks.push_back(randPazymys);
                std::cout << randPazymys << "\n";
            }
            if (pazymys == 0) break;
            student.marks.push_back(pazymys);
        }
        std::cout << "Iveskite egzamino pazymi: \n";
        student.examMark = inputMark();
        for (int i = 0; i < student.marks.size(); i++) {
            galutinisVid = galutinisVid + student.marks[i];
        }
        std::sort(student.marks.begin(), student.marks.end());
        (student.marks.size() % 2 != 0) ? mediana = student.marks[student.marks.size() / 2] : mediana = (student.marks[student.marks.size() / 2] + student.marks[student.marks.size() / 2 + 1]) / 2;
        mediana = mediana * 0.4 + student.examMark * 0.6;
        galutinisVid = galutinisVid / student.marks.size() * 0.4 + student.examMark * 0.6;
        student.vid = galutinisVid;
        student.median = mediana;
        grupe.push_back(student);
    }
    std::cout << std::setw(8) << "Pavarde" << std::setw(16) << "Vardas" << std::setw(24) << "Galutinis(vid.)/" << std::setw(25) << "Galutinis(med.)\n";
    std::cout << "-----------------------------------------------------------------------------------\n";
    for (int i = 0; i < grupe.size(); i++) {
        std::cout << std::setw(8) << grupe[i].surname << std::setw(16) << grupe[i].name << std::setw(17) << std::setprecision(3) << grupe[i].vid << std::setw(23) << grupe[i].median << "\n";
    }

}
