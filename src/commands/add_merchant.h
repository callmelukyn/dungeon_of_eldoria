#ifndef ADD_MERCHANT_H
#define ADD_MERCHANT_H
#include <vector>

#include "../domain/entities/merchant.h"
#include "../map/map.h"


class AddMerchant {
    Merchant *m_merchant;
    std::vector<Map *> m_maps;

public:
    explicit AddMerchant(const std::vector<Map *> &maps);

    ~AddMerchant();

    void addMerchant(int currentLevel, Position position);

    Merchant *getMerchant() const;
};


#endif //ADD_MERCHANT_H
