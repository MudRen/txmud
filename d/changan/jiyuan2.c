// design by 发现号(find) . all right reserved.

// Room: /d/changan/jiyuan2.c

inherit ROOM;

void create()
{
	set("short", "流香堂");
	set("long", @LONG
上得楼来你发现怡香苑果然不愧为京城第一大妓院，这座流
香堂布置得美仑美奂，却又不失清新素雅之气，不论是梨木桌椅，
黄绫幔帐，无不搭配得恰到好处，绝非那些小城土窑里的大红大
绿可比，能够住在这里的自然也是天仙化人般的美女了。想到这
里你不禁浑身都热了起来。
LONG
	);
	set("no_steal",1);
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"ji4",
  "down" : __DIR__"jiyuan",
  "west" : __DIR__"ji2",
  "north" : __DIR__"ji1",
  "south" : __DIR__"ji3",
]));
	set("NORIDE",1);

	set("objects",([
	__DIR__"npc/gui_nu" :1
]));
	setup();
}

void init()
{
	add_action("do_accept","accept");
	add_action("do_quit","quit");
}

int do_quit(string arg)
{
	object obj;
	if(this_player()->query_temp("jiyuan")) {
	if(obj = present("m_boss",find_object(__DIR__"jiyuan")))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int do_accept(string arg)
{
	object obj,me = this_player();

	if(!me->query_temp("jiyuan/order"))
		return 0;

	if(!arg)
		return notify_fail("龟奴说：您要点哪位姑娘？\n");

	if(!objectp(obj = present(arg,this_object()))
	|| (obj->query("class") != "jiyuan")
	|| (obj->query("gender") != "女性")
	|| (obj->query("id") == "m_boss") )
		return notify_fail("龟奴说：您要点哪位姑娘？\n");

	me->delete_temp("jiyuan/shangqian");
	me->set_temp("jiyuan/shangqian",obj->name());
	message_vision("$N羞涩的一瞥$n娇滴滴的说：谢爷看得起奴，不过爷能不能赏奴几个再进房间。\n",obj,me);
	return 1;
}

int valid_leave(object me,string dir)
{
	object obj;
	if(dir == "down")
	{
	if(!me->query_temp("jiyuan/order")) return 1;
	call_out("zou_ren",2);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object(__DIR__"jiyuan")))
		obj->delete_temp("have_full");
	return 1;
	}

	return 1;
}

void zou_ren()
{
	object obj;
	if(obj = present("lian yu",this_object())) {
		tell_object(this_object(),obj->name()+"走了。\n");
		destruct(obj);
		}
	if(obj = present("wan xiang",this_object())) {
		tell_object(this_object(),obj->name()+"走了。\n");
		destruct(obj);
		}
	if(obj = present("xiang yu",this_object())) {
		tell_object(this_object(),obj->name()+"走了。\n");
		destruct(obj);
		}
	if(obj = present("hong xiu",this_object())) {
		tell_object(this_object(),obj->name()+"走了。\n");
		destruct(obj);
		}
}

void open_close_door(string msg,object user)
{
	object ob = present("gui nu",this_object());
	string fname = __DIR__"jiyuan";

	if(!msg || !user || !ob || user->query_temp("jiyuan/order"))
		return;
	if( msg == "begin_day")
	{
		tell_object(user,"龟奴走到你面前一哈腰说道：这位"+
			RANK_D->query_respect(user)+"，天亮了，姑娘们要休息了。
说着把你从楼上推了下来。\n\n");
		user->move(fname);
		tell_room(__FILE__,user->name()+"向下离开。\n");
		tell_room(fname,user->name()+"从楼上走了下来。\n",({ user }));
	}
}
