//#include <iostream>
//#include <vector>
//#include <string>
//#include <iomanip>
//#include <algorithm>
//
//
//struct Studentas {
//    std::string vardas;
//    std::string pavarde;
//    int *Pazymiai = new int[100];
//    float egzoPazymys;
//    float vidMedian = 0;
//    float vidVid = 0;
//};
//int main()
//{
//    std::vector<Studentas> grupe;
//    while (true) {
//        Studentas studentas;
//        std::cout << "Iveskite studento varda:(iveskite 0 jei norite pabaigti)\n";
//        std::cin >> studentas.vardas;
//        if (studentas.vardas == "0") break;
//        std::cout << "Iveskite studento pavarde:\n";
//        std::cin >> studentas.pavarde;
//        std::cout << "Iveskite pazymius (iveskite 0 kai norite pabaigti)\n";
//        int j = 0;
//        while (true) {
//            float pazymys = 0;
//            std::cin >> pazymys;
//            if (pazymys == 0) break;
//            studentas.Pazymiai[j] = pazymys;
//            j++;
//        }
//        std::cout << "Iveskite egzamino pazymi: \n";
//        std::cin >> studentas.egzoPazymys;
//        float galutinis = 0;
//        for (int i = 0; i < j; i++) {
//            galutinis = galutinis + studentas.Pazymiai[i];
//        }
//        std::sort(studentas.Pazymiai, studentas.Pazymiai + j);
//        float mediana = 0;
//        ((j+1) % 2 != 0) ? mediana = studentas.Pazymiai[(j) / 2] : mediana = (studentas.Pazymiai[(j) / 2] + studentas.Pazymiai[(j) / 2 + 1]) / 2;
//        mediana = mediana * 0.4 + studentas.egzoPazymys * 0.6;
//        galutinis = galutinis / (j) * 0.4 + studentas.egzoPazymys * 0.6;
//        studentas.vidVid = galutinis;
//        studentas.vidMedian = mediana;
//        grupe.push_back(studentas);
//    }
//    std::cout << std::setw(8) << "Pavarde" << std::setw(16) << "Vardas" << std::setw(24) << "Galutinis(vid.)/" << std::setw(25) << "Galutinis(med.)\n";
//    std::cout << "-----------------------------------------------------------------------------------\n";
//    for (int i = 0; i < grupe.size(); i++) {
//        std::cout << std::setw(8) << grupe[i].pavarde << std::setw(16) << grupe[i].vardas << std::setw(17) << std::setprecision(3) << grupe[i].vidVid << std::setw(23) << grupe[i].vidMedian << "\n";
//    }
//    std::cout << "end";
//    for (int i = 0; i < grupe.size(); i++) {
//        delete[] grupe[i].Pazymiai;
//    }
//}
