// longyan.c

inherit ITEM;

void create()
{
        set_name("����", ({ "long yan"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ������,���۵���ζ��ƽ,���ڲ�����Ƣ����Ѫ����\n");
        }
}
