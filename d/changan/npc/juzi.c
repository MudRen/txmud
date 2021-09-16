// juzi.c

inherit NPC;

void create()
{
	set_name("�������", ({ "ju zi" }) );
	set("gender", "����" );
	set("age", 38);

	set("long", "һ�����Ǿ���һ�������Ͽ��ľ��ӡ�\n");

	set("combat_exp", 2000);
	set("per",20);
	set("str", 20);
	set_skill("unarmed",30);

	setup();

	carry_object(__DIR__"obj/bugua")->wear();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
 
void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;

	switch(random(2))
	{
		case 0:
			command(sprintf("sigh %s",query("id")));
			break;
		default:
			command("say ��һ����û�н�������ô������ȥѽ��");
	}
}
