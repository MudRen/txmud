// Room: /d/hangzhou/hotel.c

#include <ansi.h>

inherit ROOM;

string m_id = "pao tang",m_name = "跑堂";

void create()
{
	set("short", "梨园酒楼");
	set("long", @LONG
你正处身于一间繁华的酒楼里面，宽敞的大厅里的饭桌座满
了食客，熙熙攘攘，店小二忙忙碌碌的穿梭于饭桌和顾客之间，
掌柜的也忙着收拾银子。
LONG
	);

        set("night_long", @LONG
梨园酒楼有杭州第一楼的美誉，现在已经打烊了，跑堂的没
精打采的趴在柜台上。
LONG
        );

	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"minan03",
	"up" : __DIR__"hotell2",
	"east" : __DIR__"chufang",
]));

	set("valid_startroom",1);
	set(SAFE_ENV,1);

	set("objects",([
	__DIR__"npc/paotang" : 1,
]));
	setup();
	load_board("board_hangzhou");
}

void open_close_door(string msg,object user)
{
        object ob = present(m_id,this_object());

        if(!msg || !user)
                return;
        if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,sprintf(CYN"%s笑盈盈的对你说道：开始营业了！！%s请随便看看。\n"NOR,
				m_name,RANK_D->query_respect(user) ));
                else
                        tell_object(user,sprintf(CYN "%s开始营业了。\n"NOR,query("short")));
                return;
        }

        else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,sprintf(CYN"%s说道：这位%s对不起，小铺打烊了，请您明天再来吧。\n"NOR,
				m_name,RANK_D->query_respect(user)));
                else
                        tell_object(user,sprintf(CYN "%s打烊了。\n"NOR,query("short")));
                return;
        }
}
