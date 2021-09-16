// daoke.c

inherit NPC;

void create()
{
	set_name("����", ({ "dao ke" }) );
	set("long", "����һλ��ɫ�ҴҵĴ󺺣����ﻹ����
һ�����λεĴ�Ƭ����\n");
	set("age", 33);

	set("attitude", "heroism");
	set("combat_exp", 250000);
	set("max_kee",900);
	set("max_gin",1000);
	set("max_sen",1000);
	set("max_force",2000);
	set("force",2000);
	set("force_factor",10);

	set_skill("riding",100);
	set_skill("blade",50);
	set_skill("parry",80);
	set_skill("dodge",80);
	set_skill("unarmed",70);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
}) );
	set("donkey",0);

	setup();
	carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        if( !query("donkey") )
	{
                call_out("do_ride", 1);
		set("donkey", 1);
	}
	else if (!query_temp("on_rided"))
		call_out("ride",1);
}

void ride()
{
	object donkey;

	if( (donkey = present("huang biao",environment()))
	&& donkey->query("ride")
	&& living(donkey)
	&& !donkey->query_temp("have_been_rided"))
	command("ride huang biao");
}

void do_ride()
{
        object ob;
	ob = new(RIDE_DIR"huangbiao");
	ob->move( environment(this_object()) );
        command("ride huang biao");
        return; 
}
