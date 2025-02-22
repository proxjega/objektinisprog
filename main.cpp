#include "mylibrary.h"

int main()
{
    _setmode(_fileno(stdout), _O_U8TEXT);
    srand(time(NULL));
    vector<Student> grupe;
    string names[5] = { "name1", "name2", "name3", "name4", "name5" };
    string surnames[5] = { "surname1", "surname2", "surname3", "surname4", "surname5" };
    float galutinisVid = 0;
    float mediana = 0;
    char menu;
    int markNum;
    int randExMark;
    int randMark;
    bool check = true;
	string fileName;
	ifstream inputFile;
	std::ofstream outputFile("rezultatai.txt");
    outputFile.close();

    while (check == true) {
        Student student;
        std::wcout << "---------------------------------\nMENU\n";
        std::wcout << L"1 - ranka įvesti duomenis\n2 - generuoti pažymius\n3 - generuoti ir pažymius ir studentų vardus, pavardės\n4 - įvesti duomenis iš failo\n5 - baigti darbą\n---------------------------------\n";
        cin >> menu;
        switch (menu)
        {
        case('1'):
            cout << "Įveskite studento vardą:\n";
            cin >> student.name;
            cout << "Įveskite studento pavardę:\n";
            cin >> student.surname;
            cout << "Įveskite pažymius (0 - pabaigti)\n";
            while (true) {
                int mark = InputMark();
                if (mark == 0) {
                    if (student.marks.size() != 0) {
                        break;
                    }
                    else cout << "Įveskite bent vieną pažymį\n";
                    continue;
                }
                student.marks.push_back(mark);
            }
            cout << "Įveskite egzamino pažymį:\n";
            student.examMark = InputExamMark();
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('2'):
            cout << "Įveskite studento vardą:\n";
            cin >> student.name;
            cout << "Įveskite studento pavardę:\n";
            cin >> student.surname;
            cout << "Kiek pažymių generuoti?\n";
            markNum = InputMarkNum();
            for (int i = 0; i < markNum; i++) {
                randMark = rand() % 10 + 1;
                cout << "Generuotas pažymys: " << randMark << "\n";
                student.marks.push_back(randMark);
            }
            randExMark = rand() % 10 + 1;
            cout << "Generuotas egzamino pažymys: " << randExMark << "\n";
            student.examMark = randExMark;
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('3'):
            student.name = names[rand() % 5];
            cout << "Generuotas vardas: " << student.name << endl;
            student.surname = surnames[rand() % 5];
            cout << "Generuota pavardė: " << student.surname << endl;
            cout << "Kiek pažymiu generuoti?\n";
            markNum = InputMarkNum();
            for (int i = 0; i < markNum; i++) {
                randMark = rand() % 10 + 1;
                cout << "Generuotas pažymys: " << randMark << "\n";
                student.marks.push_back(randMark);
            }
            randExMark = rand() % 10 + 1;
            cout << "Generuotas egzamino pažymys: " << randExMark << "\n";
            student.examMark = randExMark;
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('4'):
            cout << "Iš kokio failo nuskaityti duomenis?\n";
			system("dir /b *.txt");
            cin >> fileName;
            inputFile.open(fileName);
            if (!inputFile) {
                std::cerr << "Failas nerastas\n";
                break;
            }
            else {
                string temp;
                getline(inputFile, temp);
                stringstream ss(temp);
                int counter = 0;
                while (ss >> temp) {
                    counter++;
                }
				stringstream buffer;
				buffer << inputFile.rdbuf();
                inputFile.close();
                while (buffer) {
                    if (buffer.eof()) {
                        break;
                    }
                    Student student;
                    buffer >> student.name >> student.surname;
                    int mark = 0;
                    for (int i = 0; i < counter - 3; i++) {
                        buffer >> mark;
                        student.marks.push_back(mark);
                    }
                    buffer >> mark;
                    student.examMark = mark;
                    student.vid = Mean(student);
                    student.median = Median(student);
                    grupe.push_back(student);
                }
            }
            break;
        case('5'):
            check = false;
            break;
        default:
            cout << "Įveskite tinkamą skaičių nuo 1 iki 5\n";
            continue;
        }
    }
	cout << "Pagal ką rušiuoti studentus? (1 - pagal vardą, 2 - pagal pavardę, 3 - pagal galutinį balą (vid.), 4 - pagal galutinį balą (med.))\n";
    while (true) {
        cin >> menu;
        switch (menu)
        {
        case('1'):
            sort(grupe.begin(), grupe.end(), CompareByName);
            break;
        case('2'):
            sort(grupe.begin(), grupe.end(), CompareBySurname);
            break;
        case('3'):
            sort(grupe.begin(), grupe.end(), CompareByVid);
            break;
        case('4'):
            sort(grupe.begin(), grupe.end(), CompareByMed);
            break;
        default:
            cout << "Įveskite tinkama skaičių nuo 1 iki 4\n";
            continue;
        }
        break;
    }
    stringstream output;
    output << setw(17) << left << "Pavardė" << setw(17) << left << "Vardas" << setw(20) << left << "Galutinis(vid.)" << setw(15) << left << "Galutinis(med.)\n";
    output << "-----------------------------------------------------------------------------------\n";
    for (int i = 0; i < grupe.size(); i++) {
        output << setw(17) << left << grupe[i].surname << setw(17) << left << grupe[i].name << setw(20) << left << setprecision(2) << fixed << grupe[i].vid << setw(15) << left << setprecision(2) << fixed << grupe[i].median << "\n";
    }
    outputFile.open("rezultatai.txt");
	outputFile << output.str();
    outputFile.close();
    system("notepad \"rezultatai.txt\"");
	return 0;
   
}
