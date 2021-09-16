// xiaocui.c

#define DATONG	"/d/hangzhou/"

#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
	set_name("СѾ��", ({ "servant girl" }) );

	set("gender", "Ů��" );

	set("age", 17);

	set("long","����һλʮ�߰����СѾ�ߡ�\n");
	set("combat_exp", 100);
	set(NO_KILL, 1);

	set("attitude", "friendly");

	set("inquiry",([
	"�·�" : (: ask_me :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_me(object who)
{
	string *pos = ({DATONG"changanw3",DATONG"changane3",DATONG"minan05"}),where;
	object room,ob;

	if(!who->query("quest/shaolin_quest/win_feng"))
		return 0;

	if(who->query("quest/shaolin_quest/asked_hyahuan"))
	{
		write(sprintf(CYN"%s˵�������Ǹ������Ѿ��ͳ�ȥ�ˣ�����Ҳû�á�\n"NOR,name()));
		return 1;
	}

	where = pos[random(sizeof(pos))];
	room = find_object(where);
	if(!room)
		room = load_object(where);
	if(!room)
		return 0;

	if(!objectp(ob = new(__DIR__"blind_beggar")))
		return 0;

	write(sprintf(CYN"%s˵����Ŷ����˵������ү�Ǽ�����С�˵����·����Ǽ��·���ү
          �þö������ˣ��ֲ�����ϴ��ǰ����������ľ��·�һ
          �𶼲�ʩ���������ؤ�ˡ��Ǽ��·��Ҽǵú����Ǳ�һ
          ������ؤ�����ˡ���ȥ���Ұɡ�\n"NOR,name()));

	who->set("quest/shaolin_quest/asked_hyahuan",1);
	who->add("quest/shaolin_quest/hint",sprintf("      %s\n",
		"СѾ�߸������·���һ�����ݸ��ġ�����ؤ�������ˡ�"));

	ob->move(room);
	tell_room(sprintf("%s���˹�����\n",ob->name()));

	return 1;
}
