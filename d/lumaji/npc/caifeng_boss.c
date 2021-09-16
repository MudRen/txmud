// caifeng_boss.c

inherit NPC;

void create()
{
	set_name("���ɩ", ({ "boss li", "boss","li" }) );
	set("gender", "Ů��" );
	set("title","�÷����ϰ�");
        set("age", 35);
	set("per",20);
        set("long","����һλ��ʵ��ɽ���ɩ��\n");
        set("combat_exp", 10000);

        set("attitude", "friendly");

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = previous_object()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	say( "���ɩ΢Ц�š�\n");

}
