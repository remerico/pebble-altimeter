#include <pebble.h>
#include "window_main.h"

int main(void) {
  show_window_main();
  app_event_loop();
  hide_window_main();
}
