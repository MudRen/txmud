// bookroom <room.h> 书局

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "汇文阁");
        set("long", @LONG
这是一间规模不算小的书局，一进门便给人书香之气，倒不
是说书中的墨香，而是这里朴素的设置和主人高雅的气质，使你
有一种脱俗的感觉。一进门，你可以看见正中有一幅很大的“孔
圣图(eikon)”，两边是一幅对联(couplet)，从这里也可看出主
人的修养，在书柜上摆满了各种书籍，有卖的，但如果你要是有
缘，也许会送你的。由此向北出门就是南大街。
LONG
        );

	set("night_long",@LONG
汇文阁现在已经关门了。柜台边的八仙桌上点着一盏小油灯，
一位中年男子就着灯光在摇头晃脑的读着一本书。
LONG
);

	set("item_desc", ([
		"eikon": "这是一幅描绘相当细致的孔圣图，人物诩诩如生，虽然\n"+
			 "可以猜测到它的作者，绝非一般的庸庸之辈，但是落款\n"+
                         "的地方却没有写什么名字。\n",
		"couplet": "      远求海内珍藏本\n"+
                           "      快读人间未见书\n",
        ]) );

	set("exits", ([
		"west" :	__DIR__"wroad3",
]) );
	set("no_sleep_room",1);

	set("objects",([
		__DIR__"npc/shu_boss"	: 1,
]));
        setup();
}

void open_close_door(string msg,object user)
{
	// 此物件为本店常驻营业员。
	object ob = present("boss zhang",this_object());

	// user 为此房间内的玩家之一.
	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"张老板走到你跟前一鞠躬说道：小号开门了！！这位"+
			RANK_D->query_respect(user)+"需要些什么书？\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"张老板谦声对你说道：这位"+
			RANK_D->query_respect(user)+"对不起，小号要关门了，请您明天再来。\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"关门休息了。\n"NOR);
		return;
	}
}