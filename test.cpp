#include <assert.h.>
#include <iostream>
#include "purchase.h"

using namespace std;

void test_default_constructor()
{
    purchase pur1;
    assert(pur1.get_time() == "00:00:00");
    assert(pur1.get_date() == "01:01:1970");
    assert(pur1.get_amount() == 0);
}

void test_init_constructor()
{
    purchase pur("12:12:12", "21:12:2000", 200);
    assert(pur.get_time() == "12:12:12");
    assert(pur.get_date() == "21:12:2000");
    assert(pur.get_amount() == 200);
}

void test_copy_constructor()
{
    purchase pur("12:12:12", "21:12:2000", 200);
    purchase pur2(pur);
    assert(pur2.get_time() == "12:12:12");
    assert(pur2.get_date() == "21:12:2000");
    assert(pur2.get_amount() == 200);
}

void test_sets()
{
    purchase pur;
    //Correct data
    pur.set_date("23:12:2001");
    pur.set_time("22:22:22");
    pur.set_amount(1000);
    assert(pur.get_time() == "22:22:22");
    assert(pur.get_date() == "23:12:2001");
    assert(pur.get_amount() == 1000);
    //Wrong data
    pur.set_date("32:01:2001");
    pur.set_time("25:00:00");
    pur.set_amount(-100);
    assert(pur.get_time() == "00:00:00");
    assert(pur.get_date() == "01:01:1970");
    assert(pur.get_amount() == 0);

}

void test_class()
{
    test_default_constructor();
    test_init_constructor();
    test_copy_constructor();
    test_sets();
    cout << "All tests are passed"<< endl;
}
