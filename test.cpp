#include <iostream>
#include "Vector.cpp"
using namespace std;

void testnorm();
void testdiv();
void testmult();
void testsum();
void testmag();
void testinit();

int main ()
{
    testnorm();
    //testdiv();
    //testmult();
    // testsum();
    // testmag();
    // testinit();
    return 0;
}

void testnorm()
{
    Vector vec1 = {1.0, -2.0, -2.0};
    Vector normVec1 = vec1.normalize();
    cout << "normVec1 is " << normVec1.Y << endl;
}

void testdiv()
{
    Vector vec1 = {2.0, -2.0, -2.0};

    Vector nConstProd = vec1 / 4;
    cout << "nConstDiv.X is " << nConstProd.X << endl;
}

void testmult()
{
    Vector vec1 = {2.0, -2.0, -2.0};

    Vector nConstProd = vec1 * 3;
    cout << "nConstProd.X is " << nConstProd.X << endl;

    Vector rConstProd = 3 * vec1;
    cout << "rConstProd.X is " << rConstProd.X << endl;
}

void testsum()
{
    Vector vec1 = {1.0, -2.0, -2.0};
    Vector vec2 = {3.0, 6.0, 9.0};

    Vector sum = vec1 + vec2;

    sum.printVector();

    if(sum.X == 4.0)
        cout << "sum.X is " << sum.X << endl;
    else
        cout << "vec.magnitude() is not 4, it is " << sum.X << endl;
}

void testmag()
{
    Vector vec = {1.0, -2.0, -2.0};

    if(vec.magnitude() == 3.0)
        cout << "vec.magnitude() is " << vec.magnitude() << endl;
    else
        cout << "vec.magnitude() is not 3, it is " << vec.magnitude() << endl;
}

void testinit()
{
    float Num1 , Num2 , Num3 ;

    printf("Please Enter the First Number:");
    scanf("%f" , &Num1);

    printf("Please Enter the Second Number:");
    scanf("%f" , &Num2);

    printf("Please Enter the Third Number:");
    scanf("%f" , &Num3);

    printf("the First result is =%.0f \n" , Num1);
    printf("the Second result is =%.2f \n" , Num2);
    printf("the Third result is =%.4f \n" , Num3);
}


