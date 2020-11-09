#ifndef PURCHASE_COLLECTION_H
#define PURCHASE_COLLECTION_H
#include <string>
#include "purchase.h"
using namespace std;

class purchase_collection
{
public:
    purchase_collection();
    purchase_collection(purchase &pur);
    purchase_collection(const purchase_collection &other);
    int push(purchase &pur);
    int pop();
    int clear();
    int size() const;
    int sum(const string &time_from, const string &date_from, const string &time_to, const string &date_to) const;
    int input_from_file(const string &name);
    int bc_input_from_file(const string &name);
    int output_to_file(const string &name);
    ~purchase_collection();
    purchase** get_iterator() const {return this->queue;}
    int get_count() const {return  this->count;}
    int check_queue_date(const purchase &prev,const purchase &curr) const;
private:
    int equal(const purchase_collection& curr) const;
    purchase **queue;
    int count;
};

#endif // PURCHASE_COLLECTION_H
