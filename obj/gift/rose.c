// red rose
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"��õ��"NOR, ({ "red rose"}) );

        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else
       {
                set("unit", "��");
                set("long", HIW"����" +HIC MUD_NAME + HIW"��ʦ����ʥ����ʱ�͸�������Ը��ʥ���ڿ��֣�\n"NOR);
                set("value", 50);
        }
	setup();
}
