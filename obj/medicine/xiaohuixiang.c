//ziaohuixiang.c

inherit ITEM;

void create()
{
        set_name("С����", ({ "xiao huixiang"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��С����,С�������ζ����,����ɢ��ֹʹ����θ��ʳ��\n");
        }
}
