// Room: /d/fengtian/xm4.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������Ƿ���ٸ����ڵأ���������Ƚ��ྲ������û��̫
��ĵ��̣��Ƚϴ�ĵ��̾��Ƿ��������ھ֡���Զ�ھ֡�����
��һЩ����ĸ���Ҳס�����
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xm3",
  "north" : __DIR__"cross",
  "east" : __DIR__"yizui",
  "west" : __DIR__"zhubao",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
