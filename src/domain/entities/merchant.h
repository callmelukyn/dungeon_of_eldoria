//
// Created by Lukyn on 14.12.2024.
//

#ifndef MERCHANT_H
#define MERCHANT_H
#include "player.h"
#include "../../map/map.h"
#include "../value_objects/screen.h"

class Merchant {
    Position m_position;
    int m_range;

public:
    Merchant(Position position);

    Position getPosition();

    void displayShop() const;

    void interaction(Screen currentScreen, const Player *player, char keyboardKey,
                     const std::function<void()> &changeScreen) const;
};


#endif //MERCHANT_H
