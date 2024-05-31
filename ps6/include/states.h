/**
 * List of available states.
 */
enum state {
    ALARM,
    CLOCK,
    SHOW_DATE,
    SHOW_ENV,
    TIMER
};


/**
 * Individual implementation of states.
 */

enum state state_clock();
//enum state state_factory_reset();
enum state state_timer();
enum state state_alarm();
enum state state_show_date();
enum state state_show_env();
