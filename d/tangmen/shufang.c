// Room: /d/tangmen/shufang.c

inherit ROOM;

void create()
{
  set("short", "�鷿");
  set("long", @LONG
����һ���ª���鷿���м�һ��ľ�����ű�īֽ�⣬һ��С
���η����Աߣ��������һ��С��ܣ�������ɢ�ķ��ż����顣
LONG
  );
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gd7",
  "enter": __DIR__"xiaoting",
]));

  set("objects", ([
  __DIR__"npc/master_yuan" : 1,
]));

  setup();
  replace_program(ROOM);
}

