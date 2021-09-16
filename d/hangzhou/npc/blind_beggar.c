// blind_beggar.c

inherit NPC;

string ask_me(object who);
int is_quest_object() { return 1;}

private int being,finish = 0;

void create()
{
	set_name("����ؤ", ({ "old beggar" }) );

	set("gender", "����" );

	set(NO_KILL, 1);
	set("age", 57);

	set("long","����һλ��ͺܴ������ؤ��\n");
	set("combat_exp", 100);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("attitude", "friendly");

	set("inquiry",([
	"�·�" : (: ask_me :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	if(!who->query("quest/shaolin_quest/asked_hyahuan"))
		return 0;

	if(who->query("quest/shaolin_quest/have"))
		return "С�Ĳ����Ѿ������ˣ���ô��Ҫ��";

	return "�Ǽ��·��Ƿ����ү���͵ģ���������С�ľ�û�������ˣ�Ҫ��������͸������������Ӱɡ�";
}

int accept_object(object who,object ob)
{
	object cloth;

	if(being)
		return 0;

	being++;

	if(who->query("quest/shaolin_quest/asked_hyahuan")
	&& is_money(ob) && ob->value() > 300)
	{
	cloth = new(__DIR__"obj/tupu");
	write(sprintf("%s�������ó�һ�����·��������㡣\n\n��չ����������·��������滭����С�ˡ�\n
������书ѧʶ������������һ����ȭ��ͼ�ס�����\n",name()));
	cloth->move(who);
	who->set("quest/shaolin_quest/have",1);
	finish = 1;
	}
	command("say ��л��λ" + RANK_D->query_respect(who) + "��������һ�����кñ��ģ�");
	return 1;
}

int heal_up()
{
	if(finish && living(this_object()))
	{
		call_out("go_away",1);
		return 1;
	}
	return ::heal_up() + 1;
}

void go_away()
{
	if(environment())
		tell_object(environment(),name()+"�Ҵ�ææ�����ˡ�\n");
	destruct(this_object());
}
