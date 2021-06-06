#include "crypto.h"


//function for conversion from Octal to Decimal
int octalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}
//function for conversion from Decimal to Octal
string DecimalToOctal(int dec) {
	if (dec < 1) return "0";

	string octStr = "";

	while (dec > 0)
	{
		octStr = octStr.insert(0, to_string(dec % 8));
		dec /= 8;
	}

	return octStr;
}

bool crypto::is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}


void crypto::write_to_file(ofstream &outfile,string c,string path){
  outfile.open(path); //opens file
  outfile << c << endl;    //write into file
  outfile.close();     //closes the file
}

string crypto::read_file(ifstream &file,string path){
  file.open(path);
  string str;
  if(!file) {
          cout << "not found";
     } else{
      stringstream strStream;
      strStream << file.rdbuf(); //read the file
      str = strStream.str();
      }
  file.close();
  return str;
}


vector<int> crypto::ASCIIToOctal(string str) {
	vector<int> dec;
	vector<int> octal;
	int strLen = str.length();

	for (int i = 0; i < strLen; ++i)
	{
		dec.push_back((int)str[i]);
	}
	for (int i = 0; i < strLen; ++i)
	{
		int x = dec[i];
		octal.push_back(stoi(DecimalToOctal(x)));
	}
	return octal;
}

string crypto::add(vector<int> file,vector<int> pass){
  vector<int> sum;
  int size = file.size() - pass.size();
  int x = 0;
  for(int i=0;i<size;i++){
      if(x<pass.size()){
          pass.push_back(pass[x]);
          x++;
        }else{
          x = 0;
        }
    }
  for(int i =0; i< file.size(); i++){
      sum.push_back(file[i]+pass[i]);
    }
  vector<char> to_char;
  for(int i = 0; i<sum.size(); i++){
      to_char.push_back((char)sum[i]);
    }
  string str(to_char.begin(), to_char.end());
  return str;
}

string crypto::encrypt(string target, string password){
  vector<int> source = crypto::ASCIIToOctal(target);
  vector<int> pass = crypto::ASCIIToOctal(password);
  string encrypted = crypto::add(source,pass);
  return encrypted;
}

string crypto::decrypt(string target,string password){
  vector<long> source;
  vector<int> pass;
  for(int i=0;i<target.size()-1;i++){
      source.push_back((unsigned char)target[i]);
    }
  for(int i=0;i<password.size();i++){
      pass.push_back((unsigned char)password[i]);
    }
  vector<long> difference;
  int size = source.size() - pass.size();
  int x = 0;
  for(int i=0;i<size;i++){
      if(x<pass.size()){
          pass.push_back(pass[x]);
          x++;
        }else{
          x = 0;
        }
    }
  for(int i =0;i<pass.size(); i++){
      pass[i] = (stoi(DecimalToOctal(pass[i])));
    }
  for(int i =0; i< source.size(); i++){
      difference.push_back(source[i]-pass[i]);
    }
  for(int i =0;i<difference.size(); i++){
      difference[i] = octalToDecimal(difference[i]);
    }
  vector<char> to_char;
  for(int i = 0; i<difference.size(); i++){
      to_char.push_back((char)difference[i]);
    }
  string decrypted(to_char.begin(), to_char.end());
  return decrypted;

}

