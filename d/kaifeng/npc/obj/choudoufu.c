inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("������", ({ "chou doufu" , "doufu"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ֳ��ĳ�������\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 10);
                set("material", "food");
        }
        setup();
}
