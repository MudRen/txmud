#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY"С�־�"NOR, ({ "xiao shoujuan","shoujuan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ԧ���С�־\n");
                set("value", 100);
                set("material", "cloth");
        }
        setup();
}
