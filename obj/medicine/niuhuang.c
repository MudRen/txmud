//niuhuang.c

inherit ITEM;

void create()
{
        set_name("ţ��", ({ "niu huang"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��ţ��,ţ�Ƶ���ζ�����,�������½ⶾ�����ϻ�̵��\n");
        }
}
