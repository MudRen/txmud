// teacher.c

inherit NPC;

string heal_me(object me);

string learn_ok();
void deleteall(object me);

void create()
{
	set_name("����٢", ({ "sai hua tuo" }) );
	set("title", "��ҽ");
	set("gender", "����" );
	set("age", 58);
	set("str",30);
	set("int", 30);
	set("combat_exp",1);
	set("long",
		"����٢��һ�������ϡ�����ˣ�������·���Էǳ��Ƚ������������Ȼ�ǳ�����\n"
		"����Ȼ�������ҩ�̣���ȴ�Դ��Ĳ����ɡ�\n");
	set("inquiry", ([
		"����": (: heal_me :),
		"����": (: heal_me :),
		"��ҩ": (: heal_me :),
		"�ö�": (: learn_ok :),
	]) );

	set_skill("literate", 70);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	setup();
	add_money("coin", 80);
}

void init()
{
	::init();
}

string heal_me(object me)
{
	int ratio;

	ratio = (int)me->query("eff_kee") * 100 / (int)me->query("max_kee");
	if( ratio >= 100 )
		return "��λ" + RANK_D->query_respect(me) + "������������ɫ�ܺð������������˵����ӡ�";
	if( ratio >= 95 )
		return "Ŷ....�ҿ���....ֻ��ЩƤ��С�ˣ��������ҩ��ȥ����û���ˡ�";
	
}

string learn_ok()
{
	object me;
	me = this_player();
	    command("say "+RANK_D->query_respect(me)+"�Ҵ����˰�!\n");
		command("say �����β��ģ���ô�����ֶ�����\n");
	if( me->query_skill("dujing") >= 5 ) {
		me->set_temp("marks/����٢ok",1);
		return "������˳��ģ��Ҿ͸�����һ��Ƥë��������...... �ǾͿ�����ô���ˡ�";
	} else {
	return "��һ���ǵ���;˵����Ҫʲô���š�";
	}
}

int recognize_apprentice(object ob)
{
	int num;
	if( !ob->query_temp("marks/����٢") ){
		say("����٢˵�����ף��ҿ�ʲô�����ᰡ....\n");
		return 0;
	}
	num = ob->query_temp("marks/����٢") -1;
	ob->set_temp("marks/����٢",ob->query_temp("marks/����٢")-1);
	return 1;
}

int accept_object(object who, object ob)
{
	if( who->query_temp("marks/����٢ok") ) {
		if( !who->query_temp("marks/����٢") ) {
			if( ob->value() >= 1000){
				say("����٢˵�����ܺã�����������������йض���(dujing)\n"
					"         ���κ����⡣\n");
				who->set_temp("marks/����٢", (int)ob->value()/1000);
				return 1;
			} else {
				say("����٢˵������ĳ��ⲻ������Ǯ�����û�ȥ�ɡ�\n");
				return 0;
			}
		} else {
			say("����٢���˵�ͷ��˵����Ŷ�������������ĵ�ѧ�������ǲ�������ú�Ŭ��\n"
				"                      �����ض�ǰ;������л�ˡ�\n");
			say("���ˣ���ǧ���˵���ҽ̹���Ŷ��\n");
			return 1;
		}
	} else {
		say("����εº��ܣ��ܽ����Ʒѣ����ǲ�����˼��\n");
		return 0;
	}
}


int accept_learn(object me, string skill)
{
	if (me->query_temp("marks/����٢ok")) 
		return 1;
	else
		return 0;
}
int accept_fight(object me)
{
        command("say ��һ������ͷ�ӣ��㻹�ǷŹ��Ұɣ�\n");
        return 0;
}

void accept_kill(object me)
{
	object *fellow;
	int i;
	fellow = all_inventory(environment(this_object()));
	for (i=0;i<sizeof(fellow);i++)
	{
		if (fellow[i]->query("id")=="purple guard")
		{
			fellow[i]->kill_ob(me);
			fellow[i]->set_temp("guarding","south");
		}
	}
}

