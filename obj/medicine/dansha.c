// dasha.c

inherit ITEM;

void create()
{
        set_name("��ɰ", ({ "dan sha"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�ĵ�ɰ,��ɰ����ζ��΢��,���ڰ��񣬶������ⶾ��\n");
        }
}
