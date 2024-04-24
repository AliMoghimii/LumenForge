#include "../Vector3D.cpp"

#include <iostream>
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
    testdiv();
    testmult();
    testsum();
    testmag();
    // testinit();
    return 0;
}

void testnorm()
{
    Vector3D vec1 = Vector3D(1.0, -2.0, -2.0);
    Vector3D normVec1 = vec1.normalize();
    cout << "normVec1 is " << normVec1.y << endl;
}

void testdiv()
{
    Vector3D vec1 = {2.0, -2.0, -2.0};

    Vector3D nConstDiv = vec1 / 4;
    if(nConstDiv.x == 0.5)
        cout << "nConstDiv.x is " << nConstDiv.x << endl;
    else
        cout << "nConstDiv.x is not 0.5, it is " << nConstDiv.x << endl;
}

void testmult()
{
    Vector3D vec1 = {2.0, -2.0, -2.0};

    Vector3D nConstProd = vec1 * 3;
    if(nConstProd.x == 6.0)
        cout << "nConstProd.x is " << nConstProd.x << endl;
    else
        cout << "nConstProd.x is not 6, it is " << nConstProd.x << endl;

    Vector3D rConstProd = 3 * vec1;
    if(rConstProd.x == 6.0)
        cout << "rConstProd.x is " << rConstProd.x << endl;
    else
        cout << "rConstProd.x is not 6, it is " << rConstProd.x << endl;
}

void testsum()
{
    Vector3D vec1 = {1.0, -2.0, -2.0};
    Vector3D vec2 = {3.0, 6.0, 9.0};

    Vector3D sum = vec1 + vec2;

    if(sum.x == 4.0)
        cout << "sum.x is " << sum.x << endl;
    else
        cout << "vec.magnitude() is not 4, it is " << sum.x << endl;
}

void testmag()
{
    Vector3D vec = {1.0, -2.0, -2.0};

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


