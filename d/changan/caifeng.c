// Room: /d/changan/caifeng.c

#include <ansi.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "四季裁缝铺");
	set("long", @LONG
这里是京城里的四季裁缝铺，这里的老板张嫂心灵手巧、远
近闻名，据说祖上还为皇上秀过龙袍，宫里的衣服多出自这里，
因此生意越做越大，达官贵人们量体裁衣也都到这里。由于名声
在外，价格当然不菲了。柜台上放着一块镶金的红木牌(sign)。
LONG
	);

	set("night_long", @LONG
这里是京城里的四季裁缝铺，现在已经打烊了，柜台上放着
一块镶金的红木牌(sign)。
LONG
	);

	set("item_desc",([
		"sign" : (: look_sign :),
	]));

	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sroad2",
]));
	set("objects",([
		__DIR__"npc/zhang_sao" : 1,
]));

	setup();
}

string look_sign(object me)
{
	return "本店出售各式男女服装，也可量身定(ding)做。\n";
}

void open_close_door(string msg,object user)
{
	object ob = present("boss zhang",this_object());

        if(!msg || !user)
                return;
	if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,CYN"张大嫂笑盈盈的对你说道：开始营业了！！"+
                        RANK_D->query_respect(user)+"请随便看看。\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
                return;
        }

	else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,CYN"张大嫂说道：这位"+
                        RANK_D->query_respect(user)+"对不起，鄙店打烊了，请您明天再来吧。\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"打烊了。\n"NOR);
                return;
        }
}