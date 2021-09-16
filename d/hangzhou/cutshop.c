// Room: /d/hangzhou/cutshop.c

#include <ansi.h>

inherit ROOM;

string m_id = "hua dajie",m_name = "花大姐";

void create()
{
        set("short", "花记裁缝铺");
        set("long", @LONG
这是一间小小的裁缝铺子，座落在民安街的街角，屋里只有
一张长案，上面放了一些剪刀针线之类的东西，一位中年的大嫂
在忙前忙后的招呼客人。
LONG
        );

        set("night_long", @LONG
这是座落在民安街的街角一间小小的裁缝铺子，现在已经打
烊了，店老板还在忙和着手里的活计。
LONG
        );

        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"minan03",
]));
        set("objects",([
		__DIR__"npc/caifeng_boss" : 1,
]));

        setup();
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
