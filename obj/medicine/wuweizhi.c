// wuweizhi.c

inherit ITEM;

void create()
{
        set_name("��ζ��", ({ "wu weizhi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ����ζ��,��ζ�ӵ���ζ�����,��������������\n");
        }
}
