// array (niz):
// https://en.cppreference.com/w/cpp/language/array.html

int arr1[10];
int arr2[5] = { 1, 2, 3, 4, 5 };
double arr3[] = { 1, 2, 3 };

int matrix1[3][2] = {
  { 1, 2 },
  { 3, 4 },
  { 5, 6 }
};

int matrix2[][2] = {
  { 1, 2 },
  { 3, 4 },
  { 5, 6 }
};

int matrix3[][2][3] = {
  { { 1, 2, 3 },
    { 4, 5, 6 } },
  { { 1, 2, 3 },
    { 4, 5, 6 } }
};

const int* p1 = arr1;
