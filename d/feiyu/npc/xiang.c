#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "xiangyu er","er","xiangyu"}) );
        set("title",YEL"С���"NOR);
        set("gender", "Ů��" );
        set("age", 22);
        set("long", "����һ����Ľ�С��Ů����\n");
        set("combat_exp", 10000);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
