#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("ľ��", ({ "wood blade", "blade" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("long", 
"����һ�Ѻ���ľ����\n");
        }
        init_blade(2);
        setup();
}
