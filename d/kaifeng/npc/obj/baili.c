inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("�����", ({ "da baili", "baili"}) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����İ��档\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 6);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}