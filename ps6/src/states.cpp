#include<states.h>
#include<Arduino.h>

#include<rtc_wrapper.h>
#include<lcd_wrapper.h>
#include<sensors.h>
#include<config.h>

#include<EEPROM.h>

#define SPACE_SYBMOL "0"

// 9 -> 09 $$ 12 -> 12
#define B_SPACE(DATA) (DATA<10 ? SPACE_SYBMOL : ""),DATA
//повышение в границах
#define UPPER_TO(DATA,MIN,MAX) DATA=(DATA+1>=MAX ? MIN : DATA+1)



#define DELAY_CLICK 150

//используем функ и переменную из main.cpp
void on_button_press();
extern byte btn_state;


//time print format
void print_time_at(struct dt clock,byte y,byte x){
    lcd_printf_at(y,x,"%s%d:%s%d:%s%d",B_SPACE(clock.hours),B_SPACE(clock.minutes),B_SPACE(clock.seconds));
}
void print_date_at(struct dt clock,byte y,byte x){
    lcd_printf_at(y,x,"%d/%s%d/%s%d",clock.year,B_SPACE(clock.month),B_SPACE(clock.day));
}
//change interface
void print_clock(struct dt clock){
    lcd_print_at(0,0,"time: ");
    print_time_at(clock,6,0);
    lcd_print_at(3,1,"Good time"); 
}
void print_date(struct dt clock){
    lcd_print_at(0,0,"date: ");
    print_date_at(clock,6,0);
    lcd_print_at(4,1,"Good day");
}
void print_budic(struct dt *clock){
    if(clock==NULL){
        lcd_print_at(0,0,"alarm: NULL");
    }else{
        lcd_print_at(0,0,"alarm:");
        print_time_at(*clock,7,0);
    }
}
struct dt skip_time(struct dt s,int time){
    if(s.minutes+time>=60){
        s.minutes=s.minutes+time-60;
        s.hours=UPPER_TO(s.hours,0,24);
    }else{
        s.minutes+=time;
    }
    return s;
}
void skip_budic(int time){
    struct dt now_clock=now();
    now_clock=skip_time(now_clock,time);
    EEPROM.put(1,now_clock);
    EEPROM.put(0,true);
}
//change lamp reaction
void lamp_alarm(){
    digitalWrite(A1,HIGH);
    while(1){
        on_button_press();
        if(btn_state& BTN1_PRESSED) skip_budic(1);
        else if(btn_state & BTN2_PRESSED) skip_budic(5);
        if(btn_state !=0)break;
        digitalWrite(BUZZER_PIN,HIGH);
        delay(300);
        if(btn_state& BTN1_PIN) skip_budic(5);
        else if(btn_state & BTN2_PRESSED) skip_budic(5);
        if(btn_state !=0 )break;
        digitalWrite(BUZZER_PIN,LOW);
        delay(300);
    }
    digitalWrite(A1,LOW);
}
//change alarm reaction
void alarm(){
    lcd_clear();
    lcd_print_at(0,0,"alarm alarm");
    digitalWrite(BUZZER_PIN,HIGH);
    lamp_alarm();
    digitalWrite(BUZZER_PIN,LOW);
    lcd_clear();
    delay(1000);
}


bool time_cmp(struct dt a,struct dt b){
    return (a.hours==b.hours && a.minutes==b.minutes && a.seconds==b.seconds);
}
void budic_handler(){
    byte flag=EEPROM.read(0);
    if(flag){
        struct dt clock;
        EEPROM.get(1,clock);
        struct dt now_clock=now();
        if(time_cmp(clock,now_clock)){
            EEPROM.put(0,false);
            alarm();
        }
    }
    flag=EEPROM.read(10);
    if(flag){
        struct dt clock;
        EEPROM.get(11,clock);
        struct dt now_clock=now();
        if(time_cmp(clock,now_clock)){
            EEPROM.put(10,false);
            alarm();
        }
    }

}
bool handler_time(struct dt *clock){
    on_button_press();
    if(btn_state & BTN1_PRESSED){UPPER_TO(clock->hours,0,24);delay(DELAY_CLICK);}
    if(btn_state & BTN2_PRESSED){UPPER_TO(clock->minutes,0,60);delay(DELAY_CLICK);}
    if(btn_state & BTN3_PRESSED){UPPER_TO(clock->seconds,0,60);delay(DELAY_CLICK);}
    if(btn_state & BTN4_PRESSED) return true;
    return false;
}
//используешь глоб пер но она статическая видна только в єтом файле
static uint8_t ChangeMode=false;
enum state state_clock(){
    on_button_press();
    budic_handler();
    struct dt clock=now();
    if(!ChangeMode){
        print_clock(clock);
        if(btn_state & BTN1_PRESSED){
            delay(DELAY_CLICK);
            lcd_clear();
            return ALARM;
        }else if(btn_state & BTN2_PRESSED){
            delay(DELAY_CLICK);
            lcd_clear();
            return SHOW_DATE;
        }else if(btn_state & BTN4_PRESSED){
            ChangeMode=true;
            delay(DELAY_CLICK);
            lcd_clear();
        }
    }else{
        lcd_print_at(15,0,"C");
        lcd_print_at(15,1,"#");
        print_clock(clock);
        delay(200);
        while(1){
            print_clock(clock);
            budic_handler();
            if(handler_time(&clock)){
                ChangeMode=false;
                set_time(clock.hours,clock.minutes,clock.seconds);
                delay(DELAY_CLICK);
                lcd_clear();
                break;
            }
        }       
    }
    return CLOCK;
}

uint8_t max_month_day[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool handler_date(struct dt *clock){
    on_button_press();
    budic_handler();
    if(btn_state & BTN1_PRESSED){UPPER_TO(clock->year,2000,2050);delay(DELAY_CLICK);}
    if(btn_state & BTN2_PRESSED){UPPER_TO(clock->month,1,13); delay(DELAY_CLICK);}
    if(clock->day>=max_month_day[clock->month-1]+1) clock->day=max_month_day[clock->month-1];
    if(btn_state & BTN3_PRESSED){UPPER_TO(clock->day,1,max_month_day[clock->month-1]+1);delay(DELAY_CLICK);}
    if(btn_state & BTN4_PRESSED) return true;
    return false;
}
enum state state_show_date(){
    on_button_press();
    budic_handler();
    struct dt clock=now();
    if(!ChangeMode){
        print_date(clock);
        if(btn_state & BTN1_PRESSED){
            delay(DELAY_CLICK);
            lcd_clear();
            return CLOCK;
        }else if(btn_state & BTN2_PRESSED){
            delay(DELAY_CLICK);
            lcd_clear();
            return SHOW_ENV;
        }else if(btn_state & BTN4_PRESSED){
            ChangeMode=true;
            delay(DELAY_CLICK);
            lcd_clear();
        }
    }else{
        lcd_print_at(15,0,"C");
        lcd_print_at(15,1,"#");
        print_date(clock);
        delay(200);
        while(1){
            print_date(clock);
            if(handler_date(&clock)){
                ChangeMode=false;
                set_date(clock.day,clock.month,clock.year);
                delay(DELAY_CLICK);
                lcd_clear();
                break;
            }
        }       
    }
    delay(100);
    return SHOW_DATE;
}
enum state state_alarm(){
    on_button_press();
    budic_handler();
    byte flag=EEPROM.read(0);
    if(flag){
        struct dt clock;
        EEPROM.get(1,clock);
        print_budic(&clock);
    }else print_budic(NULL);
    if(btn_state & BTN1_PRESSED){
        delay(DELAY_CLICK);
        lcd_clear();
        return TIMER;
    }else if(btn_state & BTN2_PRESSED){
        delay(DELAY_CLICK);
        lcd_clear();
        return CLOCK;
    }else if(btn_state & BTN4_PRESSED){
        ChangeMode=true;
        delay(DELAY_CLICK);
        lcd_clear();
    }
    if(ChangeMode){
        byte flag=EEPROM.read(0);
        struct dt clock=now();
        if(flag) EEPROM.get(1,clock);
        lcd_print_at(0,0,"alarm:");
        lcd_print_at(15,0,"C");
        lcd_print_at(15,1,"#");
        while(1){
            print_time_at(clock,4,1);
            if(handler_time(&clock)){
                EEPROM.put(0,true);
                EEPROM.put(1,clock);
                delay(DELAY_CLICK);
                ChangeMode=false;
                lcd_clear();
                break;
            }
        }
    }

    return ALARM;
}
enum state state_show_env(){
    on_button_press();
    budic_handler();
    if(btn_state & BTN1_PRESSED){
        delay(DELAY_CLICK);
        lcd_clear();
        return SHOW_DATE;
    }else if(btn_state & BTN2_PRESSED){
        delay(DELAY_CLICK);
        lcd_clear();
        return TIMER;
    }
    lcd_printf_at(0,1,"Humidity %d%%   ",get_humidity());
    lcd_printf_at(0,0,"Temp: %.1fC   ",get_temperature());
    delay(100);
    return SHOW_ENV;
}
long timeToSeconds(byte hours, byte minutes, byte seconds) {
    return hours * 3600L + minutes * 60 + seconds;
}

// Функция для перевода секунд с начала суток обратно в часы, минуты и секунды
void secondsToTime(long totalSeconds, byte &hours, byte &minutes, byte &seconds) {
    hours = (totalSeconds / 3600) % 24;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;
}

void addTimes(const dt &time1, const dt &time2, dt &result) {
    long seconds1 = timeToSeconds(time1.hours, time1.minutes, time1.seconds);
    long seconds2 = timeToSeconds(time2.hours, time2.minutes, time2.seconds);
    long totalSeconds = seconds1 + seconds2;
    secondsToTime(totalSeconds, result.hours, result.minutes, result.seconds);
}

enum state state_timer(){
    on_button_press();
    budic_handler();
    lcd_print_at(0,0,"timer: ");
    byte flag=EEPROM.read(10);
    if(flag){
        struct dt clock;
        struct dt n=now();
        EEPROM.get(11,clock);
        uint64_t now_time=timeToSeconds(n.hours,n.minutes,n.seconds);
        uint64_t clock_time=timeToSeconds(clock.hours,clock.minutes,clock.seconds);
        struct dt res;
        secondsToTime(clock_time-now_time,res.hours,res.minutes,res.seconds);
        print_time_at(res,8,0);
    }else lcd_print_at(8,0,"NULL");
    if(btn_state & BTN1_PRESSED){
        delay(DELAY_CLICK);
        lcd_clear();
        return SHOW_ENV;
    }else if(btn_state & BTN2_PRESSED){
        delay(DELAY_CLICK);
        lcd_clear();
        return ALARM;
    }else if(btn_state & BTN4_PRESSED){
        ChangeMode=true;
        delay(DELAY_CLICK);
        lcd_clear();
    }
    if(ChangeMode){
        byte flag=EEPROM.read(0);
        struct dt clock;
       
        //if(flag) EEPROM.get(10,clock);
        memset(&clock,0,sizeof(clock));
        lcd_print_at(0,0,"timer:");
        lcd_print_at(15,0,"C");
        lcd_print_at(15,1,"#");
        while(1){
            print_time_at(clock,4,1);
            if(handler_time(&clock)){
                struct dt n=now();
                EEPROM.put(10,true);
                struct dt res;
                addTimes(n,clock,res);
                EEPROM.put(11,res);
                delay(DELAY_CLICK);
                ChangeMode=false;
                lcd_clear();
                break;
            }
        }
    }

    return TIMER;
}
