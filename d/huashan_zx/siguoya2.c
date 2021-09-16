// Room: siguoya2.c

inherit ROOM;

int do_enter(string arg);

void create()
{
	set("short","桠口");
	set("long",@LONG
这里是两峰交会处，从北面呼啸而来的山风在这里被两山逼
到了几十米宽的桠口处，被南面的绝壁(juebi)一挡，风头一转，
向西狂泻而来，真有飞沙走石之势。你的衣襟被风吹的猎猎作响。
一棵老松树迎风而立，稀疏的枝杈在竟一动不动。
LONG
);

	set("exits", ([ /* sizeof() == 3 */
	"west":__DIR__"siguoya.c",
]));

	set("item_desc",([
   		"松树":("
	这是一棵老松树，枝叶稀疏，却并不为风势所动摇。\n
	你不禁沉思，古语云：无欲责刚。看来不假。\n"),

		"juebi":("
	 山路南面是一堵近千尺高的绝壁。绝壁直拔而起寸草不生，\n
	 从这里很难攀爬。\n"),
]));

	set("outdoors", "huashan_zx");
	setup();
}

void init()
{
	add_action( (: do_enter :), ({"pa", "climb"}) );
}

int do_enter(string arg)
{
	object me = this_player();

        if( (arg != "松树") && (arg != "老松树") )
		return notify_fail("你要想什么地方爬？\n");

	if( me->query_temp("on_rided") )
		UNRIDE_CMD->main(me);

	me->start_busy(1);

	message_vision("$N攀着老松树爬了上去.\n", me);

	if( me->move(__DIR__"laosong") )
		tell_room(environment(me), me->name() + "从下面爬了上来。\n",({me}));
	return 1;
}
