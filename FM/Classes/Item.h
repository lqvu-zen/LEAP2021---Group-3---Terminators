#ifndef __ITEM_H__
#define __ITEM_H__

#include "cocos2d.h"
#include "Stats.h"

using namespace std;

class Item 
{
public:
	enum class ItemType {
		GEM, HP_POTION, MP_POTION, GOLD
	};

	Item(ItemType _itemType);

	cocos2d::Sprite* getSprite();

	Item::ItemType getType();

	Stats getStats();

	void setPosition(cocos2d::Vec2 position);

private:
	cocos2d::Sprite* itemSprite;
	cocos2d::Sprite* itemImage;
	cocos2d::PhysicsBody* itemBody;
    
	Item::ItemType itemType;

	Stats itemStats;
};

#endif // __ITEM_H__
