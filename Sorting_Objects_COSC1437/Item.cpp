#include "Item.h"
#include "NamesList.h"

Item::Item(Type type, RandomXorShift& rng, bool spec)
    : price(price), type(type), rng(rng)
{
    generateStats(spec);
    name = generateName();
}

Item::Item(RandomXorShift& rng, bool spec)
    : rng(rng)
{
    type = getRandType();
    generateStats(spec);
    name = generateName();
}

int Item::getPrice(bool isShop) const
{
    if (isShop) return price * shopScaler;

    return price;
}

void Item::generateStats(bool isSpec)
{
    float DmgScale, AtkScale, DefScale;

    switch (type)
    {
    case Sword:
        DmgScale = 1.25;
        AtkScale = 1.25;
        DefScale = 1.25;
        break;
    case Shield:
        DmgScale = 0.25;
        AtkScale = 0.25;
        DefScale = 2;
        break;
    case Gun:
        DmgScale = 2;
        AtkScale = 0.5;
        DefScale = 0.5;
        break;
    default:
        DmgScale = 1;
        AtkScale = 1;
        DefScale = 1;
        break;
    }

    Dmg = rng.getRandomRange(100, int(1000 * DmgScale));
    Atk = rng.getRandomRange(100, int(1000 * AtkScale));
    Def = rng.getRandomRange(100, int(1000 * DefScale));
    if (isSpec) Spec = rng.getRandomRange(-400, 400);

    int priceScaler = (Atk + (Def / 100) + Dmg) / 30;

    if (isSpec) priceScaler* Spec;
    if (priceScaler < 0) priceScaler = 0;

    price = 100 * priceScaler;
}

std::string Item::generateName()
{
    return names::PREFIXE[rng.getRandomRange(0, 55)] + ' ' + names::ITEM_TYPE[type][rng.getRandomRange(0, 10)] + " of " + names::NAME[rng.getRandomRange(0, 40)] + " the " + names::TITLE[rng.getRandomRange(0, 35)];
}

Type Item::getRandType()
{
    switch (rng.getRandomRange(0, 2))
    {
    case 0:
        return Type::Sword;
    case 1:
        return Type::Gun;
    case 2:
        return Type::Shield;
    default:
        //This is amarica goddamnnit
        return Type::Gun;
    }
}
