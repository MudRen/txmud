// mihan.c
// by dicky

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"�ܺ�"NOR, ({ "mi han","mihan"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        HIW"����һ���ܺ����ŷ�ĺ���ʵ����ڸ��ź���ӡ����\n"NOR);
                set("value", 0);
                set("material", "paper");
         }
}