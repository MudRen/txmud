// mangxiao.c

inherit ITEM;

void create()
{
        set_name("â��", ({ "mang xiao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��â��,â���Ĺ������������,к��ͨ�㡣\n");
        }
}
