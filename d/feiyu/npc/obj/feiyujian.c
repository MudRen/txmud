#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"��꽣"NOR, ({ "feiyu sword","sword" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������ר�õĶ̽�.\n");
                set("value", 1000);
                set("material", "iron");
        }
        init_sword(30);
        setup();
}
