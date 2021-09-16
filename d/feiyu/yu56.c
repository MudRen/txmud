// Room: /u/w/wangs/a/yu56.c

inherit ROOM;

void create()
{
	set("short", "阁楼二层");
	set("long", @LONG
这里是梅林阁二楼，透过开在四面的小窗，那美丽的梅
花圆尽收眼底，其景美不胜收。在阁楼的一角，有一扇大屏
风(ping feng)挡住了你的视线。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"geloue",
  "down" : __DIR__"yu55",
]));

	set("item_desc",([
	"屏风" : "一面高大的屏风，上边画着一幅山水画，隐约中你能看见屏风后面有个人影。\n",
	"ping feng" : "一面高大的屏风，上边画着一幅山水画，隐约中你能看见屏风后面有个人影。。\n",
]));

	setup();
}

void init()
{
        add_action("do_yao","yao");
}

int do_yao(string arg)
{
	object me = this_player(),ob;

	if( (arg != "暗杀令") && (arg != "kill plate") )
		return notify_fail("你想要什么？\n");

	if(me->query("class") != "rain")
		return 0;

	if(me->query_temp("louth_killer"))
		return notify_fail("屏风后的人道：已经给过你一枚令牌了。\n");

	message_vision("屏风后的人站了起来，道：好的，既然$N想帮本门杀掉仇家，
本座今天就给你一次机会，拿着这枚令牌去找苏妖妖吧。\n",me);

	me->set_temp("louth_killer",1);
	ob=new(__DIR__"obj/lingpai");
	ob->move(me);
	return 1;
}
