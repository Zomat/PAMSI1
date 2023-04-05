#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <iostream>
#include <random>
#include <fstream>

class Array1D{
private:
    int* _data;
    int _size;
public:
    Array1D(int size=0) {
        _size = size;
        _data = new int[size];

        /** Init new array with zeros */
        for (uint i = 0; i < _size; i++) {
            _data[i] = 0;
        }
    }

    ~Array1D() {
        delete[] _data;
    }

    void saveToTxt(std::string filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (uint i = 0; i < _size; i++) {
                file << _data[i] << std::endl;
            }
            file.close();
            std::cout << "Tablica zapisana do " << filename << std::endl;
        } else {
            std::cout << "Nie można otworzyć pliku!" << std::endl;
        }
    }

    void loadFromTxt(std::string filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            uint lineNum = 0;
            std::string line;

            while (std::getline(file, line)) {
                lineNum++;
            }

            file.clear();
            file.seekg(0, std::ios::beg);

            delete[] _data;
            _size = lineNum;
            _data = new int[_size];

            uint i = 0;
            while (std::getline(file, line)) {
                _data[i] = std::stoi(line);
                i++;
            }

            file.close();
            std::cout << "Tablica załadowana z " << filename << std::endl;
        } else {
            std::cout << "Nie można otworzyć pliku!" << std::endl;
        }
    }

    void saveToBin(std::string filename) {
        std::ofstream file(filename, std::ios::out | std::ios::binary);
        if (file.is_open()) {
            file.write(reinterpret_cast<char*>(_data), _size * sizeof(int));
            file.close();
            std::cout << "Tablica zapisana do pliku binarnego " << filename << std::endl;
        } else {
            std::cout << "Nie można otworzyć pliku!" << std::endl;
        }
    }

    void loadFromBin(std::string filename) {
        std::ifstream file(filename, std::ios::in | std::ios::binary);
        if (file.is_open()) {
            file.seekg(0, std::ios::end);
            _size = file.tellg() / sizeof(int);
            file.seekg(0, std::ios::beg);

            delete[] _data;
            _data = new int[_size];

            file.read(reinterpret_cast<char*>(_data), _size * sizeof(int));
            file.close();
            std::cout << "Tablica załadowana z pliku binarnego " << filename << std::endl;
        } else {
            std::cout << "Nie można otworzyć pliku!" << std::endl;
        }
    }
};

#endif //ARRAY1D_H
