inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("�²˰���", ({ "jiucai baozi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ڵľ²˰��ӡ�\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}
