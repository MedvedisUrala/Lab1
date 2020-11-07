#include <assert.h.>
#include <iostream>
#include "bonus_card.h"

using namespace std;

void test_bc_default_constructor()
{
    bonus_card card;
    assert(card.get_time() == "00:00:00");
    assert(card.get_date() == "01:01:1970");
    assert(card.get_amount() == 0);
    assert(card.get_bonus_card_number() == "000000000000");
}

void test_bc_init_constructor()
{
    bonus_card card("12:12:12", "21:12:2000", 200, "123456789123","+79041232123");
    assert(card.get_time() == "12:12:12");
    assert(card.get_date() == "21:12:2000");
    assert(card.get_amount() == 200);
    assert(card.get_bonus_card_number() == "123456789123");
}

void test_bc_copy_constructor()
{
    bonus_card card("12:12:12", "21:12:2000", 200, "123456789123","+79041232123");
    bonus_card card2(card);
    assert(card2.get_time() == "12:12:12");
    assert(card2.get_date() == "21:12:2000");
    assert(card2.get_amount() == 200);
    assert(card2.get_bonus_card_number() == "123456789123");
}

void test_bc_sets()
{
    bonus_card card;
    //Correct data
    card.set_date("23:12:2001");
    card.set_time("22:22:22");
    card.set_amount(1000);
    card.set_bonus_card_number("123456789123");
    assert(card.get_time() == "22:22:22");
    assert(card.get_date() == "23:12:2001");
    assert(card.get_amount() == 1000);
    assert(card.get_bonus_card_number() == "123456789123");
    //Wrong data
    card.set_date("32:01:2001");
    card.set_time("25:00:00");
    card.set_amount(-100);
    card.set_bonus_card_number("123sadassgd");
    assert(card.get_time() == "00:00:00");
    assert(card.get_date() == "01:01:1970");
    assert(card.get_amount() == 0);
    assert(card.get_bonus_card_number() == "000000000000");
}

void test_bc_class()
{
    test_bc_default_constructor();
    test_bc_init_constructor();
    test_bc_copy_constructor();
    test_bc_sets();
    cout << "All tests of bonus card are passed"<< endl;
}
