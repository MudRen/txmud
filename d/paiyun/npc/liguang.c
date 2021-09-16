// liguang.c

inherit NPC;

int is_paiyun() { return 1;}

void create()
{
	set_name("���", ({ "li guang" }) );
	set("title","����կ��կ��");
	set("long", "����һλ�⺷�������ˡ�\n");
        set("age", 45);

	set("max_gin", 1500);
	set("max_kee", 1500);
	set("max_sen", 1500);
	set("max_force",4500);
	set("force",4500);
	set("force_factor",70);
	set("str", 100);
	set("cor", 30);
	set("kar", 35);
	set("combat_exp", 3200000);

	set_skill("hammer", 250);
	set_skill("lianhuan-chui",220);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);

	map_skill("hammer","lianhuan-chui");
	map_skill("parry","lianhuan-chui");

	set_auto_recover(1);
	setup();

	carry_object(__DIR__"obj/armor")->wear();
	carry_object(__DIR__"obj/p_hammer")->wield();
	carry_object(__DIR__"obj/p_hammer")->wield(1);
}

int accept_kill(object me)
{
	object *obs;

	if(!environment())
		return 0;

	say("���ݺݵ�˵��������̫��ͷ�϶���������������ų�ȥ��\n");

	obs = filter_array(all_inventory(environment()) - ({this_object()}),(: $1->is_paiyun() :));

	if(sizeof(obs))
		obs->kill_ob(me);
	return 1;
}


int accept_fight(object me)
{
	object *obs;

	if(!environment())
		return 0;

	say("���ݺݵ�˵��������̫��ͷ�϶���������������ų�ȥ��\n");

	obs = filter_array(all_inventory(environment()) - ({this_object()}),(: $1->is_paiyun() :));

	if(sizeof(obs))
		obs->kill_ob(me);
	kill_ob(me);
	return 1;
}
