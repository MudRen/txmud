#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "huanyu er","er","huanyu"}) );
        set("title",HIW"������"NOR);
        set("gender", "Ů��" );
        set("age", 21);
        set("long", "�����ĳ������ˣ�˭�����������ϲ����\n");
        set("combat_exp", 6000);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
