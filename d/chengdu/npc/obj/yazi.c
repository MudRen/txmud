// yazi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("’¡≤Ë—º", ({ "zhang cha ya" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "“ª≈Ã’¡≤Ë—º°£\n");
                set("unit", "≈Ã");
                set("value", 500);
                set("food_remaining", 6);
                set("food_supply", 12);
        }
}

