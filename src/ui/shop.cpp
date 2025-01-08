//
// Created by Lukyn on 14.12.2024.
//

#include "shop.h"

#include "../domain/value_objects/screen.h"

Shop::Shop(const std::function<void(Screen screen, char keyboardKey)> &changeScreenCallback) {
    m_scene = new Scenes();
    m_changeScreenCallback = changeScreenCallback;
    //Items to buy-creation
    //Weapons:
    m_warriorWeapon1 = new Weapon(10, 300);
    m_warriorWeapon2 = new Weapon(15, 400);
    m_warriorWeapon3 = new Weapon(25, 800);
    m_archerWeapon1 = new Weapon(10, 300);
    m_archerWeapon2 = new Weapon(13, 400);
    m_archerWeapon3 = new Weapon(15, 500);
    m_mageWeapon1 = new Weapon(10, 350);
    m_mageWeapon2 = new Weapon(15, 400);
    m_mageWeapon3 = new Weapon(18, 600);
    //Armors:
    m_warriorArmor1 = new Armor(10, 500);
    m_warriorArmor2 = new Armor(15, 700);
    m_warriorArmor3 = new Armor(20, 1000);
    m_archerArmor1 = new Armor(8, 400);
    m_archerArmor2 = new Armor(12, 600);
    m_archerArmor3 = new Armor(15, 800);
    m_mageArmor1 = new Armor(7, 400);
    m_mageArmor2 = new Armor(10, 700);
    m_mageArmor3 = new Armor(15, 1300);
    //Potions:
    m_potion = new Potion();
}

Shop::~Shop() {
    delete m_scene;
}

//Functionality
void Shop::changeScreen(const Screen newScreen, const char keyboardKey) {
    m_changeScreenCallback(newScreen, keyboardKey);
}

void Shop::buyWeapon(Player *player, Weapon *weapon) {
    if (player->getCoins() - weapon->getPrice() >= 0) {
        player->removeCoins(weapon->getPrice());
        player->addWeapon(weapon);
    } else {
        std::cout << "NOT ENOUGH COINS\n";
    }
}

void Shop::buyArmor(Player *player, Armor *armor) {
    if (player->getCoins() - armor->getPrice() >= 0) {
        player->removeCoins(armor->getPrice());
        player->addArmor(armor);
    } else {
        std::cout << "NOT ENOUGH COINS\n";
    }
}

void Shop::buyPotion(Player *player, Potion *potion) {
    if (player->getCoins() - potion->getPrice() >= 0) {
        player->removeCoins(potion->getPrice());
        player->addPotion();
    } else {
        std::cout << "NOT ENOUGH COINS\n";
    }
}

void Shop::confirmSelectionShopMain(const char keyboardKey, int selected) {
    switch (selected) {
        case 0:
            changeScreen(Screen::shopWeapons, keyboardKey);
            break;
        case 1:
            changeScreen(Screen::shopArmor, keyboardKey);
            break;
        case 2:
            changeScreen(Screen::shopPotions, keyboardKey);
            break;
        case 3:
            if (keyboardKey == KEYBOARD_ENTER) {
                changeScreen(Screen::game, keyboardKey);
            }
            break;
        default: break;
    }
}

void Shop::confirmSelectionShopWeapons(char keyboardKey, int selected, Player *player) {
    if (keyboardKey == KEYBOARD_ENTER) {
        switch (selected) {
            case 0:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyWeapon(player, m_warriorWeapon1);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                    case Role::archer:
                        buyWeapon(player, m_archerWeapon1);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                    case Role::mage:
                        buyWeapon(player, m_mageWeapon1);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                }
                break;
            case 1:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyWeapon(player, m_warriorWeapon2);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                    case Role::archer:
                        buyWeapon(player, m_archerWeapon2);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                    case Role::mage:
                        buyWeapon(player, m_mageWeapon2);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                }
                break;
            case 2:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyWeapon(player, m_warriorWeapon3);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                    case Role::archer:
                        buyWeapon(player, m_archerWeapon3);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                    case Role::mage:
                        buyWeapon(player, m_mageWeapon3);
                        changeScreen(Screen::shopWeapons, keyboardKey);
                        break;
                }
                break;
            default: break;
        }
    }
}

void Shop::confirmSelectionShopArmor(char keyboardKey, int selected, Player *player) {
    if (keyboardKey == KEYBOARD_ENTER) {
        switch (selected) {
            case 0:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyArmor(player, m_warriorArmor1);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                    case Role::archer:
                        buyArmor(player, m_archerArmor1);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                    case Role::mage:
                        buyArmor(player, m_mageArmor1);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                }
                break;
            case 1:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyArmor(player, m_warriorArmor2);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                    case Role::archer:
                        buyArmor(player, m_archerArmor2);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                    case Role::mage:
                        buyArmor(player, m_mageArmor2);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                }
                break;
            case 2:
                switch (player->getRole()) {
                    case Role::warrior:
                        buyArmor(player, m_warriorArmor3);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                    case Role::archer:
                        buyArmor(player, m_archerArmor3);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                    case Role::mage:
                        buyArmor(player, m_mageArmor3);
                        changeScreen(Screen::shopArmor, keyboardKey);
                        break;
                }
                break;
            default: break;
        }
    }
}

void Shop::confirmSelectionShopPotions(char keyboardKey, int selected, Player *player) {
    if (keyboardKey == KEYBOARD_ENTER) {
        switch (selected) {
            case 2:
                buyPotion(player, m_potion);
                changeScreen(Screen::shopPotions, keyboardKey);
                break;
            default: break;
        }
    }
}

//Scenes
void Shop::displayShopHeader() const {
    m_scene->sceneShopHeader();
}

void Shop::displayShopWeaponHeader(Player *player) const {
    m_scene->sceneShopWeaponHeader(player);
}

void Shop::displayShopArmorHeader(Player *player) const {
    m_scene->sceneShopArmorHeader(player);
}

void Shop::displayShopPotionHeader(Player *player) const {
    m_scene->sceneShopPotionHeader(player);
}

void Shop::displayShopHint() const {
    m_scene->sceneShopHint();
}

void Shop::displayShopMain(int selected) const {
    displayShopHeader();
    switch (selected) {
        case 0:
            m_scene->sceneShopMainSelectedWeapons();
            break;
        case 1:
            m_scene->sceneShopMainSelectedArmor();
            break;
        case 2:
            m_scene->sceneShopMainSelectedPotions();
            break;
        case 3:
            m_scene->sceneShopMainSelectedExit();
            break;
        default: break;
    }
    displayShopHint();
}

void Shop::displayShopWeapons(int selected, Player *player) const {
    displayShopWeaponHeader(player);
    switch (selected) {
        case 0:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopWeaponsSelectedWeapon1(player, m_warriorWeapon1);
                    break;
                case Role::archer:
                    m_scene->sceneShopWeaponsSelectedWeapon1(player, m_archerWeapon1);
                    break;
                case Role::mage:
                    m_scene->sceneShopWeaponsSelectedWeapon1(player, m_mageWeapon1);
                    break;
            }
            break;
        case 1:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopWeaponsSelectedWeapon2(player, m_warriorWeapon2);
                    break;
                case Role::archer:
                    m_scene->sceneShopWeaponsSelectedWeapon2(player, m_archerWeapon2);
                    break;
                case Role::mage:
                    m_scene->sceneShopWeaponsSelectedWeapon2(player, m_mageWeapon2);
                    break;
            }
            break;
        case 2:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopWeaponsSelectedWeapon3(player, m_warriorWeapon3);
                    break;
                case Role::archer:
                    m_scene->sceneShopWeaponsSelectedWeapon3(player, m_archerWeapon3);
                    break;
                case Role::mage:
                    m_scene->sceneShopWeaponsSelectedWeapon3(player, m_mageWeapon3);
                    break;
            }
            break;
        default: break;
    }
}

void Shop::displayShopArmor(int selected, Player *player) const {
    displayShopArmorHeader(player);
    switch (selected) {
        case 0:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopArmorSelectedArmor1(player, m_warriorArmor1);
                    break;
                case Role::archer:
                    m_scene->sceneShopArmorSelectedArmor1(player, m_archerArmor1);
                    break;
                case Role::mage:
                    m_scene->sceneShopArmorSelectedArmor1(player, m_mageArmor1);
                    break;
            }
            break;
        case 1:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopArmorSelectedArmor2(player, m_warriorArmor2);
                    break;
                case Role::archer:
                    m_scene->sceneShopArmorSelectedArmor2(player, m_archerArmor2);
                    break;
                case Role::mage:
                    m_scene->sceneShopArmorSelectedArmor2(player, m_mageArmor2);
                    break;
            }
            break;
        case 2:
            switch (player->getRole()) {
                case Role::warrior:
                    m_scene->sceneShopArmorSelectedArmor3(player, m_warriorArmor3);
                    break;
                case Role::archer:
                    m_scene->sceneShopArmorSelectedArmor3(player, m_archerArmor3);
                    break;
                case Role::mage:
                    m_scene->sceneShopArmorSelectedArmor3(player, m_mageArmor3);
                    break;
            }
            break;
        default: break;
    }
}

void Shop::displayShopPotions(int selected, Player *player) const {
    displayShopPotionHeader(player);
    switch (selected) {
        case 2:
            m_scene->sceneShopPotionsSelectedPotion1(m_potion);
            break;
        default: break;
    }
}
