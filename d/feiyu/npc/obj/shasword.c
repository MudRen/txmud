#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"��ѩ����"NOR, ({ "feixue sword","sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ɱ��ר���õĶ̽���\n");
                set("value", 8000);
                set("material", "steel");
        }
        init_sword(40);

        set("wield_msg", "$N�ӽ�������һ��ѩ�׵�$n�������У�������Χɱ������\n");
        set("unwield_msg", "$N�����е�$n��ؽ����С�\n");

        setup();
}
