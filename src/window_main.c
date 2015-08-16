#include <pebble.h>
#include "window_main.h"

static Window *s_window;
static GFont s_res_bitham_42_bold;
static GFont s_res_gothic_24_bold;
static TextLayer *s_altitude_text;
static TextLayer *s_masl_label;

// Forward declarations
static void sync_changed_handler(const uint32_t key, const Tuple *new_tuple, const Tuple *old_tuple, void *context);
static void sync_error_handler(DictionaryResult dict_error, AppMessageResult app_message_error, void *context);

static void initialise_ui(void) {
  s_window = window_create();
  
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif  
    
  #ifdef PBL_COLOR
    window_set_background_color(s_window, GColorVividCerulean );
  #endif
    
  s_res_bitham_42_bold = fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD);
  s_res_gothic_24_bold = fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD);
  
  // s_altitude_text
  s_altitude_text = text_layer_create(GRect(0, 34, 144, 56));
  text_layer_set_text(s_altitude_text, "0.0");
  text_layer_set_text_alignment(s_altitude_text, GTextAlignmentCenter);
  text_layer_set_font(s_altitude_text, s_res_bitham_42_bold);
  text_layer_set_background_color(s_altitude_text, GColorClear);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_altitude_text);
  
  // s_masl_label
  s_masl_label = text_layer_create(GRect(0, 14, 144, 24));
  text_layer_set_text(s_masl_label, "MASL");
  text_layer_set_text_alignment(s_masl_label, GTextAlignmentCenter);
  text_layer_set_font(s_masl_label, s_res_gothic_24_bold);
  text_layer_set_background_color(s_masl_label, GColorClear);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_masl_label);
  
}

static void handle_window_unload(Window* window) {
  window_destroy(s_window);
  text_layer_destroy(s_altitude_text);
  text_layer_destroy(s_masl_label);
}

void show_window_main(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_window_main(void) {
  window_stack_remove(s_window, true);
}

static void sync_changed_handler(const uint32_t key, const Tuple *new_tuple, const Tuple *old_tuple, void *context) {
  // Update UI here
}

static void sync_error_handler(DictionaryResult dict_error, AppMessageResult app_message_error, void *context) {
  // An error occured!

}
