#include "Cup.hpp"
#include "Plastic.hpp"
#include "PlasticCup.hpp"

bool PlasticCup::is_usable(){
    return Plastic::is_usable();
}

void PlasticCup::fill(int volume, enum WaterType type){
    if (!PlasticCup::is_usable()) return;

    Cup::fill(volume,type);
    use();
    int temp = Plastic::shred_microplastics(Cup::get_water_volume(), Cup::capacity);
    if (type == HOT_WATER){
        temp *= 2;
    }
    current_microplastics += temp;
}

void PlasticCup::drink(int volume){
    if (!is_usable()) return;
    Cup::drink(volume);
    use();
    current_microplastics = current_microplastics - volume < 0 ? 0 : current_microplastics - volume;
}

void PlasticCup::drop(int height){
    current_microplastics += Plastic::shred_microplastics(Cup::get_water_volume()*height, Cup::capacity);
}

