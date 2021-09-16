// design by 发现号(find) . all right reserved.

// Room: /d/changan/jiyuan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "怡香苑");
	set("long", @LONG
这里就是京师闻名第一大妓院，不知多少多情公子为一亲芳
泽而一掷千金。屋里到处张灯结彩，香气扑鼻，几位妖娆的姑娘
坐在旁边，不时的冲你嬉笑，老鸨在热情的招呼着客人。这里无
论是南方娇娃，还是北地胭脂都别有丰韵，楼上不时地传来阵阵
打情骂俏的声音。门口立着一块红木牌子(pai)。
LONG
	);

// 妓院晚上才开门，这是白天玩家来到这里看到的长描述。
	set("day_long", @LONG
这里就是京师闻名第一大妓院，不知多少多情公子为一亲芳
泽而一掷千金。现在大概是休息时间，桌子上杯盘狼籍，地上满
是果皮、瓜子壳，老鸨蔫头耷脑的坐在门口。门边立着一块红木
牌子(pai)。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jiyuan2",
  "north" : __DIR__"nroad7",
]));
	set("no_clean_up", 0);
	set("item_desc",([
	"pai" : "
每日夜晚营业：

普通花酒(putong)   五两金子
银围花酒(yinwei)   十两金子
金围花酒(jinwei) 二十两金子

您可以摆(order)各种花酒\n\n"
]));
	set("objects",([
	__DIR__"npc/m_boss" : 1,
]));
	set(SAFE_ENV,1);
	set("no_magic",1);
	setup();
}

int valid_leave(object ob,string dir)
{
        if ( is_day() && dir == "up" )
		return notify_fail("姑娘们正休息呢，请晚上天黑了再来吧。\n");
	else return ::valid_leave(ob,dir);
}

void open_close_door(string msg,object user)
{
	// 此物件为本店常驻营业员。
	object ob = present("m_boss",this_object());

	// user 为此房间内的玩家之一.
	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"老鸨对你说道：天亮了，姑娘们要休息了！！这位"+
			RANK_D->query_respect(user)+"请明晚再来吧。\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"都去休息了。\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"老鸨高声喊道：快把灯都点上，姑娘们出来接客啦！！\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
		return;
	}
}