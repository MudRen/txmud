//tianma.c

inherit ITEM;

void create()
{
        set_name("����", ({ "tian ma"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ������,�������ζ����΢��,����ƽ��Ϩ�𣬶���ֹʹ��\n");
        }
}
