#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include "dictionare.h"
#include "transformariUnitati.h"

using namespace std;

char separator[]="!@£$%^&()_}{|':?><±§`~ ;][,";
char operatori[]="+-/%",nr[]="0123456789";
int nrUnit;
short raspuns,op;

// ANALIZA EXPRESIE //

bool isExpValid( char * p )
{
    for (unsigned int i=0; i < strlen(separator); i++ )
        if (strchr(p,separator[i]))
        {
            cout<<"Cerere invalida"<<endl;
            return false;
        }
    bool ok = false;
    for (unsigned int i=0; i < strlen(nr); i++ )
        if (strchr(p,nr[i]))
            ok = true;
    if (!ok)
        cout<<"Cerere invalida"<<endl;
    return ok;
}

bool verificareCifra( char * p )
{
    if (*p!='\0')
        return *p <= '9' && *p >='0';
    return false;
}
void getValoareInitiala( char *p )
{
    if (*p!='\0')
    {
		while (!verificareCifra(p))
			strcpy(p,p+1);
    
		char valoareInitiala[256];
		short i=0;
		while ( verificareCifra(p) || *p == '.')
		{
			valoareInitiala[i++]=*p;
			strcpy(p,p+1);
		}
		input.valoareInitiala = atof(valoareInitiala);
    }
}
bool getUnitateInitiala( char *p )
{
    if (*p!='\0')
    for (int i=1; i <= 10; i++)
        if (strncmp(p, dictionar[i],strlen(dictionar[i]))==0 )
        {
            input.unitInitial = i;
            strcpy(p,p+strlen(dictionar[i]));
            return true;
        }
    return false;
}

bool getUnitateFinala( char *p )
{
    if(*p == '=')
    {
		strcpy(p,p+1);
		for (int i=1; i<=10; i++)
        if (strcmp(p, dictionar[i])==0 )
        {
            input.unitFinal = i;
            strcpy(p,p+strlen(dictionar[i]));
            return true;
        }
    }
    return false;
}
void getOperator( char * p )
{
    if(*p != '\0')
    {
        if(*p=='+')
            op=1;
        if(*p=='-')
            op=2;
        if(*p=='*')
            op=3;
        if(*p=='/')
            op=4;
        strcpy(p,p+1);
    }
}

// FUNCTII PRINCIPALE //

void lungime()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareMetrii = transformareInMetrii();
            transformareDinMetrii(valoareMetrii);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareMetrii=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareMetrii = transformareInMetrii();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareMetrii += transformareInMetrii();
                    if (op==2)
                        valoareMetrii -= transformareInMetrii();
                    if (op==3)
                        valoareMetrii *= transformareInMetrii();
                    if (op==4)
                        valoareMetrii /= transformareInMetrii();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinMetrii(valoareMetrii);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void arie()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareMetrii2 = transformareInMetrii2();
            transformareDinMetrii2(valoareMetrii2);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareMetrii2=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareMetrii2 = transformareInMetrii2();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareMetrii2 += transformareInMetrii2();
                    if (op==2)
                        valoareMetrii2 -= transformareInMetrii2();
                    if (op==3)
                        valoareMetrii2 *= transformareInMetrii2();
                    if (op==4)
                        valoareMetrii2 /= transformareInMetrii2();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinMetrii2(valoareMetrii2);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void volum()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareMetrii3 = transformareInMetrii3();
            transformareDinMetrii3(valoareMetrii3);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareMetrii3=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareMetrii3 = transformareInMetrii3();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareMetrii3 += transformareInMetrii3();
                    if (op==2)
                        valoareMetrii3 -= transformareInMetrii3();
                    if (op==3)
                        valoareMetrii3 *= transformareInMetrii3();
                    if (op==4)
                        valoareMetrii3 /= transformareInMetrii3();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinMetrii3(valoareMetrii3);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void timp()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareSecunde=transformareInSecunde();
            transformareDinSecunde(valoareSecunde);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareSecunde=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareSecunde = transformareInSecunde();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareSecunde += transformareInSecunde();
                    if (op==2)
                        valoareSecunde -= transformareInSecunde();
                    if (op==3)
                        valoareSecunde *= transformareInSecunde();
                    if (op==4)
                        valoareSecunde /= transformareInSecunde();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinSecunde(valoareSecunde);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void viteza()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareMetriiSec=transformareInMetriiSec();
            transformareDinMetriiSec(valoareMetriiSec);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareMetriiSec=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareMetriiSec = transformareInMetriiSec();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareMetriiSec += transformareInMetriiSec();
                    if (op==2)
                        valoareMetriiSec -= transformareInMetriiSec();
                    if (op==3)
                        valoareMetriiSec *= transformareInMetriiSec();
                    if (op==4)
                        valoareMetriiSec /= transformareInMetriiSec();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinMetriiSec(valoareMetriiSec);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void temperatura()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareC=transformareInC();
            transformareDinC(valoareC);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareC=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareC = transformareInC();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareC += transformareInC();
                    if (op==2)
                        valoareC -= transformareInC();
                    if (op==3)
                        valoareC *= transformareInC();
                    if (op==4)
                        valoareC /= transformareInC();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinC(valoareC);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void masa()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareGrame=transformareInGrame();
            transformareDinGrame(valoareGrame);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareGrame=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareGrame = transformareInGrame();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareGrame += transformareInGrame();
                    if (op==2)
                        valoareGrame -= transformareInGrame();
                    if (op==3)
                        valoareGrame *= transformareInGrame();
                    if (op==4)
                        valoareGrame /= transformareInGrame();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinGrame(valoareGrame);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void energie()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == 5)
            input.unitInitial = 1;
        if (input.unitFinal == 5)
            input.unitFinal = 1;
        
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareJoule=transformareInJoule();
            transformareDinJoule(valoareJoule);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareJoule=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareJoule = transformareInJoule();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareJoule += transformareInJoule();
                    if (op==2)
                        valoareJoule -= transformareInJoule();
                    if (op==3)
                        valoareJoule *= transformareInJoule();
                    if (op==4)
                        valoareJoule /= transformareInJoule();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinJoule(valoareJoule);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void presiune()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoarePa=transformareInPa();
            transformareDinPa(valoarePa);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoarePa=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoarePa = transformareInPa();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoarePa += transformareInPa();
                    if (op==2)
                        valoarePa -= transformareInPa();
                    if (op==3)
                        valoarePa *= transformareInPa();
                    if (op==4)
                        valoarePa /= transformareInPa();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinPa(valoarePa);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void densitate()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareKmM3=transformareInKmM3();
            transformareDinKmM3(valoareKmM3);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareKmM3=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareKmM3 = transformareInKmM3();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareKmM3 += transformareInKmM3();
                    if (op==2)
                        valoareKmM3 -= transformareInKmM3();
                    if (op==3)
                        valoareKmM3 *= transformareInKmM3();
                    if (op==4)
                        valoareKmM3 /= transformareInKmM3();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinKmM3(valoareKmM3);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}
void consumCombustibil()
{
    if( !*input.expresie )
    {
        if (input.unitInitial == input.unitFinal)
            cout<<fixed<<input.valoareInitiala<<endl;
        else
        {
            double valoareL100km=transformareInL100km();
            transformareDinL100km(valoareL100km);
            cout<<fixed<<input.valoareFinala<<endl;
        }
    }
    else
    {
        char *p;
        double valoareL100km=0;
        p=input.expresie;
        if(isExpValid(p))
        {
            getValoareInitiala(p);
            if(!getUnitateInitiala(p))
                cout<<"Cerere invalida"<<endl;
            else
            {
                valoareL100km = transformareInL100km();
                getOperator(p);
                
                getValoareInitiala(p);
                
                if(!getUnitateInitiala(p))
                    cout<<"Cerere invalida"<<endl;
                else
                {
                    if (op==1)
                        valoareL100km += transformareInL100km();
                    if (op==2)
                        valoareL100km -= transformareInL100km();
                    if (op==3)
                        valoareL100km *= transformareInL100km();
                    if (op==4)
                        valoareL100km /= transformareInL100km();
                    
                    
                    if(!getUnitateFinala(p))
                        cout<<"Cerere invalida"<<endl;
                    else
                    {
                        transformareDinL100km(valoareL100km);
                        cout<<fixed<<input.valoareFinala<<endl;
                    }
                }
            }
        }
    }
}





// CITIRE SI AFISARE TEXT //


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

bool verificareDateIntrare( short x )
{
    if (x < 1)
        return false;
    if (input.unitMasura == 1 || input.unitMasura == 2 || input.unitMasura == 3 || input.unitMasura == 7)
        if (x > 10)
            return false;
    if (input.unitMasura == 5 || input.unitMasura == 6 || input.unitMasura == 11)
        if (x > 3)
            return false;
    if (input.unitMasura == 4)
        if (x > 9)
            return false;
    if (input.unitMasura == 8)
        if (x > 6)
            return false;
    if (input.unitMasura == 9)
        if (x > 8)
            return false;
    if (input.unitMasura == 10)
        if (x > 7)
            return false;
    return true;
}

void creeareDictionar()
{
    if (input.unitMasura == 1)
    {
        nrUnit=10;
        dictionarLungime();
    }
    if (input.unitMasura == 2)
    {
        nrUnit=10;
        dictionarArie();
    }
    if (input.unitMasura == 3)
    {
        nrUnit=10;
        dictionarVolum();
    }
    if (input.unitMasura == 4)
    {
        nrUnit=9;
        dictionarTimp();
    }
    if (input.unitMasura == 5)
    {
        nrUnit=3;
        dictionarViteza();
    }
    if (input.unitMasura == 6)
    {
        nrUnit=3;
        dictionarTemperatura();
    }
    if (input.unitMasura == 7)
    {
        nrUnit=10;
        dictionarMasa();
    }
    if (input.unitMasura == 8)
    {
        nrUnit=6;
        dictionarEnergie();
    }
    if (input.unitMasura == 9)
    {
        nrUnit=8;
        dictionarPresiune();
    }
    if (input.unitMasura == 10)
    {
        nrUnit=7;
        dictionarDensitate();
    }
    if (input.unitMasura == 11)
    {
        nrUnit=3;
        dictionarConsumCombustibil();
    }
}
void afisareTextUnitMasura()
{
    for (int i=1; i<=nrUnit; i++)
        cout<<i<<". "<<dictionar[i]<<endl;
}

void citireClasic()
{
    creeareDictionar();
    afisareTextUnitMasura();
    bool ok = true;
    
    cout<<"Unitatea de masura initiala = ";
    cin>>input.unitInitial;
    
    if (!verificareDateIntrare(input.unitInitial))
    {
        cout<<"Cerere invalida"<<endl;
        ok = false;
    }
    else
    {
        cout<<"Valoarea = ";
        cin>>input.valoareInitiala;

        cout<<"Unitatea de masura in care sa fie convertita valoarea = ";
        cin>>input.unitFinal;
        if (!verificareDateIntrare(input.unitFinal))
        {
            cout<<"Cerere invalida"<<endl;
            ok = false;
        }
    }	
    
    if (ok)
        analizaInput(input.unitMasura);
}
void citireExpresie()
{
    cout<<"Introduceti o expresie de tipul:\n";
	cout<<"valoare1_unitate1_operator_valoare2_unitate2_=_unitate3\n";
    cout<<"Exemplu pentru conversie din km si m in mm: 3km+2m=mm\n";

    cin>>input.expresie;
	
    creeareDictionar();
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
        cout<<"Cerere invalida"<<endl;
        return false;
    }
    return true;
}

void interogare()
{
    cout<<"Selectati tipul de convertor:\n";
    cout<<"1. Clasic\n";
    cout<<"2. Pentru expresie\n";
    
    cin>>raspuns;
    
    if (raspuns<1 || raspuns>2)
        cout<< "Cerere invalida"<<endl;
    else
    if (citireUnitateMasura())
    {
        if (raspuns == 1)
            citireClasic();
        else
        if (raspuns == 2)
            citireExpresie();
    }
}

int main()
{
    interogare();
	return 0;
}