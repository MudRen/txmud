// zhubao_room  珠宝店

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "德荣古玩行");
        set("long", @LONG
这里是一家很有名的珠宝店，一进来，你便看见一幅很大的
财神送宝图，四边的柜台很大很干净，柜台后的货架上摆放着各
种古玩珠宝、字画首饰，如果你是行家，会发现这里不愧是长安
的大字号的珠宝店，不但有许多稀有的翡翠宝石，还有很多前朝
的珍贵的字画，宫里采购珠宝古玩都要先来这里。一位胖乎乎的
老板正微笑地看着你，似乎在想怎么把你口袋里的银子赚到手。
从这里向东出门便是永泰路了。
LONG
        );
        
        set("night_long",@LONG
这里就是京城闻名的德荣古玩行，现在是休息时间，屋里静
悄悄的，奇怪的是掌柜的却还坐在柜台后，不时的向门外张望，
象是在等什么人。
LONG
);
	set("exits", ([
                "east"            : __DIR__"wroad2", ]) );
	set("objects",([
		__DIR__"npc/zhubao_boss" : 1,
	]));
        setup();
}


void open_close_door(string msg,object user)
{
	object ob = present("liu qianhong",this_object());

	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"刘掌柜站起身高喊一声:伙计们！卸板、摆货，开门营业了！！\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"刘掌柜看看外面的天说道：伙计们！收货、上板，关门了！！\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"打烊了。\n"NOR);
		return;
	}
}