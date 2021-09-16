// Room: /d/shaolin/shulin2.c

inherit ROOM;

#define MAX	100
#define DIS	15

int mu = 100, time = time();
void check_mu();

void create()
{
	set("short", "小树林");
	set("long", @LONG
这里是一片静静的小树林，不少小树被齐腰砍断，看来经常
有人到这里砍柴。南面是乱石岗，远处一所宏大的寺庙隐约可见。
LONG
	);

	set("exits",([
	"south" : __DIR__"shulin1",
]));

	setup();
}

void init()
{
	add_action("do_kan","kanchai");
}

int do_kan(string arg)
{
	object me = this_player(),muchai;
/*
	if(!stringp(arg) || arg != "muchai")
		return notify_fail("你要砍什么？\n");
*/
	if(!objectp(present("kanchai dao",me)))
		return notify_fail("你没带砍柴刀怎么砍木柴？\n");

	if(me->query("kee") < 10)
		return notify_fail("你现在体力不支，还是歇一会儿再砍吧。\n");

	check_mu();
	if(!mu)
		return notify_fail("这片小树林已经没有木柴可砍了。\n");
	message_vision("$N抡圆了手中的砍柴刀狠狠的砍了下去。\n",me);
	muchai = new(__DIR__"obj/muchai");
	muchai->move(me);
	--mu;
        me->receive_damage("kee",4,"tire");
	me->add_temp("shaolinjob/kanchai",1);
	return 1;
}

void check_mu()
{
	int add;

	if(mu == MAX)
		return;

	add = to_int((time() - time)/DIS);
	if(!add)
		return;
	mu += add;
	if(mu > MAX)
		mu = MAX;
	time = time();
	return;
}
