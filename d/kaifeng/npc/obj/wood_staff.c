#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("ľ��", ({ "wood staff", "staff" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("long", 
"����һ�Ѻ���ľ�ȡ�\n");
        }
        init_staff(2);
        setup();
}
