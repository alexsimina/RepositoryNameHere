#include <bits/stdc++.h>
#define pi 3.1415926535897932384626433
using namespace std;

ifstream fin ("distantapuncte.in");
ofstream fout("distantapuncte.out");

struct coordonate
{
    int x, y;
};

istream& operator>>(istream& in, coordonate& a)
{
    in >> a.x >> a.y;
    return in;
}

ofstream& operator<<(ofstream& out, coordonate& a)
{
    out << a.x << " " << a.y;
    return out;
}

double LungimeSegment(coordonate& a, coordonate& b)
{
    int A, B;
    A = b.x - a.x;
    B = b.y - a.y;
    return sqrt(A*A + B*B);
}

int PozitieZInFunctieDeAB(coordonate& z, coordonate& a, coordonate& b) //punct z, a-b seg/dr
{
    //0 - pe dreapta
    // < 0 - sub
    // > 0 - peste
    //-|+; | fiind linia
    //Caz 1:
    //    -       B |    +       A
    //              |
    // A       +    | B       -

    //Caz 2:
    // A       -    | B       +
    //              |
    //    +       B |    -       A

    //Caz 3:
    //      -       |      +
    // A          B | B          A
    //      +       |      -

    //Caz 4:
    //      A       |       B
    //   +      -   |   -      +
    //      B       |       A

    int ecuatiaDreptei;

    ecuatiaDreptei = z.x * (b.y - a.y) + z.y * (a.x - b.x) + a.y * b.x - a.x * b.y;

    if (a.x < b.x)
    {//Caz 1, 2, 3
        ecuatiaDreptei = -ecuatiaDreptei;
    }

    else if (a.x == b.x && a.y > b.y)
    {//Caz 4
        ecuatiaDreptei = -ecuatiaDreptei;
    }

    return ecuatiaDreptei;
}

double ArieTriunghi(coordonate& a, coordonate& b, coordonate& c) //varfuri
{
    double arie = (double) (a.x * b.y + b.x * c.y + c.x * a.y - c.x * b.y - b.x * a.y - a.x * c.y) / (double) 2;

    return abs(arie);
}

bool SeIntersecteazaSeg(coordonate& a, coordonate& b, coordonate& c, coordonate& d) //a-b seg1, c-d seg2
{
    int up, dw, le ,ri;

    up = PozitieZInFunctieDeAB(d, a, b);
    dw = PozitieZInFunctieDeAB(c, a, b);
    le = PozitieZInFunctieDeAB(a, c, d);
    ri = PozitieZInFunctieDeAB(b, c, d);

    if((up == 0 && dw == 0) || (le == 0 && ri == 0)) // |--|---|--|
    {
        if ((max(c.y , d.y) >= min(a.y, b.y) && min(c.y, d.y) <= max(a.y, b.y)) ||
            (max(c.x , d.x) >= min(a.x, b.x) && min(c.x, d.x) <= max(a.x, b.x))) return true;
        return false;
    }

    return (up == 0 || dw == 0 || ((up >> 31) != (dw >> 31))) && (le == 0 || ri == 0 || ((le >> 31) != (ri >> 31)));
}

double AriePoligon(int nrPuncte, coordonate puncte[])
{
    int i;
    double arie = 0;
    puncte[nrPuncte + 1] = puncte[1];
    for(i = 1; i <= nrPuncte; i++)
        arie += (puncte[i].x * puncte[i+1].y - puncte[i+1].x * puncte[i].y);

    return abs(arie / 2);
}

bool VerifyDacaPotDucePPLaSeg(coordonate& z, coordonate& a, coordonate& b)
{
    bool rsp = true;
    double lung, lat, diff, drY, stY;

    if(a.y > b.y) swap(a, b);

    if(a.x <= b.x)
    {
        drY = b.y;
        stY = a.y;
    }
    else
    {
        drY = a.y;
        stY = b.y;
    }
    lung = b.y - a.y;
    lat = b.x - a.x;

    if(lat == 0) return z.y >= a.y && z.y <= b.y;

    diff = lung / lat;
    if(min(a.x, b.x) + abs(z.y - stY) * diff > z.x) rsp = false;
    if(max(a.x, b.x) + abs(z.y - drY) * diff < z.x) rsp = false;
    return rsp;
}

double DistantaDeLaPunct(coordonate& z, coordonate& a, coordonate& b, bool segment) //punct z, a-b seg/dr
{
    double ec, A, B, C;
    double rez;

    A = b.y - a.y;
    B = a.x - b.x;
    if(segment == false || VerifyDacaPotDucePPLaSeg(z, a, b))
    {
        C = a.y * b.x - a.x * b.y;
        ec = abs(z.x * A + z.y * B + C);
        rez = ec / sqrt(A*A + B*B);
    }

    else
        rez = min(LungimeSegment(z, a), LungimeSegment(z, b));


    return rez;
}

bool SeAflaPunctInPoligon(coordonate& punct, int nrVarfuri, coordonate varfuri[])
{
    coordonate random = {punct.x + 1, 2005};
    int nrIntersectii{};

    varfuri[0] = varfuri[nrVarfuri];
    varfuri[nrVarfuri + 1] = varfuri[1];
    cout << "   ";
    for(int i = 1; i <= nrVarfuri; i++)
    {
        int seIntesecteaza = SeIntersecteazaSeg(punct, random, varfuri[i], varfuri[i + 1]);
        if (seIntesecteaza)
        {
            nrIntersectii++;
            if (PozitieZInFunctieDeAB(punct, varfuri[i], varfuri[i + 1]) == 0) return true;
        }
    }

    return nrIntersectii % 2;
}

double GradeToRadians(double& grade)
{
    double radians = grade / 180 * pi;
    if (radians < 0) radians += 2 * pi;
    return radians;
}

double RadiansToGrade(double& radians)
{
    double grade = radians / pi * 180;
    if (grade < 0) grade += 360;
    return grade;
}

coordonate a, b;

int main()
{

    fin >> a >> b;
    double dist = LungimeSegment(a, b);
    fout << dist * dist;
    return 0;
}