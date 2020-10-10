#pragma once
class time
{
    inline static float delta_time = 0.0f;
    inline static float last_frame_time = 0.0f;

public:
    static void update_time(float current_frame_time);
    static float get_delta_time();
};

