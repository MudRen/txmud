// Room: /d/feiyu/miaopu5.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[5]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"miaopu4",
  "south" : __DIR__"miaopu8",
  "east" : __DIR__"miaopu6",
  "north" : __DIR__"miaopu2",
]));

	set("outdoors","feiyu");
	setup();
}
