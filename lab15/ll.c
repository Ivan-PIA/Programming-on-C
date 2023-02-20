#include "stdafx.h"

#include <iostream>

#include <algorithm>

using namespace std;

int f ( ){

static int i = 1;

return (++i) * 3;

}

int main(){

int a[5], i;

generate(a, a + 5, f);

for ( i = 0 ; i<5; i++) cout << a[i] << " "; 

return 0;

}