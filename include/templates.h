#pragma once


template <class T>
void Readfile(std::wifstream& inputFile, T& grupe) { //skaitymas is failo
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
        buffer >> student.surname >> student.name;
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

template <class arr1, class arr2, class arr3>
void SortStudentsInGroups(arr1& kietiakai, arr2& vargsiukai, arr3 group, bool sortType) { //sorting function
    for (int i = 0; i < group.size(); i++) {
        if (sortType == 1) {
            if (group[i].vid < 5.0) {
                vargsiukai.push_back(group[i]);
            }
            else {
                kietiakai.push_back(group[i]);
            }
        }
        else {
            if (group[i].median < 5.0) {
                vargsiukai.push_back(group[i]);
            }
            else {
                kietiakai.push_back(group[i]);
            }
        }
    }
    kietiakai.shrink_to_fit();
    vargsiukai.shrink_to_fit();
}

template <class T>
void PrintIntoFile(T group, wstring fileName) {
    wstringstream output;
    output << setw(17) << left << L"Pavardė" << setw(17) << left << L"Vardas" << setw(20) << left << "Galutinis(vid.)" << setw(15) << left << "Galutinis(med.)\n";
    output << "-----------------------------------------------------------------------------------\n";
    for (int i = 0; i < group.size(); i++) {
        output << setw(17) << left << group[i].surname << setw(17) << left
            << group[i].name << setw(20) << left << setprecision(2) << fixed
            << group[i].vid << setw(15) << left << setprecision(2) << fixed << group[i].median << L"\n";
    }
    std::wofstream outputFile(fileName);
    outputFile.imbue(std::locale(outputFile.getloc(), new std::codecvt_utf8<wchar_t>));
    outputFile << output.str();
    outputFile.close();
}

template <class arr1, class arr2, class arr3>
void TestFunction(arr1& grupe, arr2& vargsiukai, arr3& kietiakai) {
    wcout << L"Is kiek irasu testuoti programa?";
    int testNum;
    while (true) {
        try {
            testNum = InputTestNum();
            break;
        }
        catch (const wchar_t* e) {
            std::wcerr << e << endl;
            continue;
        }
        catch (...) {
            std::wcerr << L"\007Nezinoma klaida" << endl;
            continue;
        }
    }
    wcout << L"Testo pradzia\n";
    for (int i = 0; i < 5; i++) {
        string inputFileName = "studentai" + std::to_string(testNum) + ".txt";
        wifstream inputFile(inputFileName);
        if (!inputFile) {
            std::wcerr << L"Failas nerastas\n";
            return;
        }
    
        std::ofstream testFile;
        if (std::is_same<typename std::decay<decltype(grupe)>::type, std::vector<Student>>::value)
            testFile.open("tyrimasVector.txt", std::ios::app);
        else if (std::is_same<typename std::decay<decltype(grupe)>::type, std::deque<Student>>::value)
            testFile.open("tyrimasDeque.txt", std::ios::app);
        else if (std::is_same<typename std::decay<decltype(grupe)>::type, std::list<Student>>::value)
            testFile.open("tyrimasList.txt", std::ios::app);
        else
            testFile.open("tyrimas.txt", std::ios::app); // Default fallback

    
        testFile << "Programos veikimas: \n";

        std::chrono::time_point<std::chrono::system_clock> programStart = std::chrono::system_clock::now();
        Readfile(inputFile, grupe);
        grupe.shrink_to_fit();
        std::chrono::time_point<std::chrono::system_clock> endReading = std::chrono::system_clock::now();

        std::chrono::time_point<std::chrono::system_clock> startSorting = std::chrono::system_clock::now();
        SortStudentsInGroups(kietiakai, vargsiukai, grupe, 1);
        grupe.clear();
        grupe.shrink_to_fit();
        sort(kietiakai.begin(), kietiakai.end(), CompareByVid);
        sort(vargsiukai.begin(), vargsiukai.end(), CompareByVid);
        std::chrono::time_point<std::chrono::system_clock> endSorting = std::chrono::system_clock::now();

        std::chrono::time_point<std::chrono::system_clock> startOutput = std::chrono::system_clock::now();
        wstring outputFileName = L"vargsiukuRezultatai.txt";
        PrintIntoFile(vargsiukai, outputFileName);
        outputFileName = L"kietiakuRezultatai.txt";
        PrintIntoFile(kietiakai, outputFileName);
        std::chrono::time_point<std::chrono::system_clock> endOutput = std::chrono::system_clock::now();
        std::chrono::time_point<std::chrono::system_clock> programEnd = std::chrono::system_clock::now();

        testFile << "Duomenu nuskaitymas is " << testNum << " irasu: " << std::chrono::duration<double>(endReading - programStart).count() << " s\n";
        testFile << "Studentu rusiavimas i 2 grupes is " << testNum << " irasu: " << std::chrono::duration<double>(endSorting - startSorting).count() << " s\n";
        testFile << "Surusiuotu studentu isvedimas is " << testNum << " irasu: " << std::chrono::duration<double>(endOutput - startOutput).count() << " s\n";
        testFile << "Visos programos veikimo laikas is " << testNum << " irasu: " << std::chrono::duration<double>(programEnd - programStart).count() << " s\n\n";
		grupe.clear();
		kietiakai.clear();
		vargsiukai.clear();
    }
    wcout << L"Testas baigtas. Patikrinkite tyrimas.txt\n";
}