#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("�̽�", ({ "short sword","sword" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ϰ�õĶ̽���\n");
                set("value", 100);
                set("material", "iron");
        }
        init_sword(10);
        setup();
}

