//turou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("兔肉", ({ "tu rou" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块看起来味道不怎么样的兔肉。\n");
                set("unit", "块");
                set("value", 30);
                set("food_remaining", 2);
                set("food_supply", 30);
        }
}
