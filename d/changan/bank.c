// bank  钱庄

#include <ansi.h>

inherit BANK;
void create()
{
	set("short", "日升隆钱庄");
        set("long", @LONG
这里一家很大的钱庄，由于地处最繁华的地方，所以生意格
外的好。据说这里的老板曾经也是一位江湖人，不知什么原因得
来的这笔巨款，开下这长安城最大的钱庄。一进门，就看到墙上
有大招牌(sign)，柜台后的小伙计满脸堆笑的迎了过来。从这里
出门向东就是北玄武大街。
LONG
        );
/*
        set("night_long",@LONG
这里就是长安著名的黄记钱庄，单从外表看就气派不凡。虽
说现在已经打烊了，可四处收拾得利利落落，一丝不苟。
LONG
);
*/
        set("item_desc", ([ /* sizeof() == 2 */
	"sign" :  "日升隆钱庄目前提供的服务有：
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan		转账
",
]));
        set("no_beg", 1);

        set("objects",([
        	__DIR__"npc/banker" :1,        
        ]));
	set("exits", ([
                "east"            : __DIR__"nroad9", ]) );
        setup();
}
/*
void open_close_door(string msg,object user)
{
	object ob = present("huang shengfa",this_object());

	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"黄老板对你一抱拳说道：鄙庄开始营业了！！"+
			RANK_D->query_respect(user)+"有什么要办理的敬请吩咐。\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"黄老板对你说道：鄙庄要休息了，您有什么要办理的事务请明天再来吧。\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"打烊了。\n"NOR);
		return;
	}
}
*/
