#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
    set_name(HIW "�˵�", ({ "blade" }) );
    set_weight(0);
    if(clonep() )
        set_default_object(__FILE__);
    else
    {
    set("unit", "��");
    set("long", "һ�����صĵ�����Ϊ��û�е��У�ֻ�е��ѡ�");
    set("value", 99);
    set("material", "iron");
    set("wield_msg", "$N���ٺ١�һЦ�������һ��$n��\n");
    set("unwield_msg", "$N��$n��������ʡ��Ū���ˡ�\n");
    }

    init_blade(320);
    setup();
}
