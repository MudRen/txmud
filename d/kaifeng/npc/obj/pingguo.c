inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("苹果", ({ "ping guo"}) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个熟透了的苹果。\n");
                set("unit", "个");
                set("value", 100);
                set("food_remaining", 6);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}

