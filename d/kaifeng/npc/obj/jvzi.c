inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("橘子", ({ "jv zi"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个黄橙橙的橘子。\n");
                set("unit", "个");
                set("value", 100);
                set("food_remaining", 6);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}

