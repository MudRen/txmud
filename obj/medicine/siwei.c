// shiwei.c

inherit ITEM;

void create()
{
        set_name("ʯέ", ({ "shi wei"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��ʯέ,ʯέ����ζ���΢��,������ʪ����С�㡣\n");
        }
}
