// rotten_dan.c

inherit ITEM;

void create()
{
        set_name("���õ��ߵ�", ({"rotten dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����ߵ��Ѿ������ˣ�ɢ���Ŷ����\n");
                set("value", 0);
        }
        setup();
}
