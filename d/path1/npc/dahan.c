// dahan.c

inherit NPC;

void create()
{
	set_name("������", ({ "da han" }) );
	set("long", "����һλ����Ӣ��֮���ĺ����󺺣�
һ������һλ�����ӡ�\n");
	set("age", 38);
	set("per", 30);
	set("kar", 28);
	set("str", 35);
	set("attitude", "heroism");
	set("combat_exp", 160000);
	set("max_kee",900);
	set("max_gin",900);
	set("max_sen",1000);
	set("max_force",2000);
	set("force",2000);
	set("force_factor",10);

	set_skill("parry",100);
	set_skill("dodge",100);
	set_skill("unarmed",70);

	setup();
        carry_object(__DIR__"obj/white_cloth")->wear();
}
