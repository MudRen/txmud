// xuecheng.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("江安血橙", ({ "jiang an orange" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个江安血橙。\n");
                set("unit", "个");
                set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 10);
        }
}

