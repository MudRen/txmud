// sanqi.c

inherit ITEM;

void create()
{
        set_name("����", ({ "san qi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ������,���ߵ���ζ��΢����,����ֹѪ���٣����׶�ʹ��\n");
        }
}
