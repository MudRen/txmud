// fengmi.c

inherit ITEM;

void create()
{
        set_name("����", ({ "feng mi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�ķ���,���۵���ζ��ƽ,���ڲ�������,ֹ���ⶾ��\n");
        }
}
