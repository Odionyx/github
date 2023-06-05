// Task2_Sorting_address.cpp : 


#include <iostream>
#include <fstream>
#include <string>

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
    ////////////////////////////////////////
    std::string get_city(void) {
        return city;
    }
    std::string get_street(void) {
        return street;
    }
    int get_house(void) {
        return house;
    }
    int get_apartment(void) {
        return apartment;
    }
    void get_address(std::ofstream& fout) {
        fout << this->city << ", " << this->street << ", " << this->house << ", " << this->apartment;
        return;
    }
    //////////////////////////////////////////
    std::string set_city(std::string city) {
        return this->city = city;
    }
    std::string set_street(std::string street) {
        return this->street = street;
    }
    int set_house(int house) {
        return this->house = house;
    }
    int set_apartment(int apartment) {
        return this->apartment = apartment;
    }
    void set_address(std::string* city, std::string* street, int* house, int* apartment) {
        this->city = *city;
        this->street = *street;
        this->house = *house;
        this->apartment = *apartment;
        return;
    }
};

////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU");
    //* initialization
    int size = 5;
    std::string c = "abc";
    std::string s = "abc";
    int h = 0;
    int a = 0;
    Address* adr = nullptr;

    //* reading_from_a_file
    std::ifstream fin("in.txt");
    if (!(fin.is_open())) {
        std::cout << "Error reading from file." << std::endl;
        return 1;
    }
    else {
        if (!(fin >> size)) {
            std::cout << "Error reading size from file." << std::endl;
        }
        //* проверка размера
        if (0 >= size) {
            std::cout << "Negative or zero size." << std::endl;
        }
        adr = new Address[5]{};
        std::string str = "abc";
        for (int x = 0; (x < size); x++) {
            fin >> c >> s >> h >> a;
            adr[x].set_address(&c, &s, &h, &a);
        }
        fin.close();
    }


    bool sorted;
    do
    {
        
        sorted = false;
           // переменная для обмена значениями
        for (int i = 0; i < 4; i++)
        {
            // если предыдущая строка больше последующей
            if (adr[i].get_city() < adr[i+1].get_city())
            {
                std::string c = adr[i].get_city();
                std::string s = adr[i].get_street();
                int h = adr[i].get_house();
                int a = adr[i].get_apartment();

                adr[i].set_city     (adr[i+1].get_city());
                adr[i].set_street   (adr[i+1].get_street());
                adr[i].set_house    (adr[i + 1].get_house());
                adr[i].set_apartment(adr[i + 1].get_apartment());

                adr[i+1].set_city(c);
                adr[i+1].set_street(s);
                adr[i+1].set_house(h);
                adr[i+1].set_apartment(a);

                sorted = true;
            }
        }
    } while (sorted);

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
        for (int x = (size - 1); 0 <= x; x--) {
            adr[x].get_address(fout);
            fout << std::endl;
        }
        fout.close();
    }
    delete[] adr;
    adr = nullptr;
    return 0;
}
//* Thanks for the tutorial!