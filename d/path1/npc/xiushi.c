// xiushi.c

inherit NPC;

void create()
{
	set_name("������ʿ", ({ "xiu shi" }) );
	set("long", "����һλ������������ʿ,��������
ȴ����һ�ѽ���\n");
	set("age", 28);
	set("per", 30);
	set("kar", 28);
	set("str", 20);
	set("attitude", "peaceful");
	set("combat_exp", 60000);
	set("max_kee",900);
	set("max_gin",1000);
	set("max_sen",1000);
	set("max_force",2000);
	set("force_factor",10);

	set_skill("sword",40);
	set_skill("parry",90);
	set_skill("dodge",90);
	set_skill("unarmed",80);

	setup();
	carry_object(WEAPON_DIR"thin_sword")->wield();
        carry_object(__DIR__"obj/white_cloth")->wear();
}
