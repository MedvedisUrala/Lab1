#include <assert.h.>
#include <iostream>
#include "purchase_collection.h"

using namespace std;


int print(purchase_collection& pur)
{
    for(int i = 0; i < pur.size();i++)
    {
        std:: cout << "#" << i + 1;
        std::cout << endl << pur.get_iterator()[i]->get_time()<< endl;
        std::cout << pur.get_iterator()[i]->get_date()<< endl;
        std::cout << pur.get_iterator()[i]->get_amount()<< endl << endl;
    }
    return 1;
}


void test_collection_default_constructor()
{
    purchase_collection pur;
    assert(pur.get_iterator() == nullptr);
    assert(pur.get_count() == 0);
}

void test_collection_init_constructor()
{
    purchase pur("12:12:12", "21:12:2000", 200);
    purchase_collection pc(pur);
    assert(pc.get_iterator()[0]->get_time() == "12:12:12");
    assert(pc.get_iterator()[0]->get_date() == "21:12:2000");
    assert(pc.get_iterator()[0]->get_amount() == 200);
    assert(pc.get_count() == 1);
}

void test_collection_copy_constructor()
{
    purchase pur("12:12:12", "21:12:2000", 200);
    purchase_collection pc1(pur);
    purchase_collection pc2(pc1);

}


void test_push_and_pop()
{
    purchase pur("12:12:12", "21:12:2000", 200);
    purchase pur1("22:01:00", "01:01:2001", 1000);
    purchase_collection pc;
    //Check push
    pc.push(pur);
    assert(pc.get_iterator()[0]->get_time() == "12:12:12");
    assert(pc.get_iterator()[0]->get_date() == "21:12:2000");
    assert(pc.get_iterator()[0]->get_amount() == 200);
    assert(pc.get_count() == 1);
    //late date
    pc.push(pur1);
    assert(pc.get_iterator()[0]->get_time() == "12:12:12");
    assert(pc.get_iterator()[0]->get_date() == "21:12:2000");
    assert(pc.get_iterator()[0]->get_amount() == 200);
    assert(pc.get_iterator()[1]->get_time() == "22:01:00");
    assert(pc.get_iterator()[1]->get_date() == "01:01:2001");
    assert(pc.get_iterator()[1]->get_amount() == 1000);
    assert(pc.get_count() == 2);
    //early
    pc.push(pur);
    assert(pc.get_count() == 2);
    //Check pop
    pc.pop();
    assert(pc.get_iterator()[0]->get_time() == "22:01:00");
    assert(pc.get_iterator()[0]->get_date() == "01:01:2001");
    assert(pc.get_iterator()[0]->get_amount() == 1000);
    assert(pc.get_count() == 1);
    pc.pop();
    assert(pc.get_iterator() == nullptr);
    assert(pc.get_count() == 0);
}

void test_clear_and_sum()
{

    purchase pur("12:12:12", "21:12:2000", 200);
    purchase pur1("22:01:00", "01:01:2001", 1000);
    purchase_collection pc;
    pc.push(pur);
    pc.push(pur1);
    assert(pc.sum("12:12:12", "20:12:1999","12:12:12", "21:12:2001") == 1200);
    pc.clear();
    assert(pc.get_iterator() == nullptr);
    assert(pc.get_count() == 0);
}

void test_print()
{
    purchase pur("12:12:12", "21:12:2000", 200);
    purchase pur1("22:01:00", "01:01:2001", 1000);
    purchase_collection pc;
    pc.push(pur);
    pc.push(pur1);
    assert(print(pc) == 1);
}

void test_input_output_file()
{
    purchase_collection pc;
    assert(pc.input_from_file("test_file.txt") == 1);
    print(pc);
    assert(pc.output_to_file("test_out.txt") == 1);
}



void test_collection_class()
{
    test_collection_default_constructor();
    test_collection_init_constructor();
    test_collection_copy_constructor();
    test_push_and_pop();
    test_clear_and_sum();
    test_print();
    test_input_output_file();
    cout << "All tests of collection are passed"<< endl;
}

