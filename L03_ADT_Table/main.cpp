#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <map>
#include <unordered_map>
#include <algorithm>

#include "Crono.cpp"

std::vector<std::wstring> SepararPalabras(std::wifstream &in);
void QuitarCaracteresRaros(std::vector<std::wstring> &palabras);

template <typename T>
void ContadorPalabrasRepetidas(T &contador, std::vector<std::wstring> &palabras);

template <typename T>
void MostrarMap(T &mapa);

template <typename T>
std::vector<std::pair<std::wstring, int>> RankPalabrasMasUsadas(const T& map, const int& n);

const int ITERACIONES = 100;

int main() 
{
    // If it is not found, search with: cat /etc/locale.gen | grep is
    // the available languages
    std::locale::global(std::locale("en_US.UTF-8")); // es_ES.UTF-8 no funciona...

    // std::locale loc("es_ES.UTF-8");
    // std::setlocale(LC_ALL, loc.name().c_str());


    // Text1 test
    std::wcout << L"test map" << std::endl;

    std::map<std::wstring, int> contador;
    std::wifstream in("texto1.txt");
    std::vector<std::wstring> palabras = SepararPalabras(in);
    ContadorPalabrasRepetidas(contador, palabras);

    MostrarMap(contador);

    // Text2
    in = std::wifstream("texto2.txt");
    palabras = SepararPalabras(in);

    // std::map
    {
        Cronometro crono = Cronometro();

        for (int i=0; i < ITERACIONES; i++){
            std::map<std::wstring, int> contador2;
            ContadorPalabrasRepetidas(contador2, palabras);
        }

        std::wcout << "Tiempo: ";
    }

    // std::unordered_map
    {
        Cronometro crono = Cronometro();

        for (int i=0; i < ITERACIONES; i++){
            std::unordered_map<std::wstring, int> contador2;
            ContadorPalabrasRepetidas(contador2, palabras);
        }

        std::wcout << "Tiempo: ";
    }

    // Rank words
    std::map<std::wstring, int> contador2;
    ContadorPalabrasRepetidas(contador2, palabras);
    std::vector<std::pair<std::wstring, int>> rank = RankPalabrasMasUsadas(contador2, 30);

    std::wcout << L"\n#### Ranking ####" << std::endl;
    for (auto &p : rank){
        std::wcout << p.first << L": " << p.second << std::endl;
    }

    std::wcout << "Fin" << std::endl;

    return 0;
}

/**********************************************************************/ /**
*
*  Separates words from a text file, also removes all characters
*  who are not alphabetic.
*
*  @param [in] in Input file
*  @return Word vector
*
*/
/**********************************************************************/
std::vector<std::wstring> SepararPalabras(std::wifstream &in)
{
    std::vector<std::wstring> palabras;
    std::wstring linea;
    while (std::getline(in, linea))
    {
        // Separar la linea en palabras
        std::wistringstream iss(linea);
        std::wstring palabra;
        while (iss >> palabra)
        {
            palabras.push_back(palabra);
        }        
    }

    QuitarCaracteresRaros(palabras);
    return palabras;
}

/**********************************************************************/ /**
*
*  Remove all non-alphabetic characters.
*
*  @param [out] words Word vector
*
*/
/**********************************************************************/
void QuitarCaracteresRaros(std::vector<std::wstring> &palabras) 
{
    std::locale loc;
    const std::ctype<wchar_t> &ct = std::use_facet<std::ctype<wchar_t>>(loc);

    for (auto &palabra : palabras)
    {

        // Erase extrange chars
        palabra.erase(std::remove_if(palabra.begin(), palabra.end(),
                                     [&ct](wchar_t c) { return !ct.is(std::ctype_base::alpha, c); }),
                      palabra.end());

        // To lower
        ct.tolower(&palabra[0], &palabra[0] + palabra.size());
    } 
}

/**********************************************************************/ /**
*
*  Counts repeated words in a word vector.
*
*  @param [out] counter Word Map
*  @param [out] words Word vector
*
**************************************************************************/
template <typename T>
void ContadorPalabrasRepetidas(T &contador, std::vector<std::wstring> &palabras)
{
    for (auto &palabra : palabras)
    {
        if (contador.find(palabra) == contador.end())
        {
            contador[palabra] = 1;
        }
        else
        {
            contador[palabra]++;
        }
    }
}

/**********************************************************************/ /**
*
*  Shows the content of a map.
*
*  @param [in] map Word map
*
**************************************************************************/
template <typename T>
void MostrarMap(T &mapa)
{
    for (auto par : mapa)
        std::wcout << par.first << " " << par.second << std::endl;
}

/**********************************************************************/ /**
*
*  Returns a vector with the n most used words.
*
*  @param [in] map Word map
*  @param [in] n Number of words to return
*  @return Word vector
*
**************************************************************************/
template <typename T>
std::vector<std::pair<std::wstring, int>> RankPalabrasMasUsadas(const T& map, const int& n)
{
    std::vector<std::pair<std::wstring, int>> palabras;
    std::multimap<int, std::wstring> rank;

    for (auto it = map.begin(); it != map.end(); it++) {
        rank.insert(std::pair<int, std::wstring>(it->second, it->first));
    }

    auto it = rank.end();
    --it;
    for (unsigned i = 0; i < n; i++, --it){
        palabras.push_back(std::pair<std::wstring, int>(it->second, it->first));
    }
    return palabras;
}