#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "nianqing ren" , "ren" }) );
        set("gender", "����" );
        set("age", 24);
        set("long", "����һ�����ǵ�������\n");

	set_skill("unarmed",10);
	set_skill("dodge",30);

	set("combat_exp",6000);
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
