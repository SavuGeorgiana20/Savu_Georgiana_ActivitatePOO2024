#include<iostream>

using namespace std;

class Cofetarie {
private:
	string nume; //
	int nrAngajati;//
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

public:
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}

	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	Cofetarie operator=(const Cofetarie& c) {
		if (&c != this) {
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this;
	}

	~Cofetarie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	Cofetarie operator+(Cofetarie c)const {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c.nrAngajati; i++) {
			aux[i + this->nrAngajati] = c.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Cofetarie& operator+=(Cofetarie c) {
		*this = *this + c;
		return *this;
	}

	Cofetarie operator+(float salariu)const {
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	friend Cofetarie operator+(float salariu, Cofetarie c) {
		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++) {
			temp.salarii[i] = c.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	
	explicit operator int() {
		return this->nrAngajati;
	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s = s + this->nrAngajati;
		}
		return s;
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Are produse vegane:" << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Adaos:" << this->adaos << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}
	}
	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}

	friend ostream& operator<<(ostream& output, Cofetarie c);

	friend istream& operator>>(istream& input, Cofetarie& c)
	{
		cout << "Nume";
		input >> c.nume;
		cout << "Nr angajati";
		input >> c.nrAngajati;
		if (c.salarii != NULL) {
			delete[]c.salarii;
		}
		if (c.nrAngajati > 0) {
			c.salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				cout << "Salariul " << i + 1 << ":";
				input >> c.salarii[i];
			}
		}
		else {
			c.salarii = NULL;
		}

		cout << "Are produse vegane? 1-DA; 0-NU: ";
		input >> c.esteVegana;
		cout << "Adaos comercial: ";
		input >> c.adaos;

		return input;
	}

	//pt c1<c2 din main
	bool operator<(Cofetarie c) {
		return this->nrAngajati < c.nrAngajati;
	}

	//operator index
	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "Indexul este inafara limitelor";
			//throw
			//try
			//catch
		}
	}
};

int Cofetarie::TVA = 9;


ostream& operator<<(ostream& output, Cofetarie c)  
{
	output << "Nume:" << c.nume << endl;
	output << "Nr angajati:" << c.nrAngajati << endl;
	if (c.salarii != NULL) {
		for (int i = 0; i < c.nrAngajati; i++) {
			cout << c.salarii[i] << " ";
		}
	}
	cout << endl;
	output << "Are produse vegane:" << (c.esteVegana ? "DA" : "NU") << endl;
	output << "An deschidere:" << c.anDeschidere << endl;
	output << "Adaos:" << c.adaos << endl;
	output << "TVA:" << Cofetarie::TVA << endl;

	return output;
}


//clasa mostenitoare
class CofetarieOnline : public Cofetarie {
	char* site;
	int nrColaboratori;

public:
	
	CofetarieOnline() :Cofetarie() {
		this->site = NULL;
		this->nrColaboratori = 0;
	}

	
	CofetarieOnline(const char* site, int nrColaboratori, string nume, int nrAngajati, float* salarii, bool esteVegana, const int anDeschidere, float adaos) :Cofetarie(nume, nrAngajati, esteVegana, anDeschidere, adaos) {
		
		this->setNrAngajati(nrAngajati, salarii);
		this->site = new char[strlen(site) + 1];
		strcpy_s(this->site, strlen(site) + 1, site);
		this->nrColaboratori = nrColaboratori;
	}

	
	CofetarieOnline(CofetarieOnline& co) :Cofetarie(co) {

		this->site = new char[strlen(co.site) + 1];
		strcpy_s(this->site, strlen(co.site) + 1, co.site);
		this->nrColaboratori = co.nrColaboratori;
	}

	//destructor
	~CofetarieOnline() {
		if (this->site != NULL) {
			delete[]this->site;
		}
	}

	//operator =
	CofetarieOnline operator=(const CofetarieOnline& co) {
		if (this != &co) {
			//apelez op = din clasa parinte
			Cofetarie::operator=(co);
			if (this->site != NULL) {
				delete[]this->site;
			}
			this->site = new char[strlen(co.site) + 1];
			strcpy_s(this->site, strlen(co.site) + 1, co.site);
			this->nrColaboratori = co.nrColaboratori;

		}
		return *this;
	}
	explicit operator int() {
		return this->nrColaboratori;
	}

	//calculeaza Nr Mediu Angajati Per Colaborator
	float getcalculeazaNrMediuAngajatiPerColaborator() {
		return this->getNrAngajati() / (float)this->nrColaboratori; 
		
	}
	friend ostream& operator<<(ostream& out, const CofetarieOnline& co);

};

ostream& operator<<(ostream& out, const CofetarieOnline& co) {
	out << (Cofetarie)co; 
	out << "Site-ul Cofetariei: ";
	out << co.site;
	out << endl;
	out << "Nr colaboratori: ";
	out << co.nrColaboratori;
	out << endl;
	out << endl;
	return out;
}
int main() {

	CofetarieOnline co1;
	float* vector = new float[3] {100, 200, 300}; 
	CofetarieOnline co2("cofetarie.ro", 4, "cofetarie.ro", 3, vector, 1, 2020, 10);
	CofetarieOnline co3(co2); 
	CofetarieOnline co5 = co2; 

	CofetarieOnline co4;
	co4 = co2;// operator egal

	cout << co4 << endl;
	cout << co2 << endl;

	int nrColaboratori = (int)co2;
	cout << "Numar colaboratori= " << nrColaboratori << endl;

	cout << "Numarul mediu de angajati pentru fiecare colaborator: " << co2.getcalculeazaNrMediuAngajatiPerColaborator();

	return 645;

}