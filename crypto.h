#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
class crypto
{
public:
  crypto();

  static void write_to_file(ofstream &outfile,string c,string path);
  static string read_file(ifstream &inputfile,string path);
  static string encrypt(string target,string password);
  static string decrypt(string target,string password);
  static vector<int> ASCIIToOctal(string str);
  static string add(vector<int> file,vector<int> pass);
  static bool is_digits(const std::string &str);
};

#endif // CRYPTO_H
