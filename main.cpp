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

double transformareInMetrii()
{
    double valoareMetrii=0;
    if (input.unitInitial == 8)
        valoareMetrii = input.valoareInitiala * 0.0254;
    if (input.unitInitial == 9)
        valoareMetrii = input.valoareInitiala * 0.3048;
    if (input.unitInitial == 10)
        valoareMetrii = input.valoareInitiala * 0.9144002494;
    if (input.unitInitial < 8)
    {
        short exponent = abs (input.unitInitial - 4);
        unsigned long diferenta=1;
        for (int i=0; i<exponent; i++)
            diferenta *= 10;
        if (input.unitInitial > 4)
            valoareMetrii = input.valoareInitiala * diferenta;
        else
            valoareMetrii = input.valoareInitiala / diferenta;
    }
    return valoareMetrii;
}

void transformareDinMetrii( double valoareMetrii )
{
    if (input.unitFinal == 8)
        input.valoareFinala = valoareMetrii / 0.0254;
    if (input.unitFinal == 9)
        input.valoareFinala = valoareMetrii / 0.3048;
    if (input.unitFinal == 10)
        input.valoareFinala = valoareMetrii / 0.9144002494;
    if (input.unitFinal < 8)
    {
        short exponent = abs (input.unitFinal - 4);
        unsigned long diferenta=1;
        for (int i=0; i<exponent; i++)
            diferenta *= 10;
        if (input.unitFinal > 4)
            input.valoareFinala = valoareMetrii / diferenta;
        else
            input.valoareFinala = valoareMetrii * diferenta;
    }
}
void lungime()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<input.valoareInitiala;
        else
        if (input.unitInitial <= 7 && input.unitFinal <= 7)
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
            double valoareMetrii = transformareInMetrii();
            transformareDinMetrii(valoareMetrii);
            cout<<input.valoareFinala;

        }
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
        if (input.unitInitial == input.unitFinal)
            cout<<input.valoareInitiala;
        else
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
        if (input.unitInitial == input.unitFinal)
            cout<<input.valoareInitiala;
        else
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
    }
    else
    {
        for (int i=0; i<strlen(input.expresie); i++);
    }

}
void timp()
{
    double valoareSecunde=0;
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<input.valoareInitiala;
        else
        if (input.unitInitial <= 4 && input.unitFinal <= 4)
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
            if (input.unitInitial == 5)
                valoareSecunde = input.valoareInitiala * 60;
            if (input.unitInitial == 6)
                valoareSecunde = input.valoareInitiala * 3600;
            if (input.unitInitial == 7)
                valoareSecunde = input.valoareInitiala * 86400;
            if (input.unitInitial <5)
            {
                short exponent = abs(input.unitInitial-4);
                unsigned long diferenta=1;
                for (int i=0; i < exponent; i++)
                    diferenta *= 10;
                valoareSecunde = input.valoareInitiala / diferenta;

            }
            
            if (input.unitFinal == 5)
                input.valoareFinala = valoareSecunde / 60;
            if (input.unitFinal == 6)
                input.valoareFinala = valoareSecunde / 3600;
            if (input.unitFinal == 7)
                input.valoareFinala = valoareSecunde / 86400;
            if (input.unitFinal < 5)
            {
                short exponent = abs(input.unitFinal-4);
                unsigned long diferenta=1;
                for (int i=0; i < exponent; i++)
                    diferenta *= 10;
                input.valoareFinala = valoareSecunde * diferenta;
            }
            cout<<input.valoareFinala;
        }
    }
    else
    {
        for (int i=0; i<strlen(input.expresie); i++);
    }

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
    cout<<"8. in\n";
    cout<<"9. ft\n";
    cout<<"10. yd\n";
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
    cout<<"1. m/s\n";
    cout<<"2. m/min\n";
    cout<<"3. m/h\n";
    cout<<"4. km/s\n";
    cout<<"5. km/min\n";
    cout<<"6. km/h\n";
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
    
    cout<<"Unitatea de masura initiala = ";
    cin>>input.unitInitial;
    
    if ((input.unitInitial > 10 || (input.unitInitial>6 && input.unitMasura==5)) || input.unitInitial < 1)
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
        if (input.unitFinal > 10 || input.unitFinal < 1)
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