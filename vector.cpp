//#include "mylibrary.h"
//
//int inputMark(){
//    int value;
//    while (true) {
//        if (std::cin >> value && value <= 10 && value > -2) {
//            return value;
//        }
//        else {
//            std::cout << "Iveskite tinkama pazymi nuo 1 iki 10 (0 - pabaigti, -1 - generuoti atsitiktinai)" << std::endl;
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        }
//    }
//}
//
//int inputExamMark() {
//    int value;
//    while (true) {
//        if (std::cin >> value && value <= 10 && value > -2 && value != 0) {
//            return value;
//        }
//        else {
//            std::cout << "Iveskite tinkama pazymi nuo 1 iki 10 (-1 - generuoti atsitiktinai)" << std::endl;
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        }
//    }
//}
//
//int main()
//{
//    srand(time(NULL));
//
//    std::vector<Student> grupe;
//    std::string names[5] = { "name1", "name2", "name3", "name4", "name5" };
//    float galutinisVid = 0;
//    float mediana = 0;
//
//    while (true) {
//        Student student;
//        std::cout << "Iveskite studento varda:(0 - pabaigti, -1 - generuoti atsitiktinai)\n";
//        std::cin >> student.name;
//        if (student.name == "0") break;
//        if (student.name == "-1") {
//            student.name = names[rand() % 5];
//        }
//        std::cout << "Iveskite studento pavarde:\n";
//        std::cin >> student.surname;
//        std::cout << "Iveskite pazymius (0 - pabaigti, -1 - generuoti atsitiktinai)\n";
//        while (true) {
//            int mark = inputMark();
//            if (mark == -1) {
//                int randMark = rand() % 10 + 1;
//                mark = randMark;
//                std::cout << "Generuotas pazymys: " << randMark << "\n";
//            }
//            if (mark == 0) {
//                if (student.marks.size() != 0) {
//                    break;
//                }
//                else std::cout << "Iveskite bent viena pazymi\n";
//                continue;
//            }
//            student.marks.push_back(mark);
//        }
//        std::cout << "Iveskite egzamino pazymi (-1 - generuoti atsitiktinai):\n";
//        student.examMark = inputExamMark();
//        if (student.examMark == -1) {
//            student.examMark = rand() % 10 + 1;
//            std::cout << "Generuotas pazymys: " << student.examMark << "\n";
//        }
//        for (int i = 0; i < student.marks.size(); i++) {
//            galutinisVid = galutinisVid + student.marks[i];
//        }
//        std::sort(student.marks.begin(), student.marks.end());
//        (student.marks.size() % 2 != 0) ? mediana = student.marks[student.marks.size() / 2] : mediana = (student.marks[student.marks.size() / 2] + student.marks[student.marks.size() / 2 - 1]) / 2.0;
//        mediana = mediana * 0.4 + student.examMark * 0.6;
//        galutinisVid = galutinisVid / student.marks.size() * 0.4 + student.examMark * 0.6;
//        student.vid = galutinisVid;
//        student.median = mediana;
//        grupe.push_back(student);
//    }
//    std::cout << std::setw(8) << "Pavarde" << std::setw(16) << "Vardas" << std::setw(24) << "Galutinis(vid.)/" << std::setw(25) << "Galutinis(med.)\n";
//    std::cout << "-----------------------------------------------------------------------------------\n";
//    for (int i = 0; i < grupe.size(); i++) {
//        std::cout << std::setw(8) << grupe[i].surname << std::setw(16) << grupe[i].name << std::setw(17) << std::setprecision(2) << std::fixed << grupe[i].vid << std::setw(23) << std::setprecision(2) << std::fixed << grupe[i].median << "\n";
//    }
//
//}
