#ifndef __BAG_H__
#define __BAG_H__

#include <vector>

#include <Item.h>
#include <util.h>

class User;
namespace NLogic {

class Item;

class Bag
{
public:
    Bag();
    Bag(User *user, int eBagType);
    virtual ~Bag();

    void Initialize();
    void Finalize();
public:
    typedef std::vector<Item *> ITEMVECTOR;
};

} // namespace NLogic

#endif // __BAG_H__