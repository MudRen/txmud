
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ľ��", ({ "muren_m" }) );
	set("long", "����һ����̾�ϸ��ľ�ˡ�\n");
        set("max_gin", 100);
	set("max_kee", 150+random(400));
	set("max_sen", 100);

	set("str", 100);
	set("cor", 5+random(20));
	set("con", 20);

	set_skill("unarmed",1);
	set_skill("dodge",1);

	setup();
}
