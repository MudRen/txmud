inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("������", ({ "tuzi rou", "rou" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ����������⡣\n");
                set("unit", "ֻ");
                set("value", 40);
                set("food_remaining", 4);
                set("food_supply", 20);
        }
    setup();
}
