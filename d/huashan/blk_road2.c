// Room: /d/huashan/blk_road2.c

inherit ROOM;

void create ()
{
        set("short", "�ص�");
    set("long", @LONG
������һ���谵�ĵص���ǽ�ϲ��Ż��΢���Ļ�ѡ�
LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"blk_road1",
  "eastdown" : __DIR__"blk_room",
]) );

  set("light_up", 1);

  setup();
}


