//cheqianchao.c

inherit ITEM;

void create()
{
        set_name("����", ({ "ban xia"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", 
"һ����ͨ�İ��ģ����ĵ���ζ���£���ʪ��̵����θֹŻ��\n");
        }
}
