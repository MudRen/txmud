#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ѩ���", ({ "xueyu er","er","xueyu"}) );
        set("title",CYN"˼����"NOR);
        set("gender", "Ů��" );
        set("age", 22);
        set("long", "����һ��ò���绨��Ů����\n");
        set("combat_exp", 14000);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
