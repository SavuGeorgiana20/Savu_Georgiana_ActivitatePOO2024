#include<iostream>

using namespace std;

class Cofetarie
{
private:
	string nume;
	int nrAngajati;
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;
public:
	Cofetarie() :adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}


	Cofetarie(string nume, int nrAngajati, bool esteVegana, int an, float adaos) :anDeschidere(an)
	{
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = esteVegana;
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
		for (int i = 0; i < c.nrAngajati; i++)
			this->salarii[i] = c.salarii[i];


		this->esteVegana = c.esteVegana;


		this->adaos = c.adaos;
	}

	
	~Cofetarie()
	{
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}

	
	Cofetarie operator=(const Cofetarie& c) {
		
		if (&c != this) {
			this->nume = c.nume;

			this->nrAngajati = c.nrAngajati;

			if (this->salarii != NULL)
				delete[]this->salarii;

			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++)
				this->salarii[i] = c.salarii[i];


			this->esteVegana = c.esteVegana;

			this->adaos = c.adaos;
			
		}
		return *this;
	}





	string getNume()
	{
		return this->nume;
	}

	void setNume(string nume)
	{
		if (nume.length() > 1) {
			
			this->nume = nume;
		}
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}


	void setNrAngajati(int nrAngajati, float* salarii)
	{
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL)
				delete[]this->salarii;
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii()
	{
		return this->salarii;
	}

	float getSalariu(int index)
	{
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	
	Cofetarie operator+(Cofetarie c2)const {
		
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c2.nrAngajati;
		
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			
			aux[i] = this->salarii[i];
		}
		
		for (int i = 0; i < c2.nrAngajati; i++)
		{
			
			aux[i + this->nrAngajati] = c2.salarii[i];
		}
		
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		
		temp.salarii = aux;
		return temp;

	}
	Cofetarie operator+(float salarii)const
	{
		
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];

		
		for (int i = 0; i < this->nrAngajati; i++)
		{
			temp.salarii[i] = this->salarii[i];
		}
		
		temp.salarii[temp.nrAngajati] = salarii;
		temp.nrAngajati++;
		return temp;
	}

	
	friend Cofetarie operator+(float salarii, Cofetarie c) {

		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];


		for (int i = 0; i < c.nrAngajati; i++)
		{
			temp.salarii[i] = c.salarii[i];
		}

		temp.salarii[temp.nrAngajati] = salarii;
		temp.nrAngajati++;
		return temp;
	}


	friend Cofetarie operator+(float salarii, Cofetarie c);

	void afisare()
	{
		cout << "Nume: " << this->nume << endl;
		cout << "Nr. angajati: " << this->nrAngajati << endl;
		cout << "E vegana?: " << (this->esteVegana ? "da" : "nu") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << this->TVA << endl;
	}


	static void modificaTVA(int noulTVA)
	{
		if (noulTVA > 0)
			Cofetarie::TVA = noulTVA;

	}

	static int calculareNrTotalAngajati(int nrCofetarii, Cofetarie* vector)
	{
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++)
			suma += vector[i].nrAngajati;
		return suma;
	}

};

int Cofetarie::TVA = 9;

void f(Cofetarie c) {

}


int main()
{

	Cofetarie c1;
	Cofetarie c2("Minimal", 3, false, 2019, 10);

	int a = 9;
	int b = 6;
	int c = a + b;
	
	Cofetarie c3 = c1 + c2;
	Cofetarie c4 = c1.operator+(c2);
	Cofetarie c5 = c1 + 2000.0f; 
}