//kouren.c

inherit ITEM;

void create()
{
        set_name("ޢ��", ({ "kou ren"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��ޢ�ʣ�ޢ�ʵ���ζ����΢�������ڲ�Ѫ��������Ѫֹʹ��\n");
        }
}
