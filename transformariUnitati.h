struct date
{
	char expresie[256];
	short unitInitial, unitFinal;
    int unitMasura;
    double valoareInitiala, valoareFinala;
    
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
