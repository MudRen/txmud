#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����", ({ "xiaoyu er","er","xiaoyu"}) );
        set("title",CYN"������"NOR);
        set("gender", "Ů��" );
        set("age", 19);
        set("long", "���ر�ϲ��һ���˷������Ǹ��ľ���Ů����\n");
        set("combat_exp", 16000);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
