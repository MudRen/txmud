// yayi.c

inherit NPC;

void create()
{
	set_name("衙役", ({ "ya yi" }) );
	set("gender", "男性");
	set("age", 30);
	set("vendetta_mark", "guanfu");

	set("long",@LONG
这是一位威风凛凛的衙役，手执一副水火大棍，
恶狠狠的扫视着周围。
LONG
);
	set("combat_exp", 100000);
	set("attitude", "heroism");
	set("str", 40);
	set("con", 25);
	set("max_kee", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 30);
	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_skill("stick", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();

	carry_object(__DIR__"obj/yayifu")->wear();
	carry_object(__DIR__"obj/fw_gun")->wield();
}