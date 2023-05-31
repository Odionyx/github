// Get_to_know_VisualStudio_2022.cpp
#include <iostream>
#include <fstream>
#include <string>


bool reading_size_from_a_file(std::ifstream& fin, int& size)
{
    // считывание размера 
    if (!(fin >> size)) {
        std::cout << "Error reading size from file." << std::endl;
        return false;
    }
    // проверка размера
    if (size <= 0) {
        std::cout << "Negative or zero size." << std::endl;
        return false;
    }
    return true;
}

bool reading_from_a_file (std::ifstream& fin, int*& arr, int size)
{
    // заполнение массива
    for (int x = 0; (x < size); x++) {
        int y = 0;
        fin >> y;
        arr[x] = y;
    }
    return true;
}
bool delete_array (int*& arr, int*& arr2)
{
    // удаление массивов
    delete[] arr2;
    delete[] arr;
    arr2 = nullptr;
    arr = nullptr;
    return true;
}

bool writing_to_a_file (std::ofstream& fout, int* arr, int size, bool b) 
{
    if (b) {
        fout << size << std::endl;
        fout << arr[size - 1];
        for (int x = 0; x < (size - 1); x++) {
            fout << " " << arr[x];
        }
        fout << std::endl;
        return true;
    }
    else if (!b) {
        fout << size << std::endl;
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
    int* arr = nullptr;
    int* arr2 = nullptr;
    // чтение из файла
    std::string str = "in.txt";
    std::ifstream fin (str);
    
    if (fin.is_open()) {
        //arr
        reading_size_from_a_file(fin, size);
        arr = new int[size];
        reading_from_a_file (fin, arr, size);
        //arr2
        reading_size_from_a_file(fin, size2);
        arr2 = new int[size2];
        reading_from_a_file (fin, arr2, size2);

        fin.close();
    }
    else {
        std::cout << "Error reading from file." << std::endl;
        delete_array(arr, arr2);
        return 1;
    }
    // запись в файл
    str = "out.txt";
    std::ofstream fout(str);

    if (fout.is_open()) {
        writing_to_a_file(fout, arr2, size2, true);
        writing_to_a_file(fout, arr, size, false);
    }
    else {
        std::cout << "Failed to write to file out.txt." << std::endl;
        delete_array(arr, arr2);
        return 1;
    }
    fout.close();
    delete_array(arr, arr2);
    return 0;
}