inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({ "ji chi" }) );
        set_weight(1000);
        if( clonep() )  
                set_default_object(__FILE__);
        else {
                set("long", "һ�������缦���\n");
                set("unit", "��");
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}

