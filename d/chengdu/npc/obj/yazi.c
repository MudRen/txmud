// yazi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����Ѽ", ({ "zhang cha ya" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������Ѽ��\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 6);
                set("food_supply", 12);
        }
}

