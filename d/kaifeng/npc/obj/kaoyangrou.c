inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("������", ({ "kao yangrou", "yangrou" , "meat" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ŀ����⡣\n");
                set("unit", "��");
                set("value", 300);
                set("food_remaining", 4);
                set("food_supply", 30);
                set("material", "food");
        }
        setup();
}