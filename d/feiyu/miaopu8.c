// Room: /d/feiyu/miaopu8.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[8]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miaopu9",
  "east" : __DIR__"miaopu7",
  "north" : __DIR__"miaopu5",
]));

	set("outdoors","feiyu");
	setup();
}
