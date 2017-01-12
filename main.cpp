#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

char sep[]="!@£$%^&()_}{|':?><±§`~ ;][,", operatori[]="+-/%",nr[]="0123456789";
char dictionar[11][8];
int nrUnit;
short raspuns;

struct date
{
    int unitMasura;
    double valoareInitiala, valoareFinala;
    short unitInitial, unitInitial2, unitFinal;
    char expresie[256];
}input;





// CREEARE DICTIONARE //

void dictionarLungime()
{
    strcpy(dictionar[1], "mm");
    strcpy(dictionar[2], "cm");
    strcpy(dictionar[3], "dm");
    strcpy(dictionar[4], "m");
    strcpy(dictionar[5], "dam");
    strcpy(dictionar[6], "hm");
    strcpy(dictionar[7], "km");
    strcpy(dictionar[8], "in");
    strcpy(dictionar[9], "ft");
    strcpy(dictionar[10], "yd");
}
void dictionarArie()
{
    strcpy(dictionar[1], "mm^2");
    strcpy(dictionar[2], "cm^2");
    strcpy(dictionar[3], "dm^2");
    strcpy(dictionar[4], "m^2");
    strcpy(dictionar[5], "dam^2");
    strcpy(dictionar[6], "hm^2");
    strcpy(dictionar[7], "km^2");
    strcpy(dictionar[8], "in^2");
    strcpy(dictionar[9], "ft^2");
    strcpy(dictionar[10], "yd^2");
}
void dictionarVolum()
{
    strcpy(dictionar[1], "mm^3");
    strcpy(dictionar[2], "cm^3");
    strcpy(dictionar[3], "dm^3");
    strcpy(dictionar[4], "m^3");
    strcpy(dictionar[5], "dam^3");
    strcpy(dictionar[6], "hm^3");
    strcpy(dictionar[7], "km^3");
    strcpy(dictionar[8], "in^3");
    strcpy(dictionar[9], "ft^3");
    strcpy(dictionar[10], "yd^3");
}
void dictionarTimp()
{
    strcpy(dictionar[1], "ms");
    strcpy(dictionar[2], "cs");
    strcpy(dictionar[3], "ds");
    strcpy(dictionar[4], "s");
    strcpy(dictionar[5], "min");
    strcpy(dictionar[6], "h");
    strcpy(dictionar[7], "zi");
    strcpy(dictionar[8], "luna");
    strcpy(dictionar[9], "an");
}
void dictionarViteza()
{
    strcpy(dictionar[1], "m/s");
    strcpy(dictionar[2], "mph");
    strcpy(dictionar[3], "km/h");
}
void dictionarTemperatura()
{
    strcpy(dictionar[1], "C");
    strcpy(dictionar[2], "F");
    strcpy(dictionar[3], "K");
}
void dictionarMasa()
{
    strcpy(dictionar[1], "mg");
    strcpy(dictionar[2], "cg");
    strcpy(dictionar[3], "dg");
    strcpy(dictionar[4], "g");
    strcpy(dictionar[5], "dag");
    strcpy(dictionar[6], "hg");
    strcpy(dictionar[7], "kg");
    strcpy(dictionar[8], "lb");
    strcpy(dictionar[9], "oz");
    strcpy(dictionar[10], "t");
}
void dictionarEnergie()
{
    strcpy(dictionar[1], "J");
    strcpy(dictionar[2], "kJ");
    strcpy(dictionar[3], "cal");
    strcpy(dictionar[4], "kcal");
    strcpy(dictionar[5], "W/s");
    strcpy(dictionar[6], "W/h");
}
void dictionarPresiune()
{
    strcpy(dictionar[1], "Pa");
    strcpy(dictionar[2], "kPa");
    strcpy(dictionar[3], "MPa");
    strcpy(dictionar[4], "bar");
    strcpy(dictionar[5], "N/mm^2");
    strcpy(dictionar[6], "Torr");
    strcpy(dictionar[7], "atm");
    strcpy(dictionar[8], "PSI");
}
void dictionarDensitate()
{
    strcpy(dictionar[1], "kg/m^3");
    strcpy(dictionar[2], "kg/l");
    strcpy(dictionar[3], "g/m^3");
    strcpy(dictionar[4], "g/l");
    strcpy(dictionar[5], "lb/in^3");
    strcpy(dictionar[6], "lb/ft^3");
    strcpy(dictionar[7], "t/m^3");
}
void dictionarConsumCombustibil()
{
    strcpy(dictionar[1], "l/100km");
    strcpy(dictionar[2], "km/l");
    strcpy(dictionar[3], "mpg");
}





// TRANSFORMARI UNITATI //

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

double transformareInMetrii2()
{
    double valoareMetrii2=0;
    if (input.unitInitial == 8)
        valoareMetrii2 = input.valoareInitiala * 0.0006452;
    if (input.unitInitial == 9)
        valoareMetrii2 = input.valoareInitiala * 0.0929;
    if (input.unitInitial == 10)
        valoareMetrii2 = input.valoareInitiala * 0.836127816;
    if (input.unitInitial < 8)
    {
        short exponent = abs (input.unitInitial - 4);
        unsigned long diferenta=1;
        for (int i=0; i<exponent; i++)
            diferenta *= 100;
        if (input.unitInitial > 4)
            valoareMetrii2 = input.valoareInitiala * diferenta;
        else
            valoareMetrii2 = input.valoareInitiala / diferenta;
    }
    return valoareMetrii2;

}
void transformareDinMetrii2( double valoareMetrii2 )
{
    if (input.unitFinal == 8)
        input.valoareFinala = valoareMetrii2 / 0.0006452;
    if (input.unitFinal == 9)
        input.valoareFinala = valoareMetrii2 / 0.0929;
    if (input.unitFinal == 10)
        input.valoareFinala = valoareMetrii2 / 0.836127816;
    if (input.unitFinal < 8)
    {
        short exponent = abs (input.unitFinal - 4);
        unsigned long diferenta=1;
        for (int i=0; i<exponent; i++)
            diferenta *= 100;
        if (input.unitFinal > 4)
            input.valoareFinala = valoareMetrii2 / diferenta;
        else
            input.valoareFinala = valoareMetrii2 * diferenta;
    }
}

double transformareInMetrii3()
{
    double valoareMetrii3=0;
    if (input.unitInitial == 8)
        valoareMetrii3 = input.valoareInitiala * 0.000016387064;
    if (input.unitInitial == 9)
        valoareMetrii3 = input.valoareInitiala * 0.02832;
    if (input.unitInitial == 10)
        valoareMetrii3 = input.valoareInitiala * 0.76456;
    if (input.unitInitial < 8)
    {
        short exponent = abs (input.unitInitial - 4);
        unsigned long diferenta=1;
        for (int i=0; i<exponent; i++)
            diferenta *= 1000;
        if (input.unitInitial > 4)
            valoareMetrii3 = input.valoareInitiala * diferenta;
        else
            valoareMetrii3 = input.valoareInitiala / diferenta;
    }
    return valoareMetrii3;
    
}
void transformareDinMetrii3( double valoareMetrii3 )
{
    if (input.unitFinal == 8)
        input.valoareFinala = valoareMetrii3 / 0.000016387064;
    if (input.unitFinal == 9)
        input.valoareFinala = valoareMetrii3 / 0.02832;
    if (input.unitFinal == 10)
        input.valoareFinala = valoareMetrii3 / 0.76456;
    if (input.unitFinal < 8)
    {
        short exponent = abs (input.unitFinal - 4);
        unsigned long diferenta=1;
        for (int i=0; i<exponent; i++)
            diferenta *= 1000;
        if (input.unitFinal > 4)
            input.valoareFinala = valoareMetrii3 / diferenta;
        else
            input.valoareFinala = valoareMetrii3 * diferenta;
    }
}

double transformareInSecunde()
{
    double valoareSecunde = 0;
    if (input.unitInitial == 5)
        valoareSecunde = input.valoareInitiala * 60;
    if (input.unitInitial == 6)
        valoareSecunde = input.valoareInitiala * 3600;
    if (input.unitInitial == 7)
        valoareSecunde = input.valoareInitiala * 86400;
    if (input.unitInitial == 8)
        valoareSecunde = input.valoareInitiala * 2628000;
    if (input.unitInitial == 9)
        valoareSecunde = input.valoareInitiala * 31536000;
    if (input.unitInitial <5)
    {
        short exponent = abs(input.unitInitial-4);
        unsigned long diferenta=1;
        for (int i=0; i < exponent; i++)
            diferenta *= 10;
        valoareSecunde = input.valoareInitiala / diferenta;
    }
    return valoareSecunde;
}
void transformareDinSecunde( double valoareSecunde )
{
    if (input.unitFinal == 5)
        input.valoareFinala = valoareSecunde / 60;
    if (input.unitFinal == 6)
        input.valoareFinala = valoareSecunde / 3600;
    if (input.unitFinal == 7)
        input.valoareFinala = valoareSecunde / 86400;
    if (input.unitFinal == 8)
        input.valoareFinala = valoareSecunde / 2628000;
    if (input.unitFinal == 9)
        input.valoareFinala = valoareSecunde / 31536000;
    if (input.unitFinal < 5)
    {
        short exponent = abs(input.unitFinal-4);
        unsigned long diferenta=1;
        for (int i=0; i < exponent; i++)
            diferenta *= 10;
        input.valoareFinala = valoareSecunde * diferenta;
    }
}

double transformareInMetriiSec()
{
    double valoareMetriiSec=0;
    if (input.unitInitial == 1)
        return input.valoareInitiala;
    if (input.unitInitial == 2)
        valoareMetriiSec = input.valoareInitiala * 0.44704;
    if (input.unitInitial == 3)
        valoareMetriiSec = input.valoareInitiala * 0.27777778;
    return valoareMetriiSec;
}
void transformareDinMetriiSec( double valoareMetriiSec)
{
    if (input.unitFinal == 1)
        input.valoareFinala = valoareMetriiSec;
    if (input.unitFinal == 2)
        input.valoareFinala = valoareMetriiSec / 0.44704;
    if (input.unitFinal == 3)
        input.valoareFinala = valoareMetriiSec / 0.27777778;
}

double transformareInC()
{
    double valoareC=0;
    if (input.unitInitial == 1)
        return input.valoareInitiala;
    if (input.unitInitial == 2)
        valoareC = (input.valoareInitiala - 32) * 5/9;
    if (input.unitInitial == 3)
        valoareC = input.valoareInitiala - 273.15;
    return valoareC;
}
void transformareDinC( double valoareC)
{
    if (input.unitFinal == 1)
        input.valoareFinala = valoareC;
    if (input.unitFinal == 2)
        input.valoareFinala = valoareC * 9/5 + 32;
    if (input.unitFinal == 3)
        input.valoareFinala = valoareC + 273.15;
}

double transformareInGrame()
{
    double valoareGrame=0;
    if (input.unitInitial == 8)
        valoareGrame = input.valoareInitiala * 453.592;
    if (input.unitInitial == 9)
        valoareGrame = input.valoareInitiala * 28.3495;
    if (input.unitInitial == 10)
        valoareGrame = input.valoareInitiala * 1000000;
    if (input.unitInitial < 8)
    {
        short exponent = abs (input.unitInitial - 4);
        unsigned long diferenta=1;
        for (int i=0; i<exponent; i++)
            diferenta *= 10;
        if (input.unitInitial > 4)
            valoareGrame = input.valoareInitiala * diferenta;
        else
            valoareGrame = input.valoareInitiala / diferenta;
    }
    return valoareGrame;
}
void transformareDinGrame( double valoareGrame )
{
    if (input.unitFinal == 8)
        input.valoareFinala = valoareGrame / 453.592;
    if (input.unitFinal == 9)
        input.valoareFinala = valoareGrame / 28.3495;
    if (input.unitFinal == 10)
        input.valoareFinala = valoareGrame / 1000000;
    if (input.unitFinal < 8)
    {
        short exponent = abs (input.unitFinal - 4);
        unsigned long diferenta=1;
        for (int i=0; i<exponent; i++)
            diferenta *= 10;
        if (input.unitFinal > 4)
            input.valoareFinala = valoareGrame / diferenta;
        else
            input.valoareFinala = valoareGrame * diferenta;
    }
}

double transformareInJoule()
{
    double valoareJoule = 0;
    if (input.unitInitial == 1)
        return input.valoareInitiala;
    if (input.unitInitial == 2)
        valoareJoule = input.valoareInitiala * 1000;
    if (input.unitInitial == 3)
        valoareJoule = input.valoareInitiala * 4.1868;
    if (input.unitInitial == 4)
        valoareJoule = input.valoareInitiala * 4186.8;
    if (input.unitInitial == 6)
        valoareJoule = input.valoareInitiala * 3600;
    return valoareJoule;
}
void transformareDinJoule( double valoareJoule )
{
    if (input.unitFinal == 1)
        input.valoareFinala = valoareJoule;
    if (input.unitFinal == 2)
        input.valoareFinala = valoareJoule / 1000;
    if (input.unitFinal == 3)
        input.valoareFinala = valoareJoule / 4.1868;
    if (input.unitFinal == 4)
        input.valoareFinala = valoareJoule / 4186.8;
    if (input.unitFinal == 6)
        input.valoareFinala = valoareJoule / 3600;
}

double transformareInPa()
{
    double valoarePa = 0;
    if (input.unitInitial == 1)
        return input.valoareInitiala;
    if (input.unitInitial == 2)
        valoarePa = input.valoareInitiala * 1000;
    if (input.unitInitial == 3)
        valoarePa = input.valoareInitiala * 1000000;
    if (input.unitInitial == 4)
        valoarePa = input.valoareInitiala * 98000;
    if (input.unitInitial == 5)
        valoarePa = input.valoareInitiala * 1000000;
    if (input.unitInitial == 6)
        valoarePa = input.valoareInitiala * 133.322368421;
    if (input.unitInitial == 7)
        valoarePa = input.valoareInitiala * 101325.2738;
    if (input.unitInitial == 8)
        valoarePa = input.valoareInitiala * 6894.75729317;
    return valoarePa;
}
void transformareDinPa( double valoarePa )
{
    if (input.unitFinal == 1)
        input.valoareFinala = valoarePa;
    if (input.unitFinal == 2)
        input.valoareFinala = valoarePa / 1000;
    if (input.unitFinal == 3)
        input.valoareFinala = valoarePa / 1000000;
    if (input.unitFinal == 4)
        input.valoareFinala = valoarePa / 98000;
    if (input.unitFinal == 5)
        input.valoareFinala = valoarePa / 1000000;
    if (input.unitFinal == 6)
        input.valoareFinala = valoarePa / 133.322368421;
    if (input.unitFinal == 7)
        input.valoareFinala = valoarePa / 101325.2738;
    if (input.unitFinal == 8)
        input.valoareFinala = valoarePa / 6894.75729317;
}

double transformareInKmM3()
{
    double valoareKmM3 = 0;
    if (input.unitInitial == 1)
        return input.valoareInitiala;
    if (input.unitInitial == 2)
        valoareKmM3 = input.valoareInitiala * 1000;
    if (input.unitInitial == 3)
        valoareKmM3 = input.valoareInitiala * 0.001;
    if (input.unitInitial == 4)
        return input.valoareInitiala;
    if (input.unitInitial == 5)
        valoareKmM3 = input.valoareInitiala * 27679.89858;
    if (input.unitInitial == 6)
        valoareKmM3 = input.valoareInitiala * 16.017940092904052;
    if (input.unitInitial == 7)
        valoareKmM3 = input.valoareInitiala * 1000;
    return valoareKmM3;
}
void transformareDinKmM3( double valoareKmM3 )
{
    if (input.unitFinal == 1)
        input.valoareFinala = valoareKmM3;
    if (input.unitFinal == 2)
        input.valoareFinala = valoareKmM3 / 1000;
    if (input.unitFinal == 3)
        input.valoareFinala = valoareKmM3 / 0.001;
    if (input.unitFinal == 4)
        input.valoareFinala = valoareKmM3;
    if (input.unitFinal == 5)
        input.valoareFinala = valoareKmM3 / 27679.89858;
    if (input.unitFinal == 6)
        input.valoareFinala = valoareKmM3 / 16.017940092904052;
    if (input.unitFinal == 7)
        input.valoareFinala = valoareKmM3 / 1000;
}

double transformareInL100km()
{
    double valoareL100km=0;
    if (input.unitInitial == 1)
        return input.valoareInitiala;
    if (input.unitInitial == 2)
        valoareL100km = 100 / input.valoareInitiala ;
    if (input.unitInitial == 3)
        valoareL100km = 235.2 / input.valoareInitiala;
    return valoareL100km;
}
void transformareDinL100km( double valoareL100km)
{
    if (input.unitFinal == 1)
        input.valoareFinala = valoareL100km;
    if (input.unitFinal == 2)
        input.valoareFinala = 100 / valoareL100km;
    if (input.unitFinal == 3)
        input.valoareFinala = 235.2 / valoareL100km;
}





// ANALIZA EXPRESIE //

bool valid( char * p )
{
    for( unsigned int i=0; i<strlen(sep); i++)
        if(strchr(p,sep[i]))
        {
            cout<<"Cerere invalida"<<endl;
            return false;
        }
    bool ok=false;
    for( unsigned int i=0; i<strlen(nr); i++ )
        if(strchr(p,nr[i]))
            ok=true;
    if(!ok)
        cout<<"Cerere invalida"<<endl;
    return ok;
}

bool verificareCifra( char * p )
{
    if(*p!='\0')
        return *p <= '9' && *p >='0';
    return false;
}
void getValoareInitiala( char *p )
{
    if(*p!='\0')
    {
    while (!verificareCifra(p))
        strcpy(p,p+1);
    
    input.valoareInitiala = 0;
    char valoareInitiala[256];
    short i=0;
    while ( verificareCifra(p) || *p == '.')
    {
        valoareInitiala[i++]=*p;
        strcpy(p,p+1);
    }
    input.valoareInitiala = atof(valoareInitiala);
    }
  //  cout<<input.valoareInitiala;
}
bool getUnitateInitiala( char *p )
{
    if(*p!='\0')
    for (int i=1; i<=10; i++)
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
    if(*p!='\0')
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
short op;
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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
        if(valid(p))
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

void citire1()
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
void citire2()
{
    cout<<"Introduceti expresia (conversie maxima din 2 unitati de masura intr-una)\n";
    cout<<"Exemplu pentru conversie din km si m in mm:\n";
    cout<<"3km+2m=mm\n";

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
            citire1();
        else
        if (raspuns == 2)
            citire2();
    }
}

int main()
{
    interogare();
	return 0;
}