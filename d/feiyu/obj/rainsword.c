#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"���꽣"NOR, ({ "rain sword","sword" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "Ʈ�罣�����꽣��������ʼ���������ա�\n");
                set("value", 200);
                set("material", "iron");
        }
        init_sword(10);
        setup();
}
