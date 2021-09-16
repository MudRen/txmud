// weaponboss.c

inherit F_DEALER;

void create()
{
	set_name("��������", ({ "weapon seller" }) );
	set("gender", "����" );
	set("age", 40);

	set("long", "����һλ�������ı������ӡ�\n");

	set("combat_exp", 30000);
	set("attitude", "friendly");
	set("max_kee",1000);
	set("max_force",1000);
	set("force_factor",20);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 120);

	set("sell_all_day",1);

	set("vendor_goods", ([
	__DIR__"obj/longquan_sword" : 12,
]) );

	setup();
        carry_object(__DIR__"obj/longquan_sword")->wield();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;

	switch( random(4) )
	{
		case 0:
			command(sprintf("say ��λ%s��һ�����ֵı����ɡ�", RANK_D->query_respect(ob)));
			break;
		case 1:
			command("say ���������ˣ��������ʿ��");
			break;
	}
}
