inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({ "ji tui" }) );
        set_weight(1200);
        if( clonep() )  
                set_default_object(__FILE__);
        else {
                set("long", "һ�������缦���ȡ�\n");
                set("unit", "��");
                set("food_remaining", 4);
                set("food_supply", 25);
        }
}
