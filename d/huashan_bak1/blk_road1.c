// Room: /d/huashan/blk_road1.c

inherit ROOM;

void create ()
{
        set("short", "�ص�");
    set("long", @LONG
������һ���谵�ĵص���ǽ�ϲ��Ż��΢���Ļ�ѡ�
LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"blk_road2",
  "out" : __DIR__"tiezhai",
]) );

  set("light_up", 1);

  setup();
}


