// queshi.c

inherit ITEM;

void create()
{
        set_name("���ȸ���", ({ "qc que she" }) );
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
