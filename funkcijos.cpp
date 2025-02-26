#include "funkcijos.h"

int InputMark() {
    int value;
    while (true) {
        if (cin >> value && value <= 10 && value > -1) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite tinkamą pažymį nuo 1 iki 10 (0 - pabaigti)";
        }
    }
}

int InputMarkNum() {
    int value;
    while (true) {
        if (cin >> value && value > 0) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite tinkamą pažymių skaičių";
        }
    }
}

int InputExamMark() {
    int value;
    while (true) {
        if (cin >> value && value <= 10 && value > 0) {
            return value;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw L"\007Įveskite tinkamą pažymį nuo 1 iki 10";
        }
    }
}

bool InputSortType() {
	bool value;
	while (true) {
		if (cin >> value) {
			return value;
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw L"\007Įveskite 0 arba 1";
		}
	}

float Mean(Student st) {
    return (std::accumulate(st.marks.begin(), st.marks.end(), 0) * 1.0) / (st.marks.size() * 1.0);
}

float Median(Student st) {
    float median = 0;
    sort(st.marks.begin(), st.marks.end());
    (st.marks.size() % 2 != 0) ? median = st.marks[st.marks.size() / 2] : median = (st.marks[st.marks.size() / 2] + st.marks[st.marks.size() / 2 - 1]) / 2.0;
    median = median * 0.4 + st.examMark * 0.6;
    return median;
}

bool CompareByName(Student a, Student b) {
    return a.name < b.name;
}

bool CompareBySurname(Student a, Student b) {
    return a.surname < b.surname;
}

bool CompareByVid(Student a, Student b) {
    return a.vid < b.vid;
}

bool CompareByMed(Student a, Student b) {
    return a.median < b.median;
}

void Readfile(std::wifstream& inputFile, vector<Student>& grupe) {
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

void FileGen(int n) {
    string name;
    name = "studentai" + std::to_string(n) + ".txt";
	std::ofstream file(name);

    std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 10);
    file << setw(17) << left << "Pavarde" << setw(17) << left << "Vardas" << setw(10) << left << "ND1"
        << setw(10) << left << "ND2" << setw(10) << left << "ND3" << setw(10) << left << "ND4" << setw(10) << left << "ND5" << setw(9) << left << "Egzaminas";
    for (int i = 0; i < n; i++) {
        file << endl;
        file << setw(17) << left << "Pavarde" + std::to_string(i+1) << setw(17) << left << "Vardas" + std::to_string(i+1)
            << setw(10) << left << dist(mt) << setw(10) << left << dist(mt) << setw(10) << left << dist(mt) << setw(10) << left << dist(mt)
            << setw(10) << left << dist(mt) << setw(9) << left << dist(mt);
    }
	file.close();
}