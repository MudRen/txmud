inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("ţ�����", ({ "niurou baozi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ڵ�ţ����ӡ�\n");
                set("unit", "��");
                set("value", 300);
                set("food_remaining", 8);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}
