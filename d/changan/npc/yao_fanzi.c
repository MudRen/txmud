// yao_fanzi.c

#define CA_DIR	"/d/changan/"

#include <ansi.h>
inherit NPC;

int ask_xuelian(object me);

void create()
{
        set_name("ҩ�ķ���", ({ "yao fanzi","fanzi" }) );
        set("gender", "����" );
        set("age", 37);
        set("long", "��ʱһλ��������ҩ�ķ��ӡ�\n");

	set(NO_KILL, 1);

	set("inquiry",([
	"ҩ��" : "�Ҿ���ר�ŷ�ҩ�ĵġ�\n",
	"��ɽѩ��" : (: ask_xuelian :),
	"ѩ��" : "ѩ�����������м٣���ժ�ļ��ڲ�һ���۸�Ҳ��ͬ�������ѧ�ʿɴ�����\n",
]));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_xuelian(object me)
{
	mapping
xing = ([
"��":"zhang",
"��":"wang",
"��":"li",
"��":"zhao",
"��":"wu",
"��":"liu",
"����":"huangpu",
]),

ming = ([
"־ǿ":"zhiqiang",
"����":"fugui",
"����":"gaosheng",
"����":"jincai",
"�ǿ�":"dengke",
"��ͨ":"shitong",
]),

position = ([
"��" : CA_DIR"nroad4",
"��" : CA_DIR"wroad4",
"��" : CA_DIR"sroad4",
]);

	string name,id,file;
	int a,b,p;
	object room,npc;

	if(me->query("quest/shaolin_quest/name") != "��ɽѩ��")
	{
		write(sprintf(CYN"%s���˷��۾�˵�����ⶫ���Ǻ�Ū�ģ����ܼ��������������Ǹ�����\n"NOR,name()));
		return 1;
	}

	if(me->query("quest/shaolin_quest/asked_xuelian")
	|| me->query("quest/shaolin_quest/have"))
	{
		write(sprintf(CYN"%s˵�������Ǹ������˻����Ͻ�ȥ׷��\n"NOR,name()));
		return 1;
	}

	a = random(sizeof(xing));
	b = random(sizeof(ming));
	p = random(sizeof(position));

	name = sprintf("%s%s",keys(xing)[a],keys(ming)[b]);
	id = sprintf("%s %s",values(xing)[a],values(ming)[b]);
	file = values(position)[p];
	room = find_object(file);
	if(!room)
		room = load_object(file);
	if(!room)
		return 0;

	npc = new(__DIR__"yao_npc");
	npc->set_name(name, ({ id }) );

	npc->move(room);
	tell_object(room,name+"���˹�����\n");

	write(sprintf(CYN"%s˵���������ˣ����ϸ��¸�Ū��һ֦���������ɸոձ������ߡ�
\t��λ�Ͽͺ����%s���ҿ�������֮��%s�ŷ������ˣ�
\t��Ҫ�����ҵ���ȥ�������������ɡ�
\t����������10�������������ġ�
\n"NOR,name(),name,keys(position)[p]));

	me->set("quest/shaolin_quest/asked_xuelian",id);

	me->add("quest/shaolin_quest/hint",sprintf("\n      %s\n",
			sprintf("��ѩ������λ�Ͽͺ����%s���ҿ�������֮��%s�ŷ������ˡ�",
			name,keys(position)[p])) );

	return 1;
}
