//shengjiang.c

inherit ITEM;

void create()
{
        set_name("����", ({ "sheng jiang"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ����������������ζ��΢�£����ڷ����������ֹŻ��\n");
        }
}
