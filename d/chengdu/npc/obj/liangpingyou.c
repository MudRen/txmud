// liangpingyou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("梁平柚", ({ "liang ping you" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个梁平柚。\n");
                set("unit", "个");
                set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 10);
        }
}

