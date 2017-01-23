//
// Created by Vladislav on 1/22/2017.
//

#include <string>
#include <vector>

using namespace std;

#ifndef WEEKEND_MARATHON_1_RESPONSEHANDLER_H
#define WEEKEND_MARATHON_1_RESPONSEHANDLER_H

class ResponseHandler
{
public:
    ResponseHandler();
    void getDate();
    void getTime();
    void sendEmail(string source_email, string target_email);
    void getWeather(int zip_code, bool verbose);
    void getLocation();
//private:
    // Maybe add some variables here later
};


#endif //WEEKEND_MARATHON_1_RESPONSEHANDLER_H
