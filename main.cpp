#include <iostream>
#include <cmath>

using namespace std;
struct  Quat
{
    double L0;
    double L1;
    double L2;
    double L3;
};

struct Ang
{
    double rx;
    double ry;
    double rz;
};

int main()
{
    setlocale(LC_ALL,"rus");
    const double Pi=M_PI;
    struct Ang A;
    struct  Quat Q;
    cout << "Введите rx: "<<endl;
    cin >> A.rx;
    cout << "Введите ry: "<<endl;
    cin >> A.ry;
    cout << "Введите rz: "<<endl;
    cin >> A.rz;
    //Перевод градусов в радианы
    A.rx=A.rx*Pi/180;
    A.ry=A.ry*Pi/180;
    A.rz=A.rz*Pi/180;

    Q.L0=cos(A.rx/2)*cos(A.ry/2)*cos(A.rz/2)-sin(A.rx/2)*sin(A.ry/2)*sin(A.rz/2);
    Q.L1=sin(A.rx/2)*sin(A.ry/2)*cos(A.rz/2)-cos(A.rx/2)*cos(A.ry/2)*sin(A.rz/2);
    Q.L2=sin(A.rx/2)*cos(A.ry/2)*cos(A.rz/2)-cos(A.rx/2)*sin(A.ry/2)*sin(A.rz/2);
    Q.L3=cos(A.rx/2)*sin(A.ry/2)*cos(A.rz/2)-sin(A.rx/2)*cos(A.ry/2)*sin(A.rz/2);

    cout << "Значения углов поворота"<<endl;
    cout << "(" << A.rx << " , " << A.ry << " , " << A.rz << ")"<<endl;
    cout << "Полученные значения кватерниона"<< endl;
    cout << "(" << Q.L0 << " , " << Q.L1 << " , " << Q.L2 << " , " << Q.L3 << ")"<<endl;

    return 0;

}
