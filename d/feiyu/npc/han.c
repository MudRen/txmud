// han.c

#include <ansi.h>
inherit NPC;

string ask_me(object who);

void create()
{
	set_name("�����", ({ "hanyu er","er","hanyu"}) );
	set("title",HIG"Ц����"NOR);
	set("gender", "Ů��" );
	set("age", 20);

	set(NO_KILL, 1);
	set("inquiry",([
	"����" : (: ask_me :),
]));

	set("long", "������Ц�����ģ�һ���������ǵ����ӡ�\n");
	set("combat_exp", 4000);
	set("per", 30);
	set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	string *get;
	object ob;

	if( (who->query("quest/rain_quest/name") == "������")
	&& ( !(get = who->query("quest/rain_quest/geted"))
	|| !sizeof(get)
	|| (member_array("����",get) == -1) ) )
	{
		ob = new(__DIR__"obj/lian_zi");
		ob->move(this_object());
		command(sprintf("give lian zi to %s",who->query("id")));

		if(!arrayp(get))
			get = ({"����"});
		else
			get += ({"����"});
		who->set("quest/rain_quest/geted",get);
		who->add("quest/rain_quest/hint",sprintf("      %s\n",
			"���Ѿ��õ������ӡ�"));
		if(sizeof(get) >= 4)
		who->add("quest/rain_quest/hint",sprintf("      %s\n",
			"��������ԭ�����Ѿ����룬����ȥ��ҩ�ˡ�"));

		return "�������û���һ�ţ���Ȼ�㼱����͸�������\n";
	}

	return "����Ҳû�ˣ�������ȥ���Ұɡ�\n";
}
