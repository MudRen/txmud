// huizhe.c
// 四罗汉之一

inherit NPC;

void create()
{
	set_name("晦证", ({ "hui zheng" }) );

	set("class","shaolin");
	create_family("少林寺", 36, "弟子");

	set("gender", "男性" );
	set("age", 53);
	set("long", "这是一位晦字辈的高僧，江湖上赫赫有名
的少林寺四大罗汉之一。\n");

	set("combat_exp", 3000000);
	set("str", 67);
	set("max_kee",4000);
	set("kee",4000);
	set("max_gin",4000);
	set("gin",4000);
	set("max_sen",4000);
	set("sen",4000);
	set("force", 6000);
	set("max_force", 6000);
	set("atman", 4000);
	set("max_atman", 4000);
	set("mana", 4000);
	set("max_mana", 4000);
	set("force_factor", 350);

	set("chat_chance_combat",25);
	set("chat_msg_combat",({
		(: perform_action, "stick.xiangmo" :),
}));

	set_skill("unarmed",260);
	set_skill("dodge",260);
	set_skill("parry",250);
	set_skill("force",200);
	set_skill("stick",200);
	set_skill("iron-cloth",260);
	set_skill("perception",260);
	set_skill("yiqi-force",200);
	set_skill("ganchan",250);
	set_skill("luohan-quan",250);
	set_skill("weituo-gun",250);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("unarmed","luohan-quan");
	map_skill("stick","weituo-gun");
	setup();

	carry_object(WEAPON_DIR"stick")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}
