#include "Item.h"

string Item::Name()
{
	return Item::names[type];
}

Item::ItemType Item::MapStringToItemType(const string str)
{
	Item item{};
	if (MapStringToItemType(str, item))
		return item.type;
	throw "Item::ItemType not found";
}
Item::ItemType Item::MapStringToItemType(const wxString str)
{
	return MapStringToItemType(str.ToStdString());
}
bool Item::MapStringToItemType(const string str, Item& item)
{
	auto mapped = map_itemname_to_itemtype.find(str);
	if (mapped == map_itemname_to_itemtype.end())
		return false;
	item.type = mapped->second;
	return true;
}
bool Item::MapStringToItemType(const wxString str, Item& item)
{
	return MapStringToItemType(str.ToStdString(), item);
}
