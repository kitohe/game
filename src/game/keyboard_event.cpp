#include "keyboard_event.h"

int keyboard_event::get_last_released_key() const
{
    return last_released_key_;
}

int keyboard_event::get_last_pressed_key() const
{
    return last_pressed_key_;
}

void keyboard_event::set_last_released_key(const int key)
{
    last_released_key_ = key;
}

void keyboard_event::set_last_pressed_key(const int key)
{
    last_pressed_key_ = key;
}
