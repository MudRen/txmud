// huangya.c

inherit ITEM;

void create()
{
        set_name("�ɶ���ѿ��", ({ "md huang ya" }) );
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һС����Ҷ��\n");
                set("value", 3000);
                set("material", "leaf");
        }
        setup();
}
