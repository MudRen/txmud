// /d/hangzhou/bookroom.c

#include <ansi.h>
inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "书店");
	set("long", @LONG
这是一家书店。四边的书架上摆满了各类书籍。一个40多岁
的男人像是这里的掌柜，手里捧着一部二十四史坐在左手边
的椅子上正看得津津有味。店堂上挂着一幅对联(sign)。
LONG
	);

	set("night_long",@LONG
书店现在已经关门了。柜台边的八仙桌上点着一盏小油灯，
书店老板正趴在桌子上打盹。
LONG
);

	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
		"west"   : __DIR__"minan01",
	]) );


	set("objects", ([
		__DIR__"npc/shu_boss" : 1,
]) );

	setup();

}

string look_sign(object me)
{
	if( random(2) )
		return "招牌写著：书海无崖勤耕作！\n";
	else
		return "招牌写著：书中自有黄金屋！\n";
}

void open_close_door(string msg,object user)
{
	// 此物件为本店常驻营业员。
	object ob = present("boss liu",this_object());

	// user 为此房间内的玩家之一.
	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"刘老板走到你跟前一鞠躬说道：小号开门了！！这位"+
			RANK_D->query_respect(user)+"需要些什么书？\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"刘老板谦声对你说道：这位"+
			RANK_D->query_respect(user)+"对不起，小号要关门了，请您明天再来。\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"关门休息了。\n"NOR);
		return;
	}
}
