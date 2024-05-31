#include <Arduino.h>
#include <Wire.h>
#include <RtcDS1302.h>
#include "rtc_wrapper.h"
#include"config.h"

ThreeWire myWire(10,11,9); // IO, SCLK, CE
RtcDS1302<ThreeWire> rtc(myWire);

void clock_init() {
    myWire.begin();
    rtc.Begin();
}


byte get_day(){return rtc.GetDateTime().Day();}
byte get_month(){return rtc.GetDateTime().Month();}
int get_year(){return rtc.GetDateTime().Year();}
byte get_hours(){
    return rtc.GetDateTime().Hour();    
}
byte get_minutes(){return rtc.GetDateTime().Minute();}
byte get_seconds(){return rtc.GetDateTime().Second();}

void set_date(const byte day, const byte month, const int year) {
    RtcDateTime compiled =  RtcDateTime(year,month,day,get_hours(),get_minutes(),get_seconds());
    if (compiled.IsValid()) 
    {
        Serial.println("error set time");
    }
    rtc.SetDateTime(compiled);
}

void set_time(const byte hours, const byte minutes, const byte seconds) {
    RtcDateTime compiled = RtcDateTime(get_year(),get_month(),get_day(),hours,minutes,seconds);
    if (compiled.IsValid()) 
    {
        Serial.println("error set time");
    }
    rtc.SetDateTime(compiled);
}

void set_datetime(const byte day, const byte month, const int year, const byte hours, const byte minutes, const byte seconds) {
    RtcDateTime compiled = RtcDateTime(year,month,day,hours,minutes,seconds);
    if (compiled.IsValid()) 
    {
        Serial.println("error set datetime");
    }
    rtc.SetDateTime(compiled);
}

struct dt now() {
    struct dt current_dt;
    current_dt.day = get_day();
    current_dt.month = get_month();
    current_dt.year = get_year();
    current_dt.hours = get_hours();
    current_dt.minutes = get_minutes();
    current_dt.seconds = get_seconds();
    return current_dt;
}
