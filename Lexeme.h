//
// Created by Vladislav on 1/15/2017.
//

#include <string>
#include <vector>
#include <map>

using namespace std;

#ifndef WEEKEND_MARATHON_1_LEXEME_H
#define WEEKEND_MARATHON_1_LEXEME_H


class Lexeme
{
public:
    Lexeme();
    map<string, int> getMap();
    void setMap(map<string, int> new_lexeme_map);
    int findMapFromString(string mapped_string, bool verbose);
    string findStringFromMap(int string_map);
private:
    map<string, int> lexeme_map;
};


#endif //WEEKEND_MARATHON_1_LEXEME_H
