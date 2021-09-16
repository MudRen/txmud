// Room: /d/huashan/dilao.c

inherit ROOM;

void reset()
{
  ::reset();
  remove_call_out("reset");
  call_out("reset",3600);
}

void create ()
{
        set("short", "地牢");
    set("long", @LONG
这里是一间昏暗无光的牢房，牢房中央有一只巨大的蜈蚣，
它见你进来，开始暴躁的狂叫起来，好可怕啊！
LONG
        );

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"blk_room",
]) );

  set("objects",([
        __DIR__"npc/wugong" : 1,
]));

  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
        object ob=present("super wugong",environment(me));
        if ( !ob || !objectp(ob) )
                return ::valid_leave(me,dir);
        if ( living(ob) || !ob->query_temp("unconcious") )
           return notify_fail("你正想离开，千年蜈蚣忽然堵在了门口。\n");
        this_player()->delete_temp("dilao_enter");
    return ::valid_leave(me,dir);
}


