// heshouwu.c

inherit ITEM;

void create()
{
        set_name("������", ({ "he shou wu"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�ĺ�����,�����ڵ���ζ���,���ڲ�����Ƣ��\n");
        }
}
