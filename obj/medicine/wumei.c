//wumei.c

inherit ITEM;

void create()
{
        set_name("��÷", ({ "wu mei"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ����÷����÷����ζ��ɬ�£���������ɬ�����������ס�\n");
        }
}
