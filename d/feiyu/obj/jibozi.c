inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������", ({ "ji bozi" }) );
        set_weight(500);
        if( clonep() )  
                set_default_object(__FILE__);
        else {
                set("long", "һ�������缦���ӡ�\n");
                set("unit", "��");
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}

