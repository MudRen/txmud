//tianxianteng.c

inherit ITEM;

void create()
{
        set_name("������", ({ "tian xianteng"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ��������,�����ٵ���ζ����,����ǿ��ǣ�ȥ��ʪ��\n");
        }
}
