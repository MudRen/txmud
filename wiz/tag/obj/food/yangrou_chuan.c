//yangrou_chuan.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���⴮", ({ "yangrou chuan " }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������������⴮����������Ȼ������ĩ��\n");
                set("unit", "��");
                set("value", 20);
                set("food_remaining", 2);
                set("food_supply", 20);
        }
        setup();
}

