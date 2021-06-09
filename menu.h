#ifndef LAB_2_MENU_H
#define LAB_2_MENU_H

#include "Matrix.h"
#include "iostream"
#include <complex>

#endif //LAB_2_MENU_H


using namespace std;

int GetInt(){
    int a;
    cin>>a;
    if (a<1){
        cout<<"Number is out of range. Try again:";
        GetInt();
    }
    return a;
}

int GetInt(int lower, int upper){
    int a;
    cout<<"Input number: ";
    cin>>a;
    if(a>upper||a<lower){
        cout<<"Number is out of range, try again"<<endl;
        GetInt(lower, upper);
    }
    return a;
}

int getNumber(int a){
    int b;
    cin>>b;
    return b;
}

float getNumber(float a){
    float b;
    cin>>b;
    return b;
}

complex<float> getNumber(complex<float> a){
    float b, c;
    cout<<endl;
    cout<<"Input real part: ";
    cin>>b;
    cout<<"Input imaginary part: ";
    cin>>c;
    complex<float> num = complex<float>(b,c);
    return num;
}

int randomInt() {
    return rand()%1000;
}

float randomFloat() {
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
}

complex<float> randomComplex() {
    return complex<float>(randomFloat(), randomFloat());
}

ostream& operator << (ostream& cout, complex<float> com){
    if (com.imag() == 0) return cout << com.real();

    if (com.real() != 0) {
        cout << com.real();
    }

    if (com.imag() > 0) {
        if (com.real() != 0)
            cout << '+';
        if (com.imag() != 1)
            cout << com.imag();
        return cout << 'i';
    }
    else {
        if (com.imag() == -1)
            return cout << "-i";
        return cout << com.imag() << 'i';
    }
}

template<class T>
void createVector(ArraySequence<Vector<T>*> *array, int dimension){
cout<<endl;
cout<<"Input 1 coordinate:";
T a = getNumber(a);
T *r = new T[1];
r[0] = a;
ArraySequence<T> *arraySequence = new ArraySequence<T>(r, 1);
for (int i = 0; i < dimension-1; ++i) {
cout<<"Input "<<i + 2 <<" coordinate:";
arraySequence->Append(getNumber(a));
}
auto *vector = new Vector<T>(*arraySequence);
cout<<"This is your new vector: "<<*vector;
array->Append(vector);
};

void createRandomIntVector(ArraySequence<Vector<int>*> *vectorInt, int dimension){
int *a = new int[dimension];
for (int i = 0; i < dimension; ++i) {
a[i] = randomInt();
}
auto *vector = new Vector<int>(a, dimension);
cout<<"This is your new vector: "<<*vector;
vectorInt->Append(vector);
}

void createRandomFloatVector(ArraySequence<Vector<float>*> *vectorFloat, int dimension){
float *a = new float[dimension];
for (int i = 0; i < dimension; ++i) {
a[i] = randomFloat();
}
Vector<float> *vector = new Vector<float>(a, dimension);
cout<<"This is your new vector: "<<*vector;
vectorFloat->Append(vector);
}

void createRandomComplexVector(ArraySequence<Vector<complex<float>>*> *vectorComplex, int dimension){
float *a = new float[dimension];
float *b = new float[dimension];
for (int i = 0; i < dimension; ++i) {
a[i] = randomFloat();
b[i] = randomFloat();
}
complex<float> *c = new complex<float>[dimension];
for (int i = 0; i < dimension; ++i) {
c[i] = complex<float>(a[i],b[i]);
}
Vector<complex<float>> *vector = new Vector<complex<float>>(c, dimension);
cout<<"This is your new vector: "<<*vector;
vectorComplex->Append(vector);
}

void getVector(ArraySequence<Vector<int>*> *vectorInt, ArraySequence<Vector<float>*> *vectorFloat, ArraySequence<Vector<complex<float>>*> *vectorComplex){
cout<<"---------";
int ch;
cout<<endl;
cout<<"What type of vector do you want?"<<endl;
cout<<"1. Int."<<endl;
cout<<"2. Float."<<endl;
cout<<"3. Complex."<<endl;
int a = GetInt(1, 3);

cout<<"Input vector dimension: ";
int dimension = GetInt();

cout<<"How do you want to input your vector?"<<endl;
cout<<"1. Randomly."<<endl;
cout<<"2. By myself."<<endl;
ch = GetInt(1, 2);

switch (a) {
case 1:
if(ch==1) {
createRandomIntVector(vectorInt, dimension);
}else{
createVector(vectorInt,dimension);
}
break;
case 2:
if (ch==1){
createRandomFloatVector(vectorFloat, dimension);
}else{
createVector(vectorFloat, dimension);
}
break;
case 3:
if (ch==1){
createRandomComplexVector(vectorComplex, dimension);
}else{
createVector(vectorComplex, dimension);
}
break;
default: break;
}
cout<<"---------"<<endl;
}

template<class T>
void createMatrix(ArraySequence<Matrix<T>*> *array, int height, int length){
    cout<<endl;
    cout<<"Input 1,1 number:";
    T a = getNumber(a);
    T *r = new T[1];
    r[0] = a;
    ArraySequence<T> *arraySequence = new ArraySequence<T>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
            cout<<"Input "<<i+1<<", "<<j+1<<" number:";
            arraySequence->Append(getNumber(a));
        }
        j = 0;
    }
    auto *matrix = new Matrix<T>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomIntMatrix(ArraySequence<Matrix<int>*> *array, int height, int length){
    cout<<endl;
    int a = randomInt();
    int *r = new int[1];
    r[0] = a;
    ArraySequence<int> *arraySequence = new ArraySequence<int>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
            arraySequence->Append(randomInt());
        }
        j = 0;
    }
    auto *matrix = new Matrix<int>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomFloatMatrix(ArraySequence<Matrix<float>*> *array, int height, int length){
    cout<<endl;
    float a = randomFloat();
    float *r = new float[1];
    r[0] = a;
    ArraySequence<float> *arraySequence = new ArraySequence<float>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
            arraySequence->Append(randomFloat());
        }
        j = 0;
    }
    auto *matrix = new Matrix<float>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void createRandomComplexMatrix(ArraySequence<Matrix<complex<float>>*> *array, int height, int length){
    cout<<endl;
    complex<float> a = randomComplex();
    complex<float> *r = new complex<float>[1];
    r[0] = a;
    ArraySequence<complex<float>> *arraySequence = new ArraySequence<complex<float>>(r, 1);
    int j = 1;
    for (int i = 0; i < height; ++i) {
        for (j ; j < length; ++j) {
            arraySequence->Append(randomComplex());
        }
        j = 0;
    }
    auto *matrix = new Matrix<complex<float>>(*arraySequence, length, height);
    cout<<"it is your new matrix: "<<*matrix;
    array->Append(matrix);
}

void getMatrix(ArraySequence<Matrix<int>*> *matrixInt, ArraySequence<Matrix<float>*> *matrixFloat, ArraySequence<Matrix<complex<float>>*> *matrixComplex){
    cout<<"---------"<<endl;
    cout<<"What type of matrix do you want?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    cout<<"3. Complex."<<endl;
    int a = GetInt(1, 3);

    cout<<"Input matrix length:";
    int length = GetInt();
    cout<<"Input matrix height: ";
    int height = GetInt();

    int ch;
    cout<<endl;
    cout<<"How do you want to input your matrix?"<<endl;
    cout<<"1. Randomly."<<endl;
    cout<<"2. By myself."<<endl;
    ch = GetInt(1, 2);
    switch (a) {
        case 1:
            if(ch==1) {
                createRandomIntMatrix(matrixInt, height, length);
            }else{
                createMatrix(matrixInt, height, length);
            }
            break;
        case 2:
            if (ch==1){
                createRandomFloatMatrix(matrixFloat, height, length);
            }else{
                createMatrix(matrixFloat, height, length);
            }
            break;
        case 3:
            if (ch==1){
                createRandomComplexMatrix(matrixComplex, height, length);
            }else{
                createMatrix(matrixComplex, height, length);
            }
            break;
        default: break;
    }
    cout<<"---------"<<endl;
}

template<class T>
void printVectorsFromMemory(ArraySequence<Vector<T>*> *arraySequence){
for (int i = 0; i < arraySequence->GetLength(); ++i) {
cout<<i+1<<": ";
cout<<"{";
if(arraySequence->Get(i)->GetDimension()<4){
for (int j = 0; j < arraySequence->Get(i)->GetDimension(); ++j) {
if(j!=0) cout<<", ";
cout<<arraySequence->Get(i)->GetCoordinate(j+1);
}
cout<<"}";
}else{
for (int j = 0; j < 3; ++j) {
cout<<arraySequence->Get(i)->GetCoordinate(j+1)<<", ";
}
cout<<"...}";
}
cout<<" | ";
}
cout<<endl;
}

void showAvailableVector(ArraySequence<Vector<int>*> *vectorInt, ArraySequence<Vector<float>*> *vectorFloat, ArraySequence<Vector<complex<float>>*> *vectorComplex){
cout<<"---------";
cout<<"What type do you want to look at?"<<endl;
cout<<"1. Int."<<endl;
cout<<"2. Float."<<endl;
cout<<"3. Complex."<<endl;
int a = GetInt(1, 3);
switch (a) {
case 1:
printVectorsFromMemory(vectorInt);
break;
case 2:
printVectorsFromMemory(vectorFloat);
break;
case 3:
printVectorsFromMemory(vectorComplex);
break;
default: break;
}
cout<<"---------"<<endl;
}

template<class T>
void printMatrixFromMemory(ArraySequence<Matrix<T>*> *arraySequence) {
    for (int k = 0; k < arraySequence->GetLength(); ++k) {
        cout<<k+1<<": ";
        if(arraySequence->Get(k)->GetLength()<4) {
            if (arraySequence->Get(k)->GetHeight()<4) {
                for (int i = 0; i < arraySequence->Get(k)->GetHeight(); ++i) {
                    for (int j = 0; j < arraySequence->Get(k)->GetLength(); ++j) {
                        cout<<arraySequence->Get(k)->GetElement(i,j)<<" ";
                    }
                    cout<<""<<endl;
                    cout<<"    ";
                }
                cout<<endl;
            }else {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < arraySequence->Get(k)->GetLength(); ++j) {
                        cout<<arraySequence->Get(k)->GetElement(i,j)<<" ";
                    }
                    cout<<""<<endl;
                    cout<<"    ";
                }
                for (int i = 0; i <  arraySequence->Get(k)->GetLength(); ++i) {
                    cout<<"...  ";
                }
                cout<<endl;
            }
        }else{
            if (arraySequence->Get(k)->GetHeight()<4) {
                for (int i = 0; i < arraySequence->Get(k)->GetHeight(); ++i) {
                    for (int j = 0; j < 3; ++j) {
                        cout<<arraySequence->Get(k)->GetElement(i,j)<<" ";
                    }
                    cout<<"... ";
                    cout<<""<<endl;
                    cout<<"    ";
                }
            }else {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        cout<<arraySequence->Get(k)->GetElement(i,j)<<" ";
                    }
                    cout<<"...";
                    cout<<""<<endl;
                    cout<<"    ";
                }
                for (int i = 0; i <  3; ++i) {
                    cout<<"...";
                }
                cout<<endl;
            }
        }
    }
}

void showAvailableMatrix(ArraySequence<Matrix<int>*> *matrixInt, ArraySequence<Matrix<float>*> *matrixFloat, ArraySequence<Matrix<complex<float>>*> *matrixComplex){
    cout<<"---------"<<endl;
    cout<<"What type do you want to look at?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    cout<<"3. Complex."<<endl;
    int a = GetInt(1, 3);
    switch (a) {
        case 1:
            printMatrixFromMemory(matrixInt);
            break;
        case 2:
            printMatrixFromMemory(matrixFloat);
            break;
        case 3:
            printMatrixFromMemory(matrixComplex);
            break;
        default: break;
    }
    cout<<"---------"<<endl;
}

template <class T>
void saveVector(ArraySequence<Vector<T>*> *vectorsArray, Vector<T> *vector){
cout<<"Do you want to save vector?"<<endl;
cout<<"1. Yes."<<endl;
cout<<"2. No."<<endl;
int a = GetInt(1,2);
if(a == 1) vectorsArray->Append(vector);
}

template <class T>
Vector<T> *getVectorFromMemory(ArraySequence<Vector<T>*> *vectorsArray){
cout<<"What vector number do you want to use?"<<endl;
int a = GetInt(1, vectorsArray->GetLength());
auto *vector = vectorsArray->Get(a-1);
return vector;
}


template <class T>
Vector<T> *getVectorForOperation(ArraySequence<Vector<T>*> *vectorsArray){
int ch, dimension;
cout<<"What vector do you want to use?"<<endl;
cout<<"1. My own new vector."<<endl;
cout<<"2. Vector from memory."<<endl;
int a = GetInt(1,2);
Vector<T> *vector;
switch (a) {
case 1: {
cout << "What dimension do you want?" << endl;
dimension = GetInt();
cout << endl;
cout << "Input 1 coordinate:";
T b = getNumber(b);
T *r = new T[1];
r[0] = b;
ArraySequence<T> *arraySequence = new ArraySequence<T>(r, 1);
for (int i = 0; i < dimension - 1; ++i) {
cout << "Input " << i + 2 << " coordinate:";
arraySequence->Append(getNumber(b));
}
vector = new Vector<T>(*arraySequence);
cout << "it is your new vector: " << *vector << endl;
saveVector(vectorsArray, vector);
break;
}
case 2:
printVectorsFromMemory(vectorsArray);
vector = getVectorFromMemory(vectorsArray);
break;
default: break;
}
return vector;
};

template <class T>
void vectorsSum(Vector<T> first, Vector<T> second, ArraySequence<Vector<T>*> *vectorsArray ){
Vector<T> *res = first.addVectors(second);
cout<<"This is your summed vector: "<<*res<<endl;
saveVector(vectorsArray, res);
}

template <class T>
void vectorsSub(Vector<T> first, Vector<T> second, ArraySequence<Vector<T>*> *vectorsArray ){
Vector<T> *res = first.subVectors(second);
cout<<"This is your subtracted vector: "<<*res<<endl;
saveVector(vectorsArray, res);
}

template <class T>
void vectorsMult(Vector<T> first, Vector<T> second, ArraySequence<Vector<T>*> *vectorsArray ){
Vector<T> *res = first.multVectors(second);
cout<<"This is your multiplied  vector: "<<*res<<endl;
saveVector(vectorsArray, res);
}

template <class T>
void vectorsScalarMult(Vector<T> first, ArraySequence<Vector<T>*> *vectorsArray ){
cout<<"Input number that you want to multiply on vector: ";
float a = getNumber(a);
Vector<T> *res = first.scalarMultVector(a);
cout<<endl<<"This is your scalar multiplicated vector: "<<*res<<endl;
saveVector(vectorsArray, res);
}

template <class T>
void chooseOperation(int a, Vector<T> *first, Vector<T> *second, ArraySequence<Vector<T>*> *vectorsArray){
switch (a) {
case 1:
vectorsSum(*first, *second, vectorsArray);
break;
case 2:
vectorsSub(*first, *second, vectorsArray);
break;
case 3:
vectorsMult(*first, *second, vectorsArray);
break;
default: break;
}
}

void operateWithVectors(ArraySequence<Vector<int>*> *vectorInt, ArraySequence<Vector<float>*> *vectorFloat, ArraySequence<Vector<complex<float>>*> *vectorComplex){
cout<<"---------"<<endl;
cout<<"What do you want to do with vector"<<endl;
cout<<"1. Sum two vectors."<<endl;
cout<<"2. Sub two vectors."<<endl;
cout<<"3. Multiply two vectors."<<endl;
cout<<"4. Multiply scalar vector."<<endl;
int a = GetInt(1,4);

cout<<"What type of vector do you want?"<<endl;
cout<<"1. Int."<<endl;
cout<<"2. Float."<<endl;
cout<<"3. Complex."<<endl;
int b = GetInt(1, 3);
switch (b) {
case 1: {
Vector<int> *first = getVectorForOperation(vectorInt);
if(a!=4){
Vector<int> *second = getVectorForOperation(vectorInt);
chooseOperation(a, first, second, vectorInt);
}else{
vectorsScalarMult(*first, vectorInt);
}
}break;
case 2:{
Vector<float> *first = getVectorForOperation(vectorFloat);
if(a!=4){
Vector<float> *second = getVectorForOperation(vectorFloat);
chooseOperation(a, first, second, vectorFloat);
}else{
vectorsScalarMult(*first, vectorFloat);
}
} break;
case 3:{
Vector<complex<float>> *first = getVectorForOperation(vectorComplex);
if(a!=4){
Vector<complex<float>> *second = getVectorForOperation(vectorComplex);
chooseOperation(a, first, second, vectorComplex);
}else{
vectorsScalarMult(*first, vectorComplex);
}
} break;
default: break;
}
cout<<"---------"<<endl;
}

template<class T>
void saveMatrix(ArraySequence<Matrix<T>*> *matricesArray, Matrix<T> *matrix){
    cout<<"Do you want to save matrix?"<<endl;
    cout<<"1. Yes."<<endl;
    cout<<"2. No."<<endl;
    int a = GetInt(1,2);
    if(a == 1) matricesArray->Append(matrix);
}

template <class T>
Matrix<T> *getMatrixFromMemory(ArraySequence<Matrix<T>*> *matricesArray){
    cout<<"What matrix number do you want to use?"<<endl;
    int a = GetInt(1, matricesArray->GetLength());
    auto *matrix = matricesArray->Get(a-1);
    return matrix;
}

template <class T>
Matrix<T> *getMatrixForOperation(ArraySequence<Matrix<T>*> *matricesArray){
    cout<<"What vector do you want to use?"<<endl;
    cout<<"1. My own new matrix."<<endl;
    cout<<"2. Matrix from memory."<<endl;
    int a = GetInt(1,2);
    Matrix<T> *matrix;
    switch (a) {
        case 1: {
            cout<<"Input matrix height: ";
            int height = GetInt();
            cout<<endl<<"Input matrix length";
            int length = GetInt();
            cout<<endl;
            cout<<"Input 1,1 number:";
            T a = getNumber(a);
            T *r = new T[1];
            r[0] = a;
            ArraySequence<T> *arraySequence = new ArraySequence<T>(r, 1);
            int j = 1;
            for (int i = 0; i < height; ++i) {
                for (j ; j < length; ++j) {
                    cout<<"Input "<<i+1<<", "<<j+1<<" number:";
                    arraySequence->Append(getNumber(a));
                }
                j = 0;
            }
            auto *matrix = new Matrix<T>(*arraySequence, length, height);
            cout<<"it is your new matrix: "<<*matrix;
            saveMatrix(matricesArray, matrix);
            return matrix;
        }break;
        case 2:{
            printMatrixFromMemory(matricesArray);
            matrix = getMatrixFromMemory<T>(matricesArray);
            return matrix;
        }break;
        default: break;
    }

}

template <class T>
void matricesSum(Matrix<T> *first, Matrix<T> *second, ArraySequence<Matrix<T>*> *matricesArray){
    if(first->GetHeight() != second->GetHeight() || first->GetLength() != second->GetLength()){
        cout<<"Matrices cant be summed"<<endl;
        return;
    }
    Matrix<T> *res = first->sumMatrices(second);
    cout<<"This is your summed matrix"<<*res;
    saveMatrix(matricesArray, res);
}

template <class T>
void matricesSub(Matrix<T> *first, Matrix<T> *second, ArraySequence<Matrix<T>*> *matricesArray){
    if(first->GetHeight() != second->GetHeight() || first->GetLength() != second->GetLength()){
        cout<<"Matrices cant be subtracted"<<endl;
        return;
    }
    Matrix<T> *res = first->subMatrices(second);
    cout<<"This is your subtracted matrix"<<*res;
    saveMatrix(matricesArray, res);
}

template <class T>
void matricesMult(Matrix<T> *first, Matrix<T> *second, ArraySequence<Matrix<T>*> *matricesArray){
    if(first->GetHeight() != second->GetLength()){
        cout<<"Matrices cant be multiplied"<<endl;
        return;
    }
    Matrix<T> *res = first->multMatrices(second);
    cout<<"This is your multiplied  matrix"<<*res;
    saveMatrix(matricesArray, res);
}

template <class T>
void matrixScalarMult(Matrix<T> *first, ArraySequence<Matrix<T>*> *matricesArray){
    cout<<"Input number you want to multiply matrix on: ";
    float a = getNumber(a);
    first->scalarMultMatrix(a);
    cout<<endl<<"This is your scalar multiplied matrix"<<*first;
}

template <class T>
void matrixChangeLines(Matrix<T> *first, ArraySequence<Matrix<T>*> *matricesArray){
    cout<<"Input number for first line: ";
    int a = GetInt(1, first->GetHeight());
    cout<<endl<<"Input number for second line: ";
    int b = GetInt(1, first->GetHeight());
    first->changeLines(a,b);
    cout<<endl<<"This is your changed lines matrix"<<*first;
}

template <class T>
void matrixMultLine(Matrix<T> *first, ArraySequence<Matrix<T>*> *matricesArray){
    cout<<"Line?"<<endl;
    int a = GetInt(1, first->GetHeight());
    cout<<"Input number you want to multiply line on: ";
    float b = getNumber(b);
    first->multLine(a,b);
    cout<<endl<<"This is your multiplied line matrix"<<*first;
}

template <class T>
void matrixAddLines(Matrix<T> *first, ArraySequence<Matrix<T>*> *matricesArray){
    cout<<"Input number for first line, which would be changed: ";
    int a = GetInt(1, first->GetHeight());
    cout<<endl<<"Input number for second line, which would be added: ";
    int b = GetInt(1, first->GetHeight());
    first->addLineToLine(a,b);
    cout<<endl<<"This is your added lines matrix"<<*first;
    saveMatrix(matricesArray, first);
}

template <class T>
void matrixSubLines(Matrix<T> *first, ArraySequence<Matrix<T>*> *matricesArray){
    cout<<"Input number for first line, which would be changed: ";
    int a = GetInt(1, first->GetHeight());
    cout<<endl<<"Input number for second line, which would be subtracted: ";
    int b = GetInt(1, first->GetHeight());
    first->subLineToLine(a,b);
    cout<<endl<<"This is your subtracted lines matrix"<<*first;
    saveMatrix(matricesArray, first);
}

template <class T>
void chooseOperation(int a, Matrix<T> *first, Matrix<T> *second, ArraySequence<Matrix<T>*> *matricesArray){
    switch (a) {
        case 1:
            matricesSum(first, second, matricesArray);
            break;
        case 2:
            matricesSub(first, second, matricesArray);
            break;
        case 3:
            matricesMult(first, second, matricesArray);
            break;
        default: break;
    }
}

template <class T>
void chooseOperationSingle(int a, Matrix<T> *first, ArraySequence<Matrix<T>*> *matricesArray){
    switch (a) {
        case 4:
            matrixScalarMult(first, matricesArray);
            break;
        case 5:
            matrixChangeLines(first, matricesArray);
            break;
        case 6:
            matrixMultLine(first, matricesArray);
            break;
        case 7:
            matrixAddLines(first, matricesArray);
            break;
        case 8:
            matrixSubLines(first, matricesArray);
            break;
        default: break;
    }
}

void operateWithMatrices(ArraySequence<Matrix<int>*> *matrixInt, ArraySequence<Matrix<float>*> *matrixFloat, ArraySequence<Matrix<complex<float>>*> *matrixComplex){
    cout<<"---------"<<endl;
    cout<<"What do you want to do with matrices?"<<endl;
    cout<<"1. Sum two matrices."<<endl;
    cout<<"2. Sub two matrices."<<endl;
    cout<<"3. Multiply two matrices."<<endl;
    cout<<"4. Multiply scalar matrix."<<endl;
    cout<<"5. Change lines in matrix."<<endl;
    cout<<"6. Multiply line in matrix."<<endl;
    cout<<"7. Add line to line in matrix."<<endl;
    cout<<"8. Sub line to line in matrix."<<endl;
    int a = GetInt(1,8);

    cout<<"What type of matrix do you want?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    cout<<"3. Complex."<<endl;
    int b = GetInt(1, 3);
    switch (b) {
        case 1: {
            Matrix<int> *first = getMatrixForOperation<int>(matrixInt);
            if(a!=5 && a!=6 && a!=7 && a!=8 && a!=4){
                Matrix<int> *second = getMatrixForOperation<int>(matrixInt);
                chooseOperation(a, first, second, matrixInt);
            }else{
                chooseOperationSingle(a, first, matrixInt);
            }
        }break;
        case 2:{
            Matrix<float> *first = getMatrixForOperation<float>(matrixFloat);
            if(a!=5 && a!=6 && a!=7 && a!=8 && a!=4){
                Matrix<float> *second = getMatrixForOperation<float>(matrixFloat);
                chooseOperation(a, first, second, matrixFloat);
            }else{
                chooseOperationSingle(a, first, matrixFloat);
            }
        } break;
        case 3:{
            Matrix<complex<float>> *first = getMatrixForOperation<complex<float>>(matrixComplex);
            if(a!=5 && a!=6 && a!=7 && a!=8 && a!=4){
                Matrix<complex<float>> *second = getMatrixForOperation<complex<float>>(matrixComplex);
                chooseOperation(a, first, second, matrixComplex);
            }else{
                chooseOperationSingle(a, first, matrixComplex);
            }
        } break;
        default: break;
    }
}

template <class T>
void deleteElementVector(ArraySequence<Vector<T>*> *vectorsArray){
printVectorsFromMemory(vectorsArray);
cout<<"Which one do you want to delete? If none, input 0.";
int r = GetInt(0, vectorsArray->GetLength());
if(r!=0){
vectorsArray->deleteElement(r);
}
}

template <class T>
void deleteElementMatrix(ArraySequence<Matrix<T>*> *matricesArray){
    printMatrixFromMemory(matricesArray);
    cout<<"Which one do you want to delete? If none, input 0."<<endl;
    int r = GetInt(0, matricesArray->GetLength());
    if(r!=0){
        matricesArray->deleteElement(r);
    }
}

void chooseDeleteElement(ArraySequence<Vector<int>*> *vectorInt, ArraySequence<Vector<float>*> *vectorFloat, ArraySequence<Vector<complex<float>>*> *vectorComplex,
ArraySequence<Matrix<int>*> *matrixInt, ArraySequence<Matrix<float>*> *matrixFloat, ArraySequence<Matrix<complex<float>>*> *matrixComplex){
cout<<"---------"<<endl;
cout<<"What do you want?"<<endl;
cout<<"1. Vectors array."<<endl;
cout<<"2. Matrices array."<<endl;
int a = GetInt(1,2);
cout<<"What type  do you want?"<<endl;
cout<<"1. Int."<<endl;
cout<<"2. Float."<<endl;
cout<<"3. Complex."<<endl;
int b = GetInt(1,3);
switch (a) {
case 1:
switch (b) {
case 1:
printVectorsFromMemory(vectorInt);
deleteElementVector(vectorInt);
break;
case 2:
printVectorsFromMemory(vectorFloat);
deleteElementVector(vectorFloat);
break;
case 3:
printVectorsFromMemory(vectorComplex);
deleteElementVector(vectorComplex);
break;
default: break;
}
break;
case 2:
switch (b) {
case 1:
printMatrixFromMemory(matrixInt);
deleteElementMatrix(matrixInt);
break;
case 2:
printMatrixFromMemory(matrixFloat);
deleteElementMatrix(matrixFloat);
break;
case 3:
printMatrixFromMemory(matrixComplex);
deleteElementMatrix(matrixFloat);
break;
default: break;
}break;
default: break;
}
cout<<"---------"<<endl;
}

void menu(){
    ArraySequence<Vector<int>*> vectorInt;
    ArraySequence<Vector<float>*> vectorFloat;
    ArraySequence<Vector<complex<float>>*> vectorComplex;

    ArraySequence<Matrix<int>*> matrixInt;
    ArraySequence<Matrix<float>*> matrixFloat;
    ArraySequence<Matrix<complex<float>>*> matrixComplex;

    int number;

    while (true) {
        cout << "Menu: " << endl;
        cout << "What do you want to do?" << endl;
        cout << "1.  Input vector in memory." << endl;
        cout << "2.  Input matrix in memory." << endl;
        cout << "3.  Show available vectors in memory." << endl;
        cout << "4.  Show available matrices in memory." << endl;
        cout << "5.  Operate with vectors."<<endl;
        cout << "6.  Operate with matrices."<<endl;
        cout << "7.  Remove vector from memory."<<endl;;
        cout << "8.  Exit."<<endl;

        number = GetInt(1,8);

        if(number == 8) break;

        switch (number) {
            case 1:
                getVector(&vectorInt, &vectorFloat, &vectorComplex);
                break;
            case 2:
                getMatrix(&matrixInt, &matrixFloat, &matrixComplex);
                break;
            case 3:
                showAvailableVector(&vectorInt, &vectorFloat, &vectorComplex);
                break;
            case 4:
                showAvailableMatrix(&matrixInt, &matrixFloat, &matrixComplex);
                break;
            case 5:
                operateWithVectors(&vectorInt, &vectorFloat, &vectorComplex);
                break;
            case 6:
                operateWithMatrices(&matrixInt, &matrixFloat, &matrixComplex);
                break;
            case 7:
                chooseDeleteElement(&vectorInt, &vectorFloat, &vectorComplex, &matrixInt, &matrixFloat, &matrixComplex);
                break;
            default: break;
        }
    }
}
