// wujiapi.c

inherit ITEM;

void create()
{
        set_name("���Ƥ", ({ "wu jiapi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "Ƭ");
                set("long", 
"һƬ��ͨ�����Ƥ,���Ƥ����ζ������,����ȥ�绯ʪ,ǿ��ͨ�硣\n");
        }
}
