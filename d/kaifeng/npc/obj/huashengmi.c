inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("花生米", ({ "hua sheng" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盘油炸花生米。\n");
                set("unit", "盘");
                set("value", 8);
                set("food_remaining", 3);
                set("food_supply", 8);
        }
}

