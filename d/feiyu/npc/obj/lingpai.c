inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR"��ɱ��"NOR, ({ "kill plate","plate" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ʺ�����ơ�\n");
                //set("value", 1000);
        }
}
