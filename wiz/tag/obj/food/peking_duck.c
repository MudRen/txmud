//peking_duck.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������Ѽ", ({ "peking duck" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ֻ�ı�����Ѽ���ʵ����ͣ�Ƥ�����ۣ�����޲���һ������ȥ��\n");
                set("unit", "ֻ");
                set("value", 1000);
                set("food_remaining", 8);
                set("food_supply", 100);
        }
        setup();
}

