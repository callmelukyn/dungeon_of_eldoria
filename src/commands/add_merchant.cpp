#include "add_merchant.h"

AddMerchant::AddMerchant(const std::vector<Map *> &maps) {
    m_merchant = nullptr;
    m_maps = maps;
}

AddMerchant::~AddMerchant() {
    delete m_merchant;
}

void AddMerchant::addMerchant(const int currentLevel, const Position position) {
    m_merchant = new Merchant(position);
    m_maps[currentLevel]->putCharacterInPosition(position, '$');
}

Merchant *AddMerchant::getMerchant() const {
    return m_merchant;
}

void AddMerchant::setMerchantToNull() {
    m_merchant = nullptr;
}
