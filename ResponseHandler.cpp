//
// Created by Vladislav on 1/22/2017.
//

#include <iostream>
#include <locale>
#include <ctime>
#include <iomanip>
#include "ResponseHandler.h"

ResponseHandler::ResponseHandler()
{
    cout << "Creating a new ResponseHandler object..." << endl;
}

void ResponseHandler::getDate()
{
    time_t raw_time;
    struct tm * time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    cout << "Today is " << put_time(time_info, "%A") <<  ". Today's date is " <<
            put_time(time_info, "%B %d, %Y.") << endl;
}

void ResponseHandler::getTime()
{
    time_t raw_time;
    struct tm * time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);
    // Many of the options don't work for some reason (%r, %p, for instance)
    cout << put_time(time_info, "%H:%M:%S") << endl;
    // Can't get locales to work for some reason
    //cout.imbue(locale("en_US.utf8"));
    //cout << "en_US: " << put_time(time_info, "%Z") << endl;
    //cout.imbue(locale("ru_RU.utf8"));
    //cout << "ru_RU: " << put_time(time_info, "%Z") << endl;
}
void ResponseHandler::sendEmail(string source_email, string target_email)
{
    cout << "I can't send an email yet..." << endl;
}
void ResponseHandler::getWeather(int zip_code, bool verbose)
{
    cout << "I can't predict the weather yet..." << endl;
}

void ResponseHandler::getLocation()
{
    cout << "I don't know how to retrieve your location yet..." << endl;
}