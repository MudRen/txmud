#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY"小手绢"NOR, ({ "xiao shoujuan","shoujuan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块绣着鸳鸯的小手绢。\n");
                set("value", 100);
                set("material", "cloth");
        }
        setup();
}
