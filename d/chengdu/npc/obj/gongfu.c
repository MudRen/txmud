// gongfu.c

inherit ITEM;

void create()
{
        set_name("���������", ({ "gong fu cha" }) );
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һС����Ҷ��\n");
                set("value", 2500);
                set("material", "leaf");
        }
        setup();
}

