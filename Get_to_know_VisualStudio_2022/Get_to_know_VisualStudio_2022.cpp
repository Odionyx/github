// Get_to_know_VisualStudio_2022.cpp
#include <iostream>
#include <fstream>
#include <string>


bool reading_from_a_file (std::ifstream& fin, int*& arr, int& size) 
{
    // считывание размера 
    if (!(fin >> size)) {
        std::cout << "Error reading from file." << std::endl;
        return false;
    }
    // проверка размера
    if (size <= 0) {
        std::cout << "Negative or zero size." << std::endl;
        return false;
    }
    // заполнение массива
    for (int x = 0; (x < size); x++) {
        int y = 0;
        fin >> y;
        arr[x] = y;
    }
    return true;
}

bool writing_to_a_file (std::ofstream& fout, int* arr, int size, bool b) 
{
    if (b && (fout << size)) {
        fout << std::endl;
        fout << arr[size - 1];
        for (int x = 0; x < (size - 1); x++) {
            fout << " " << arr[x];
        }
        fout << std::endl;
        return true;
    }
    else if (!b && (fout << size)) {
        fout << std::endl;
        for (int x = 1; x < size; x++) {
            fout << arr[x] << " ";
        }
        fout << arr[0] << std::endl;
        return true;
    }
    else {
        return false;
    }
}

  //****************************************************************//
 //                              main                              //
//****************************************************************//
int main(int argc, char** argv) {
    int size = 0;
    int size2 = 0;
    bool b = true;
    // создание массивов
    int* arr = new int[size];
    int* arr2 = new int[size2];

    // чтение из файла
    std::string str = {'i','n','.','t','x','t'};
    std::ifstream fin (str);
    
    if (fin.is_open()) {
        reading_from_a_file (fin, arr, size);
        reading_from_a_file (fin, arr2, size2);
        fin.close();
    }
    else {
        std::cout << "The in.txt file does not exist." << std::endl;
        return 1;
    }
    // запись в файл
    str = {'o','u','t','.','t','x','t'};
    std::ofstream fout(str);

    if (fout.is_open()) {
        writing_to_a_file(fout, arr2, size2, true);
        writing_to_a_file(fout, arr, size, false);
    }
    else {
        std::cout << "Failed to write to file out.txt." << std::endl;
        return 1;
    }
    fout.close();

    // удаление массивов
    arr2 = nullptr;
    arr = nullptr;
    delete[] arr2;
    delete[] arr;
    return 0;
}