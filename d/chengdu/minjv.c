// Room: /wiz/louth/c/minjv.c

inherit ROOM;

mixed go_houyuan(object me)
{
	mapping q;
	object ob;

	if(!mapp(q = me->query("quest/tangmen_quest"))
	|| (q["name"] != "�޻�����")
	|| !q["lu_asked"]
	|| q["get_wuhuaguo"] )
		return __DIR__"hy";

	if(q["entered_hy"])
		ob = new(__DIR__"hyquest");
	else
	{
		q["entered_hy"] = 1;
		ob = new(__DIR__"hyquest", me);
	}

	return ob;
}

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ͨ��ƽ��СԺ��������һ�����ѣ����Ϸ���
һ��С�Ƴ���Ժ��������һ��ˮ��������Ϲ���һ����ˮ(fill)
�õ�СľͰ��
LONG
	);
	set("exits", ([
  "north" : __DIR__"jguanlu6",
  "south" : (: go_houyuan :),
]));

	set("NO_NPC", 1);
	set("outdoors", "chengdu");

	set("cannot_build_home", 1);

	set("resource/water",1);

	setup();
}
