/********************************************************************************************************************************
*** Author: R. Erdem Uysal                                                                                                    ***
*** Company: Atılım University                                                                                                ***
*** Create Date: 21:16:00 10/28/2015                                                                                          ***
*** Project Name: IP Parsing from Log Data	                                                                                ***
*** Additional Comments:                                                                                                      ***
***                                                                                                                           ***
*** This project have done for CS101- Introduction to Programming with C/C++ course.                                          ***
*** You can download log file that I used in this project from this link;                                                     ***
*** http://ita.ee.lbl.gov/html/contrib/NASA-HTTP.html                                                                         ***
***                                                                                                                           ***
********************************************************************************************************************************/

#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

vector<string> ayir(string satir) {
  /* Okunan string char'a cast ediliyor.
  Yani string char dizisine dönüştürülüyor.*/
  char* cstr = const_cast<char*>(satir.c_str());
  char* ayrilmisSatirElemani;
  vector<string> ayrilmisSatirDizisi;
  /*strtok ile char dizisi parçalanıyor*/
  ayrilmisSatirElemani = strtok(cstr, " ");

  while (ayrilmisSatirElemani != NULL) {
    ayrilmisSatirDizisi.push_back(ayrilmisSatirElemani);
    ayrilmisSatirElemani = strtok(NULL, " ");
  }
  return ayrilmisSatirDizisi;
}
int main() {

  ifstream okunacakDosya("C:/Users/ASUS/Projects/C++/LogDataParsing/log_data_parsing/access_log_Aug95.txt");
  ofstream sonucDosyasi("C:/Users/ASUS/Projects/C++/LogDataParsing/log_data_parsing/log_data_output.txt");
  string satir;
  vector<string> ayrilmisSatirDizisi;

  while (getline(okunacakDosya, satir)) {
    /*ayir() fonksiyonu burada çağrılıyor.*/
    ayrilmisSatirDizisi = ayir(satir);
    sonucDosyasi << ayrilmisSatirDizisi[0] + " " +
    ayrilmisSatirDizisi[6].substr(0, ayrilmisSatirDizisi[6].size() - 1) << endl;
  }

  okunacakDosya.close();
  sonucDosyasi.close();
  cout<<"File has been readed and parsing succesfully."<<endl;
  return 0;
}





