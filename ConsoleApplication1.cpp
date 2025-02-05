#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>


struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<float>Pazymiai;
    int egzoPazymys;
};
int main()
{
    Studentas studentas;
    int n;
    std::cout << "Iveskite studento varda:\n";
    std::cin >> studentas.vardas;
    std::cout << "Iveskite studento pavarde:\n";
    std::cin >> studentas.pavarde;
    std::cout << "Iveskite kiek pazymiu bus\n";
    std::cin >> n;
    std::cout << "Iveskite pazymius\n";
    for (int i = 0; i < n; i++) {
        float pazymys = 0;
        std::cin >> pazymys;
        studentas.Pazymiai.push_back(pazymys);
    }
    std::cout << "Iveskite egzamino pazymi: \n";
    std::cin >> studentas.egzoPazymys;
    float galutinis = 0;
    for (int i = 0; i < studentas.Pazymiai.size(); i++) {
        galutinis = galutinis + studentas.Pazymiai[i];
    }
    std::sort(studentas.Pazymiai.begin(), studentas.Pazymiai.end());
    float mediana = 0;
    (n % 2 != 0) ? mediana = studentas.Pazymiai[n / 2] : mediana = (studentas.Pazymiai[n / 2] + studentas.Pazymiai[n / 2 + 1]) / 2;
    mediana = mediana * 0.4 + studentas.egzoPazymys * 0.6;
    galutinis = galutinis / n * 0.4 + studentas.egzoPazymys * 0.6;
    std::cout << std::setw(8) << "Pavarde" << std::setw(16) << "Vardas" << std::setw(24) << "Galutinis(vid.)/" << std::setw(25) << "Galutinis(med.)\n";
    std::cout << "-----------------------------------------------------------------------------------\n";
    std::cout << std::setw(8) << studentas.pavarde << std::setw(16) << studentas.vardas << std::setw(17) << std::setprecision(3) << galutinis<< std::setw(23) << mediana << "\n";
}
