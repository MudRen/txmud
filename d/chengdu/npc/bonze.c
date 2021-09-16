// bonze.c

inherit NPC;

void create()
{
        set_name("�Ϻ���", ({ "old bonze","bonze" }) );
        set("gender", "����" );
        set("age", 68);
        set("long",
                "���Ѿ��ڱ����´��˼�ʮ���ˡ�\n");
        set("combat_exp", 20);

        set_skill("literate",1);
        set("attitude", "friendly");
        setup();
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
	if( !ob || !present(ob, environment(this_object())) )
		return;

	say( "�Ϻ���˵������λ" + RANK_D->query_respect(ob)
		+ "��������Ǯ�������°ɡ�\n");
}

int accept_object(object who, object ob)
{
	int val;

	if(!is_money(ob))
		return notify_fail("��ף������Ʒ�ľ��ס�\n");

	if( (val = ob->value()) >= 100 )
	{
		if( who->query("bellicosity") > 0 )
			who->add("bellicosity", - to_int((random(who->query("kar")) + val/100)) );
	}
	say( "�Ϻ���˵������л��λ" + RANK_D->query_respect(who)
		+ "������һ���ᱣ����ġ�\n");

        return 1;
}
