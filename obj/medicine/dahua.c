// dahuang.c

inherit ITEM;

void create()
{
        set_name("���", ({ "da huang"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�Ĵ��,��Ƶ���ζ�ຮ,����к��ͨ�㡣\n");
        }
}
