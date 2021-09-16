// Room: /d/huashan/tiezhai.c

inherit ROOM;

void create ()
{
        set("short", "铁宅");
    set("long", @LONG
这里是一个完全由黒铁盖成的大宅院，宅内四周没有一扇窗，
阳光无法投射到屋内，使得光线非常昏暗，而隐约中似乎能听到
可怕的呻吟声，让你不禁的打了个冷战。

LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"blk_road1",
  "west" : __DIR__"xianshi_tomb",
]) );

  set("light_up", 1);

  setup();
}


