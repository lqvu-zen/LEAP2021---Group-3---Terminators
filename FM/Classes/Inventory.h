#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "cocos2d.h"
#include "Definitions.h"
#include "Item.h"

using namespace std;

class Inventory 
{
public:
	
	Inventory();

	void init();

	void addItem(Item* _item);

	cocos2d::Sprite* GetSprite();
private:
	int gold;

	int itemCount;
	std::map<Item::ItemType, std::list<Item *>> itemMap;

	cocos2d::Sprite* inventorySprite;

	cocos2d::TMXTiledMap* inventoryMap;
};

#endif // __INVENTORY_H__
