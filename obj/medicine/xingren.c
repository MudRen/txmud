// xingren.c

inherit ITEM;

void create()
{
        set_name("����", ({ "xing ren"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ������,���ʵ���ζ������,��С��,���������󳦡�\n");
        }
}
