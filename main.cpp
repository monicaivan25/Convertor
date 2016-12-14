#include <iostream>
#include <string>

using namespace std;

short raspuns;

struct
{
    int unitMasura;
    double valoareInitiala, valoareFinala;
    short unitInitial, unitFinal;
    char expresie[256];
}input;


void lungime()
{
    if( !*input.expresie )
    {
        short exponent = abs(input.unitFinal-input.unitInitial);
        unsigned long diferenta=1;
        for (int i=0; i < exponent; i++)
            diferenta *= 10;
        if (input.unitInitial > input.unitFinal)
            input.valoareFinala = input.valoareInitiala * diferenta;
        else
            input.valoareFinala = input.valoareInitiala / diferenta;
        cout<<input.valoareFinala;
    }
    else
    {
        for (int i=0; i<strlen(input.expresie); i++);
    }
}
void arie()
{
    if( !*input.expresie )
    {
        short exponent = abs(input.unitFinal-input.unitInitial);
        unsigned long diferenta=1;
        for (int i=0; i < exponent; i++)
            diferenta *= 100;
        if (input.unitInitial > input.unitFinal)
            input.valoareFinala = input.valoareInitiala * diferenta;
        else
            input.valoareFinala = input.valoareInitiala / diferenta;
        cout<<input.valoareFinala;
    }
    else
    {
        for (int i=0; i<strlen(input.expresie); i++);
    }

}
void volum()
{
    if( !*input.expresie )
    {
        short exponent = abs(input.unitFinal-input.unitInitial);
        unsigned long diferenta=1;
        for (int i=0; i < exponent; i++)
            diferenta *= 1000;
        if (input.unitInitial > input.unitFinal)
            input.valoareFinala = input.valoareInitiala * diferenta;
        else
            input.valoareFinala = input.valoareInitiala / diferenta;
        cout<<input.valoareFinala;
    }
    else
    {
        for (int i=0; i<strlen(input.expresie); i++);
    }

}
void timp()
{
    
}
void viteza()
{
    
}
void temperatura()
{
    
}
void masa()
{
    
}
void energie()
{
    
}
void presiune()
{
    
}
void densitate()
{
    
}
void consumCombustibil()
{
    
}


void analizaInput( int numarCitit )
{
    if (numarCitit == 1)
        lungime();
    else
    if (numarCitit == 2)
        arie();
    else
    if (numarCitit == 3)
        volum();
    else
    if (numarCitit == 4)
        timp();
    else
    if (numarCitit == 5)
        viteza();
    else
    if (numarCitit == 6)
        temperatura();
    else
    if (numarCitit == 7)
        masa();
    else
    if (numarCitit == 8)
        energie();
    else
    if (numarCitit == 9)
        presiune();
    else
    if (numarCitit == 10)
        densitate();
    else
    if (numarCitit == 11)
        consumCombustibil();
}
void textLungime()
{
    cout<<"1. mm\n";
    cout<<"2. cm\n";
    cout<<"3. dm\n";
    cout<<"4. m\n";
    cout<<"5. dam\n";
    cout<<"6. hm\n";
    cout<<"7. km\n";
}
void textArie()
{
    cout<<"1. mm^2\n";
    cout<<"2. cm^2\n";
    cout<<"3. dm^2\n";
    cout<<"4. m^2\n";
    cout<<"5. dam^2\n";
    cout<<"6. hm^2\n";
    cout<<"7. km^2\n";
}
void textVolum()
{
    cout<<"1. mm^3\n";
    cout<<"2. cm^3\n";
    cout<<"3. dm^3\n";
    cout<<"4. m^3\n";
    cout<<"5. dam^3\n";
    cout<<"6. hm^3\n";
    cout<<"7. km^3\n";
}
void textTimp()
{
    cout<<"1. ms\n";
    cout<<"2. cs\n";
    cout<<"3. ds\n";
    cout<<"4. s\n";
    cout<<"5. min\n";
    cout<<"6. h\n";
    cout<<"7. zi\n";
}
void textViteza()
{
    
}
void textTemperatura()
{
    
}
void textMasa()
{
    
}
void textEnergie()
{
    
}
void textPresiune()
{
    
}
void textDensitate()
{
    
}
void textCombustibil()
{
    
}

void citire1()
{
    cout<<"Introduceti expresia\n";
    cout<<"(Exemplu pentru conversie din km si m in mm):\n";
    cout<<"(3km+2m) = mm\n";
    
    cin>>input.expresie;
    
    analizaInput(input.unitMasura);
}

void afisareTextUnitMasura()
{
    if (input.unitMasura == 1)
        textLungime();
    if (input.unitMasura == 2)
        textArie();
    if (input.unitMasura == 3)
        textVolum();
    if (input.unitMasura == 4)
        textTimp();
    if (input.unitMasura == 5)
        textViteza();
    if (input.unitMasura == 6)
        textTemperatura();
    if (input.unitMasura == 7)
        textMasa();
    if (input.unitMasura == 8)
        textEnergie();
    if (input.unitMasura == 9)
        textPresiune();
    if (input.unitMasura == 10)
        textDensitate();
    if (input.unitMasura == 11)
        textCombustibil();
}
void citire2()
{
    afisareTextUnitMasura();
    bool ok = true;
    
    cout<<"Unitatea de masura initiala:\n";
    cin>>input.unitInitial;
    
    if (input.unitInitial > 7 || input.unitInitial < 1)
    {
        cout<<"Cerere invalida";
        ok = false;
    }
    else
    {
        cout<<"Valoarea = ";
        cin>>input.valoareInitiala;
        cout<<"Unitatea de masura in care sa fie convertita valoarea = ";
        cin>>input.unitFinal;
        if (input.unitFinal > 7 || input.unitFinal < 1)
        {
            cout<<"Cerere invalida";
            ok = false;
        }
    }
    
    if (ok)
        analizaInput(input.unitMasura);
}
bool citireUnitateMasura()
{
    cout<< "Selectati unitatea de masura:\n";
    cout<<"1. Lungime\n";
    cout<<"2. Arie\n";
    cout<<"3. Volum\n";
    cout<<"4. Timp\n";
    cout<<"5. Viteza\n";
    cout<<"6. Temperatură\n";
    cout<<"7. Masa\n";
    cout<<"8. Energie\n";
    cout<<"9. Presiune\n";
    cout<<"10. Densitate\n";
    cout<<"11. Consum combustibil\n";
    
    cin>>input.unitMasura;
    if (input.unitMasura > 11 || input.unitMasura < 1)
    {
        cout<<"Cerere invalida";
        return false;
    }
    return true;
}

void interogare()
{
    cout<<"Selectati tipul de convertor:\n";
    cout<<"1. Pentru expresie\n";
    cout<<"2. Clasic\n";
    
    cin>>raspuns;
    
    if (citireUnitateMasura())
    {
        if (raspuns == 1)
            citire1();
        else
        if (raspuns == 2)
            citire2();
        else
            cout<< "Cerere invalida";
    }
}

int main()
{
    interogare();
}