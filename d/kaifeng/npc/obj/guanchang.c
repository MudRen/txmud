inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("�೦", ({ "guan chang"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�̸��պõĹ೦��\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 6);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}
