#include <weapon.h>

inherit STICK;

void create()
{
        set_name("ľ��", ({ "wood stick", "stick" }) );
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
        init_stick(2);
        setup();
}
