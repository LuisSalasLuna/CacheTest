// CacheTest.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iostream>
#include <ctime> 
using namespace std;

int main()
{
    const int MAXI = 2000;

    int* A;
    int* B;
    int** C;
    //Definiendo
    A = new int[MAXI];
    B = new int[MAXI];
    C = new int* [MAXI];
    for (int i = 0; i < MAXI; i++) {
        C[i] = new int[MAXI];
    }
    //Inicializando
    for (int i = 0; i < MAXI; i++) {
        for (int j = 0; j < MAXI; j++) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < MAXI; i++) {
        A[i] = i + 10;
        B[i] = i * 2;
    }

    unsigned t0, t1, t2, t3;

    //Ejecucion
    t0 = clock();

    for (int i = 0; i < MAXI; i++) {
        for (int j = 0; j < MAXI; j++) {
            A[i] += C[i][j] * B[j];
        }
    }

    t1 = clock();

    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    //Ejecucion 2
    t2 = clock();
    for (int j = 0; j < MAXI; j++) {
        for (int i = 0; i < MAXI; i++) {
            A[i] += C[i][j] * B[j];
        }
    }
    t3 = clock();

    time = (double(t3 - t2) / CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
