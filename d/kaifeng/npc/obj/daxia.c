inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("��Ϻ", ({ "da xia"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ƴ�Ϻ��\n");
                set("unit", "��");
                set("value", 5000);
                set("food_remaining", 9);
                set("food_supply", 4);
                set("material", "food");
        }
        setup();
}
