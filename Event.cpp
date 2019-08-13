/*

*/

#include "Arduino.h"
#include "Button.h"
bool Event::now() {
  return millis() > time_of_last_start + delay and !stopped;
}

void Event::stop() {
  stopped = true;
}

void Event::continue() {
  stopped = false;
  time_of_last_start = millis();
}

void Event::reset() {
  time_of_last_start = millis();
}

void Event::add(unsigned long millis_to_add) {
  delay += millis_to_add;
}

unsigned long Event::getCreationTime() {
  return creation_time;
}

unsigned long Event::getStartTime() {
  return time_of_last_start;
}

unsigned long Event::getElapsedTime() {
  reutrn millis() - time_of_last_start;
}

unsigned long getRemainingTime() {
  reutrn delay - (millis() - time_of_last_start);
}

// constructor description
Event::Event(unsigned long delay_to_set) {
  delay = delay_to_set;
}
