// Room: /wiz/louth/a/zhangroom.c

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
你来到一间内室，这里收拾得精细异常。一进去，就发
现一面大屏风立在墙角。在屏风后的暗影中，似乎有一女郎
在低头沉思。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yu103",
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

	if(arg != "绯雨令" && arg != "rain plate")
		return notify_fail("你想要什么？\n");

	if(sizeof(filter_array(children(__DIR__"obj/lingpai2"),(: clonep :))) > 0)
		return notify_fail("屏风后的人道：绯雨令我已经给人了，你来晚了一步。\n");

	message_vision ("屏风后的人站了起来，道：好的，既然$N想给本门立功，
本座今天就给你一次机会，拿着这枚令牌去找二总管吧。\n",me);
	ob=new(__DIR__"obj/lingpai2");
	ob->move(me);
	return 1;
}

