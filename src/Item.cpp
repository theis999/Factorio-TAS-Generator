#include "Item.h"

Item::Item() : category(0)
{
	type = wooden_chest;
}
Item::Item(int _type) : category(0)
{
	type = (ItemType) _type;
	category = map_itemtype_to_category[type];
}
string Item::Name()
{
	return Item::names[type];
}

Item::Category::Category(int category)
{
	bit_vector = category;
}
bool Item::Category::IsCategory(ItemCategory c)
{
	return (bit_vector & c) == c;
}
bool Item::Category::IsPlaceable()
{
	return bit_vector & 0b111;
}

Item Item::MapStringToItem(const string str)
{
	Item item{};
	if (MapStringToItem(str, item)) return item;
	else throw "Item::ItemType not found";
}
Item Item::MapStringToItem(const wxString str)
{
	return MapStringToItem(str.ToStdString());
}
bool Item::MapStringToItem(const string str, Item& item)
{
	auto mapped = map_itemname_to_itemtype.find(str);
	if (mapped == map_itemname_to_itemtype.end())
		return false;
	item.type = mapped->second;
	item.category = map_itemtype_to_category[item.type];
	return true;
}
bool Item::MapStringToItem(const wxString str, Item& item)
{
	return MapStringToItem(str.ToStdString(), item);
}
