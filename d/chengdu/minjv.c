// Room: /wiz/louth/c/minjv.c

inherit ROOM;

mixed go_houyuan(object me)
{
	mapping q;
	object ob;

	if(!mapp(q = me->query("quest/tangmen_quest"))
	|| (q["name"] != "无花果干")
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
	set("short", "民居");
	set("long", @LONG
这里是一处普通的平民小院，西面是一个柴火堆，边上放着
一架小推车，院子中央是一口水井，辘轳上挂着一个打水(fill)
用的小木桶。
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
