// man.c

#include <ansi.h>
inherit NPC;

string ask_hoe(object who);
string ask_tong(object who);

void create()
{
        set_name("�����", ({ "manyu er","er","manyu"}) );
        set("title",RED"������"NOR);
        set("gender", "Ů��" );
        set("age", 19);
        set("long", "������Ц�����ģ�һ���������ǵ����ӡ�\n");
        set("combat_exp", 2000);
        set("per", 30);

	set(NO_KILL, 1);
	set("inquiry",([
	"ҩ��" : (: ask_hoe :),
	"ˮͰ" : (: ask_tong :),
]));

        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_hoe(object who)
{
	object ob;

	if(!who)
		return 0;

	if(who->query("quest/rain_quest/quest") != "ҩ����")
		return "û��Ҫ�����ʲô��\n";

	if(objectp(present("medicine hoe",who)))
		return "�㲻���Ѿ���ҩ���ˣ���ȥ�ɻ�ɡ�\n";

	ob = new(__DIR__"obj/hoe");
	ob->move(this_object());

	command(sprintf("give medicine hoe to %s",who->query("id")));

	return "��֪��������Ĳ�ҩ�糤����ô���ˡ�\n";
}

string ask_tong(object who)
{
	object ob;

	if(!who)
		return 0;

	if(who->query("quest/rain_quest/quest") != "ҩ����")
		return "û��Ҫ�����ʲô��\n";

	if(objectp(present("water bucket",who)))
		return "�㲻���Ѿ���ˮͰ�ˣ���ȥ�ɻ�ɡ�\n";

	ob = new(__DIR__"obj/tong");
	ob->move(this_object());

	command(sprintf("give water bucket to %s",who->query("id")));

	return "��֪��������Ĳ�ҩ�糤����ô���ˡ�\n";
}
