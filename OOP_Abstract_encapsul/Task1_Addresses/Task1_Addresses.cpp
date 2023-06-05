// Task1_Addresses.cpp :
#include <string>
#include <fstream>
#include <iostream>

/*
Вам дан файл in.txt, в котором находится N адресов. Число N идёт первым в файле. 
После числа N располагаются N блоков по 4 строки в каждом.
Каждый блок состоит из следующих строк: название города, название улицы, номер дома, номер квартиры.

Задача программы заключается в том, чтобы считать адреса из файла in.txt и 
вывести их в файл out.txt в другом формате и в обратном порядке.

Не забудьте вывести количество адресов в начале.
Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.
*/
class Address
{
private:
    std::string* city;
    std::string* street;
    int house;
    int apartment;
public:
    //* Default Constructor
    Address(void) {
        std::string c = "Unknown";
        this -> city = &c;
        this -> street = &c;
        this -> house = 1;
        this -> apartment = 1;
    }
    void set_city(std::string* city) {
        this->city = city;
    }
    void set_street(std::string* street) {
        this->street = street;
    }
    void set_house(int* house) {
        this->house = *house;
    }
    void set_apartment(int* apartment) {
        this->apartment = *apartment;
    }
    std::string get_city(void) {
        return *city;
    }
    std::string get_street(void) {
        return *street;
    }
    int get_house(void) {
        return house;
    }
    int get_apartment(void) {
        return apartment;
    }
};

//* reading_from_a_file
bool reading_ff(std::ifstream& fin, Address* adr, int& size)
{
    int a = 0;
    std::string str = "abc";
    for (int x = 0; (x < size); x++) {
        fin >> str;
        adr[x].set_city(&str);
        fin >> str;
        adr[x].set_street(&str);
        fin >> a;
        adr[x].set_house(&a);
        fin >> a;
        adr[x].set_apartment(&a);
    }
    return true;
}

//* writing_to_a_file
bool writing_tf(std::ofstream& fout, Address* adr, int& size)
{
    int i = 0;
    std::string str;
    fout << size << std::endl;
    for (int x = 0; x < size; x++) {
        str = adr[x].get_city();
        fout << str << " ";
        str = adr[x].get_street();
        fout << str << " ";
        i = adr[x].get_house();
        fout << i << " ";
        i = adr[x].get_apartment();
        fout << i << std::endl;
    }
    return true;
}

////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    setlocale(LC_ALL,"ru_RU");
    //* initialization
    int size = 0;
    Address* adr = nullptr;

    //* reading_from_a_file
    std::ifstream fin("in.txt");
    if (!(fin.is_open())) {
        std::cout << "Error reading from file." << std::endl;
        return 1;
    }
    else {
        fin >> size;
        /*
        if (!(fin >> size)) {
            std::cout << "Error reading size from file." << std::endl;
        }
        //* проверка размера
        if (0 >= size) {
            std::cout << "Negative or zero size." << std::endl;
        }
        */
        adr = new Address[size];
        reading_ff(fin, adr, size);
        fin.close();
    }

    //* writing_to_a_file
    std::ofstream fout("out.txt");
    if (!(fout.is_open())) {
        std::cout << "Failed to write to file out.txt." << std::endl;
        delete[] adr;
        adr = nullptr;
        return 1;
    }
    else {
        writing_tf(fout, adr, size);
        fout.close();
    }
    delete[] adr;
    adr = nullptr;
    return 0;
}
//* Thanks for the tutorial!