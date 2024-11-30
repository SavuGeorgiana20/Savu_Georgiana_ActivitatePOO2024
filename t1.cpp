#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Bloc {
    string strada;
    int numarScari;
    int numarApartamente;
    int anConstructie;
    string tipMaterial;

    // Func?ie pentru afi?area detaliilor blocului
    void afiseazaDetalii() const {
        cout << "Blocul de pe strada " << strada
            << ", are " << numarScari << " scãri, "
            << "un numãr total de " << numarApartamente << " apartamente, "
            << "a fost construit în anul " << anConstructie
            << " ?i este realizat din materialul " << tipMaterial << "." << endl;
    }
};

// Func?ie pentru citirea datelor unui bloc
Bloc* citesteBloc() {
    Bloc* bloc = new Bloc;
    cout << "Introduce?i detaliile pentru un bloc:" << endl;
    cout << "Strada: ";
    cin.ignore(); 
    getline(cin, bloc->strada);
    cout << "Numãr scãri: ";
    cin >> bloc->numarScari;
    cout << "Numãr apartamente: ";
    cin >> bloc->numarApartamente;
    cout << "Anul construc?iei: ";
    cin >> bloc->anConstructie;
    cout << "Tip material: ";
    cin.ignore();
    getline(cin, bloc->tipMaterial);
    return bloc;
}

int main() {
    const int numarBlocuri = 10;
    vector<Bloc*> blocuri;

    // Citirea informa?iilor pentru 10 blocuri
    for (int i = 0; i < numarBlocuri; ++i) {
        cout << "Bloc #" << (i + 1) << ":" << endl;
        Bloc* bloc = citesteBloc();
        blocuri.push_back(bloc);
    }

    // Afi?area informa?iilor despre fiecare bloc
    cout << "\nDetaliile blocurilor introduse:" << endl;
    for (int i = 0; i < numarBlocuri; ++i) {
        cout << "Bloc #" << (i + 1) << ": ";
        blocuri[i]->afiseazaDetalii();
    }

    // Eliberarea memoriei alocate pentru blocuri
    for (Bloc* bloc : blocuri) {
        delete bloc;
    }

    return 0;
}