#include "time.h"

void time::update_time(float current_frame_time)
{
    delta_time = current_frame_time - last_frame_time;
    last_frame_time = current_frame_time;
}

float time::get_delta_time()
{
    return delta_time;
}
