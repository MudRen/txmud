#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"绯雨剑"NOR, ({ "feiyu sword","sword" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把绯雨阁弟子专用的短剑.\n");
                set("value", 1000);
                set("material", "iron");
        }
        init_sword(30);
        setup();
}
