// Room: /d/china/junying/xiaozhen/ji1.c

inherit ROOM;

void create()
{
	set("short", "登仙阁");
	set("long", @LONG
这
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jiyuan2",
]));
	set("no_clean_up", 0);

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
	if(obj = present("m_boss",find_object("/d/china/junying/xiaozhen/jiyuan")))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int valid_leave(object me,string dir)
{
	object obj;
	if(dir == "south" || dir == "s")
	{
	if(me->query_temp("jiyuan/sleep") != "红秀") return 1;
	call_out("zou_ren",1);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object("/d/china/junying/xiaozhen/jiyuan")))
		obj->delete_temp("have_full");
	return 1;
	}

	return 1;
}

void zou_ren()
{
	object obj;

	if(obj = present("hong xiu",this_object())) {
		tell_object(this_object(),obj->name()+"幽怨的叹了一口气，走了。\n");
		destruct(obj);
		}
}
