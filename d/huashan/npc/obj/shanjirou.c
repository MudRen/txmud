//shanjirou.c
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("ɽ����", ({ "shanji rou","rou" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�鿴����ζ������ô����ɽ���⡣\n");
                set("unit", "��");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}