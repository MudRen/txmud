// snake_powder.c

inherit ITEM;

void create()
{
        set_name("�ߵ���", ({"snake powder"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "С��");
                set("long", "����һС���ߵ�ĥ�ɵķ�ĩ����������ҩ�ꡣ\n");
                set("value", 250);
        }
        setup();
}
