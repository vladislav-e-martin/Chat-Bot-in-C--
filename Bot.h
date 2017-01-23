//
// Created by Vladislav on 1/15/2017.
//

#include <string>
#include <vector>

using namespace std;

#ifndef WEEKEND_MARATHON_1_BOT_H
#define WEEKEND_MARATHON_1_BOT_H

class Bot
{
public:
    Bot();
    string getQuery();
    void setQuery(string new_query);
    void getReplyFromUser(bool initialize);
    vector<string> getReply();
    void setReply(vector<string> new_reply);
private:
    string greeting;
    string query;
    string quit_instructions;
    vector<string> reply;
};


#endif //WEEKEND_MARATHON_1_BOT_H
