#pragma once


class keyboard_event
{
    int last_pressed_key_ = 0;
    int last_released_key_ = 0;

public:

    void set_last_released_key(int key);
    void set_last_pressed_key(int key);

    int get_last_released_key() const;
    int get_last_pressed_key() const;

};
