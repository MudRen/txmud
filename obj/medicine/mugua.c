//mugua.c

inherit ITEM;

void create()
{
        set_name("ľ��", ({ "mu gua"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��ľ��,ľ�ϵ���ζ��ɬ��,���ں�θ��ʪ�������硣\n");
        }
}
