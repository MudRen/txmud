// mangxiao.c

inherit ITEM;

void create()
{
        set_name("���", ({ "yang jin hua"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "֧");
                set("long", 
"һ֧��ͨ��ɽҩ,��𻨵���ζ����,����ƽ����ȡ�\n");
        }
}
