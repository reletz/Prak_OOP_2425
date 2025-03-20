#include "Cup.hpp"
#include "Glass.hpp"
#include "GlassCup.hpp"

bool GlassCup::is_usable(){
    return Glass::is_usable();
}

void GlassCup::fill(int volume, enum WaterType type){
    if (is_usable()){
        Cup::fill(volume, type);
    }
}

void GlassCup::drink(int volume){
    if (is_usable()){
        Cup::drink(volume);
    }
}

void GlassCup::drop(int height){
    Glass::apply_force(get_water_volume() ? get_water_volume()*height : height);
}


