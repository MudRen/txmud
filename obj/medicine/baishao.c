//baishao.c

inherit ITEM;

void create()
{
        set_name("����", ({ "bai shao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�İ��֣����ֵ���ζ����΢�������ڲ�Ѫ��������Ѫֹʹ��\n");
        }
}
