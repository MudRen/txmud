// Room: /d/huashan/blk_road2.c

inherit ROOM;

void create ()
{
        set("short", "地道");
    set("long", @LONG
这里是一个昏暗的地道，墙上插着火光微弱的火把。
LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"blk_road1",
  "eastdown" : __DIR__"blk_room",
]) );

  set("light_up", 1);

  setup();
}


