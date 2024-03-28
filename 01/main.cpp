#include <iostream>
#include <map>
#include <set>
#include <string>

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    size_t letterReps = 0;
    std::string phrase = "";
    std::cout << "[IN]: ";
    std::getline(std::cin, phrase);
    std::set<char> setOfLetters;
    std::multimap<size_t, char, std::greater<size_t>> mapOfLetters;

    for (size_t i {}; i < phrase.length(); i++)
    {
        setOfLetters.insert(phrase[i]);
    }

    for (const auto& i : setOfLetters)
    {
        letterReps = std::count(phrase.begin(), phrase.end(), i);
        mapOfLetters.emplace(letterReps, i);
    }

    std::cout << "[OUT]:" << std::endl;
    for (const auto& pair : mapOfLetters)
    {
        std::cout << pair.second << ": " << pair.first << std::endl;
    }
    return 0;
}