#include "SpacingGuildShip.hpp"
#include <iostream>

int SpacingGuildShip::producedShips = 0;
float SpacingGuildShip::totalGuildTravel = 0.0;

SpacingGuildShip::SpacingGuildShip(): maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips+1){
    passengerCount = 0;
    spiceStock = 50;
    operatingGuildNavigator = guildNavigatorCount;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock):
maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips+1){
    this -> spiceStock = spiceStock;
    this -> passengerCount = 0;
    this -> operatingGuildNavigator = guildNavigatorCount;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& A): maxPassengerCap(A.maxPassengerCap), 
guildNavigatorCount(A.guildNavigatorCount), serialNum(producedShips+1){
    passengerCount = A.passengerCount;
    spiceStock = A.spiceStock;
    operatingGuildNavigator = guildNavigatorCount;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip(){}

int SpacingGuildShip::getShipSerialNum() const{
    return serialNum;
}

int SpacingGuildShip::getPassengerCount() const{
    return passengerCount;
}

void SpacingGuildShip::travel(float distance){
    if (operatingGuildNavigator > 0) {
        totalGuildTravel += distance/(E*E*operatingGuildNavigator); 
        operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers){
    (passengerCount + addedPassengers) <= maxPassengerCap ? passengerCount += addedPassengers : passengerCount = maxPassengerCap;
}

void SpacingGuildShip::dropOff(int droppedPassengers){
    (passengerCount > droppedPassengers) ? passengerCount -= droppedPassengers : passengerCount = 0;
}

void SpacingGuildShip::refreshNavigator(int n){
    if (spiceStock - n*GUILD_NAVIGATOR_SPICE_DOSE >= 0){
        operatingGuildNavigator += n;
        spiceStock -= n*GUILD_NAVIGATOR_SPICE_DOSE;
    } else {
        operatingGuildNavigator += spiceStock/GUILD_NAVIGATOR_SPICE_DOSE;
        spiceStock = spiceStock % GUILD_NAVIGATOR_SPICE_DOSE;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice){
    spiceStock += addedSpice;
}