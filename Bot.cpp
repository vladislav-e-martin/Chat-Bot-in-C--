//
// Created by Vladislav on 1/15/2017.
//

#include <iostream>
#include <sstream>
#include "Bot.h"

Bot::Bot()
{
    greeting = "Hello";
    quit_instructions = "Quit the program at any time by typing 'quit' into the prompt";
    query = "What would you like me to do: ";
}

string Bot::getQuery()
{
    return query;
}

void Bot::setQuery(string new_query)
{
    if (!new_query.empty()) { query = new_query; }
    else { cout << "This query is empty. Will not update query..." << endl; }

}

vector<string> Bot::getReply()
{
    return reply;
}

void Bot::setReply(vector<string> new_reply)
{
    if (!new_reply.empty()) { reply = new_reply; }
    else { cout << "This query is empty. Will not update query..." << endl; }

}

void Bot::getReplyFromUser(bool initialize)
{
    if (initialize)
    {
        cout << quit_instructions << endl;
        cout << "Please enter your name: " << endl;
        string username;
        getline(cin, username, '\n');
        if (!username.empty()) { greeting = greeting + ", " + username + "!"; }
        else { cout << "Prefer to keep an air of mystery about yourself?" << endl; }
    }
    reply.clear();
    cout << greeting << endl;
    cout << query << endl;
    string full_reply;
    getline(cin, full_reply, '\n');

    istringstream iss_reply(full_reply);
    string sub_string;
    while (iss_reply >> sub_string);
    {
        reply.push_back(sub_string);
        cout << "The following substring was extracted from the user's reply: '" + sub_string + "'." << endl;
    }
    full_reply.clear();
    sub_string.clear();
}