#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "Lexeme.h"
#include "Bot.h"
#include "ResponseHandler.h"

using namespace std;

int main()
{
    // Variable initialization
    Lexeme response_lexeme;
    Bot bot;
    ResponseHandler response_handler;
    bool initialize_user;
    int command_map = 0;

    // So that the user can give multiple commands
    while (true)
    {
        vector<string> empty_reply = {"quit"};
        bot.setReply(empty_reply);
        bot.getReplyFromUser(initialize_user);
        if (initialize_user)
        {
            initialize_user = false;
        }
        // SAMPLE RESPONSES
        // "I want to go home"
        // "We want to know what time it is"
        // "They want to know what the weather is like"
        // "She wants to know what day it is today"

        // I could perform this processing in the above while loop (reducing algorithmic complexity)
        // THIS CAN'T HANDLE PERIODS / PUNCTUATION
        vector<string> user_reply = bot.getReply();
        cout << "User's reply: " << user_reply[0] << endl;
        string current_word;
        bool verbose = false;
        for(vector<string>::const_iterator iter = user_reply.begin();
            iter != user_reply.end(); ++iter)
        {
            current_word = *iter;
            // Convert the string to lowercase
            transform(current_word.begin(), current_word.end(), current_word.begin(), ::tolower);
            verbose = true;
            command_map = response_lexeme.findMapFromString(current_word, verbose);
        }
        current_word.clear();

        // Now the subject / verb / object has been extracted from the user's response...
        // Process! Call function in the subject that determines which function to call based on the verb,
        // then call that function in verb so that it can determine what function must be called from object,
        // which performs the final task.

        int my_zip = 11111;
        bool verbose_info = false;
        string source = "ex@example.org";
        string destination = "example@ex.edu";
        stringstream reply_stream;
        string reply_sentence;

        switch(command_map)
        {
            case 0:
                cout << "Quitting & exiting the program :( ..." << endl;
                return 0;
            case 1:
                response_handler.getTime();
                break;
            case 2:
                response_handler.getDate();
                break;
            case 3:
                response_handler.getWeather(my_zip, verbose_info);
                break;
            case 4:
                response_handler.getLocation();
                break;
            case 5:
                response_handler.sendEmail(source, destination);
                break;
            default:
                for(size_t i = 0; i < user_reply.size(); ++i)
                {
                    if(i != 0)
                        reply_stream << " ";
                    reply_stream << user_reply[i];
                }
                reply_sentence = reply_stream.str();
                cout << "I didn't understand the command '" << reply_sentence << "'..." << endl;
                break;
        }
    }

    return 0;
}