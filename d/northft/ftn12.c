// Room: /d/northft/ftn12.c

inherit ROOM;

protected int open, count;
protected object mob;

protected object query_mob()
{
	if(!mob)
		mob = find_object(__DIR__"stone");
	if(!mob)
		mob = load_object(__DIR__"stone");

	return mob;
}

string query_long()
{
	object ob = query_mob();

	if(!ob || ob->query_open())
		return "����һ��խխ����ɽС·�����Թ�ʯ��ᾣ��м��·���Ǻ�
ƽ̹���������Ǳ���ר�ſ�������ġ�\n";
	else
		return "����һ��խխ����ɽС·�����Թ�ʯ��ᾣ��м��·���Ǻ�
ƽ̹���������Ǳ���ר�ſ�������ġ�·����һ���ʯͷ��ס��
������ȥ·��\n";
}

mapping query_desc()
{
	object ob = query_mob();

	if(ob && !ob->query_open())
		return ([
"ʯͷ" : "����һ�����ʯͷ����֪���ܲ�����(push)����\n",
"��ʯͷ" : "����һ�����ʯͷ����֪���ܲ�����(push)����\n",
]);

	else
		return 0;
}

void create()
{
	set("short", "ɽ·");
	set("long",  (: query_long :));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ftn13",
]));

	set("item_desc", (: query_desc :));

	set("outdoors", "northft");
	setup();
}

void init()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object ob = query_mob(), me = this_player();

	if( !ob || ob->query_open() || ((arg != "ʯͷ") && (arg != "��ʯͷ")) )
		return 0;

	message_vision("$N˫��һ������ʹ������һ�´�ʯͷ��\n", me);
	ob->do_push(me);

	return 1;
}
