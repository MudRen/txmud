inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("��ײ�", ({ "da baicai" , "baicai"}) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������͵Ĵ�ײ�.\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 10);
                set("food_supply", 1);
                set("material", "food");
        }
        setup();
}
