#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string nume;
    string numar_telefon;
};

void adaugaContact(vector<Contact>& agenda) {
    Contact contact;
    cout << "Introduceti numele contactului: ";
    cin >> contact.nume;
    cout << "Introduceti numarul de telefon: ";
    cin >> contact.numar_telefon;

    bool valid_contact = true;
    for (const Contact& existingContact : agenda) {
        if (existingContact.numar_telefon == contact.numar_telefon) {
            cout << "Acest numar de telefon exista deja in agenda!" << endl;
            valid_contact = false;
        }
        if (existingContact.nume == contact.nume) {
            cout << "Acest nume exista deja in agenda!" << endl;
            valid_contact = false;
        }
    }

    if (valid_contact) {
        agenda.push_back(contact);
        cout << "Contact adaugat cu succes!" << endl;
    }
}


void afiseazaAgenda(const vector<Contact>& agenda) {
    cout << "Agenda telefonica:" << endl;
    for (const Contact& contact : agenda) {
        cout << "Nume: " << contact.nume << ", Numar de telefon: " << contact.numar_telefon << endl;
    }
}

void salveazaInFisier(const vector<Contact>& agenda) {
    ofstream fout("date.txt");
    if (fout.is_open()) {
        for (const Contact& contact : agenda) {
            fout << contact.nume << " " << contact.numar_telefon << endl;
        }
        fout.close();
        cout << "Contactele au fost salvate in fisierul date.txt!" << endl;
    }
    else {
        cout << "Eroare la deschiderea fisierului!" << endl;
    }
}

int main() {
    vector<Contact> agenda;
    ifstream fin("date.txt");
    if (fin.is_open()) {
        string nume, numar_telefon;
        while (fin >> nume >> numar_telefon) {
            Contact contact;
            contact.nume = nume;
            contact.numar_telefon = numar_telefon;
            agenda.push_back(contact);
        }
        fin.close();
    }
    else {
        cout << "Nu s-a putut deschide fisierul date.txt. Un fisier nou va fi creat." << endl;
    }

    while (true) {
        cout << "1. Adauga contact" << endl;
        cout << "2. Afiseaza agenda" << endl;
        cout << "3. Salveaza in fisier" << endl;
        cout << "4. Iesire" << endl;
        int optiune;
        cin >> optiune;

        switch (optiune) {
        case 1:
            adaugaContact(agenda);
            break;
        case 2:
            afiseazaAgenda(agenda);
            break;
        case 3:
            salveazaInFisier(agenda);
            break;
        case 4:
            return 0;
        default:
            cout << "Optiune invalida. Va rugam sa introduceti o optiune valida." << endl;
        }
    }

    return 0;
}
