// xunzhai.c

inherit NPC;

void create()
{
	int n = random(2);
	set_name("Ѳկ", ({ "xun zhai" }) );

	set("title","�ڷ�կ");
	set("gender", "����");
	set("age", 33);
	set("long", "��һ��������⣬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 1500000);

	set("vendetta_mark", "heifeng_tufei");

	set("max_kee",1200);
	set("max_gin",1500);
	set("max_sen",1500);
	set("max_force",1500);
	set("force",1500);
	set("force_factor",20);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("bellicosity", 600);
	set("attitude", "heroism");
	set_skill("unarmed", 120);
	if(n)
		set_skill("fork", 120);
	else
		set_skill("blade", 120);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("ganchan",50);

	map_skill("dodge","ganchan");

	setup();
	if(n)
		carry_object(__DIR__"obj/spear")->wield();
	else
		carry_object(__DIR__"obj/blade")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
