// Room: /d/feiyu/miaopu4.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[4]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"miaopu9",
  "east" : __DIR__"miaopu5",
  "north" : __DIR__"miaopu3",
]));

	set("outdoors","feiyu");
	setup();
}
