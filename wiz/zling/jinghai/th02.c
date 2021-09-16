// Room: /d/jinghai/th02.c

inherit ROOM;

void create()
{
        set("short", "桃花山庄前吊桥");
        set("long", @LONG
出现在你面前是一条阔达二十步的护城河，有两丈多深，河
上面架设有一双车对行木悬桥，由粗铁链吊紧。再往西望去，有
一座城楼高筑，旌旗飘扬。巍峨宽阔的拱行城门上方镂着“桃花
山庄”四个金漆大字。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"th01",
]));
        set("outdoors","jinghai");

        setup();
}

void init()
{
        add_action("do_han", "yell");
}

int do_han(string arg)
{
        object me, key, nroom;
        string passwd;

        me = this_player();

        if( !arg
        || !(passwd = "有人吗")
        || (arg != passwd))
                return notify_fail("你扯着脖子喊了几嗓子，周围好像没有任何反映。\n");

        if( !(key = present("zhu ling", me))
        || (key->query("master") != me->query("id")))
                return notify_fail("城上探出了个脑袋看了看你又缩了回去。\n");

        if( !(nroom = find_object(__DIR__"th03")) )
                nroom= load_object(__DIR__"th03");

        set("exits/westup", __DIR__"th03");

        message_vision("城上探出了个脑袋看了看$N，$N赶紧把手中的令牌拿出来晃了晃。\n", me);
        message_vision("只听城上有人喊了些什么，吊桥慢慢放下。\n", me );

        me->delete_temp("jinghai_have_ling/zhu");
        destruct(key);

        call_out("open",10,me);
        return 1;
}

void open()
{
        message("vision", "只听城上有人喊道:关门...升桥。\n", this_object() );
        delete("exits/westup");
}
