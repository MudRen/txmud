// mangxiao.c

inherit ITEM;

void create()
{
        set_name("ɽҩ", ({ "shan yao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��ɽҩ,ɽҩ����ζ��ƽ,�������,����ֹк��\n");
        }
}
