// soldier.c

inherit NPC;

int help = 0;
void set_help() { help = 1;}

void create()
{
	set_name("ʿ��", ({ "soldier" }) );
	set("long","һ������ɫ������װ��ʿ������������
������ͱ�׼��վ�ʣ���Ȼ��ѵ�����ء�\n");
	set("age", 25);
	set("attitude", "peaceful");
	set("combat_exp", 100000);
	set("bellicosity", 400);
	set("vendetta_mark", "guanfu");
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set_skill("sword", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("force", 150);

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 20);

	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_fight(object me)
{
	command("say ��С��Ҳ������������ʲô�ط�����Ȼ����������Ұ��");
	return 0;
}

int accept_kill(object me)
{
	mixed *fellow;
	int i,num;
	object sold1,sold2,sold3,sold4;

	if(help)
		return 1;

	fellow = all_inventory(environment());
	for(i=0,num=0; i<sizeof(fellow); i++) {
		if( fellow[i]->query("id")=="soldier" ) num++;
	}
	if( num < 4 ) {
		help = 1;
		sold1=new(__DIR__"soldier");
		sold1->set_help();
		sold2=new(__DIR__"soldier");
		sold2->set_help();
		sold3=new(__DIR__"soldier");
		sold3->set_help();
		sold4=new(__DIR__"soldier");
		sold4->set_help();
		write("ͻȻ���Ա��ܹ�������ʿ������������Χ�����롣");
		sold1->move(environment(me));
		sold2->move(environment(me));
		sold3->move(environment(me));
		sold4->move(environment(me));
	}
	fellow = all_inventory(environment())->help_soldier(this_object(), me);
	fellow -= ({ 0 });
	if( sizeof(fellow) ) {
		command("say �д̿� ...  ,��������....");
	}
	return 1;
}

int help_soldier(object me, object foe)
{
	if( me==this_object() ) return 0;
	command("say �д̿� ...  ,��������....");
	kill_ob(foe);
	return 1;
}
