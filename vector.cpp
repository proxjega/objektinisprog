#include "mylibrary.h"

int inputMark(){
    int value;
    while (true) {
        if (std::cin >> value && value <= 10 && value > -1) {
            return value;
        }
        else {
            std::cout << "\007Iveskite tinkama pazymi nuo 1 iki 10 (0 - pabaigti)" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int inputMarkNum() {
    int value;
    while (true) {
        if (std::cin >> value && value > 0) {
            return value;
        }
        else {
            std::cout << "\007Iveskite tinkama pazymiu skaiciu" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int inputExamMark() {
    int value;
    while (true) {
        if (std::cin >> value && value <= 10 && value > 0 ) {
            return value;
        }
        else {
            std::cout << "\007Iveskite tinkama pazymi nuo 1 iki 10" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

float Mean(Student st) {
    float mean = 0;
    for (int i = 0; i < st.marks.size(); i++) {
        mean = mean + st.marks[i];
    }
    mean = mean / st.marks.size() * 0.4 + st.examMark * 0.6;
    return mean;
}

float Median(Student st) {
    float median = 0;
    std::sort(st.marks.begin(), st.marks.end());
    (st.marks.size() % 2 != 0) ? median = st.marks[st.marks.size() / 2] : median = (st.marks[st.marks.size() / 2] + st.marks[st.marks.size() / 2 - 1]) / 2.0;
    median = median * 0.4 + st.examMark * 0.6;
    return median;
}

int main()
{
    srand(time(NULL));
    std::vector<Student> grupe;
    std::string names[5] = { "name1", "name2", "name3", "name4", "name5" };
    std::string surnames[5] = { "surname1", "surname2", "surname3", "surname4", "surname5" };
    float galutinisVid = 0;
    float mediana = 0;
    char menu;
    int markNum;
    int randExMark;
    int randMark;
    bool check = true;

    while (check == true) {
        Student student;
        std::cout << "---------------------------------\nMENU\n";
        std::cout << "1 - ranka ivesti duomenis\n2 - generuoti pazymius\n3 - generuoti ir pazymius ir studentu vardus, pavardes\n4 - baigti darba\n---------------------------------\n";
        std::cin >> menu;
        switch (menu)
        {
        case('1'):
            std::cout << "Iveskite studento varda:\n";
            std::cin >> student.name;
            std::cout << "Iveskite studento pavarde:\n";
            std::cin >> student.surname;
            std::cout << "Iveskite pazymius (0 - pabaigti)\n";
            while (true) {
                int mark = inputMark();
                if (mark == 0) {
                    if (student.marks.size() != 0) {
                        break;
                    }
                    else std::cout << "Iveskite bent viena pazymi\n";
                    continue;
                }
                student.marks.push_back(mark);
            }
            std::cout << "Iveskite egzamino pazymi:\n";
            student.examMark = inputExamMark();
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('2'):
            std::cout << "Iveskite studento varda:\n";
            std::cin >> student.name;
            std::cout << "Iveskite studento pavarde:\n";
            std::cin >> student.surname;
            std::cout << "Kiek pazymiu generuoti?\n";
            markNum = inputMarkNum();
            for (int i = 0; i < markNum; i++) {
                randMark = rand() % 10 + 1;
                std::cout << "Generuotas pazymys: " << randMark << "\n";
                student.marks.push_back(randMark);
            }
            randExMark = rand() % 10 + 1;
            std::cout << "Generuotas egzamino pazymys: " << randMark << "\n";
            student.examMark = randMark;
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('3'):
            student.name = names[rand() % 5];
            std::cout << "Generuotas vardas: " << student.name << std::endl;
            student.surname = surnames[rand() % 5];
            std::cout << "Generuota pavarde: " << student.surname << std::endl;
            std::cout << "Kiek pazymiu generuoti?\n";
            markNum = inputMarkNum();
            for (int i = 0; i < markNum; i++) {
                randMark = rand() % 10 + 1;
                std::cout << "Generuotas pazymys: " << randMark << "\n";
                student.marks.push_back(randMark);
            }
            randExMark = rand() % 10 + 1;
            std::cout << "Generuotas egzamino pazymys: " << randMark << "\n";
            student.examMark = randMark;
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('4'):
            check = false;
            break;
        default:
            std::cout << "Iveskite tinkama skaiciu nuo 1 iki 4\n";
            continue;
        }
    }
    std::cout << std::setw(8) << "Pavarde" << std::setw(16) << "Vardas" << std::setw(24) << "Galutinis(vid.)/" << std::setw(25) << "Galutinis(med.)\n";
    std::cout << "-----------------------------------------------------------------------------------\n";
    for (int i = 0; i < grupe.size(); i++) {
        std::cout << std::setw(8) << grupe[i].surname << std::setw(16) << grupe[i].name << std::setw(17) << std::setprecision(2) << std::fixed << grupe[i].vid << std::setw(23) << std::setprecision(2) << std::fixed << grupe[i].median << "\n";
    }

}
