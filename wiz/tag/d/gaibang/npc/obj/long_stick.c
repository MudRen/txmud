#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
    set_name("����", ({ "long stick" }) );
    set_weight(3000);
    if(clonep() )
        set_default_object(__FILE__);
    else
    {
    set("unit", "��");
    set("long", "���ľͷ��������һ�ɶ೤��");
    set("value", 1000);
    set("material", "wood");
    set("wield_msg", "$N˫�ֽ�����ס��$n��\n");
    set("unwield_msg", "$N���ɿ���$n��\n");
    }

    init_stick(20);
    setup();
}

