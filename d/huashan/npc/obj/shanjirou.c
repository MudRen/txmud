//shanjirou.c
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("山鸡肉", ({ "shanji rou","rou" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块看起来味道不怎么样的山鸡肉。\n");
                set("unit", "块");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}
