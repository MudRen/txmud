inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("������", ({ "hua sheng" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ը�����ס�\n");
                set("unit", "��");
                set("value", 8);
                set("food_remaining", 3);
                set("food_supply", 8);
        }
}

