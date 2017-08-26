#include <iostream>

using namespace std;

int main() {

    int *is = new int[2]();
    is[0] = 1;
    is[1] = 2;
    int *nis = new int[2]();
    cout << is << endl;
    int *s=is;
    int *d=nis;
    for(int i=0;i<2;i++) *d++ = *s++; // 先++后解引用
    cout << is << endl;
    cout << s << endl;

    return 0;
}