// shiwei.c

inherit ITEM;

void create()
{
        set_name("�ٺ�", ({ "bai he"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�İٺ�,�ٺϵ���ζ���΢��,�����������ȡ�\n");
        }
}
