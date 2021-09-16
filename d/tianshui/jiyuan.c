// Room: /u/xiaozhen/jiyuan.c

inherit ROOM;

void create()
{
	set("short", "畅春园");
	set("long", @LONG
这里是方圆百里唯一的一家妓院，屋里到处张灯结彩，香气
扑鼻，几位妖娆的姑娘坐在旁边，不时的冲你嬉笑。这里虽然没
有南方娇娃，但北地胭脂也别有丰韵，楼上不时地传来阵阵打情
骂俏的声音。门口立着一块牌子(pai)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jiyuan2",
  "east" : __DIR__"nroad1",
]));
	set("no_clean_up", 0);
	set("item_desc",([
	"pai" : "
每日天黑营业：

普通花酒(putong)   五两金子
银围花酒(yinwei)   十两金子
金围花酒(jinwei) 二十两金子

您可以摆(order)各种花酒\n\n"
]));
	set("objects",([
	__DIR__"npc/m_boss" : 1,
]));

	set(SAFE_ENV,1);
	setup();
}

int valid_leave(object ob,string dir)
{
	string day_night;
	int time;

        if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
        {
		if(day_night == "day" && dir == "up")
			return notify_fail("姑娘们正休息呢，请晚上天黑了再来吧。\n");
	}
	return ::valid_leave(ob,dir);
}