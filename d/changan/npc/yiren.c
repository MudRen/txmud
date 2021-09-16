// yiren.c

inherit F_DEALER;

void create()
{
	set_name("������", ({ "yiren" }) );
	set("gender", "����" );
	set("age", 12);
	set("long", "�������ģ�һ��̴�磬��������͸�ž���\n");
	set("per", 35);
	set("combat_exp", 50000);
	set("attitude", "friendly");

	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("dodge",90);
	set("sell_all_day",1);

	set("vendor_goods",([
	__DIR__"obj/daliwan":40,
]));


	setup();
	add_money("silver", 2);
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	switch (random(3))
	{
		case 0:
			command("say ��˵�����ٰ�ʽ��������˵ɵ��ʽ��\n");
			break;
		case 1:
			command("say ��Ǯ������Ǯ����ûǮ�������˳�������\n");
			break;
		default:
			command("say ���������ҵ��洫�ط����ơ��ش������衱��\n");
	}
}