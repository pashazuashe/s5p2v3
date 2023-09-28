#include <iostream>
#include <vector>

using namespace std;

class MyArray {

private:
    vector<float> v;

public:
    MyArray() {

    }
    MyArray(int arg) {
        this->v = vector<float>(arg);
    }
    float operator [](int index) {
        if (index < v.size() && index >= 0) {
            return v[index];
        }
        else
            throw 0;
    }
    int GetSize() {
        return v.size();
    }
    void SetValue(int index, float value) {
        v[index] = value;
    }
    void PrintMyArray() {
        for (float i : v) {
            cout << i << " ";
        }
        cout << '\n';
    }
    bool operator ==(MyArray& v2) {
        bool result = true;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != v2[i]) {
                result = false;
            }
        }
        return result;
    }
    MyArray operator +(MyArray& v2) {
        MyArray result(v.size());
        for (int i = 0; i < v.size(); i++) {
            result.SetValue(i, v[i] + v2[i]);
        }
        return result;
    }
    MyArray operator -(MyArray& v2) {
        MyArray result(v.size());
        for (int i = 0; i < v.size(); i++) {
            result.SetValue(i, v[i] - v2[i]);
        }
        return result;
    }
    MyArray operator *(MyArray& v2) {
        MyArray result(v.size());
        for (int i = 0; i < v.size(); i++) {
            result.SetValue(i, v[i] * v2[i]);
        }
        return result;
    }
    MyArray operator *(float value) {
        MyArray result(v.size());
        for (int i = 0; i < v.size(); i++) {
            result.SetValue(i, v[i] * value);
        }
        return result;
    }
    MyArray operator /(MyArray& v2) {
        MyArray result(v.size());
        for (int i = 0; i < v.size(); i++) {
            result.SetValue(i, v[i] / v2[i]);
        }
        return result;
    }

};

int main()
{
    int size = 0;

    cin >> size;

    MyArray v1(size);
    MyArray v2(size);

    for (int i = 0; i < size; i++) {
        float temp = 0;
        cin >> temp;
        v1.SetValue(i, temp);
    }
    for (int i = 0; i < size; i++) {
        float temp = 0;
        cin >> temp;
        v2.SetValue(i, temp);
    }

    float multi = 0;
    cin >> multi;

    cout << "massiv1= ";
    v1.PrintMyArray();

    cout << "massiv2= ";
    v2.PrintMyArray();

    MyArray v3 = v1 + v2;
    cout << "summa= ";
    v3.PrintMyArray();
    v3 = v1 - v2;
    cout << "raznost= ";
    v3.PrintMyArray();
    v3 = v1 * v2;
    cout << "proizv= ";
    v3.PrintMyArray();
    v3 = v1 / v2;
    cout << "delenie= ";
    v3.PrintMyArray();
    v3 = v1 * multi;
    cout << "mult chislo massiv1= ";
    v3.PrintMyArray();
    v3 = v2 * multi;
    cout << "mult chislo massiv2= ";
    v3.PrintMyArray();
    
    if (v1 == v2)
        cout << "massivy ravny";
    else
        cout << "massivy ne ravny";


    return 0;
}

