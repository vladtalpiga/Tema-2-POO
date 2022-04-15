#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Contract{

   int nrContract;
   int anul;
   string beneficiar;
   string furnizor;
   int valoare;

public:

// Constructor & destructor

    Contract(){

        this-> nrContract = 0;
        this-> anul = 0;
        this-> beneficiar = "";
        this-> furnizor = "";
        this-> valoare = 0;
    }

    Contract(int nrContract, int anul, string beneficiar, string furnizor, int valoare){

        this-> nrContract = nrContract;
        this-> anul = anul;
        this-> beneficiar = beneficiar;
        this-> furnizor = furnizor;
        this-> valoare = valoare;
    }

    Contract(const Contract& c){

        this-> nrContract = c.nrContract;
        this-> anul = c.anul;
        this-> beneficiar = c.beneficiar;
        this-> furnizor = c.furnizor;
        this-> valoare = c.valoare;
    }

    virtual ~Contract(){};

// Setters & getters

    void setNrContract(int nrContract){

        this-> nrContract = nrContract;
    }

    int getNrContract(){

        return nrContract;
    }

    void setAnul(int anul){

        this-> anul = anul;
    }

    int getAnul(){

        return anul;
    }

    void setBeneficiar(string beneficiar){

        this-> beneficiar = beneficiar;
    }

    string getBeneficiar(){

        return beneficiar;
    }

    void setFurnizor(string furnizor){

        this-> furnizor = furnizor;
    }

    string getFurnizor(){

        return furnizor;
    }

    void setValoare(int valoare){

        this-> valoare = valoare;
    }

    int getValoare(){

        return valoare;
    }

// Functii virtuale

    virtual void citire(){

        cout<<"Numar contract: ";
        cin>>nrContract;

        cout<<"Anul semnarii contractului: ";
        cin>>anul;

        cout<<"Numele beneficiarului: ";
        cin>>beneficiar;

        cout<<"Numele furnizorului: ";
        cin>>furnizor;

        cout<<"Valoarea produsului: ";

        try{

        cin >> valoare;

        if(valoare < 0)

            throw(valoare);

        }

        catch (int val){

            cout << "Valoarea este invalida, introduceti din nou: ";
            cin >> val;
            valoare = val;
        }
    }

    virtual void afisare(){

        cout<<"Numar contract: "<<nrContract<<endl;

        cout<<"Anul semnarii contractului: "<<anul<<endl;

        cout<<"Numele beneficiarului: "<<beneficiar<<endl;

        cout<<"Numele furnizorului: "<<furnizor<<endl;

        cout<<"Valoarea produsului: "<<valoare<<endl;
    }

// Supraincarcare ">>", "<<", "="

    friend istream& operator>>(istream& in, Contract& c){

        cout<<"Numar contract: ";
        in>>c.nrContract;

        cout<<"Anul semnarii contractului: ";
        in>>c.anul;

        cout<<"Numele beneficiarului: ";
        in>>c.beneficiar;

        cout<<"Numele furnizorului: ";
        in>>c.furnizor;

        cout<<"Valoarea totala a produsului: ";
        in>>c.valoare;

        return in;
    }


    friend ostream& operator<<(ostream& out, Contract& c){

        cout<<"Contractul cu numarul ";
        out<<c.nrContract;

        cout<<" a fost semnat in anul ";
        out<<c.anul;

        cout<<" de catre beneficiarul ";
        out<<c.beneficiar;

        cout<<". Contractul este oferit de furnizorul ";
        out<<c.furnizor;

        cout<<" si are valoare totala de ";
        out<<c.valoare;
        cout<<".";

        return out;
    }

    Contract& operator=(const Contract& c){

        nrContract = c.nrContract;
        anul = c.anul;
        beneficiar = c.beneficiar;
        furnizor = c.furnizor;
        valoare = c.valoare;

        return *this;
    }


};

class ContractInchiriere: public Contract{

    int perioada;

public:

// Functii citire, afisare pt vectorul declarat dinamic

    void citire(){

    Contract::citire();
    cout << "Perioada inchirierii: ";

    try{

        cin >> perioada;

        if(perioada <= 0)

            throw(perioada);

    }

    catch (int per){

        cout << "Perioada este invalida, introduceti din nou: ";
        cin >> per;
        perioada = per;
    }
    }

    void afisare(){

    Contract::afisare();
    cout << "Perioada inchirierii: "<< perioada << endl;
    }

// Constructor & destructor

    ContractInchiriere(): Contract(){

        perioada = 0;
    }

    ContractInchiriere(int nrContract, int anul, string beneficiar, string furnizor, int valoare, int perioada): Contract(nrContract, anul, beneficiar, furnizor, valoare){

        this-> perioada = perioada;
    }

    ContractInchiriere(const ContractInchiriere& ci): Contract(ci){

        this-> perioada = ci.perioada;
    }

    ~ContractInchiriere(){};

// Setters & getters

    void setPerioada(int perioada){

        this-> perioada = perioada;
    }

    int getPerioada(){

        return perioada;
    }

    friend istream& operator>>(istream& in, ContractInchiriere& ci){

        in >> dynamic_cast <Contract&> (ci);

        cout << "Introduceti perioada: ";
        in >> ci.perioada;

        return in;
    }

    friend ostream& operator<<(ostream& out, ContractInchiriere& ci){

        out << dynamic_cast <Contract&> (ci);

        cout << "Perioada este de ";
        out << ci.perioada;
        cout << "luni";

        return out;
    }

};


class Dosar{

    vector <ContractInchiriere*> v;
    int nrContracteInchiriere;

public:

// Constructors & destructor

    Dosar(){

//        *v = NULL;
        this-> nrContracteInchiriere = 0;
    }

    Dosar(int nrContracteInchiriere){

        this-> nrContracteInchiriere = nrContracteInchiriere;
    }

    Dosar(const Dosar& d){

        this-> nrContracteInchiriere = d.nrContracteInchiriere;
    }

    ~Dosar(){};

//Setters & getters

    void setNrContracteInchiriere(int nrContracteInchiriere){

        this-> nrContracteInchiriere = nrContracteInchiriere;
    }

    int getNrContracteInchiriere(){

        return nrContracteInchiriere;
    }

//Citire & afisare vector

    void citireDosar();
    void afisareDosar();
    void valxPerioada();
};

void Dosar::citireDosar(){

        int i;

        cout << "Introduceti numarul de contracte: ";
        cin >> nrContracteInchiriere;
        cout << endl;

        for(i = 0; i < nrContracteInchiriere; i++){

            v.push_back(new ContractInchiriere());
        }

        i = 0;

        for (auto p = v.begin(); p != v.end(); p++) {

            cout << "Contractul " << i+1 << ":" << endl;
            (*p) -> citire();
            cout << endl;
            i++;
        }
}


void Dosar :: afisareDosar(){

        int i = 0;

        if(!v.empty()){

            cout << "Dosarul contine: " << endl;

            for (auto p = v.begin(); p != v.end(); p++) {

                cout << endl << "Contractul " << i+1 << ":" << endl;
                i++;
                (*p) -> afisare();

            }
            } else {

                cout << "Dosarul nu contine niciun contract." << endl;
            }
}


void Dosar :: valxPerioada(){

    int total = 0, i = 0;

    if(!v.empty()){

        cout << "Valoarea contractelor:" << endl << endl;

        for(auto p = v.begin(); p != v.end(); p++){

            cout << "Contractul " << i+1 << " are valoarea " << (*dynamic_cast <Contract*> (*p)).getValoare() << "/luna, pentru o perioada de " << (*dynamic_cast <ContractInchiriere*> (*p)).getPerioada() << " luni.";
            cout << " Valoarea totala a chiriei este " << ((*dynamic_cast <Contract*> (*p)).getValoare()) * ((*dynamic_cast <ContractInchiriere*> (*p)).getPerioada()) << "." << endl;
            i++;
            total += ((*dynamic_cast <Contract*> (*p)).getValoare()) * ((*dynamic_cast <ContractInchiriere*> (*p)).getPerioada());
        }

        cout << endl << "Valoarea totala a contractelor este " << total << "." << endl << endl;

    } else {

        cout << "Dosarul nu contine niciun contract." << endl;
    }

}

int meniu(){

    int tasta;

    cout<<endl<<"Apasati tasta corespunzatoare comenzii pe care doriti sa o executati:"<<endl<<endl;
    cout<<"1. Citirea contractelor din dosar"<<endl;
    cout<<"2. Afisarea contractelor din dosar"<<endl;
    cout<<"3. Afisarea valorilor tuturor contractelor"<<endl<<endl;
    cout<<"Pentru a parasi meniul apasati orice alta tasta."<<endl<<endl;

    cin>>tasta;

    cout<<endl;

    return tasta;

}

int main()
{
    Dosar d;
    int option;
    bool k = true;

    while(k){

        option = meniu();

        switch(option){

        case 1:
            {
                d.citireDosar();
                break;
            }

        case 2:
            {
                d.afisareDosar();
                break;
            }

        case 3:
            {
                d.valxPerioada();
                break;
            }

        default:
            {
                cout << "La revedere!" << endl;
                k = false;
            }
    }
}

    return 0;
}
