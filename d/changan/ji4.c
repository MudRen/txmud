// Room: /d/changan/ji4.c

inherit ROOM;

string fname = __DIR__"jiyuan";

void create()
{
	set("short", "暖香阁");
	set("long", @LONG
置身于此，你不禁筋骨皆酥，屋角处生着一盆火炭让这里一
室皆春，昏黄的灯光中一股醉人的女体幽香使你意乱神迷，你摸
索着寻觅那让你神往的桃花仙境，却又迷失在那无处不在的暗香
浮动之中了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiyuan2",
]));
	set("no_clean_up", 0);
	set("no_sleep_room",1);

	setup();
}

void init()
{
	add_action("do_quit","quit");
}

int do_quit(string arg)
{
	object obj;
	if(this_player()->query_temp("jiyuan")) {
	if(obj = present("m_boss",find_object(fname)))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int valid_leave(object me,string dir)
{
	object obj;
	if(dir == "west" || dir == "w")
	{
	if(me->query_temp("jiyuan/sleep") != "香玉") return 1;
	call_out("zou_ren",1);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object(fname)))
		obj->delete_temp("have_full");
	return 1;
	}

	return 1;
}

void zou_ren()
{
	object obj;

	if(obj = present("xiang yu",this_object())) {
		tell_object(this_object(),obj->name()+"幽怨的叹了一口气，走了。\n");
		destruct(obj);
		}
}