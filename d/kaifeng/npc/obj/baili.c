inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("大白梨", ({ "da baili", "baili"}) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个大大的白梨。\n");
                set("unit", "个");
                set("value", 100);
                set("food_remaining", 6);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}
