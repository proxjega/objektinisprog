#include "mylibrary.h"

int main()
{
    _setmode(_fileno(stdout), _O_U8TEXT);
    srand(time(NULL));
    vector<Student> grupe;
    wstring names[5] = { L"name1", L"name2", L"name3", L"name4", L"name5" };
    wstring surnames[5] = { L"surname1", L"surname2", L"surname3", L"surname4", L"surname5" };
    float galutinisVid = 0;
    float mediana = 0;
    char menu;
    int markNum;
    int randExMark;
    int randMark;
    bool check = true;
	wstring fileName;
	wifstream inputFile;
	wofstream outputFile("rezultatai.txt");
    outputFile.close();

    while (check == true) {
        Student student;
        wcout << "---------------------------------\nMENU\n";
        wcout << L"1 - ranka įvesti duomenis\n2 - generuoti pažymius\n3 - generuoti ir pažymius ir studentų vardus, pavardės\n4 - įvesti duomenis iš failo\n5 - baigti darbą\n---------------------------------\n";
        cin >> menu;
        switch (menu)
        {
        case('1'):
            wcout << L"Įveskite studento vardą:\n";
            wcin >> student.name;
            wcout << L"Įveskite studento pavardę:\n";
            wcin >> student.surname;
            wcout << L"Įveskite pažymius (0 - pabaigti)\n";
            while (true) {
                int mark = InputMark();
                if (mark == 0) {
                    if (student.marks.size() != 0) {
                        break;
                    }
                    else wcout << L"Įveskite bent vieną pažymį\n";
                    continue;
                }
                student.marks.push_back(mark);
            }
            wcout << L"Įveskite egzamino pažymį:\n";
            student.examMark = InputExamMark();
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('2'):
            wcout << L"Įveskite studento vardą:\n";
            wcin >> student.name;
            wcout << L"Įveskite studento pavardę:\n";
            wcin >> student.surname;
            wcout << L"Kiek pažymių generuoti?\n";
            markNum = InputMarkNum();
            for (int i = 0; i < markNum; i++) {
                randMark = rand() % 10 + 1;
                wcout << L"Generuotas pažymys: " << randMark << "\n";
                student.marks.push_back(randMark);
            }
            randExMark = rand() % 10 + 1;
            wcout << L"Generuotas egzamino pažymys: " << randExMark << "\n";
            student.examMark = randExMark;
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('3'):
            student.name = names[rand() % 5];
            wcout << L"Generuotas vardas: " << student.name << endl;
            student.surname = surnames[rand() % 5];
            wcout << L"Generuota pavardė: " << student.surname << endl;
            wcout << L"Kiek pažymiu generuoti?\n";
            markNum = InputMarkNum();
            for (int i = 0; i < markNum; i++) {
                randMark = rand() % 10 + 1;
                wcout << L"Generuotas pažymys: " << randMark << "\n";
                student.marks.push_back(randMark);
            }
            randExMark = rand() % 10 + 1;
            wcout << L"Generuotas egzamino pažymys: " << randExMark << "\n";
            student.examMark = randExMark;
            student.vid = Mean(student);
            student.median = Median(student);
            grupe.push_back(student);
            break;
        case('4'):
            wcout << L"Iš kokio failo nuskaityti duomenis?\n";
			system("dir /b *.txt");
            wcin >> fileName;
            inputFile.open(fileName);
            if (!inputFile) {
                std::cerr << "Failas nerastas\n";
                break;
            }
            else {
                wstring temp;
                getline(inputFile, temp);
                wstringstream ss(temp);
                int counter = 0;
                while (ss >> temp) {
                    counter++;
                }
				wstringstream buffer;
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
            wcout << L"Įveskite tinkamą skaičių nuo 1 iki 5\n";
            continue;
        }
    }
	wcout << L"Pagal ką rušiuoti studentus? (1 - pagal vardą, 2 - pagal pavardę, 3 - pagal galutinį balą (vid.), 4 - pagal galutinį balą (med.))\n";
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
            wcout << L"Įveskite tinkama skaičių nuo 1 iki 4\n";
            continue;
        }
        break;
    }
    wstringstream output;
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
