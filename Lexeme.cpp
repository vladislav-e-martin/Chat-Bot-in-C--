//
// Created by Vladislav on 1/15/2017.
//

#include <iostream>
#include "Lexeme.h"

Lexeme::Lexeme()
{
    pair<string, int> lexeme_pair;
    cout << "Creating a new Lexeme object..." << endl;
    vector<string> lexeme_options = {"time", "date", "weather", "location", "email"};
    for (unsigned int i = 1; i < (lexeme_options.size() + 1); i++)
    {
        lexeme_pair = {lexeme_options.at(i - 1), i};
        lexeme_map.insert(lexeme_pair);
    }
}

map<string, int> Lexeme::getMap()
{
    return lexeme_map;
}

void Lexeme::setMap(map<string, int> new_lexeme_map)
{
    lexeme_map = new_lexeme_map;
}

// Input Arguments...
// string mapped_string : the string that is mapped to the integer
int Lexeme::findMapFromString(string mapped_string, bool verbose)
{
    int string_map; // The integer that is mapped to the string
    if (!mapped_string.empty())
    {
        const auto string_lookup = lexeme_map.find(mapped_string);
        // Check to see if the look-up turned up empty
        if (string_lookup == lexeme_map.end())
        {
            string_map = 0;
            if (verbose) { cout << "The lexeme '" << mapped_string << "' mapped to: " << string_map << endl; }
            return string_map;
        }
        // Map the user's command to the appropriate index
        else
        {
            string_map = string_lookup->second;
            if (verbose) { cout << "The lexeme '" << mapped_string << "' mapped to: " << string_map << endl; }
            return string_map;
        }
    }
    else
    {
        cout << "You won't find a match with a word that doesn't exist!" << endl;
        return 0;
    }
}

string Lexeme::findStringFromMap(int string_map)
{
}