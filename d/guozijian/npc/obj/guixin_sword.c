// sword:__DIR__"obj/guixin_sword.c" ���Ľ�һ��

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("���Ľ�",({ "guixin sword","guixin","sword" }));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit", "��");
                set("long", "����һ��������������״���Ķ�������\n");
                set("value", 600);
                set("material", "iron");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
         }
        init_sword(20);
        setup();
}
