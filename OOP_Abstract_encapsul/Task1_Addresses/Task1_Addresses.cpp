// Task1_Addresses.cpp :
#include <iostream>
#include <fstream>

class Address
{
private:
    std::string city;
    std::string street;
    int house;
    int apartment;
public:
    //* Default Constructor with parameters
    Address(void) {
        this->city = "abc";
        this->street = "efg";
        this->house = 0;
        this->apartment = 0;
    }
    void set_address(std::string* city, std::string* street, int* house, int* apartment) {
        this->city = *city;
        this->street = *street;
        this->house = *house;
        this->apartment = *apartment;
        return;
    }
    void print_address(std::ofstream& fout) {
        fout << this->city << ", " << this->street << ", " << this->house << ", " << this->apartment;
        return;
    }
};

////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    setlocale(LC_ALL,"ru_RU");
    //* initialization
    int size = 32;
    std::string c = "abc";
    std::string s = "abc";
    int h = 0;
    int a = 0;
    Address* adr = nullptr;

    //* reading_from_a_file
    std::ifstream fin("in.txt");
    if (!(fin.is_open())) {
        std::cout << "Error reading from file." << std::endl;
        adr = nullptr;
        return 1;
    }
    else {
        if (!(fin >> size)) {
            std::cout << "Error reading size from file." << std::endl;
            adr = nullptr;
            return 1;
        }
        //* проверка размера
        if (0 >= size) {
            std::cout << "Negative or zero size." << std::endl;
            adr = nullptr;
            return 1;
        }
        adr = new Address[size];
        std::string str = "abc";
        for (int x = 0; (x < size); x++) {
            fin >> c >> s >> h >> a;
            adr[x].set_address( &c, &s, &h, &a);
        }
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
        fout << size << std::endl;
        for (int x = (size-1); 0 <= x ; x--) {
            adr[x].print_address(fout);
            fout << std::endl;
        }
        fout.close();
    }
    delete[] adr;
    adr = nullptr;
    return 0;
}
//* Thanks for the tutorial!