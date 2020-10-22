#ifndef BONUS_CARD_H
#define BONUS_CARD_H
#include "purchase.h"

class bonus_card : public purchase
{
    public:
        bonus_card();
        bonus_card(const string &time, const string &date, int amount, const string& bonus_card_number);
        bonus_card(const bonus_card &other);
        const string& get_bonus_card_number() const;
        void set_bonus_card_number(const string& value);
    private:
        string bonus_card_number;
};

#endif // BONUS_CARD_H
