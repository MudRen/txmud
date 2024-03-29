// Room: taolin.c
// 每年春秋两季才结果，每次结果 3 个。

inherit ROOM;
inherit F_SAVE;

static int sum_per_season = 3;

int sum,year,season;

string query_save_file() { return __DIR__"taolin"; }
int do_pick(string arg);
private void init_sum()
{
	int y = query_year(), s = query_season();

	if(!year || (year != y) || !season || (season != s))
	{
		sum = sum_per_season;
		year = y; season = s;
	}
	if(sum < 0)
		sum = 0;
}

int clean_up() { init_sum(); return ::clean_up(); }

void create()
{
	set("short","西山桃林");
	set("long",@LONG
这是一片不小的野山桃林，据说这里的桃树一年四季都会开
花结果，也是华山的一个奇景。每年春秋两季桃树结果的时候都
会有人来采摘，传说这里的桃子能去病化痰。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"east": __DIR__"guangw1",
	"west": __DIR__"diaoyuchi",
	"northwest":__DIR__"xiaolu1",

]));

	set("outdoors", "huashan_zx");
	setup();
	restore();
	init_sum();
}

void init()
{
	add_action( (:do_pick:),({"zhai","pick"}));
}

int do_pick(string arg)
{
	object tao;

	if(!stringp(arg) || (arg != "山桃" && arg != "桃子"))
		return notify_fail("你要采摘什么？\n");

	if(!(query_season()%2))
		return notify_fail("树上一个桃子也没有。\n");

	if(sum <= 0)
		return notify_fail("树上的桃子已经被摘光了。\n");

	if(!objectp(tao = new(__DIR__"obj/tao")))
		return notify_fail("树上的桃子已经被摘光了。\n");

	--sum;
	message_vision("$N从树上摘下了一个$n。\n",this_player(),tao);

	if(!tao->move(this_player()))
		tao->move(this_object());
	save();
	return 1;
}
