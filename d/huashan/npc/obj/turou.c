//turou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({ "tu rou" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�鿴����ζ������ô�������⡣\n");
                set("unit", "��");
                set("value", 30);
                set("food_remaining", 2);
                set("food_supply", 30);
        }
}
